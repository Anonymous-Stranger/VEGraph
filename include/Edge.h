
/*
 * Edge.h
 *
 * A class to manage each Edge in a Graph.
 * 
 * author: Ag
 * 
 * */
 
#ifndef V_E_GRAPH_EDGE_H_
#define V_E_GRAPH_EDGE_H_

#include <iostream>
#include <sstream>
#include "Errors.h"

namespace VEGraph {

template<typename T> class Vertex;

template<typename T>
struct Edge {

// debug mode will print messages when Edge objects are created, moved and destroyed.    
#ifdef V_E_GRAPH_DEBUG_MODE
    static constexpr bool debug_mode {V_E_GRAPH_DEBUG_MODE};
#else 
    static constexpr bool debug_mode {false};
#endif
    
    Vertex<T>* va;
    Vertex<T>* vb;
    const double len;
    
    Edge(Vertex<T>* va, Vertex<T>* vb, double len): 
        va{va}, vb{vb}, len{len} {
        
        va->eds.insert(this);
        vb->eds.insert(this);
        
        if (debug_mode) std::cout << ">> " << debugStr() << std::endl;
    }
    
    Edge(const Edge<T>& e)=delete;
    Edge& operator=(const Edge<T>& e)=delete;
    
    Edge(Edge<T>&& e): va{e.va}, vb{e.vb}, len{len} {
        if (debug_mode) std::cout << ">> " << debugStr() << ": <- " << e.debugStr() << std::endl;
    }
    
    Edge& operator=(Edge<T>&& e) {
        std::swap(*this, e);
        if (debug_mode) std::cout << ">> " << debugStr() << " <- " << e.debugStr() << std::endl;
    }
    
    Vertex<T>*& same(Vertex<T> *const v) {
    /* Returns a reference to va or vb, whichever points to the given vertex. */
        if (v == va) return va;
        if (v == vb) return vb;
        throw VertexDoesNotEndEdgeError{};
    }
    
    Vertex<T>*& other(Vertex<T> *const v) {
    /* Returns a reference to va or vb, whichever points to the vertex other than given vertex. */
        if (v == va) return vb;
        if (v == vb) return va;
        throw VertexDoesNotEndEdgeError{};
    }
    
    void disconnect(Vertex<T>* v) {
    /* Disconnects self from the given vertex. */
        Vertex<T>*& pt = same(v);
        pt->eds.erase(this);
        pt = nullptr;
    }
    
    ~Edge() {
        if (debug_mode) std::cout << ">> ~" << debugStr() << std::endl;
        
        if (va) disconnect(va);
        if (vb) disconnect(vb);
    }
    
    std::string debugStr() const {
    /* Returns data related to this edge in a formatted-for-viewing string. */
        std::stringstream ss {};
        ss << "edge:" << this << "(" << (va ? va->debugStr() : "null") << ", ";
        ss << (vb ? vb->debugStr() : "null") << ", " << len << ")";
        return ss.str();
    }
    
};
    
}
 
#endif