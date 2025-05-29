cmake_minimum_required(VERSION 3.20)
project(demo ) 
set(EIGEN_ROOT_DIR "D:/eigen/eigen-3.4.0")
add_executable(demo demo.cpp)
target_include_directories(demo PRIVATE ${EIGEN_ROOT_DIR})










