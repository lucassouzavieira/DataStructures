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
com este programa, Se não, veja <http://www.gnu.org/licenses/>.

Arquivo: TAD.h
Descrição: Definição dos Tipos Abstratos de Dados básicas usadas no projeto
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef TAD_H
#define TAD_H

/******************************************************************************
Listas, Pilhas e Filas
******************************************************************************/
// Nó simples
struct Node{
	long int key;
	struct Node* pointer;
};

// Nó duplo
struct DoubleNode {
	long int key;
	struct DoubleNode* next;
	struct DoubleNode* previous;
};

typedef struct DoubleNode dnode;
typedef struct Node node;

// Lista
struct List {
	node* list;
	node* last;
	long int nodes;
};

// Lista Circular
struct CircleList {
	node* list;
	long int nodes;
};

// Lista Dupla
struct DoublyList {
	dnode* list;
	dnode* startOfList;
	dnode* endOfList;
	long int nodes;
};

// Pilha
struct Stack {
	node* stack;
	node* top;
	unsigned long int nodes;
};

//Fila e Deque
struct Queue {
	node* queue;
	node* endOfQueue;
	unsigned long int nodes;
};

struct Deque {
	node* startOfQueue;
	node* endOfQueue;
	unsigned long int nodes;
};

// Pilha e Fila Estáticas
struct Array {
	long int* vector;
	unsigned long int size;
	long int last;
};

/******************************************************************************
Heap
******************************************************************************/
struct Heap{
	long int *vector;
	long int elements;
	long int maxElements;
};

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
// Árvore Binária de Busca
struct nodeBST{
	long int key;
	struct nodeBST* right;
	struct nodeBST* left;
};
typedef struct nodeBST nodetree;

struct BinarySearchTree{
	nodetree* root;
	long int nodes;
};

//Árvore AVL
struct nodeAVL{
	long int key;
	int balanceFactor;
	struct nodeAVL* right;
	struct nodeAVL* left;
};
typedef struct nodeAVL nodeavl;

struct AVLTree{
	nodeavl* root;
	long int nodes;
};

//Árvore Red-Black
enum Color { RED = 0, BLACK = 1 };
typedef enum Color Color;

struct nodeRB{
	long int key;
	int blackHeight;
	Color color;
	struct nodeRB* right;
	struct nodeRB* left;
	struct nodeRB* father;
};
typedef struct nodeRB noderb;

struct RedBlackTree{
	noderb* root;
	long int nodes;
};
/******************************************************************************
Algoritmos de Compressão de Strings
******************************************************************************/

typedef enum CompressionAlgorithm {RLE = 0, HUFFMAN = 1} CompressionAlgorithm;

typedef struct String {
	char* string;
	unsigned int length;
} string;

/******************************************************************************
Redefinição de nomes
******************************************************************************/
typedef struct Array array;
typedef struct List list;
typedef struct CircleList circlelist;
typedef struct DoublyList doublylist;
typedef struct Stack stack;
typedef struct Queue queue;
typedef struct Deque deque;
typedef struct Heap heap;
typedef struct BinarySearchTree BSTree;
typedef struct AVLTree AVLTree;
typedef struct RedBlackTree RBTree;

/******************************************************************************
Estruturas Auxiliares
******************************************************************************/
// Auxiliar nos desenhos das árvores
struct Branches{
	struct Branches *previous;
	char* str;
};

typedef struct Branches branches;

#endif