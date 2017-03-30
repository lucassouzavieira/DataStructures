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

#include "SortingTests.h"

double test_bubble_sort(long int elements)
{
    clock_t start = 0;
    clock_t end = 0;
    long int* vector = create_random_vector(elements);

    start = clock();
    vector = bubble_sort(vector, elements);
    end = clock();

    double time = ((end - start) * 1000) / CLOCKS_PER_SEC;

    return time;
}

double test_merge_sort(long int elements)
{
    clock_t start = 0;
    clock_t end = 0;
    long int* vector = create_random_vector(elements);

    start = clock();
    merge_sort(vector, elements);
    end = clock();

    double time = ((end - start) * 1000) / CLOCKS_PER_SEC;
    return time;
}
