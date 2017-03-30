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

#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include "../Types.h"

long int *bubble_sort(long int *vector, long int numberOfElements);

long int *bubble_sort_improved(long int *vector, long int numberOfElements);

long int *insertion_sort(long int *vector, long int numberOfElements);

long int *selection_sort(long int *vector, long int numberOfElements);

long int *quick_sort(long int *vector, long int numberOfElements);

/* Comb Sort 11 */
long int *comb_sort(long int *vector, long int numberOfElements);

long int *shell_sort(long int *vector, long int numberOfElements);

long int *gnome_sort(long int *vector, long int numberOfElements);

long int *bogo_sort(long int *vector, long int numberOfElements);

long int *couting_sort(long int *vector, long int numberOfElements);

void heap_sort(long int *vector, long int numberOfElements);

void merge_sort(long int *vector, long int numberOfElements);

#endif /* !SORTINGALGORITHMS_H */