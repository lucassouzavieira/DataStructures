/*
 * Copyright (C) 2016  Lucas S. Vieira
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "../Types.h"
#include <stdio.h>
#include <stdlib.h>

array *array_stack_create(unsigned long int size);

int array_stack_check(array *mystack);

/* Remove um elemento da pilha  */
array *array_stack_pop(array *mystack);

/* Insere um elemento na pilha  */
array *array_stack_push(array *mystack, long int element);

/* Imprime todos os elementos da pilha  */
void array_stack_print(array *mystack);

/* Apaga os elementos e libera memoria  */
array *array_stack_destroy(array *mystack);

#endif /* ARRAYSTACK_H */