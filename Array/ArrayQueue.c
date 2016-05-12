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

Arquivo: ArrayQueue.c
Descrição: Implementações para estruturas do tipo filas estáticas
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#include <stdlib.h>
#include <stdio.h>
#include "..\TAD.h"

/* Cria e retorna uma fila estática  */
array* ArrayQueueCreate (unsigned long int size) 
{
	array* myArrayQueue = (array *)malloc(sizeof(array));
	myArrayQueue->size = size;
	myArrayQueue->vector = (long int*)malloc(size*sizeof(long int));
	myArrayQueue->last = 0;
	return myArrayQueue;
}

/* Verifica se há elementos na fila  */
int ArrayQueueCheck (array* myArrayQueue) 
{
	if (myArrayQueue->last == 0)
		return -1;
	return 1;
}

/* Insere elementos na fila  */
array* ArrayQueueEnqueue (array* myArrayQueue, long int element) 
{
	if (myArrayQueue->last == myArrayQueue->size - 1){
		printf("Pilha cheia! \n");
		return myArrayQueue;
	}
	myArrayQueue->vector[myArrayQueue->last] = element;
	myArrayQueue->last++;
	return myArrayQueue;
}

/* Remove elementos da fila  */
array* ArrayQueueDequeue (array* myArrayQueue)
{
	if (myArrayQueue->last == 0){
		printf("Fila vazia! \n");
		return myArrayQueue;
	}
	for (long int i = 0; i < myArrayQueue->last; i++) {
		myArrayQueue->vector[i] = myArrayQueue->vector[i + 1];
	}
	myArrayQueue->last--;
	return myArrayQueue;
}

/* Imprime os elementos da fila  */
void ArrayQueueConsult (array* myArrayQueue) 
{
	for (long int i = 0; i <= myArrayQueue->last; i++) {
		printf("%ld \n", myArrayQueue->vector[i]);
	}
}

/* Apaga todos os elementos e libera memória  */
array* ArrayQueueDestroy (array* myArrayQueue) 
{
	free(myArrayQueue->vector);
	return myArrayQueue;
}