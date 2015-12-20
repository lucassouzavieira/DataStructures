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

// Listas, Pilhas e Filas dinâmicas
struct node{
	long int key;
	struct node* pointer;
};

// Listas Duplas
struct DoubleNode {
	long int key;
	struct DoubleNode* next;
	struct DoubleNode* previous;
};

typedef struct DoubleNode dnode;
typedef struct node node;

struct List {
	node* list;
	node* last;
	long int nodes;
};

struct CircleList {
	node* list;
	node* startOfList;
	node* endOfList;
	long int nodes;
};

struct DoublyList {
	dnode* list;
	dnode* startOfList;
	dnode* endOfList;
	long int nodes;
};

struct Stack {
	node* stack;
	node* top;
	long int nodes;
};

struct Queue {
	node* queue;
	node* endOfQueue;
	long int nodes;
};

// Pilhas e Filas Dinâmicas
struct Array {
	long int* vector;
	long int size;
	long int last;
};

// Heaps
struct Heap{
	long int *vector;
	long int elements;
	long int maxElements;
};

// Grafos
struct Graph{
	int weighing;
	int vertices;
	int maxDegree;

};

// Árvores Binárias
struct nodeBST{
	long int key;
	struct nodeBST* right;
	struct nodeBST* left;
};

//Árvores AVL
struct nodeAVL{
	long int key;
	int balanceFactor;
	struct nodeAVL* right;
	struct nodeAVL* left;
};

//Árvores Red-Black
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

// Convenções de nome
typedef struct Array array;
typedef struct List list;
typedef struct CircleList circlelist;
typedef struct DoublyList doublylist;
typedef struct Stack stack;
typedef struct Queue queue;
typedef struct nodeBST nodetree;
typedef struct nodeRB noderb;
typedef struct nodeAVL nodeavl;
typedef struct Heap heap;

// Auxiliar nos desenhos das árvores
struct Branches{
	struct Branches *previous;
	char* str;
};

typedef struct Branches branches;

#endif