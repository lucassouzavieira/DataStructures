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
#include "../Types.h"


queue queue_create() {
    queue myQueue;

    myQueue.queue = NULL;
    myQueue.endOfQueue = NULL;
    myQueue.nodes = 0;

    return myQueue;
}

int queue_check(queue *myQueue) {

    if (myQueue->queue == NULL) {
        return -1;
    }

    return 1;
}

void queue_enqueue(queue *myQueue, long int element) {

    node *newNode;
    newNode = (node *) (malloc(sizeof(node)));

    if(newNode == NULL){
        printf("Fail at trying insert element at queue! \n");
        return;
    }

    if (myQueue->queue == NULL) {
        newNode->key = element;
        newNode->pointer = NULL; /* Last element */
        myQueue->queue = newNode;
        myQueue->endOfQueue = newNode;
        myQueue->nodes++;
        return;
    }

    newNode->key = element;
    newNode->pointer = NULL;
    myQueue->endOfQueue->pointer = newNode;
    myQueue->endOfQueue = newNode;
    myQueue->nodes++;
}

void queue_dequeue(queue *myQueue) {

    if (myQueue->queue == NULL) {
        printf("A Fila esta vazia!\n");
        return;
    }

    node *remove = myQueue->queue;
    myQueue->queue = remove->pointer;
    free(remove);
    myQueue->nodes--;
}

void queue_print(queue *myQueue) {

    node *aux = myQueue->queue;

    while (aux != NULL) {
        printf("%ld ->", &aux->key);
        aux = aux->pointer;
    }
}

int queue_destroy(queue *myQueue) {

    node *aux = myQueue->queue;
    node *nodeToRem = NULL;

    while (aux != NULL) {
        nodeToRem = aux;
        aux = aux->pointer;
        free(nodeToRem);
    }

    return queue_check(myQueue);
}