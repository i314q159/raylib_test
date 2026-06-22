cmake_minimum_required(VERSION 3.16)
project(Raylib_Test C)

set(CMAKE_C_STANDARD 99)

# 编译raylib子库
add_subdirectory(raylib)

add_executable(test main.c)

target_link_libraries(test PRIVATE raylib)
