cmake_minimum_required(VERSION 3.25.1)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(OpenCV)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(step1 step1.cpp)
target_link_libraries(step1 ${OpenCV_LIBS})

