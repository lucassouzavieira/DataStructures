#include "SearchAlgorithms.h"
#include "SortingAlgorithms.h"
#define SEARCH_FAILURE 0000

// Algoritmo de busca binária em vetores
// Retorna a posição no vetor do elemento procurado
long int BinarySearch(long int key, long int * vector, long int numberOfElements)
{
	vector = QuickSort(vector, numberOfElements); // Ordena o vetor
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