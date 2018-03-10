cmake_minimum_required(VERSION 3.5)
project(DataStructures)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.c)

file(GLOB SOURCE_FILES
        include/*.c
        include/*.h
        src/*.h
        src/*.h
        *.c
        *.h)

add_executable(DataStructures ${SOURCE_FILES})

include_directories(
        include
        src
        .)

set_property(TARGET DataStructures PROPERTY C_STANDARD 99)

# Example executables
set_property(TARGET DataStructures PROPERTY C_STANDARD 99)