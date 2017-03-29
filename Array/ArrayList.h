/*
 Define funcoes para estruturas de tipo listas estaticas

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

#include "../Types.h"

/* Cria uma lista estatica */
array *ArrayListCreate(unsigned long int size);

/* Verifica se a lista esta vazia ou nao  */
int ArrayListCheck(array *mystack);

/* Remove um elemento da lista  */
array *ArrayListRemove(array *mystack, long int key);

/* Insere um elemento na lista  */
array *ArrayListInsert(array *mystack, long int element);

/* Imprime todos os elementos da lista */
void ArrayListConsult(array *mystack);

/* Apaga os elementos e libera memoria  */
array *ArrayListDestroy(array *mystack);
