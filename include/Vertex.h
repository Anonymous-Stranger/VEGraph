
/*
 * Vertex.h
 *
 * A class to manage each vertex in a Graph.
 * 
 * author: Ag
 * 
 * */
 
#ifndef V_E_GRAPH_VERTEX_H_
#define V_E_GRAPH_VERTEX_H_
 
#include <unordered_set>
#include "Edge.h"

namespace VEGraph {
    
template<typename T>
class Vertex {

    friend Edge<T>;
    
public:

// debug mode will print messages when Vertex objects are created and destroyed.
#ifdef V_E_GRAPH_DEBUG_MODE
    static constexpr bool debug_mode {V_E_GRAPH_DEBUG_MODE};
#else 
    static constexpr bool debug_mode {false};
#endif

    using edge_set = std::unordered_set<Edge<T>*>;

    explicit Vertex(T id={}): uid{id} {
        if (debug_mode) std::cout << ">> " << debugStr() << std::endl;
    }
    
    // Just use pointers. 
    // It's way more complicated to worry about the consequences of copies and moves within a graph.
    Vertex(const Vertex<T>& v)=delete;
    Vertex& operator=(const Vertex<T>& v)=delete;
    Vertex(Vertex<T>&& v)=delete;
    Vertex& operator=(Vertex<T>&& v)=delete;
    
    ~Vertex() {
        clear();
        if (debug_mode) std::cout << ">> ~" << debugStr() << std::endl;
        
    }

    void clear() {
        for (auto& e : eds) { // delete all connected edges
            e->same(this) = nullptr;
            delete e;
        }

        eds.clear();
    }
    
    const T& id() const { return uid; }
    const edge_set& edges() const { return eds; }

    std::string debugStr() const {
    /* Returns data related to this vertex in a formatted-for-viewing string. */
        std::stringstream ss {};
        ss << "vertex:" << this << "(" << uid << ")";
        return ss.str();
    }

private:
    T uid; // unique id
    edge_set eds {}; // edges
};

} /* VEGraph */

#endif