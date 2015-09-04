
cmake_minimum_required(VERSION 2.8)

project(VEGRaphTest)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(../include)

link_directories(../bin)

add_executable(VEGraphTest
	main.cpp
)

target_link_libraries(VEGraphTest VEGraph)