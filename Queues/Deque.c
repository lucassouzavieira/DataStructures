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

Arquivo: Deque.c
Descrição: Implementação de deque
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#include <stdlib.h>
#include <stdio.h>
#include "Deque.h"

//Cria um deque 
deque CreateDeque()
{
	deque myDeque;
	myDeque.startOfQueue = NULL;
	myDeque.endOfQueue = NULL;
	myDeque.nodes = 0;
}

//Verifica se há elementos no deque 
int CheckDeque(deque* myDeque) 
{
	if (myDeque->startOfQueue == NULL) {
		return -1;
	}
	return 1;
}

//Insere elementos no deque 
void InsertAtFront(deque* myDeque, long int element)
{
	if (myDeque == NULL)
		return;
	node* newNode;
	newNode = (node *)(malloc(sizeof(node)));
	if (newNode != NULL) {
		newNode->key = element;
		newNode->pointer = myDeque->startOfQueue;
		myDeque->startOfQueue = newNode;
		myDeque->nodes++;
	}
	// Atualiza o último nó do deque, caso necessário
	if (myDeque->endOfQueue == NULL) {
		node* current;
		node* previous;
		current = myDeque->startOfQueue;
		while (current->pointer != NULL) {
			current = current->pointer;
			previous = current;
		}
		myDeque->endOfQueue = current;
	}
}

void InsertAtBack(deque* myDeque, long int element)
{
	if (myDeque == NULL)
		return;
	node* newNode;
	newNode = (node *)(malloc(sizeof(node)));
	if (newNode != NULL) {
		newNode->key = element;
		newNode->pointer = NULL;
	}
	node* current = myDeque->startOfQueue;
	node* previous = NULL;
	while (current->pointer != NULL) {
		current = current->pointer;
		previous = current;
	}
	current->pointer = newNode;
	myDeque->endOfQueue = newNode;
	myDeque->nodes++;
}

//Remove elementos do deque 
void RemoveFromFront(deque* myDeque) 
{
	if (myDeque == NULL || myDeque->startOfQueue == NULL)
		return;
	node* tempNode = myDeque->startOfQueue;
	myDeque->startOfQueue = tempNode->pointer;
	free(tempNode);
	myDeque->nodes--;
}

void RemoveFromBack(deque* myDeque)
{
	if (myDeque == NULL || myDeque->startOfQueue == NULL)
		return;
	node* current = myDeque->startOfQueue;
	node* previous = NULL;
	while (current->pointer != NULL) {
		current = current->pointer;
		previous = current;
	}
	myDeque->endOfQueue = previous;
	free(current);
	myDeque->nodes--;
}

//Imprime os elementos do deque 
void ConsultDeque(deque* myDeque) 
{
	if (myDeque == NULL || myDeque->startOfQueue == NULL)
		return;
	node* current = myDeque->startOfQueue;
	while (current != NULL) {
		printf("%ld \n", current->key);
		current = current->pointer;
	}
}

//Apaga todos os elementos e libera memória 
int DestroyDeque(deque* myDeque) 
{
	node* current = NULL;
	while (myDeque->startOfQueue != NULL) {
		current = myDeque->startOfQueue->pointer;
		free(myDeque->startOfQueue);
		myDeque->startOfQueue = current;
	}
	return EXIT_SUCCESS;
}