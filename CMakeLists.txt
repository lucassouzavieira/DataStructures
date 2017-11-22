cmake_minimum_required(VERSION 3.5)
project(DataStructures)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.c)

file(GLOB SOURCE_FILES
        array/*.c
        array/*.h
        compression/*.c
        compression/*.h
        heap/*.c
        heap/*.h
        queues/*.c
        queues/*.h
        stack/*.c
        stack/*.h
        vector/*.c
        vector/*.h
        *.c
        *.h)

add_executable(DataStructures ${SOURCE_FILES})

include_directories(
        .
        array
        binarytrees
        compression
        heap
        queues
        stack
        lists
        vector)

set_property(TARGET DataStructures PROPERTY C_STANDARD 99)

# Example executables
set(VECTOR_EXAMPLE_SOURCES
        vector/Vector.h
        vector/Vector.c
        examples/vector.c)

add_executable(vector ${VECTOR_EXAMPLE_SOURCES})
set_property(TARGET DataStructures PROPERTY C_STANDARD 99)