cmake_minimum_required(VERSION 3.19)
project(cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp main.cpp singlylinkedlist/singlylinkedlist.cpp singlylinkedlist/singlylinkedlist.h node/node.h node/node.cpp)