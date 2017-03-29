/*
 Implementacao de Deque

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

#ifndef DEQUE_H
#define DEQUE_H

#include "../Types.h"

/* Cria um deque */
deque CreateDeque();

/* Verifica se ha elementos no deque */
int CheckDeque(deque *myDeque);

/* Insere elementos no deque  */
void InsertAtFront(deque *myQueue, long int element);

void InsertAtBack(deque *myQueue, long int element);

/* Remove elementos do deque */
void RemoveFromFront(deque *myDeque);

void RemoveFromBack(deque *myDeque);

/* Imprime os elementos do deque */
void ConsultDeque(deque *myDeque);

/* Apaga todos os elementos e libera memoria */
int DestroyDeque(deque *myDeque);

#endif /* DEQUE_H */