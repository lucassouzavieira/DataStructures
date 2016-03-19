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

Arquivo: Heap.h
Descrição: Definições para estruturas Heap
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef HEAP_H
#define HEAP_H
#include "..\TAD.h"
// Criar um novo heap
heap* CreateHeap(long int maxElements);

// Destruir um heap
void DestroyHeap(heap* myHeap);

// Insere um novo elemento no heap
int InsertInHeap(heap* myHeap, long int key);

// Remove o elemento de maior prioridade no heap
long int RemoveHeap(heap* myHeap);

// Exibe o Heap
void ShowHeap(heap* myHeap);

// Cria um Heap de Máximo dado um vetor
void MaxHeapSort(long int* vector, long int numberOfElements);
#endif // !HEAP_H