/*
 Algoritmos de busca em vetor

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


#include "SearchAlgorithms.h"
#include "SortingAlgorithms.h"
#include <stdio.h>
#define SEARCH_FAILURE 0xfa

/* Algoritmo de busca binária em vetores
   Retorna a posição no vetor do elemento procurado */
long int BinarySearch(long int key, long int * vector, long int numberOfElements)
{
	vector = QuickSort(vector, numberOfElements); /* Ordena o vetor */
	long int inferiorLimit = 0;
	long int upperLimit = numberOfElements;
	while (inferiorLimit <= upperLimit) {
		long int middle = (long int)((inferiorLimit + upperLimit) / 2);
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