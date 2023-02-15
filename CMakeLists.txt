cmake_minimum_required(VERSION 3.24)
project(omp01)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

add_executable(omp01 main.cpp)
add_executable(repaso repaso.cpp)

target_link_libraries(omp01  benchmark)
