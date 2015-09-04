
/*
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
    
    Vertex<T>* addVertex(const T id) { return addVertex(new Vertex<T>{id}); }
    
    Vertex<T>* addVertex(Vertex<T>* v) {
        auto res = verts.emplace(v->id(), v);
        if(!res.second) throw RepeatIDError<T>{v->id()};
        return res.first->second;
    }
    
    Vertex<T>* vertex(const T id) {
        auto loc = verts.find(id);
        if (loc == verts.end()) return addVertex(id);
        return loc->second; 
    }
    
    Vertex<T>* operator[] (const T id) { return vertex(id); }
    
    void connect(const T va, const T vb, double len) {
        new Edge<T>{vertex(va), vertex(vb), len};
    }
    
    const vertex_map& verticies() const { return verts; }
        
private:
    vertex_map verts {};
    
    void clear() {
        for (auto& kv : verts) delete kv.second;
        verts.clear();
    }
};
    
    
}

#endif