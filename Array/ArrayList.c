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
com este programa, Se não, veja <http://www.gnu.org/licenses/>.

Arquivo: ArrayList.c
Descrição: Implementações para estruturas do tipo listas estáticas
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#include "ArrayList.h"
#include "../Vector/SearchAlgorithms.h"
#include "../Vector/SortingAlgorithms.h"
#include <stdio.h>

//Cria uma pilha
array* ArrayListCreate(unsigned long int size)
{
	array* myArrayList = (array *)malloc(sizeof(array));
	myArrayList->size = size;
	myArrayList->vector = (long int*)malloc(size*sizeof(long int));
	myArrayList->last = 0;
	return myArrayList;
}

//Verifica se a lista está vazia ou não 
int ArrayListCheck(array * myList)
{
	if (myList->last == 0)
		return -1;
	return 1;
}

//Remove um elemento da lista 
array * ArrayListRemove(array * myList, long int key)
{
	/*Implements*/
	return NULL;
}

//Insere um elemento na lista 
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

//Imprime todos os elementos da lista 
void ArrayListConsult(array * myList)
{
	for (long int i = 0; i <= myList->last; i++) {
		printf("%ld \n", myList->vector[i]);
	}
}

//Apaga os elementos e libera memória 
array * ArrayListDestroy(array * myList)
{
	free(myList->vector);
	return myList;
}
