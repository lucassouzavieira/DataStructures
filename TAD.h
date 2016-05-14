/**
Este arquivo é parte do projeto Data Structures
Este é um software livre; você pode redistribuí-lo e/ou
modificá-lo dentro dos termos da Licença Pública Geral GNU como
publicada pela Fundação do Software Livre (FSF); na versão 3 da
Licença, ou (na sua opinião) qualquer versão.

Este programa é distribuído na esperança de que possa ser  útil,
mas SEM NENHUMA GARANTIA; sem uma garantia implícita de ADEQUAÇÃO
a qualquer MERCADO ou APLICAÇÃO EM PARTICULAR. Veja a
Licença Pública Geral GNU para maiores detalhes.

Você deve ter recebido uma cópia da Licença Pública Geral GNU junto
com este programa, Se não, veja <http:/*www.gnu.org/licenses/>.

Arquivo: TAD.h
Descrição: Definição dos Tipos Abstratos de Dados básicas usadas no projeto
Autor: Lucas de Souza Vieira <lucassouzavieiraengcomp@gmail.com>	*/

#ifndef TAD_H
#define TAD_H
#define LINE_MAX_LENGTH 500

/******************************************************************************
Listas, Pilhas e Filas
******************************************************************************/
/* Nó simples */
typedef struct Node{
	long int key;
	struct Node* pointer;
} node;

/* Nó duplo */
typedef struct DoubleNode {
	long int key;
	struct DoubleNode* next;
	struct DoubleNode* previous;
} dnode;

/* Lista */
typedef struct List {
	node* list;
	node* last;
	long int nodes;
}list;

/* Lista Circular */
typedef struct CircleList {
	node* list;
	long int nodes;
} circlelist;

/* Lista Dupla */
typedef struct DoublyList {
	dnode* list;
	dnode* startOfList;
	dnode* endOfList;
	long int nodes;
} doublylist;

/* Pilha */
typedef struct Stack {
	node* stack;
	node* top;
	unsigned long int nodes;
} stack;

/* Fila e Deque */
typedef struct Queue {
	node* queue;
	node* endOfQueue;
	unsigned long int nodes;
} queue;

typedef struct Deque {
	node* startOfQueue;
	node* endOfQueue;
	unsigned long int nodes;
} deque;

/* Pilha e Fila Estáticas */
typedef struct Array {
	long int* vector;
	unsigned long int size;
	long int last;
} array;

/******************************************************************************
Heap
******************************************************************************/
typedef struct Heap{
	long int *vector;
	long int elements;
	long int maxElements;
} heap;

/******************************************************************************
Grafos
******************************************************************************/
struct Graph{
	int weighing;
	int vertices;
	int maxDegree;

};

/******************************************************************************
Árvores Binárias
******************************************************************************/
/* Árvore Binária de Busca */
typedef struct nodeBST{
	long int key;
	struct nodeBST* right;
	struct nodeBST* left;
} nodetree;

typedef struct BinarySearchTree{
	nodetree* root;
	long int nodes;
} BSTree;

/* Árvore AVL */
typedef struct nodeAVL{
	long int key;
	int balanceFactor;
	struct nodeAVL* right;
	struct nodeAVL* left;
} nodeavl;

typedef struct AVLTree{
	nodeavl* root;
	long int nodes;
} AVLTree;

/*Árvore Red-Black */
typedef enum Color { RED = 0, BLACK = 1 } Color;

typedef struct nodeRB{
	long int key;
	int blackHeight;
	Color color;
	struct nodeRB* right;
	struct nodeRB* left;
	struct nodeRB* father;
} noderb;

typedef struct RedBlackTree{
	noderb* root;
	long int nodes;
} RBTree;
/******************************************************************************
Algoritmos de Compressão de Strings
******************************************************************************/

typedef enum CompressionAlgorithm {RLE = 0, HUFFMAN = 1} CompressionAlgorithm;

typedef struct HuffmanTreeNode {
	unsigned char character;
	unsigned int occurrences;
	struct HuffmanTreeNode* parent;
	struct HuffmanTreeNode* left;
	struct HuffmanTreeNode* right;
} huffmantreenode;

/******************************************************************************
Estruturas Auxiliares
******************************************************************************/
/* Auxiliar nos desenhos das árvores */
typedef struct Branches{
	struct Branches *previous;
	char* str;
} branches;

#endif