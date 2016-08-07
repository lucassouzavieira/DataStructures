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
com este programa, Se não, veja <http:/*www.gnu.org/licenses/>.

Arquivo: SortingAlgorithms.h
Descrição: Definição de algoritmos de ordenação
Autor: Lucas de Souza Vieira <lucassouzavieiraengcomp@gmail.com>	*/


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