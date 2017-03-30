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

#include "../Types.h"
#include "../vector/SortingAlgorithms.h"
#include <stdio.h>
#include <stdlib.h>

array *array_list_create(unsigned long int size);

int array_list_check(array *mystack);

array *array_list_remove(array *mystack, long int key);

array *array_list_insert(array *mystack, long int element);

void array_list_print(array *mystack);

array *array_list_destroy(array *mystack);
