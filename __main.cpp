/*
 * 
 * author: Ag
 * 
 * */

#include <iostream>
#include <stdexcept>
#include "_test.h"

int main(int argc, char **argv) try {
    
    VEGraphTest::run();
    
} catch (std::exception ex) {
    std::cerr << ex.what() << std::endl;
} catch (...) {
    std::cerr << "Something failed.";
}
