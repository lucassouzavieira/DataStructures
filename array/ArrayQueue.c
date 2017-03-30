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

#include "ArrayQueue.h"

array *array_queue_create(unsigned long int size) {
    array *myArrayQueue = (array *) malloc(sizeof(array));

    myArrayQueue->size = size;
    myArrayQueue->vector = (long int *) malloc(size * sizeof(long int));
    myArrayQueue->last = 0;

    return myArrayQueue;
}

int array_queue_check(array *myArrayQueue) {

    if (myArrayQueue->last == 0){
        return -1;
    }

    return 1;
}

array *array_queue_enqueue(array *myArrayQueue, long int element) {
    if (myArrayQueue->last == myArrayQueue->size - 1) {
        printf("Pilha cheia! \n");
        return myArrayQueue;
    }
    myArrayQueue->vector[myArrayQueue->last] = element;
    myArrayQueue->last++;
    return myArrayQueue;
}

array *array_queue_dequeue(array *myArrayQueue) {

    if (myArrayQueue->last == 0) {
        printf("Fila vazia! \n");
        return myArrayQueue;
    }

    for (long int i = 0; i < myArrayQueue->last; i++) {
        myArrayQueue->vector[i] = myArrayQueue->vector[i + 1];
    }

    myArrayQueue->last--;
    return myArrayQueue;
}

void array_queue_print(array *myArrayQueue) {
    for (long int i = 0; i <= myArrayQueue->last; i++) {
        printf("%ld \n", myArrayQueue->vector[i]);
    }
}

array *array_queue_destroy(array *myArrayQueue) {
    free(myArrayQueue->vector);
    return myArrayQueue;
}