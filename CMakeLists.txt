cmake_minimum_required(VERSION 3.5)
project(DataStructures)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Array/ArrayList.c
    Array/ArrayList.h
    Array/ArrayQueue.c
    Array/ArrayQueue.h
    Array/ArrayStack.c
    Array/ArrayStack.h
    BinaryTrees/AVLTree.c
    BinaryTrees/AVLTree.h
    BinaryTrees/BinarySearchTree.c
    BinaryTrees/BinarySearchTree.h
    BinaryTrees/RedBlackTree.c
    BinaryTrees/RedBlackTree.h
    Compression/Huffman.c
    Compression/Huffman.h
    Compression/RLE.c
    Compression/RLE.h
    Compression/Utilities.c
    Compression/Utilities.h
    Heap/Heap.c
    Heap/Heap.h
    Lists/CircleList.c
    Lists/CircleList.h
    Lists/DoublyLinkedList.c
    Lists/DoublyLinkedList.h
    Lists/LinkedList.c
    Lists/LinkedList.h
    Queues/Deque.c
    Queues/Deque.h
    Queues/Queue.c
    Queues/Queue.h
    Stack/Stack.c
    Stack/Stack.h
    Vector/SearchAlgorithms.c
    Vector/SearchAlgorithms.h
    Vector/SortingAlgorithms.c
    Vector/SortingAlgorithms.h
    Vector/Vector.c
    Vector/Vector.h
    Programa.c
        Types.h Tests/SortingTests.c Tests/SortingTests.h)

add_executable(DataStructures ${SOURCE_FILES})