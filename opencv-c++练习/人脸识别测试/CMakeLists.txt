cmake_minimum_required(VERSION 3.20)
project(face)
set(OpenCV_DIR "D:/OpenCV/opencv/build")

find_package(OpenCV REQUIRED)
add_executable(face face.cpp main.cpp)
target_include_directories(face PUBLIC ${OpenCV_INCLUDE_DIRS})

# 链接 OpenCV 库
target_link_libraries(face ${OpenCV_LIBS})
