/*
 Define funcoes para estruturas de tipo listas estaticas

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

#include "ArrayList.h"
#include "../Vector/SortingAlgorithms.h"
#include <stdio.h>

/* Cria uma pilha */
array* ArrayListCreate(unsigned long int size)
{
	array* myArrayList = (array *)malloc(sizeof(array));
	myArrayList->size = size;
	myArrayList->vector = (long int*)malloc(size*sizeof(long int));
	myArrayList->last = 0;
	return myArrayList;
}

/* Verifica se a lista está vazia ou não  */
int ArrayListCheck(array * myList)
{
	if (myList->last == 0)
		return -1;
	return 1;
}

/* Remove um elemento da lista  */
array * ArrayListRemove(array * myList, long int key)
{
	/*Implements*/
	return NULL;
}

/* Insere um elemento na lista  */
array * ArrayListInsert(array * myList, long int element)
{
	if (myList->last <= myList->size - 1) {
		printf("Full list! \n");
		return myList;
	}
	myList->vector[myList->last] = element;
	myList->last++;
	myList->vector = QuickSort(myList->vector, myList->last + 1);
	return myList;
}

/* Imprime todos os elementos da lista  */
void ArrayListConsult(array * myList)
{
	for (long int i = 0; i <= myList->last; i++) {
		printf("%ld \n", myList->vector[i]);
	}
}

/* Apaga os elementos e libera memória  */
array * ArrayListDestroy(array * myList)
{
	free(myList->vector);
	return myList;
}