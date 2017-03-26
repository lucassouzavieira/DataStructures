/*
 Definicoes de tipos usados no projeto

 Copyright (C) 2016  Lucas S. Vieira

 This program is free software: you can redistribute it and/or modify it
 under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License,
 or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef TAD_H
#define TAD_H
#define LINE_MAX_LENGTH 500

/******************************************************************************
Listas, Pilhas e Filas
******************************************************************************/
/* Node simples */
typedef struct Node {
    long int key;
    struct Node *pointer;
} node;

/* Node duplo */
typedef struct DoubleNode {
    long int key;
    struct DoubleNode *next;
    struct DoubleNode *previous;
} dnode;

/* Lista */
typedef struct List {
    node *list;
    node *last;
    long int nodes;
} list;

/* Lista Circular */
typedef struct CircleList {
    node *list;
    long int nodes;
} circlelist;

/* Lista Dupla */
typedef struct DoublyList {
    dnode *list;
    dnode *startOfList;
    dnode *endOfList;
    long int nodes;
} doublylist;

/* Pilha */
typedef struct Stack {
    node *stack;
    node *top;
    unsigned long int nodes;
} stack;

/* Fila e Deque */
typedef struct Queue {
    node *queue;
    node *endOfQueue;
    unsigned long int nodes;
} queue;

typedef struct Deque {
    node *startOfQueue;
    node *endOfQueue;
    unsigned long int nodes;
} deque;

/* Pilha e Fila Estaticas */
typedef struct Array {
    long int *vector;
    unsigned long int size;
    long int last;
} array;

/******************************************************************************
Heap
******************************************************************************/
typedef struct Heap {
    long int *vector;
    long int elements;
    long int maxElements;
} heap;

/******************************************************************************
Grafos
******************************************************************************/
struct Graph {
    int weighing;
    int vertices;
    int maxDegree;

};

/******************************************************************************
Arvores Binarias
******************************************************************************/

/* Arvore Binaria de Busca */
typedef struct nodeBST {
    long int key;
    struct nodeBST *right;
    struct nodeBST *left;
} nodetree;

typedef struct BinarySearchTree {
    nodetree *root;
    long int nodes;
} BSTree;

/* Arvore AVL */
typedef struct nodeAVL {
    long int key;
    int balanceFactor;
    struct nodeAVL *right;
    struct nodeAVL *left;
} nodeavl;

typedef struct AVLTree {
    nodeavl *root;
    long int nodes;
} AVLTree;

/*Arvore Red-Black */
typedef enum Color {
    RED = 0, BLACK = 1
} Color;

typedef struct nodeRB {
    long int key;
    int blackHeight;
    Color color;
    struct nodeRB *right;
    struct nodeRB *left;
    struct nodeRB *father;
} noderb;

typedef struct RedBlackTree {
    noderb *root;
    long int nodes;
} RBTree;

/******************************************************************************
Algoritmos de Compressao
******************************************************************************/

typedef enum CompressionAlgorithm {
    RLE = 0, HUFFMAN = 1
} CompressionAlgorithm;

typedef struct HuffmanTreeNode {
    unsigned char character;
    unsigned int occurrences;
    struct HuffmanTreeNode *parent;
    struct HuffmanTreeNode *left;
    struct HuffmanTreeNode *right;
} huffmantreenode;

/******************************************************************************
Estruturas Auxiliares
******************************************************************************/
/* Auxiliar nos desenhos das arvores */
typedef struct Branches {
    struct Branches *previous;
    char *str;
} branches;

#endif