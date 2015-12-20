/**
Este arquivo é parte do projeto Data Structures
/*
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

Arquivo: ArrayQueue.h
Descrição: Definições para estruturas tipo fila estática
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#define MAX 50;

#include "TAD.h"

//Cria uma fila 
array* ArrayQueueCreate();

//Verifica se há elementos na fila 
int ArrayQueueCheck(array* myArrayQueue);

//Insere elementos na fila 
array* ArrayQueueEnqueue(array* myArrayQueue, long int element);

//Remove elementos da fila 
array* ArrayQueueDequeue(array* myArrayQueue);

//Imprime os elementos da fila 
void ArrayQueueConsult(array* myArrayQueue);

//Apaga todos os elementos e libera memória 
array* ArrayQueueDestroy(array* myArrayQueue);

#endif // !ARRAYQUEUE_H