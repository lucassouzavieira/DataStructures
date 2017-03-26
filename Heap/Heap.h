/*
 Implementacao de Heap

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

#ifndef HEAP_H
#define HEAP_H
#include "../TAD.h"

/* Criar um novo heap */
heap* CreateHeap(long int maxElements);

/* Destruir um heap */
void DestroyHeap(heap* myHeap);

/* Insere um novo elemento no heap */
int InsertInHeap(heap* myHeap, long int key);

/* Remove o elemento de maior prioridade no heap */
long int RemoveHeap(heap* myHeap);

/* Exibe o Heap */
void ShowHeap(heap* myHeap);

/* Cria um Heap de Maximo dado um vetor */
void MaxHeapSort(long int* vector, long int numberOfElements);
#endif /* !HEAP_H */