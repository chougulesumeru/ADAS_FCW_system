#cmake makes your project "production-ready" and portable

cmake_minimum_required(VERSION 3.10)

project(ADAS_FCW_SYSTSEM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#include source files 
add_library(fcw_lib src/FCWEngine.cpp)

#main executbale
add_executable(adas_main src/main.cpp)
target_link_libraries(adas_main fcw_lib)

#testing 
enable_testing()
add_subdirectory(tests)