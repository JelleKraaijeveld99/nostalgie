cmake_minimum_required(VERSION 3.25)
set(CMAKE_OSX_ARCHITECTURES x86_64)
project(nostalgia_cpp)

set(CMAKE_CXX_STANDARD 17)

# Set the path to the liblo library
set(LIBLO_INCLUDE_DIR "/usr/local/Cellar/liblo/0.31/include")
set(LIBLO_LIBRARY_DIR "/usr/local/Cellar/liblo/0.31/lib")

# Find the liblo library
find_library(LIBLO_LIBRARY NAMES lo PATHS ${LIBLO_LIBRARY_DIR})

#find_library(OpenCV)
find_package(OpenCV)

# Add the liblo and openCV include directory
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${LIBLO_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 17)

add_executable(nostalgia_cpp main.cpp analyse.cpp osc_server.cpp osc.cpp)

target_link_libraries(nostalgia_cpp ${LIBLO_LIBRARY})
target_link_libraries(nostalgia_cpp ${OpenCV_LIBS})
