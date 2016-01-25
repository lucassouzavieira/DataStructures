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

Arquivo: Stack.c
Descrição: Implementação de pilha
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#define _CRT_SECURE_NO_WARNINGS 1; 

#include <stdlib.h>
#include <stdio.h>
#include "..\TAD.h"

node* top;

//Cria uma pilha
stack CreateStack ()
{
	stack myStack;
	myStack.stack = NULL;
	myStack.top = NULL;
	myStack.nodes = 0;
	return myStack;
}

//Verifica se a pilha está vazia ou não
int CheckStack (stack* myStack) 
{
	if (myStack->stack == NULL){
		return -1;
	}
	return 1;
}

//Remove um elemento da pist
void Pop (stack* myStack)
{
	if (myStack->stack == NULL){
		printf("Pilha vazia! \n");
		return;
	}
	node* current = myStack->stack;
	node* previous = NULL;
	while (current != myStack->top) {
		previous = current;
		current = current->pointer;
	}
	free(current);
	previous->pointer = NULL;
	myStack->top = previous;
	myStack->nodes--;
}

//Insere um elemento na pilha 
void Push (stack* myStack, int element)
{
	node* newNode;
	newNode = (node *)(malloc(sizeof(node)));
	if (newNode != NULL){
		if (myStack->stack == NULL){
			newNode->key = element;
			newNode->pointer = NULL;
			myStack->stack = newNode;
			myStack->top = newNode;
		} else {
			newNode->key = element;
			newNode->pointer = NULL;
			myStack->top = newNode;
		}
		myStack->nodes++;
	} else {
		printf("Falha ao inserir elemento na pilha! \n");
	}
}

//Imprime todos os elementos da pilha 
void ConsultStack (stack* myStack) 
{
	node* aux = myStack->stack;
	while (aux != NULL){
		printf("%ld ->", aux->key);
		aux = aux->pointer;
	}
}

//Apaga os elementos e libera memória 
int DestroyStack (stack* myStack)
{
	node* aux = myStack->stack;
	node* node_rem = NULL;
	while (aux != NULL){
		node_rem = aux;
		aux = aux->pointer;
		free(node_rem);
	}
	return CheckStack(myStack);
}