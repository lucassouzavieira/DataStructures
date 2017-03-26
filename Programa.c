/*
 Testes das implementacoes

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


#define DEBUG 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD.h"
#include "Vector/Vector.h"
#include "Vector/SortingAlgorithms.h"
#include "BinaryTrees/BinarySearchTree.h"


int main() {
    long int *vector = CreateRandomVector(10);

    ShowVector(vector, 10);
    vector = BubbleSortImproved(vector, 10);

#ifdef DEBUG
    printf("----\n");
#endif
    ShowVector(vector, 10);
}