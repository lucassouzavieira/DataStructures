/*
 Testes de algoritmos de ordenacao

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

#include "SortingTests.h"

double testBubbleSort(long int elements)
{
    long int* vector = CreateRandomVector(elements);
    clock_t start = 0;
    clock_t end = 0;

    start = clock();
    vector = BubbleSort(vector, elements);
    end = clock();

    double time = ((end - start) * 1000) / CLOCKS_PER_SEC;
    return time;
}

double testMergeSort(long int elements)
{
    long int* vector = CreateRandomVector(elements);
    clock_t start = 0;
    clock_t end = 0;

    start = clock();
    MergeSort(vector, elements);
    end = clock();

    double time = ((end - start) * 1000) / CLOCKS_PER_SEC;
    return time;
}
