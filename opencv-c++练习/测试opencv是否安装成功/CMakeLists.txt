cmake_minimum_required(VERSION 3.20)
project(demo)
set(OpenCV_DIR "D:/OpenCV/opencv/build")

find_package(OpenCV REQUIRED)
add_executable(demo piture.cpp main.cpp)
target_include_directories(demo PUBLIC ${OpenCV_INCLUDE_DIRS})

# 链接 OpenCV 库
target_link_libraries(demo ${OpenCV_LIBS})