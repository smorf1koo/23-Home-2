cmake_minimum_required(VERSION 3.16)
project(hw3-4_modules)

set(CMAKE_CXX_STANDARD 14)

set(Headers Matrix.h)
set(Sources Matrix.cpp)

add_library(matrix_lib STATIC ${Sources} ${Headers})

add_executable(hw3-4_modules
        main.cpp
        Matrix.cpp
        Matrix.h)

target_link_libraries(hw3-4_modules matrix_lib)