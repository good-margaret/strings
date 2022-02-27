cmake_minimum_required(VERSION 3.20)
project(str C)

set(CMAKE_C_STANDARD 11)

add_executable(str main.c string/string_.c string/string_.h string/tasks/tasks.c string/tasks/tasks.h)

add_library(strrr string/string_.h string/string_.c string/tasks/tasks.h string/tasks/tasks.c)
target_link_libraries(str strrr)
