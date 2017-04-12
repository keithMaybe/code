cmake_minimum_required(VERSION 2.8)
project(calcBackProject)
find_package(OpenCV REQUIRED)
add_executable(calcBackProject calcBackProject.cpp)
target_link_libraries(calcBackProject ${OpenCV_LIBS})

