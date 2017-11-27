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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Huffman.h"

#define DEBUG

void huffman_enconde(char *myString) {

    int stringSize = strlen(myString);
    int vectorSize = 0;
    int position = 0;
    int occurrence = 0;
    int sum = 0;
    double frequency = 0;
    char character = 0;
    long int _intaux = 0;
    static unsigned char _charaux = ' ';


    if (myString == NULL) {
        return;
    }

    int *occurrences = (int *) malloc(stringSize * sizeof(int));
    double *frequencies = (double *) malloc(stringSize * sizeof(double));
    char *characters = (char *) malloc((stringSize + 1) * sizeof(char));
    char *string = (char *) malloc((stringSize + 1) * sizeof(char));

    strcpy(string, myString);
    FILE *file = fopen("tmpHuffmanOutputFile", "w");

    for (int i = 0; i < stringSize; i++) {
        if (string[i] != '@') {
            occurrence = 1;
            character = string[i];
            characters[position] = string[i];
            string[i] = '@';
            for (int j = (i + 1); j < stringSize; j++) {
                if (string[j] == character) {
                    occurrence++;
                    string[j] = '@';
                }
            }
            occurrences[position] = occurrence;
            position++;
            vectorSize++;
        }
        occurrence = 0;
    }

#ifdef DEBUG
    for (int i = 0; i < vectorSize; i++) {
        printf("%c \t %d \n", characters[i], occurrences[i]);
    }
#endif

    for (int i = 0; i < vectorSize; i++) {
        sum = sum + occurrences[i];
    }

    for (long int i = 0; i < vectorSize; i++) {
        for (long int j = 0; j < (vectorSize - 1); j++) {
            if (occurrences[j] > occurrences[j + 1]) {
                _intaux = occurrences[j];
                occurrences[j] = occurrences[j + 1];
                occurrences[j + 1] = _intaux;

                _charaux = characters[j];
                characters[j] = characters[j + 1];
                characters[j + 1] = _charaux;

            }
        }
    }

#ifdef DEBUG
    printf("\nOrdenado \n");
    for (int i = 0; i < vectorSize; i++) {
        printf("%c \t %d \n", characters[i], occurrences[i]);
    }
#endif
}

char *decodeHuffman(huffman_tree_node *huffmanTree) {
    // TODO
    return NULL;
}

