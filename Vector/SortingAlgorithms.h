/*
 Algoritmos de Ordenacao

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

#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H
#include "../TAD.h"

/* Bubble Sort  */
long int* BubbleSort(long int* vector, long int numberOfElements);

/* Bubble Sort - Melhorado  */
long int* BubbleSortImproved(long int* vector, long int numberOfElements); 

/* Insertion Sort  */
long int* InsertionSort(long int* vector, long int numberOfElements);  

/* Selection Sort  */
long int* SelectionSort(long int* vector, long int numberOfElements);   

/* Merge Sort */
void MergeSort(long int* vector, long int numberOfElements);  

/* Quick Sort  */
long int* QuickSort(long int* vector, long int numberOfElements);  

/* Heap Sort  */
void HeapSort(long int* vector, long int numberOfElements);  

/* Comb Sort 11  */
long int* CombSort(long int* vector, long int numberOfElements);  

/* Shell Sort  */
long int* ShellSort(long int* vector, long int numberOfElements);  

/* Gnome Sort  */
long int* GnomeSort(long int* vector, long int numberOfElements);  

/* Bogo Sort  */
long int* BogoSort(long int* vector, long int numberOfElements); 

/* Couting Sort  */
long int* CoutingSort(long int* vector, long int numberOfElements);  

#endif /* !SORTINGALGORITHMS_H */