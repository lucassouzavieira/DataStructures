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
com este programa, Se não, veja <http://www.gnu.org/licenses/>.x

Arquivo: Programa.c
Descrição: Teste das implementações das estruturas de dados
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#define _CRT_SECURE_NO_WARNINGS 1 // Desabilita verificações de segurança

#include <stdio.h>
#include <stdlib.h>
#include "TAD.h"
#include "Vector.h"
#include "LinkedList.h"
#include "CircleList.h"
#include "DoublyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Heap.h"
#include "SortingAlgorithms.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"

// Testa as funções de Inserção e Remoção de Heap
void HeapTest() {
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
void AVLTest() {
	nodeavl* myTree = CreateAVLTree();
	myTree = InsertInAVLTree(myTree, 10);
	myTree = InsertInAVLTree(myTree, 11);
	myTree = InsertInAVLTree(myTree, 12);
	myTree = InsertInAVLTree(myTree, 13);
	myTree = InsertInAVLTree(myTree, 14);
	myTree = InsertInAVLTree(myTree, 15);
	myTree = InsertInAVLTree(myTree, 5);
	DrawAVLTree(myTree, 0 ,0);
	myTree = RemoveAVLTree(myTree, 12);
	DrawAVLTree(myTree, 0, 0);
}

// Teste da Árvore Binária
void BSTTest() {
	nodetree* myTree = CreateBST();
	myTree = InsertInBST(myTree);
	myTree = InsertInBST(myTree);
	myTree = InsertInBST(myTree);
	myTree = InsertInBST(myTree);
	myTree = InsertInBST(myTree);
	myTree = InsertInBST(myTree);
	myTree = InsertInBST(myTree);
	myTree = InsertInBST(myTree);
	DrawBST(myTree, 0, 0);
	myTree = RemoveBST(myTree, 10);
}

int main (void){
	AVLTest();
	system("pause");
	return 0;
}
