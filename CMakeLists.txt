cmake_minimum_required(VERSION 3.0.0)
project(cautrucdulieu_giaithuat VERSION 0.1.0 LANGUAGES C CXX)


#thêm source code vào biến SOURCES
file(GLOB SOURCES "src/*.cpp")
#include file header
include_directories(include)

#run and debug cmd
add_executable(cautrucdulieu_giaithuat ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_COMPILER "C:/mingw32/bin/g++.exe")
set(CMAKE_C_COMPILER "C:/mingw32/bin/gcc.exe")
include(CPack)
