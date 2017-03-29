/*
 Implementacao de Fila

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


/* Cria uma fila */
queue CreateQueue() {
    queue myQueue;
    myQueue.queue = NULL;
    myQueue.endOfQueue = NULL;
    myQueue.nodes = 0;
    return myQueue;
}

/* Verifica se a fila esta vazia ou nao */
int CheckQueue(queue *myQueue) {
    if (myQueue->queue == NULL) {
        return -1;
    }
    return 1;
}

/* Insere elementos na fila */
void Enqueue(queue *myQueue, long int element) {
    node *newNode;
    newNode = (node *) (malloc(sizeof(node)));
    if (myQueue->queue == NULL) {
        if (newNode != NULL) {
            newNode->key = element;
            newNode->pointer = NULL; /* Ultimo elemento nao aponta pra ninguem */
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
void Dequeue(queue *myQueue) {
    if (myQueue->queue == NULL) {
        printf("A Fila esta vazia!\n");
        return;
    } else {
        node *remove = myQueue->queue;
        myQueue->queue = remove->pointer;
        free(remove);
        myQueue->nodes--;
    }
}

/* Imprime os elementos da fila */
void ConsultQueue(queue *myQueue) {
    node *aux = myQueue->queue;
    while (aux != NULL) {
        printf("%ld ->", &aux->key);
        aux = aux->pointer;
    }
}

/* Apaga todos os elementos e libera memoria */
int DestroyQueue(queue *myQueue) {
    node *aux = myQueue->queue;
    node *node_rem = NULL;
    while (aux != NULL) {
        node_rem = aux;
        aux = aux->pointer;
        free(node_rem);
    }
    return CheckQueue(myQueue);
}