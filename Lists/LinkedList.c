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

Arquivo: LinkedList.c
Descrição: Implementação de Lista encadeada simples
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#define _CRT_SECURE_NO_WARNINGS 1;
#include <stdlib.h>
#include <stdio.h>
#include "..\TAD.h"

// Cria uma lista encadeada
list CreateLinkedList ()
{
	list myList;
	myList.list = NULL;
	myList.last = NULL;
	myList.nodes = 0;
	return myList;
}

// Verifica uma lista encadeada (se vazia)
int CheckLinkedList (list* myList)
{
	if(myList->nodes == 0){
		return -1;
	}
	return 1;
}

// Insere no início da lista
void InsertAtStartLinkedList (list* myList, long int element)
{
	node* newNode;
	newNode = (node *)(malloc(sizeof(node)));
	if(newNode != NULL){
		newNode->key = element;
		newNode->pointer = myList->list;
		myList->list = newNode;
		myList->nodes++;
	}
	// Atualiza o último nó da lista, caso necessário
	if (myList->last == NULL) {
		node* current;
		node* previous;
		current = myList->list;
		while (current->pointer != NULL) {
			current = current->pointer;
			previous = current;
		}
		myList->last = current;
	}
}

// Insere no meio da lista
void InsertAtMiddleLinkedList (list* myList, long int element) 
{
	node* newNode;
	newNode = (node *)(malloc(sizeof(node)));
	if (newNode != NULL){
		newNode->key = element;
	}
	/* Buscar a posição do novo nó
	Critério = element armazenado */
	node* previous = NULL;
	node* current = myList->list;
	while (current != NULL && current->key < element){
		previous = current;
		current = current->pointer;
	}
	/* Insere no começo caso previous = NULL*/
	if (previous == NULL){
		newNode->pointer = myList->list;
		myList->list = newNode;
	} else {
		/* Insere no meio ou no fim*/
		if (previous->pointer == NULL) {
			newNode->pointer = previous->pointer;
			previous->pointer = newNode;
			myList->last = newNode;
		} else {
			newNode->pointer = previous->pointer;
			previous->pointer = newNode;
		}
	}
	myList->nodes++;
}

// Insere no fim da lista
void InsertAtEndLinkedList (list* myList, long int element)
{
	node* newNode;
	newNode = (node *)(malloc(sizeof(node)));
	if(newNode != NULL){
		newNode->key = element;
		newNode->pointer = NULL;
	} 
	node* current = myList->list;
	node* previous = NULL;
	while(current->pointer != NULL){
		current = current->pointer;
		previous = current;
	}
	current->pointer = newNode;
	myList->last = newNode;
	myList->nodes++;
}

// Busca
node* SearchLinkedList (list* myList, long int element)
{
	node* aux;
	aux = myList->list;
	while (aux != NULL && aux->key != element){
		aux = aux->pointer;
	}
	return aux;
}

// Mostrar os elements
void ListElementsLinkedList (list* myList)
{
	node* aux;
	aux = myList->list;
	while(aux != NULL){
		printf("%ld \n", aux->key);
		aux = aux->pointer;
	}
}

// Retorna uma lista com os elementos em ordem invertida
list ReverseLinkedList (list* myList) 
{
	list reverseList = CreateLinkedList();
	node* current = myList->list;
	while (current != NULL) {
		InsertAtStartLinkedList(&reverseList, current->key);
	}
	return reverseList;
}

// Remove elements
void RemoveElementLinkedList (list* myList, long int element)
{
	node* current = myList->list;
	node* previous = NULL;
	while(current != NULL && current->key != element ){
		previous = current;
		current = current->pointer;
	}
	if(current == NULL){
		printf("Elemento nao encontrado\n");
		return;
	}
	if(previous == NULL){
		myList->list = current->pointer;
		myList->nodes--;
	} else {
		previous->pointer = current->pointer;
		myList->nodes--;
	}
	free(current);
}

// Destruir a lista
int DestroyLinkedList (list* myList)
{
	node* aux = NULL;
	int teste;
	while (myList->list != NULL) {
		aux = myList->list->pointer;
		free(myList->list);
		myList->list = aux;
	}
	return CheckLinkedList(myList);
}