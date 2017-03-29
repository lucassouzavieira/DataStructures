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
#include "SortingAlgorithms.h"

long int _count_merge_sort = 0;

/* BUBBLE SORT */
long int *bubble_sort(long int *vector, long int numberOfElements) {

    long int aux = 0;

    for (long int i = 1; i <= numberOfElements; i++) {
        for (long int j = 0; j < (numberOfElements - 1); j++) {
            if (vector[j] > vector[j + 1]) {
                aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
        }
    }

    return vector;
}

long int *bubble_sort_improved(long int *vector, long int numberOfElements) {

    long int aux;

    for (long int i = 0; i <= numberOfElements; i++) {
        for (long int j = (numberOfElements - 1); j >= i; j--) {
            if (vector[j] > vector[j + 1]) {
                aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
        }
    }

    return vector;
}

long int *insertion_sort(long int *vector, long int numberOfElements) {

    long int j;
    long int selected;

    for (long int i = 1; i <= numberOfElements; i++) {
        selected = vector[i];
        j = i - 1;
        while (j >= 0 && vector[j] > selected) {
            vector[j + 1] = vector[j];
            j = j - 1;
        }
        vector[j + 1] = selected;
    }
    return vector;
}

/* SELECTION SORT */
long int *selection_sort(long int *vector, long int numberOfElements) {

    long int i;
    long int position;
    long int selected;

    for (i = numberOfElements; i > 0; i--) {
        selected = vector[0];
        position = 0;
        for (long int j = 1; j <= i; j++) {
            if (vector[j] > selected) {
                selected = vector[j];
                position = j;
            }
        }
        vector[position] = vector[i];
        vector[i] = selected;
    }

    return vector;
}

/* MERGE SORT */
void merge(long int *vector, long int numberOfElements) {

    long int middle;
    long int i, j, k;
    long int *tmp;

    /* Temporary vector */
    tmp = (long int *) malloc(numberOfElements * sizeof(long int));

    if (tmp == NULL) {
        exit(1);
    }

    middle = numberOfElements / 2;

    i = 0;
    j = middle;
    k = 0;

    while (i < middle && j < numberOfElements) {
        if (vector[i] < vector[j]) {
            tmp[k] = vector[i++];
        } else {
            tmp[k] = vector[j++];
        }
        ++k;
    }

    /* Merge two sorted splits*/
    if (i == middle) {
        while (j < numberOfElements) {
            tmp[k++] = vector[j++];
        }
    } else {
        while (i < middle) {
            tmp[k++] = vector[i++];

        }
    }

    for (i = 0; i < numberOfElements; ++i) {
        vector[i] = tmp[i];
    }

    free(tmp);
}

void merge_sort(long int *vector, long int numberOfElements) {

    long int middle;

    if (numberOfElements > 1) {
        middle = numberOfElements / 2;
        MergeSort(vector, middle);
        MergeSort(vector + middle, numberOfElements - middle);
        merge(vector, numberOfElements);
    }
}

/* QUICK SORT */
void quick(long int *vector, long int initialPosition, long int endPosition) {

    long int i = initialPosition;
    long int j = endPosition;
    long int pivot = vector[(initialPosition + endPosition) / 2];
    long int aux;

    while (i < j) {
        while (vector[i] < pivot) {
            i++;
        }
        while (vector[j] > pivot) {
            j--;
        }
        if (i <= j) {
            aux = vector[i];
            vector[i] = vector[j];
            vector[j] = aux;
            i++;
            j--;
        }
    }

    if (j > initialPosition) {
        quick(vector, initialPosition, j);
    }

    if (i < endPosition) {
        quick(vector, i, endPosition);
    }
}

long int *quick_sort(long int *vector, long int numberOfElements) {

    long int initialPosition = 0;
    long int endPosition = numberOfElements;

    quick(vector, initialPosition, endPosition);
    return vector;
}

/* HEAP SORT */
void heap_sort(long int *vector, long int numberOfElements) {

    long int aux;
    long int n = numberOfElements;
    long int father = numberOfElements / 2;
    long int index, child;

    if (numberOfElements == 0) {
        printf("Empty Heap! \n");
    }

    while (1) {
        if (father > 0) {
            aux = vector[--father];
        } else {
            n--;
            if (n == 0) {
                return;
            }
            aux = vector[n];
            vector[n] = vector[0];
        }

        index = father;
        child = index * 2 + 1;
        while (child < n) {
            if (child + 1 < n && vector[child + 1] > vector[child]) {
                child++;
            }
            if (vector[child] > aux) {
                vector[index] = vector[child];
                index = child;
                child = index * 2 + 1;
            } else {
                break;
            }
        }

        vector[index] = aux;
    }
}

/* COMB SORT */
long int *comb_sort(long int *vector, long int numberOfElements) {

    long int i, j, jump, aux, changes = 1;
    jump = numberOfElements;

    while (jump > 1 || changes == 1) {
        jump = jump * 10 / 13;

        if (jump == 9 || jump == 10) {
            jump = 11;
        }

        if (jump < 1) {
            jump = 1;
        }
        changes = 0;
        for (i = 0, j = jump; j < numberOfElements; i++, j++) {
            if (vector[i] > vector[j]) {
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
                changes = 1;
            }
        }
    }

    return vector;
}

/* SHELL SORT */
void shell_sort_phase(long int *vector, long int numberOfElements, int jump) {

    long int i;

    for (i = jump; i < numberOfElements; i++) {
        long int valor = vector[i];
        long int j;
        for (j = (i - jump); j >= 0 && vector[j] > valor; j = j - jump) {
            vector[j + jump] = vector[j];
        }
        vector[j + jump] = valor;
    }
}

long int *shell_sort(long int *vector, long int numberOfElements) {

    numberOfElements = numberOfElements + 1;
    static const int jump[] = {1, 4, 10, 23, 57, 132, 301, 701};

    long int sizeIndex;

    for (sizeIndex = (sizeof(jump) / sizeof(jump[0]) - 1); sizeIndex >= 0; --sizeIndex) {
        shell_sort_phase(vector, numberOfElements, jump[sizeIndex]);
    }

    return vector;
}

/* GNOME SORT */
long int *gnome_sort(long int *vector, long int numberOfElements) {

    long int aux = 0;

    for (long int i = 0; i <= numberOfElements;) {
        if (vector[i - 1] <= vector[i]) {
            ++i;
        } else {
            aux = vector[i];
            vector[i] = vector[i - 1];
            vector[i - 1] = aux;
            --i;

            if (i == 0) {
                i = 1;
            }
        }
    }

    return vector;
}


/* BOGO SORT */
int sorting(long int *vector, long int elements) {
    long int n = elements;
    /* Compara todos os elementos do vector a partir do último */
    while (--n >= 1) {
        if (vector[n] < vector[n - 1]) {
            return 0;
        }
    }
    return 1;
}

void shuffle(long int *vector, long int elements) {
    long int aux, r;
    for (long int i = 0; i < elements; i++) {
        /* Realiza a troca de posi��es */
        aux = vector[i];
        r = rand() % elements;
        vector[i] = vector[r];
        vector[r] = aux;
    }
}

long int *bogo_sort(long int *vector, long int elements) {

    while (!sorting(vector, elements)) {
        shuffle(vector, elements);
    }

    return vector;
}

/* COUTING SORT */
int c_sorting(long int *vector, long int elements, long int min, long int max) {

    long int i = 0, k = 0;
    long int range = max - min + 1;
    long int *count = (long int *) malloc(range * sizeof(*vector));

    for (i = 0; i < range; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < elements; i++) {
        count[vector[i] - min]++;
    }

    for (i = min, k = 0; i <= max; i++) {
        for (long int j = 0; j < count[i - min]; j++) {
            vector[k++] = i;
        }
    }

    free(count);
    return EXIT_SUCCESS;
}

long int *couting_sort(long int *vector, long int elements) {

    long int i = 0, min = 0, max = 0;

    min = max = vector[0];

    for (i = 1; i < elements; i++) {
        if (vector[i] < min) {
            min = vector[i];
        } else if (vector[i] > max) {
            max = vector[i];
        }
    }

    c_sorting(vector, elements, min, max);
    return vector;
}