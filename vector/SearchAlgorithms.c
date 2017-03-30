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

#define SEARCH_FAILURE 0xfa

#include "SearchAlgorithms.h"
#include "SortingAlgorithms.h"
#include <stdio.h>

/* Returns position of searched element in array */
long int binary_search(long int key, long int *vector, long int numberOfElements) {

    long int inferiorLimit = 0;
    long int upperLimit = numberOfElements;

    vector = quick_sort(vector, numberOfElements);

    while (inferiorLimit <= upperLimit) {
        long int middle = (long int) ((inferiorLimit + upperLimit) / 2);
        if (vector[middle] == key)
            return middle;
        else if (vector[middle] < key)
            inferiorLimit = middle + 1;
        else
            upperLimit = middle - 1;
    }

    printf("Key not found\n");
    return SEARCH_FAILURE;
}