cmake_minimum_required(VERSION 2.4)
set(CMAKE_C_STANDARD 11)
project(curl-test C)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(curl-test main.c)