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

Arquivo: Queue.c
Descrição: Implementação de fila
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#define _CRT_SECURE_NO_WARNINGS 1;

#include <stdlib.h>
#include <stdio.h>
#include "..\TAD.h"


/* Cria uma fila */
queue CreateQueue ()
{
	queue myQueue;
	myQueue.queue = NULL;
	myQueue.endOfQueue = NULL;
	myQueue.nodes = 0;
	return myQueue;
}

/* Verifica se a fila está vazia ou não */
int CheckQueue (queue* myQueue)
{
	if (myQueue->queue == NULL){
		return -1;
	}
	return 1;
}

/* Insere elementos na fila */
void Enqueue (queue* myQueue, long int element)
{
	node* newNode;
	newNode = (node*)(malloc(sizeof(node)));
	if (myQueue->queue == NULL){
		if (newNode != NULL) {
			newNode->key = element;
			newNode->pointer = NULL; /* Último elemento não aponta pra ninguém */
			myQueue->queue = newNode;
			myQueue->endOfQueue = newNode;
			myQueue->nodes++;
		}
	} else {
		newNode->key = element;
		newNode->pointer = NULL;
		myQueue->endOfQueue->pointer = newNode;
		myQueue->endOfQueue = newNode;
		myQueue->nodes++;
	}
}

/* Remove elementos da fila */
void Dequeue (queue* myQueue)
{
	if (myQueue->queue == NULL){
		printf("A Fila esta vazia!\n");
		return;
	} else {
		node* remove = myQueue->queue;
		myQueue->queue = remove->pointer;
		free(remove);
		myQueue->nodes--;
	}
}

/* Imprime os elementos da fila */
void ConsultQueue (queue* myQueue)
{
	node* aux = myQueue->queue;
	while (aux != NULL){
		printf("%ld ->", &aux->key);
		aux = aux->pointer;
	}
}

/* Apaga todos os elementos e libera memória */
int DestroyQueue (queue* myQueue)
{
	node* aux = myQueue->queue;
	node* node_rem = NULL;
	while (aux != NULL) {
		node_rem = aux;
		aux = aux->pointer;
		free(node_rem);
	}
	return CheckQueue(myQueue);
}