cmake_minimum_required(VERSION 3.10)

project(catchkeywords CXX)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE debug)

add_library(keywords STATIC keywords.cpp)

add_executable(main main.cpp)

target_link_libraries(main keywords)