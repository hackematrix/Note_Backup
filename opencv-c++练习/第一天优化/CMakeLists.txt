cmake_minimum_required(VERSION 3.20)
project(piture)
set(OpenCV_DIR "D:/OpenCv/opencv/build")

find_package(OpenCV REQUIRED)
add_executable(piture information.cpp main.cpp)
target_include_directories(piture PUBLIC ${OpenCV_INCLUDE_DIRS})

# 链接 OpenCV 库
target_link_libraries(piture ${OpenCV_LIBS})
