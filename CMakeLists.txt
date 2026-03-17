# WARNING
# I have no clude how to use CMake so
# i used GPT to generate some of it xD

cmake_minimum_required(VERSION 3.10)

project(warships C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(Curses REQUIRED)

add_executable(warships warships.c)

target_link_libraries(warships PRIVATE ${CURSES_LIBRARY})

target_include_directories(warships PRIVATE ${CURSES_INCLUDE_DIRS})
