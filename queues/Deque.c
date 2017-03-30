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

#include <stdlib.h>
#include <stdio.h>
#include "Deque.h"

deque deque_create() {

    deque myDeque;
    myDeque.startOfQueue = NULL;
    myDeque.endOfQueue = NULL;
    myDeque.nodes = 0;

    return myDeque;
}

int deque_check(deque *myDeque) {

    if (myDeque->startOfQueue == NULL) {
        return -1;
    }

    return 1;
}

void deque_insert_at_front(deque *myDeque, long int element) {

    if (myDeque == NULL){
        return;
    }

    node *newNode;
    newNode = (node *) (malloc(sizeof(node)));

    if (newNode != NULL) {
        newNode->key = element;
        newNode->pointer = myDeque->startOfQueue;
        myDeque->startOfQueue = newNode;
        myDeque->nodes++;
    }

    if (myDeque->endOfQueue == NULL) {
        node *current;
        node *previous;
        current = myDeque->startOfQueue;
        while (current->pointer != NULL) {
            current = current->pointer;
            previous = current;
        }
        myDeque->endOfQueue = current;
    }
}

void deque_insert_at_back(deque *myDeque, long int element) {

    if (myDeque == NULL)
        return;

    node *newNode;
    newNode = (node *) (malloc(sizeof(node)));

    if (newNode != NULL) {
        newNode->key = element;
        newNode->pointer = NULL;
    }

    node *current = myDeque->startOfQueue;
    node *previous = NULL;

    while (current->pointer != NULL) {
        current = current->pointer;
        previous = current;
    }

    current->pointer = newNode;
    myDeque->endOfQueue = newNode;
    myDeque->nodes++;
}

void deque_shift(deque *myDeque) {

    if (myDeque == NULL || myDeque->startOfQueue == NULL)
        return;

    node *tempNode = myDeque->startOfQueue;
    myDeque->startOfQueue = tempNode->pointer;
    free(tempNode);
    myDeque->nodes--;
}

void deque_pop(deque *myDeque) {

    if (myDeque == NULL || myDeque->startOfQueue == NULL)
        return;

    node *current = myDeque->startOfQueue;
    node *previous = NULL;

    while (current->pointer != NULL) {
        current = current->pointer;
        previous = current;
    }
    myDeque->endOfQueue = previous;
    free(current);
    myDeque->nodes--;
}

void deque_print(deque *myDeque) {

    if (myDeque == NULL || myDeque->startOfQueue == NULL)
        return;

    node *current = myDeque->startOfQueue;

    while (current != NULL) {
        printf("%ld \n", current->key);
        current = current->pointer;
    }
}

int deque_destroy(deque *myDeque) {
    node *current = NULL;

    while (myDeque->startOfQueue != NULL) {
        current = myDeque->startOfQueue->pointer;
        free(myDeque->startOfQueue);
        myDeque->startOfQueue = current;
    }

    return EXIT_SUCCESS;
}