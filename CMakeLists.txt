cmake_minimum_required(VERSION 3.5)
project(DataStructures)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        array/ArrayList.c
        array/ArrayList.h
        array/ArrayQueue.c
        array/ArrayQueue.h
        array/ArrayStack.c
        array/ArrayStack.h
        compression/Huffman.c
        compression/Huffman.h
        compression/RLE.c
        compression/RLE.h
        compression/Utilities.c
        compression/Utilities.h
        heap/Heap.c
        heap/Heap.h
        queues/Deque.c
        queues/Deque.h
        queues/Queue.c
        queues/Queue.h
        stack/Stack.c
        stack/Stack.h
        vector/SearchAlgorithms.c
        vector/SearchAlgorithms.h
        vector/SortingAlgorithms.c
        vector/SortingAlgorithms.h
        vector/Vector.c
        vector/Vector.h
        Programa.c
        Types.h
        tests/SortingTests.c
        tests/SortingTests.h
        examples/vector.c)

add_executable(DataStructures ${SOURCE_FILES})