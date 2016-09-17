/*
 Testes das implementacoes

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD.h"
#include "Vector/Vector.h"
#include "Compression/Utilities.h"
#include "Compression/RLE.h"
#include "Compression/Huffman.h"

/* Testa as funções da Lista Encadeada  */
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

/* Testa as funções de Inserção e Remoção de Heap */
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

/* Teste da árvore AVL
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
}  */

/* Teste da �rvore Bin�ria
void BSTTest()
{
	BSTree myTree = CreateBST();
	InsertInBST(&myTree, 20);
	DrawBST(&myTree);
	system("pause");
	InsertInBST(&myTree, 21);
	DrawBST(&myTree);
	system("pause");
	InsertInBST(&myTree, 10);
	DrawBST(&myTree);
	system("pause");
	InsertInBST(&myTree, 5);
	DrawBST(&myTree);
	system("pause");
	InsertInBST(&myTree, 25);
	DrawBST(&myTree);
	system("pause");
	InsertInBST(&myTree, 60);
	DrawBST(&myTree);
	system("pause");
	InsertInBST(&myTree, 12);
	DrawBST(&myTree);
	system("pause");
	InsertInBST(&myTree, 34);
	DrawBST(&myTree);
	system("pause");
	InsertInBST(&myTree, 11);
	DrawBST(&myTree);
	system("pause");
	InsertInBST(&myTree, 100);
	DrawBST(&myTree);
	system("pause");
	InsertInBST(&myTree, 120);
	DrawBST(&myTree);
	system("pause");
	InsertInBST(&myTree, 90);
	DrawBST(&myTree);
	system("pause");
	RemoveBST(&myTree, 21);
	DrawBST(&myTree);
	system("pause");
	InsertInBST(&myTree, -2);
	DrawBST(&myTree);
	system("pause");
	InsertInBST(&myTree, -10);
	DrawBST(&myTree);
	system("pause");
	InsertInBST(&myTree, 2);
	DrawBST(&myTree);
	system("pause");
	InsertInBST(&myTree, 4);
	DrawBST(&myTree);
	system("pause");
} */


int main()
{
	encodeHuffman("sssssaaazzzt aososhkhe");
	system("pause");
	return 0;
}