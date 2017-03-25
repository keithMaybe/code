cmake_minimum_required(VERSION 2.8)
project(boxFilter)
find_package(OpenCV REQUIRED)
add_executable(boxFilter boxFilter.cpp)
target_link_libraries(boxFilter ${OpenCV_LIBS})

