
/*
 * Graph.h
 *
 * A class to manage a Vertex-Edge Graph
 * 
 * author: Ag
 * 
 * */

#ifndef V_E_GRAPH_GRAPH_H_
#define V_E_GRAPH_GRAPH_H_

#include <unordered_map>
#include "Vertex.h"
#include "Edge.h"
#include "Errors.h"

namespace VEGraph {
    
template<typename T>
class Graph {

public:

    using vertex_map = std::unordered_map<T, Vertex<T>*>;

    Graph() {}
    ~Graph() { clear(); }
    
    // Creates and adds a vertex with the given id.
    Vertex<T>* addVertex(const T id) { return addVertex(new Vertex<T>{id}); }
    
    Vertex<T>* addVertex(Vertex<T>* v) {
    /* Adds the vertex at the given pointer, returns same pointer. */
        bool successful = verts.emplace(v->id(), v).second; // tries to add vertex
        if(!successful) throw RepeatIDError<T>{v->id()}; // if failed, says so
        return v; // otherwise returns vertex
    }

    bool removeVertex(const T id) {
    /* Attempts to remove the vertex with the given id, returns true if successful. */
        
        auto loc = verts.find(id); // find vertex
        
        if (loc == verts.end()) return false; // if not found, return false
        
        // otherwise delete vertex
        delete loc.second;
        verts.erase(loc);

        return true;
    }

    Vertex<T>* vertex(const T id) {
    /* Gets the vertex with the given id. */
        auto loc = verts.find(id);
        if (loc == verts.end()) return addVertex(id); // creates if not found
        return loc->second; 
    }
    
    // See vertex(const T id)
    Vertex<T>* operator[] (const T id) { return vertex(id); }
    
    void connect(const T va, const T vb, double len) {
    /* Connects vertices with the given ids with an edge of the given length. */
        new Edge<T>{vertex(va), vertex(vb), len};
    }
    
    const vertex_map& vertices() const { return verts; } // returns the map of vertices.

    void clear() {
        for (auto& kv : verts) delete kv.second;
        verts.clear();
    }
        
private:
    vertex_map verts {};
};
    
    
}

#endif