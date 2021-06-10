cmake_minimum_required(VERSION 3.19)
project(gnl1 C)

set(CMAKE_C_STANDARD 99)

include_directories( ./ )

add_executable(gnl1
        gnl.c
        keks.txt)