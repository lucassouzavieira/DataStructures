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
#include "types.h"
#include "Vector.h"

#define LEFT(x)  (2*x + 1)
#define RIGHT(x) (2*x + 2)
#define FATHER(x)(x / 2)

void max_heapfy(heap *myHeap, long int position);

void max_heap_sort(long int *vector, long int numberOfElements);

heap *create_heap(long int maxElements) {
    heap *myHeap = (heap *) malloc(sizeof(heap));
    if (myHeap != NULL) {
        myHeap->vector = (long int *) malloc((maxElements) * sizeof(long int));
        myHeap->maxElements = maxElements;
        myHeap->elements = 0;
        return myHeap;
    } else {
        return NULL;
    }
}

void destroy_heap(heap *myHeap) {
    free(myHeap->vector);
    free(myHeap);
}

void build_heap(heap *myHeap) {
    if (myHeap->elements == myHeap->maxElements) {
        for (long int i = (myHeap->elements) / 2; i--; i >= 1) {
            max_heapfy(myHeap, i);
        }
    }
}

/* Reorganiza o heap caso o elemento i possa ser maior que seus filhos */
void max_heapfy(heap *myHeap, long int position) {
    long int left = LEFT(position);
    long int right = RIGHT(position);
    long int aux;
    long int bigger = position;
    if ((left <= myHeap->elements) &&
        (myHeap->vector[left] > myHeap->vector[position])) {
        bigger = left;
    }
    if ((right <= myHeap->elements) &&
        (myHeap->vector[right] > myHeap->vector[bigger])) {
        bigger = right;
    }
    if (bigger != position) {
        aux = myHeap->vector[position];
        myHeap->vector[position] = myHeap->vector[bigger];
        myHeap->vector[bigger] = aux;
        max_heapfy(myHeap, bigger);
    }
}

/* Insere um novo elemento no heap */
int insert_heap(heap *myHeap, long int key) {
    long int aux;
    long int position;
    if (myHeap->elements == myHeap->maxElements) {
        return 0;
    }
    position = myHeap->elements;
    myHeap->elements++;
    myHeap->vector[position] = key;
    while ((position > 1) &&
           (myHeap->vector[FATHER(position)] < myHeap->vector[position])) {
        aux = myHeap->vector[position];
        myHeap->vector[position] = myHeap->vector[FATHER(position)];
        myHeap->vector[FATHER(position)] = aux;
        position = FATHER(position);
    }
    return 1;
}

/* Remove o elemento de maior prioridade no heap
long int remove_heap (heap* myHeap)
{
	if (myHeap->elements == 0) {
		printf("Heap Vazio \n");
		return 0;
	} 
	long int max = myHeap->vector[0];
	myHeap->vector[0] = myHeap->vector[myHeap->elements - 1];
	myHeap->vector[myHeap->elements - 1] = max;
	myHeap->elements--;
	MaxHeapfy(myHeap, 1);
	return max;
} */

void show_heap(heap* myHeap)
{
	show_vector(myHeap->vector, myHeap->elements);
}

/* HEAP SORT
/* Cria um Heap de Maximo dado um vetor
void max_heap_sort(long int* vector, long int numberOfElements)
{
	/*Checar se o Heap esta vazio
	if (numberOfElements == 0) {
		printf("O Heap esta vazio! \n");
	}
	long int aux; /* Variavel auxiliar
	long int n = numberOfElements; /* + 1 para ajuste de posicao
	long int father = numberOfElements / 2;
	long int index, child;

	while (1) {
		if (father > 0) {
			/*Ordenar o Heap
			aux = vector[--father];
		}
		else {
			/*Extrair os elementos
			n--;
			if (n == 0) {
				/*Quando o heap fica vazio, o algoritmo termina
				return;
			}
			aux = vector[n];
			vector[n] = vector[0];
		}
		/*Empurrando t para baixo para recolocar o pai
		index = father;
		child = index * 2 + 1;
		while (child < n) {
			if (child + 1 < n && vector[child + 1] < vector[child]) {
				child++;
			}
			if (vector[child] < aux) {
				vector[index] = vector[child];
				index = child; /*indice fica igual ao filho
				child = index * 2 + 1; /* Pega o filho da esquerda e repetir o processo
			}
			else {
				break;
			}
		}
		/*Novos valores sao salvos temporariamente em novas posicoes
		vector[index] = aux;
	}
} */