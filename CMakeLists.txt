cmake_minimum_required(VERSION 3.6)
project(Net)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Classes/List.cpp Classes/List.h Classes/Node.cpp Classes/Node.h Net.cpp Net.h Classes/NodeNsled.cpp Classes/NodeNsled.h Classes/Atribut.cpp Classes/Atribut.h Classes/Connect.cpp Classes/Connect.h stdafx.h)
add_executable(Net ${SOURCE_FILES})