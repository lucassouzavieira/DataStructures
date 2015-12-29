/**
Este arquivo é parte do projeto Data Structures

Este é um software livre; você pode redistribuí-lo e/ou
modificá-lo dentro dos termos da Licença Pública Geral GNU como
publicada pela Fundação do Software Livre (FSF); na versão 3 da
Licença, ou (na sua opinião) qualquer versão.

Este programa é distribuído na esperança de que possa ser  útil,
mas SEM NENHUMA GARANTIA; sem uma garantia implícita de ADEQUAÇÃO
a qualquer MERCADO ou APLICAÇÃO EM PARTICULAR. Veja a
Licença Pública Geral GNU para maiores detalhes.

Você deve ter recebido uma cópia da Licença Pública Geral GNU junto
com este programa, Se não, veja <http://www.gnu.org/licenses/>.x

Arquivo: SortingAlgorithms.h
Descrição: Definição de algoritmos de ordenação
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/


#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H
#include "..\TAD.h"

// Algoritmo de ordenação Bubble Sort  
long int* BubbleSort(long int* vector, long int numberOfElements); 

// Algoritmo de ordenação Bubble Sort - Melhorado  
long int* BubbleSortImproved(long int* vector, long int numberOfElements); 

// Algoritmo de ordenação Insertion Sort  
long int* InsertionSort(long int* vector, long int numberOfElements);  

// Algoritmo de ordenação Selection Sort  
long int* SelectionSort(long int* vector, long int numberOfElements);   

// Algoritmo de ordenação Merge Sort (Passar nº elementos + 1)  
void MergeSort(long int* vector, long int numberOfElements);  

// Algoritmo de ordenação Quick Sort  
long int* QuickSort(long int* vector, long int numberOfElements);  

// Algoritmo de ordenação Heap Sort  
void HeapSort(long int* vector, long int numberOfElements);  

// Algoritmo de ordenação Comb Sort 11  
long int* CombSort(long int* vector, long int numberOfElements);  

// Algoritmo de ordenação Shell Sort  
long int* ShellSort(long int* vector, long int numberOfElements);  

// Algoritmo de ordenação Gnome Sort  
long int* GnomeSort(long int* vector, long int numberOfElements);  

// Algoritmo de ordenação Bogo Sort  
long int* BogoSort(long int* vector, long int numberOfElements); 

// Algoritmo de ordenação Couting Sort  
long int* CoutingSort(long int* vector, long int numberOfElements);  

#endif // !SORTINGALGORITHMS_H