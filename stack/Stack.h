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


#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>
#include "../Types.h"

stack stack_create();

int stack_check(stack *myStack);

void stack_pop(stack *myStack);

void stack_push(stack *myStack, int element);

void stack_print(stack *myStack);

int stack_destroy(stack *myStack);

#endif /* STACK_H */