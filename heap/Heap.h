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

#include "Types.h"

/* Criar um novo heap */
heap *create_heap(long int maxElements);

/* Destruir um heap */
void destroy_heap(heap *myHeap);

/* Insere um novo elemento no heap */
int insert_heap(heap *myHeap, long int key);

/* Remove o elemento de maior prioridade no heap */
long int remove_heap(heap *myHeap);

/* Exibe o Heap */
void show_heap(heap *myHeap);

/* Cria um Heap de Maximo dado um vetor */
void max_heap_sort(long int *vector, long int numberOfElements);

#endif /* !HEAP_H */