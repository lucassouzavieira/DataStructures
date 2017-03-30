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

#include "ArrayStack.h"

array *array_stack_create(unsigned long int size) {
    array *myArrayStack = (array *) malloc(sizeof(array));

    myArrayStack->size = size;
    myArrayStack->vector = (long int *) malloc(size * sizeof(long int));
    myArrayStack->last = 0;

    return myArrayStack;
}

int array_stack_check(array *myArrayStack) {

    if (myArrayStack->last == 0) {
        return -1;
    }

    return 1;
}

array *array_stack_pop(array *myArrayStack) {

    if (myArrayStack->last == 0) {
        printf("Empty stack! \n");
        return myArrayStack;
    }

    myArrayStack->last--;
    return myArrayStack;
}

array *array_stack_push(array *myArrayStack, long int element) {

    if (myArrayStack->last == myArrayStack->size - 1) {
        printf("Full stack! n");
        return myArrayStack;
    }

    myArrayStack->vector[myArrayStack->last] = element;
    myArrayStack->last++;
    return myArrayStack;
}

void array_stack_print(array *myArrayStack) {
    for (long int i = 0; i <= myArrayStack->last; i++) {
        printf("%ld \n", myArrayStack->vector[i]);
    }
}

array *array_stack_destroy(array *myArrayStack) {
    free(myArrayStack->vector);
    return myArrayStack;
}