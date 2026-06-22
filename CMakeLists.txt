cmake_minimum_required(VERSION 4.3.1)
project(Raylib_Test C)

if (MSVC)
    add_compile_options(/utf-8)
endif()

# raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "Build raylib examples")
set(BUILD_GAMES    OFF CACHE BOOL "Build raylib games")
add_subdirectory(lib/raylib-6.0)

# raygui
include_directories(lib/raygui-4.0/src)

# main.c
add_executable(test main.c)

target_link_libraries(test PRIVATE raylib)
