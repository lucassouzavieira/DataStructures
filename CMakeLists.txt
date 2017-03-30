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
        binarytrees/AVLTree.c
        binarytrees/AVLTree.h
        binarytrees/BinarySearchTree.c
        binarytrees/BinarySearchTree.h
        binarytrees/RedBlackTree.c
        binarytrees/RedBlackTree.h
        compression/Huffman.c
        compression/Huffman.h
        compression/RLE.c
        compression/RLE.h
        compression/Utilities.c
        compression/Utilities.h
        heap/Heap.c
        heap/Heap.h
        lists/CircleList.c
        lists/CircleList.h
        lists/DoublyLinkedList.c
        lists/DoublyLinkedList.h
        lists/LinkedList.c
        lists/LinkedList.h
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
        Types.h tests/SortingTests.c tests/SortingTests.h)

add_executable(DataStructures ${SOURCE_FILES})