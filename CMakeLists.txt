cmake_minimum_required(VERSION 3.10)
project(http-server-c
  LANGUAGES C
  VERSION 0.1.0
  DESCRIPTION "A simple HTTP server written in C"
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_C_FLAGS "-Wall -std=c11")
set(CMAKE_C_FLAGS_DEBUG_INIT "-g -Wall -std=c11")

add_executable(${CMAKE_PROJECT_NAME})
target_include_directories(${CMAKE_PROJECT_NAME}
  PRIVATE "${CMAKE_SOURCE_DIR}/include"
)

add_subdirectory("${CMAKE_SOURCE_DIR}/src")
