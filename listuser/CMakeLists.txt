cmake_minimum_required (VERSION 2.8.9)
PROJECT(listuser)
SET(CMAKE_CXX_FLAGS "-std=c++11")
SET(CMAKE_BUILD_TYPE Release)
file(GLOB srcx
    "src/*.cpp"
)
SET(sb_SOURCES "main.cpp" ${srcx})
ADD_EXECUTABLE(listuser ${sb_SOURCES})
INCLUDE_DIRECTORIES("include")
