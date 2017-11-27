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


#ifndef DEQUE_H
#define DEQUE_H

#include "types.h"

deque deque_create();

int deque_check(deque *myDeque);

void deque_insert_at_front(deque *myQueue, long int element);

void deque_insert_at_back(deque *myQueue, long int element);

void deque_shift(deque *myDeque);

void deque_pop(deque *myDeque);

void deque_print(deque *myDeque);

int deque_destroy(deque *myDeque);

#endif /* DEQUE_H */