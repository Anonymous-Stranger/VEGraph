
/*
 * 
 * author: Ag
 * 
 * */

#ifndef V_E_GRAPH_ERRORS_H_
#define V_E_GRAPH_ERRORS_H_

#include <stdexcept>
#include <sstream>

namespace VEGraph {
    
    /* (pg 730, TC++PL 4th, Stroustrup) */
	template<typename Target=std::string, typename Source=std::string>
	inline Target to(Source arg) {
		std::stringstream interp {};
		Target result;

		if ( !(interp << arg) 						   // write arg to stream
			|| !(interp >> result)					   // read result from stream
			|| !(interp >> std::ws).eof()) {		   // stuff left in stream?
			throw std::runtime_error{"to<>() failed"};
		}

		return result;
	}
    
    struct BaseError: std::runtime_error {
        BaseError(std::string message): std::runtime_error("VEGraph: "+message) {}
    };
    
    template<typename T>
    struct RepeatIDError: BaseError {
        RepeatIDError(T id): BaseError("id '" + to<std::string>(id) + "' repeated") {}
    };
    
    struct VertexDoesNotEndEdgeError: BaseError {
        VertexDoesNotEndEdgeError(std::string message="vertex does not end edge"): BaseError(message) {}
    };
    
//    template<typename T>
//    struct VertexNotFoundError: BaseError {
//        VertexNotFoundError(T id): BaseError("vertex '"+to<std::string>(id)+"' not found")
//    };
    
}

#endif