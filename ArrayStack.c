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

Arquivo: ArrayStack.h
Descrição: Definições para estruturas do tipo pilhas estáticas
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include <stdlib.h>
#include <stdio.h>
#include "TAD.h"

//Cria uma pilha
array* ArrayStackCreate(long int size){
	array* myArrayStack = (array *)malloc(sizeof(array));
	myArrayStack->size = size;
	myArrayStack->vector = (long int*)malloc(size*sizeof(long int));
	myArrayStack->last = 0;
	return myArrayStack;
}

//Verifica se a pilha está vazia ou não 
int ArrayStackCheck(array* myArrayStack) {
	if (myArrayStack->last == 0) {
		return -1;
	}
	return 1;
}

//Remove um elemento da pilha 
array* ArrayStackPop(array* myArrayStack) {
	if (myArrayStack->last == 0) {
		printf("Pilha Vazia! \n");
		return myArrayStack;
	}
	myArrayStack->last--;
	return myArrayStack;
}

//Insere um elemento na pilha 
array* ArrayStackPush(array* myArrayStack, long int element) {
	if (myArrayStack->last == myArrayStack->size - 1) {
		printf("Pilha cheia! \n");
		return myArrayStack;
	}
	myArrayStack->last++;
	myArrayStack->vector[myArrayStack->last] = element;
	return myArrayStack;
}

//Imprime todos os elementos da pilha 
void ArrayStackConsult(array* myArrayStack) {
	for (long int i = 0; i <= myArrayStack->last; i++) {
		printf("%ld \n", myArrayStack->vector[i]);
	}
}

//Apaga os elementos e libera memória 
array* ArrayStackDestroy(array* myArrayStack) {
	free(myArrayStack->vector);
	return myArrayStack;
}

#endif // ARRAYSTACK_H