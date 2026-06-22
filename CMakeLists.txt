cmake_minimum_required(VERSION 4.3.1)
project(Raylib_Test C)

# raylib
add_subdirectory(lib/raylib)

# raygui
include_directories(lib/raygui/src)

add_executable(test main.c)

target_link_libraries(test PRIVATE raylib)
