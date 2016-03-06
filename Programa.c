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

Arquivo: Programa.c
Descrição: Teste das implementações das estruturas de dados
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#define _CRT_SECURE_NO_WARNINGS 1 // Desabilita verificações de segurança


#include <stdio.h>
#include <stdlib.h>
#include "TAD.h"
#include "Vector\Vector.h"
#include "Vector\SortingAlgorithms.h"
#include "Lists\LinkedList.h"
#include "Lists\CircleList.h"
#include "Lists\DoublyLinkedList.h"
#include "Stack\Stack.h"
#include "Queues\Queue.h"
#include "Heap\Heap.h"
#include "BinaryTrees\BinarySearchTree.h"
#include "BinaryTrees\AVLTree.h"

// Testa as funções da Lista Encadeada
void LinkedListTest()
{
	list myList;
	myList = CreateLinkedList();
	InsertAtStartLinkedList(&myList, 1);
	InsertAtStartLinkedList(&myList, 2);
	InsertAtStartLinkedList(&myList, 3);
	ListElementsLinkedList(&myList);
	printf("\n");
	InsertAtEndLinkedList(&myList, 10);
	InsertAtEndLinkedList(&myList, 11);	
	InsertAtEndLinkedList(&myList, 12);
	ListElementsLinkedList(&myList);
	printf("\n");
	InsertAtMiddleLinkedList(&myList, 7);
	InsertAtMiddleLinkedList(&myList, 9);
	InsertAtMiddleLinkedList(&myList, 8);
	ListElementsLinkedList(&myList);
	printf("\n");
	RemoveElementLinkedList(&myList, 2);
	RemoveElementLinkedList(&myList, 10);
	ListElementsLinkedList(&myList);
	printf("Nodes: %ld \n", myList.nodes);
}

// Testa as funções de Inserção e Remoção de Heap
void HeapTest()
{
	heap* myHeap = CreateHeap(10);
	InsertInHeap(myHeap, 12);
	InsertInHeap(myHeap, 22);
	InsertInHeap(myHeap, -2);
	InsertInHeap(myHeap, 31);
	InsertInHeap(myHeap, 24);
	InsertInHeap(myHeap, 13);
	InsertInHeap(myHeap, 18);
	InsertInHeap(myHeap, 50);
	ShowHeap(myHeap);
	RemoveHeap(myHeap);
	printf("\n");
	ShowHeap(myHeap);
	RemoveHeap(myHeap);
	printf("\n");
	ShowHeap(myHeap);
	RemoveHeap(myHeap);
	printf("\n");
	ShowHeap(myHeap);
	RemoveHeap(myHeap);
	printf("\n");
	ShowHeap(myHeap);
}

// Teste da Árvore AVL
void AVLTest() 
{
	AVLTree myTree = CreateAVLTree();
	InsertInAVLTree(&myTree, 10);
	InsertInAVLTree(&myTree, 11);
	InsertInAVLTree(&myTree, 12);
	InsertInAVLTree(&myTree, 13);
	InsertInAVLTree(&myTree, 14);
	InsertInAVLTree(&myTree, 15);
	InsertInAVLTree(&myTree, 5);
	DrawAVLTree(&myTree);
	RemoveAVLTree(&myTree, 12);
	DrawAVLTree(&myTree);
}

// Teste da Árvore Binária
void BSTTest()
{
	BSTree myTree = CreateBST();
	InsertInBST(&myTree, 20);
	InsertInBST(&myTree, 21);
	InsertInBST(&myTree, 10);
	InsertInBST(&myTree, 5);
	InsertInBST(&myTree, 25);
	InsertInBST(&myTree, 60);
	InsertInBST(&myTree, 12);
	InsertInBST(&myTree, 34);
	InsertInBST(&myTree, 11);
	InsertInBST(&myTree, 100);
	InsertInBST(&myTree, 120);
	InsertInBST(&myTree, 90);
	DrawBST(&myTree);
	RemoveBST(&myTree, 21);
	InsertInBST(&myTree, -2);
	InsertInBST(&myTree, -10);
	InsertInBST(&myTree, 2);
	InsertInBST(&myTree, 4);
	DrawBST(&myTree);
}

#include <stdio.h>
#include <stdlib.h>
int main() {
	system("pause");
	return 0;
}
