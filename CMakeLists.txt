cmake_minimum_required(VERSION 3.18)
set(CMAKE_CXX_FLAGS "-std=c++11 -g")
project("design_pattern_cpp")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(test1 src/test1.cpp)
