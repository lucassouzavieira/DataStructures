/*
 Define funcoes para estruturas de tipo pilhas estaticas

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

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "../Types.h"

/* Cria uma pilha estatica */
array *ArrayStackCreate(unsigned long int size);

/* Verifica se a pilha esta vazia ou nao  */
int ArrayStackCheck(array *mystack);

/* Remove um elemento da pilha  */
array *ArrayStackPop(array *mystack);

/* Insere um elemento na pilha  */
array *ArrayStackPush(array *mystack, long int element);

/* Imprime todos os elementos da pilha  */
void ArrayStackConsult(array *mystack);

/* Apaga os elementos e libera memoria  */
array *ArrayStackDestroy(array *mystack);

#endif /* ARRAYSTACK_H */