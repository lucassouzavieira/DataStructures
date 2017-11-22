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

#define ELEMENTS 10

#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"

const char* filename = "example.txt";

int main(int argc, char **argv[]) {

    printf("Random array with 10 elements \n");
    long int *vector = create_random_vector(ELEMENTS);
    show_vector(vector, ELEMENTS);

    printf("Save array to file \n");
    save_vector(filename, vector, ELEMENTS);

    printf("Retrieve array from file \n");
    free(vector);
    vector = retrieve_vector(filename, vector, ELEMENTS);
    show_vector(vector, ELEMENTS);

    return 0;
}