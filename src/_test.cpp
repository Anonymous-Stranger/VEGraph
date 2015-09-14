
/**
 *
 * _test.cpp
 *
 * Tests VEGraph
 * 
 * author: Ag
 * 
 */

#include "_test.h"

namespace VEGraphTest {
    
    void run() {

        Graph<std::string> g {}; // create a graph
        
        // connect some vertices (vertices automatically created if not existing)
        g.connect("blah", "test", 5);
        g.connect("blah", "test", 2);
        g.connect("test", "hello", 2);
        
        std::cout << std::endl;
        
        // print connections
        for (auto& kv : g.vertices()) {
            
            std::cout << "vertex " << kv.first << std::endl;
            
            for (auto& e : kv.second->edges()) {
                std::cout << "    " << e->len << " -> ";
                std::cout << e->other(kv.second)->id() << std::endl;
            }
            
            std::cout << std::endl;
            
        }
        
    }
    
}