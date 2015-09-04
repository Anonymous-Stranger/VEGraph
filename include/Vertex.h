
/*
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

#ifdef V_E_GRAPH_DEBUG_MODE
    static constexpr bool debug_mode {V_E_GRAPH_DEBUG_MODE};
#else 
    static constexpr bool debug_mode {false};
#endif

    using edge_set = std::unordered_set<Edge<T>*>;

    explicit Vertex(T id={}): uid{id} {
        if (debug_mode) std::cout << ">> " << debugStr() << std::endl;
    }
    
    Vertex(const Vertex<T>& v): uid{v.uid} {
        if (debug_mode) std::cout << ">> " << debugStr() << ": " << v.debugStr() << std::endl;
    }
    
    Vertex& operator=(const Vertex<T>& v) {
        std::swap(*this, {v});
        if (debug_mode) std::cout << ">> " << debugStr() << v.debugStr() << std::endl;
        return *this;
    }
    
    Vertex(Vertex<T>&& v): uid{v.uid} {
        if (debug_mode) std::cout << ">> " << debugStr() << ": <- " << v.debugStr() << std::endl;
    }
    
    Vertex& operator=(Vertex<T>&& v) {
        std::swap(*this, v);
        if (debug_mode) std::cout << ">> " << debugStr() << " <- " << v.debugStr() << std::endl;
        return *this;
    }
    
    ~Vertex() {
        
        for (auto& e : eds) {
            e->same(this) = nullptr;
            delete e;
        }
        
        if (debug_mode) std::cout << ">> ~" << debugStr() << std::endl;
        
    }
    
    const T& id() const { return uid; }
    const edge_set& edges() const { return eds; }

    std::string debugStr() const {
        std::stringstream ss {};
        ss << "vertex:" << this << "(" << uid << ")";
        return ss.str();
    }

private:
    T uid;
    edge_set eds {};
};

} /* VEGraph */

#endif