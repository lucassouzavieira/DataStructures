/*
 Implementacao de Pilha

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

#include <stdlib.h>
#include <stdio.h>
#include "../Types.h"

node *top;

/* Cria uma pilha */
stack CreateStack() {
    stack myStack;
    myStack.stack = NULL;
    myStack.top = NULL;
    myStack.nodes = 0;
    return myStack;
}

/* Verifica se a pilha esta vazia ou nao */
int CheckStack(stack *myStack) {
    if (myStack->stack == NULL) {
        return -1;
    }
    return 1;
}

/* Remove um elemento da pilha */
void Pop(stack *myStack) {
    if (myStack->stack == NULL) {
        printf("Pilha vazia! \n");
        return;
    }
    node *current = myStack->stack;
    node *previous = NULL;
    while (current != myStack->top) {
        previous = current;
        current = current->pointer;
    }
    free(current);
    previous->pointer = NULL;
    myStack->top = previous;
    myStack->nodes--;
}

/* Insere um elemento na pilha */
void Push(stack *myStack, int element) {
    node *newNode;
    newNode = (node *) (malloc(sizeof(node)));
    if (newNode != NULL) {
        if (myStack->stack == NULL) {
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

/* Imprime todos os elementos da pilha */
void ConsultStack(stack *myStack) {
    node *aux = myStack->stack;
    while (aux != NULL) {
        printf("%ld ->", aux->key);
        aux = aux->pointer;
    }
}

/* Apaga os elementos e libera memoria */
int DestroyStack(stack *myStack) {
    node *aux = myStack->stack;
    node *node_rem = NULL;
    while (aux != NULL) {
        node_rem = aux;
        aux = aux->pointer;
        free(node_rem);
    }
    return CheckStack(myStack);
}