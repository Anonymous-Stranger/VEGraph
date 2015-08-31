
#define V_E_GRAPH_DEBUG_MODE true

#include "_test.h"

namespace VEGraphTest {
    
    void run() {
        Graph<std::string> g {};
        
        g.connect("blah", "test", 5);
        g.connect("blah", "test", 2);
        g.connect("test", "hello", 2);
        
        std::cout << std::endl;
        
        for (auto& kv : g.verticies()) {
            
            std::cout << "vertex " << kv.first << std::endl;
            
            for (auto& e : kv.second->edges()) {
                std::cout << "    " << e->len << " -> ";
                std::cout << e->other(kv.second)->id() << std::endl;
            }
            
            std::cout << std::endl;
            
        }
        
        std::cout << std::endl;
        
    }
    
}