cmake_minimum_required(VERSION 3.5)
project(DataStructures)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.c)

file(GLOB INCLUDE_FILES
        include/*.c
        include/*.h)

file(GLOB SRC_FILES
        src/*.c
        src/*.h)

file(GLOB THRD_PARTY
        3thd_party/*.h
        3thd_party/*.c)

file(GLOB UNIT_TESTS
        tests/*.c)

include_directories(
        include
        src
        3thd_party)

# Main executable
add_executable(mainExecutable ${SOURCE_FILES} ${INCLUDE_FILES})
set_property(TARGET mainExecutable PROPERTY C_STANDARD 99)

# Example executables
set_property(TARGET mainExecutable PROPERTY C_STANDARD 99)

# Unit tests executables
add_executable(utilTest ${INCLUDE_FILES} ${SRC_FILES} ${THRD_PARTY} ${UNIT_TESTS})
set_property(TARGET utilTest PROPERTY C_STANDARD 99)




