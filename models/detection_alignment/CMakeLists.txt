
#cmake_minimum_required(VERSION 3.10)
#project(detection_alignment)

#find_package(OpenCV REQUIRED)
#find_package(dlib REQUIRED)
#message(STATUS "OpenCV library status:")
#message(STATUS "    version: ${OpenCV_VERSION}")
#message(STATUS "    libraries: ${OpenCV_LIBS}")
#message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
#include_directories(${OpenCV_INCLUDE_DIRS})
#include(/usr/local/lib/cmake/dlib/dlib.cmake)
#set(CMAKE_CXX_STANDARD 11)
#add_executable(detection_alignment detection_alignment.cpp)
#set(CMAKE_CXX_STANDARD 11)
#target_link_libraries(detection_alignment ${OpenCV_LIBS} dlib::dlib)


aux_source_directory(. DIR_DETECTION_ALIGNMENT)
add_library(detection_alignment ${DIR_DETECTION_ALIGNMENT})