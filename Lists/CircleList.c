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

Arquivo: CircleList.c
Descrição: Implementação de Lista circular simples
Autor: Lucas de Souza Vieira <lucassouzavieiraengcomp@gmail.com>	*/

#define _CRT_SECURE_NO_WARNINGS 1;
#include <stdlib.h>
#include <stdio.h>
#include "..\TAD.h"

/* Cria uma lista circular  */
circlelist CreateCircleList ()
{
	circlelist myList;
	myList.list = NULL;
	myList.nodes = 0;
	return myList;
}

/* Verifica se a lista está vazia ou não */
int CheckCircleList (circlelist* myList)
{
	if (myList->list == NULL) {
		return -1;
	}
	return 1;
}

/* Insere novos elements na lista  */
void InsertAtCircleList (circlelist* myList, long int element)
{
	if (myList->list == NULL) {
		node* newNode;
		newNode = (node *)(malloc(sizeof(node)));
		if (newNode != NULL) {
			newNode->key = element;
			myList->list = newNode;
			newNode->pointer = myList->list;
			myList->nodes++;
		}
	} else {
		node* newNode;
		newNode = (node *)(malloc(sizeof(node)));
		if (newNode != NULL) {
			newNode->pointer = myList->list;
			myList->list = newNode;
			myList->nodes++;
		}
	}
}

/* Busca um dado valor na lista  */
node* SearchElementCircleList (circlelist* myList, long int element) 
{
	node* aux = myList->list;

	while (aux != myList->list && aux->key != element) {
		aux = aux->pointer;
	}
	if (aux->key == element) {
		return aux;
	}
	else {
		return NULL;
	}
}

/* Imprime todos os elements da lista */
void ListElementsCircleList (circlelist* myList)
{
	node* aux = myList->list;
	if (myList->nodes == 0) {
		printf("Lista vazia! \n");
		return;
	} else {
		while (aux != myList->list) {
			printf("%ld ->", aux->key);
			aux = aux->pointer;
		}
	}
}

/* Apaga toda a lista e libera a memória  */
void RemoveElementCircleList (circlelist* myList, long int element)
{
	node* current = myList->list;
	node* previous = NULL;
	while (current != myList->list && current->key != element) {
		previous = current;
		current = current->pointer;
	}
	if (current == myList->list) {
		printf("Elemento nao encontrado\n");
		return;
	}
	if (previous == NULL) {
		myList->list = current->pointer;
	}
	else {
		previous->pointer = current->pointer;
	}
	free(current);
}

/* Destuir a Lista */
int DestroyCircleList(circlelist* myList)
{
	node* aux = myList->list;
	while (aux != myList->list) {
		aux = myList->list;
		free(myList->list);
		myList->list = aux;
	}
	myList->list = NULL;
	return CheckCircleList(myList);
}