cmake_minimum_required(VERSION 3.30)
project(CourseTSPP C)

set(CMAKE_C_STANDARD 11)

add_executable(CourseTSPP main.c
        nodes.c
        nodes.h
        arithmetics.c
        arithmetics.h)
