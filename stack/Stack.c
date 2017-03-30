/*
 * Copyright (C) 2016  Lucas S. Vieira
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Stack.h"

node *top;

stack stack_create() {
    stack myStack;

    myStack.stack = NULL;
    myStack.top = NULL;
    myStack.nodes = 0;

    return myStack;
}

int stack_check(stack *myStack) {

    if (myStack->stack == NULL) {
        return -1;
    }

    return 1;
}

void stack_pop(stack *myStack) {

    if (myStack->stack == NULL) {
        printf("Empty stack! \n");
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

void stack_push(stack *myStack, int element) {

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
        return;
    }

    printf("Fail at trying insert element at stack! \n");
}

void stack_print(stack *myStack) {

    node *aux = myStack->stack;

    while (aux != NULL) {
        printf("%ld ->", aux->key);
        aux = aux->pointer;
    }
}

int stack_destroy(stack *myStack) {

    node *aux = myStack->stack;
    node *nodeToRem = NULL;

    while (aux != NULL) {
        nodeToRem = aux;
        aux = aux->pointer;
        free(nodeToRem);
    }

    return stack_check(myStack);
}