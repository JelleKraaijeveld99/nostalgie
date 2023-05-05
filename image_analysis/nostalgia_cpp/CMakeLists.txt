cmake_minimum_required(VERSION 3.25)
set(CMAKE_OSX_ARCHITECTURES x86_64)
project(nostalgia_cpp)

set(CMAKE_CXX_STANDARD 17)

#find_library(OpenCV)
find_package(OpenCV)

include_directories(${OpenCV_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 17)

add_executable(nostalgia_cpp main.cpp analyse.cpp)

target_link_libraries(nostalgia_cpp ${OpenCV_LIBS})
