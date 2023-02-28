cmake_minimum_required(VERSION 3.18)
set(CMAKE_CXX_FLAGS "-std=c++11 -g")
project("design_pattern_cpp")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(testA
                test/testA.cpp       
                src/example/A.cpp
                src/reflection/classfactory.cpp
                src/reflection/classregister.cpp
                src/reflection/classfield.cpp
                src/reflection/classmethod.cpp)
