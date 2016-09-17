/*
 Define funcoes para estruturas de tipo filas estaticas

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

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include "../TAD.h"

/* Cria uma fila  */
array* ArrayQueueCreate(unsigned long int size);

/* Verifica se ha elementos na fila  */
int ArrayQueueCheck(array* myArrayQueue);

/* Insere elementos na fila  */
array* ArrayQueueEnqueue(array* myArrayQueue, long int element);

/* Remove elementos da fila  */
array* ArrayQueueDequeue(array* myArrayQueue);

/* Imprime os elementos da fila  */
void ArrayQueueConsult(array* myArrayQueue);

/* Apaga todos os elementos e libera memoria  */
array* ArrayQueueDestroy(array* myArrayQueue);

#endif /* !ARRAYQUEUE_H */