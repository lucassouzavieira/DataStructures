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

Arquivo: DoubleLinkedList.c
Descrição: Implementação de Lista dupla
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#define _CRT_SECURE_NO_WARNINGS 1;
#include <stdlib.h>
#include <stdio.h>
#include "..\TAD.h"

/* Cria uma list duplamente encadeada */
doublylist CreateDLinkedList ()
{
	doublylist myDoublyList;
	myDoublyList.list = NULL;
	myDoublyList.startOfList = NULL;
	myDoublyList.endOfList = NULL;
	myDoublyList.nodes = 0;
	return myDoublyList;
}

/* Verifica se há elementos na lista */
int CheckDLinkedList (doublylist* myDoublyList)
{
	if (myDoublyList->list == NULL){
		return -1;
	}
	return 1;
}

/* Insere elementos no início da lista */
void InsertAtStartDLinkedList (doublylist* myDoublyList, long int element)
{
	dnode* newNode;
	newNode = (dnode *)(malloc(sizeof(dnode))); 
	if (newNode != NULL){
		if (myDoublyList->list == NULL){
			newNode->key = element;
			myDoublyList->list = newNode;
			myDoublyList->startOfList = newNode;
			myDoublyList->endOfList = newNode;
			newNode->previous = NULL;
			newNode->next = NULL;
		} else {
			newNode->key = element;
			newNode->next = myDoublyList->list; 
			newNode->previous = NULL;
			myDoublyList->list->previous = newNode; 
			myDoublyList->startOfList = newNode;
			myDoublyList->list = newNode;
		}
	}
}

/* Insere elementos no meio da lista */
void InsertAtMiddleDLinkedList (doublylist* myDoublyList, long int element)
{
	dnode* newNode;
	newNode = (dnode *)(malloc(sizeof(dnode)));
	if (newNode != NULL){
		if (myDoublyList->list == NULL){
			newNode->key = element;
			myDoublyList->list = newNode;
			myDoublyList->startOfList = newNode;
			myDoublyList->endOfList = newNode;
			newNode->previous = NULL;
			newNode->next = NULL;
		} else {
			newNode->key = element;
			dnode* aux = myDoublyList->startOfList;
			dnode* previous = NULL;
			while (aux != NULL && newNode->key > aux->key){
				previous = aux; /* Guarda a posição do nó previous à aux */
				aux = aux->next;
			}
			if (aux == myDoublyList->startOfList){
				/* Insere no início */
				newNode->next = myDoublyList->list;
				newNode->previous = NULL;
				myDoublyList->startOfList->previous = newNode;
				myDoublyList->list = newNode;
				myDoublyList->startOfList = newNode;
			} else if (aux == NULL){
				/* Insere no fim */
				myDoublyList->endOfList->next = newNode; 
				newNode->previous = myDoublyList->endOfList;
				newNode->next = NULL;
				myDoublyList->endOfList = newNode; 
			} else {
				/* Meio */
				newNode->next = aux;
				previous->next = newNode; /* Nó anterior aponta para o newNode nó */
				newNode->previous = previous; 
				aux->previous = newNode; 
			}
		}
	}
}

/* Insere elementos no fim da lista */
void InsertAtEndDLinkedList (doublylist* myDoublyList, long int element)
{
	dnode* newNode;
	newNode = (dnode *)(malloc(sizeof(dnode)));
	if (newNode != NULL){
		if (myDoublyList->list == NULL){
			newNode->key = element;
			myDoublyList->list = newNode;
			myDoublyList->startOfList = newNode;
			myDoublyList->endOfList = newNode;
			newNode->previous = NULL;
			newNode->next = NULL;
		} else {
			newNode->key = element;
			myDoublyList->endOfList->next = newNode;
			newNode->previous = myDoublyList->endOfList;
			newNode->next = NULL;
			myDoublyList->endOfList = newNode;
		}
	}
}

/* Busca um dado elemento na lista */
dnode* SearchElementDLinkedList (doublylist* myDoublyList, long int element)
{
	int parametro; 
	dnode* aux;
	printf("Busca Lista Duplamente Encadeada\n1 - Do inicio para o final \t2 - Do final para o inicio\n");
	scanf("%ld", &parametro);
	if (parametro == 1){
		aux = myDoublyList->startOfList;
		while (aux != NULL){
			if (aux->key == element){
				return aux;
			} else {
				aux = aux->next;
			}
		}
	} else if (parametro == 2){
		aux = myDoublyList->endOfList;
		while (aux != NULL){
			if (aux->key == element){
				return aux;
			} else {
				aux = aux->previous;
			}
		}
		
	} else {
		printf("Escolha invalida! \n");
		return NULL;
	}
	return NULL;
}

/* Imprime todos os elementos da lista  */
void ListElementsDLinkedList (doublylist* myDoublyList) 
{
	int parametro;
	dnode* current;

	printf("Mostrar elementos Lista Duplamente Encadeada\n1 - Do inicio para o final \t2 - Do final para o inicio\n");
	scanf("%ld", &parametro);
	if (parametro == 1){
		current = myDoublyList->startOfList;
		while (current != NULL){
			printf("%ld ->", current->key);
			current = current->next;
		}
	} else if (parametro == 2){
		current = myDoublyList->endOfList;
		while (current != NULL){
			printf("%ld ->", current->key);
			current = current->previous;
		}
	}
	else {
		printf("Escolha invalida! \n");
	}
}

/* Remove um dado elemento da lista */
void RemoveElementDLinkedList (doublylist* myDoublyList, long int element)
{
	dnode* aux = myDoublyList->list; 
	while (aux != NULL) { 
		if (aux->key == element) { 
			if (aux == myDoublyList->startOfList) { 
				/* Remove no início */
				myDoublyList->startOfList = aux->next;
				myDoublyList->startOfList->previous = NULL;
				free(aux);
				break;
			} else if (aux != myDoublyList->endOfList){
				/* Remove no meio */
				aux->previous->next = aux->next; 
				aux->previous->previous = aux->previous; 
				dnode* aux2; 
				aux2 = aux->next; 
				free(aux);
				aux = aux2;
				break;
			} else {
				/* Remove no fim */
				myDoublyList->endOfList = myDoublyList->endOfList->previous;
				myDoublyList->endOfList->next = NULL;
				free(aux);
				break;
			}
		}
		aux = aux->next;
	}
}

/* Apaga toda a lista e libera memória */
int DestroyDLinkedList (doublylist* myDoublyList)
{
	dnode* aux = NULL;
	int teste = 0;
	while (myDoublyList->list != NULL) {
		aux = myDoublyList->list->next;
		free(myDoublyList->list);
		myDoublyList->list = aux;
	}
	return CheckDLinkedList(myDoublyList);
}