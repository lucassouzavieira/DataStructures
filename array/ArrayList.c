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


#include "ArrayList.h"

array *array_list_create(unsigned long int size) {
    array *myArrayList = (array *) malloc(sizeof(array));

    myArrayList->size = size;
    myArrayList->vector = (long int *) malloc(size * sizeof(long int));
    myArrayList->last = 0;

    return myArrayList;
}

int array_list_check(array *myList) {

    if (myList->last == 0) {
        return -1;
    }

    return 1;
}

array *array_list_remove(array *myList, long int key) {
    // TODO implements
    return NULL;
}

array *array_list_insert(array *myList, long int element) {
    if (myList->last <= myList->size - 1) {
        printf("Full list! \n");
        return myList;
    }
    myList->vector[myList->last] = element;
    myList->last++;
    myList->vector = quick_sort(myList->vector, myList->last + 1);
    return myList;
}

void array_list_print(array *myList) {
    for (long int i = 0; i <= myList->last; i++) {
        printf("%ld \n", myList->vector[i]);
    }
}

array *array_list_destroy(array *myList) {
    free(myList->vector);
    return myList;
}