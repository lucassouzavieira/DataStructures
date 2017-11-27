/*
 * Copyright (C) 2016  Lucas S. Vieira
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TYPES_H
#define TYPES_H

#define LINE_MAX_LENGTH 500

/******************************************************************************
Lists, stacks and queues
******************************************************************************/
typedef struct node {
    long int key;
    struct node *pointer;
} node;

typedef struct double_node {
    long int key;
    struct double_node *next;
    struct double_node *previous;
} double_node;

typedef struct list {
    node *list;
    node *last;
    long int nodes;
} list;

typedef struct circle_list {
    node *list;
    long int nodes;
} circle_list;

typedef struct doubly_list {
    double_node *list;
    double_node *startOfList;
    double_node *endOfList;
    long int nodes;
} doubly_list;

typedef struct stack {
    node *stack;
    node *top;
    unsigned long int nodes;
} stack;

typedef struct queue {
    node *queue;
    node *endOfQueue;
    unsigned long int nodes;
} queue;

typedef struct deque {
    node *startOfQueue;
    node *endOfQueue;
    unsigned long int nodes;
} deque;

typedef struct array {
    long int *vector;
    unsigned long int size;
    long int last;
} array;

/******************************************************************************
Heap
******************************************************************************/

typedef struct heap {
    long int *vector;
    long int elements;
    long int maxElements;
} heap;

/******************************************************************************
Binary trees
******************************************************************************/

typedef struct bs_tree_node {
    long int key;
    struct bs_tree_node *right;
    struct bs_tree_node *left;
} bs_tree_node;

typedef struct binary_search_tree {
    bs_tree_node *root;
    long int nodes;
} bstree;

typedef struct avl_tree_node {
    long int key;
    int balanceFactor;
    struct avl_tree_node *right;
    struct avl_tree_node *left;
} avl_tree_node;

typedef struct avl_tree {
    avl_tree_node *root;
    long int nodes;
} avl_tree;

// Red black
typedef enum color {
    RED = 0, BLACK = 1
} color;

typedef struct red_black_tree_node {
    long int key;
    int blackHeight;
    color color;
    struct red_black_tree_node *right;
    struct red_black_tree_node *left;
    struct red_black_tree_node *father;
} red_black_tree_node;

typedef struct red_black_tree {
    red_black_tree_node *root;
    long int nodes;
} red_black_tree;

/******************************************************************************
Compression algorithms
******************************************************************************/

typedef enum compression_algorithm {
    RLE = 0, HUFFMAN = 1
} compression_algorithm;

typedef struct huffman_tree_node {
    unsigned char character;
    unsigned int occurrences;
    struct huffman_tree_node *parent;
    struct huffman_tree_node *left;
    struct huffman_tree_node *right;
} huffman_tree_node;

/******************************************************************************
Auxiliar structures
******************************************************************************/

typedef struct branches {
    struct branches *previous;
    char *str;
} branches;

#endif