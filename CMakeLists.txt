cmake_minimum_required(VERSION 3.10)
project(face_platform)
find_package(OpenCV REQUIRED)
find_package(dlib REQUIRED)
set(CMAKE_CXX_STANDARD 11)

add_executable(face_platform main.cpp)

add_subdirectory("./models/data_source")
add_subdirectory("./models/data_preprocess")
add_subdirectory("./models/detection_alignment")
add_subdirectory("./models/recognization")
include(/usr/local/lib/cmake/dlib/dlib.cmake)
target_link_libraries(face_platform ${OpenCV_LIBS} dlib::dlib)