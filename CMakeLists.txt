cmake_minimum_required(VERSION 3.5)
project(DataStructures)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.c include/util.h)

file(GLOB INCLUDE_FILES
        include/*.c
        include/*.h)

file(GLOB SRC_FILES
        src/*.c
        src/*.h)

include_directories(
        include
        src
        .)

add_executable(mainExecutable ${SOURCE_FILES} ${INCLUDE_FILES})
set_property(TARGET mainExecutable PROPERTY C_STANDARD 99)


# Example executables
set_property(TARGET mainExecutable PROPERTY C_STANDARD 99)

