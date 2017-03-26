/*
 Funcoes auxiliares para vetores

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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Imprime os elementos do vetor */
void ShowVector(long int *vector, long int numberOfElements) {
    long int *aux = vector;
    for (long int i = 0; i < numberOfElements; i++) {
        printf("%ld \n", aux[i]);
    }
}

/* Salva o vetor em um arquivo txt */
int SaveVector(const char *address, long int *vector, long int numberOfElements) {
    FILE *file;
    file = fopen(address, "w");
    if (file == NULL) {
        printf("Failed to save file! \n");
        return -1;
    }
    for (long int i = 0; i < numberOfElements; i++) {
        fflush(stdout);
        fprintf(file, "%ld \n", vector[i]);
    }
    fclose(file);
    printf("Successfully saved file! \n");
    return 0;
}

/* Recupera o vetor de um arquivo */
long int *RetrieveVector(const char *address, long *vector, long int numberOfElements) {
    vector = (long int *) malloc((numberOfElements) * sizeof(long int));
    *vector = 0;
    FILE *file;
    file = fopen(address, "r");
    if (file == NULL) {
        printf("Falha ao ler arquivo! \n");
        return NULL;
    }
    for (int i = 0; i <= (numberOfElements - 1); i++) {
        fflush(stdin);
        fscanf(file, "%ld", &vector[i]);
    }
    fclose(file);
    printf("Arquivo lido com sucesso! \n");
    return vector;
}

/* Cria um vetor com valorer randomicos */
long int *CreateRandomVector(long int numberOfElements) {
    srand(time(NULL));
    long int *vector;
    vector = (long int *) (malloc(numberOfElements * sizeof(long int)));
    if (vector == NULL) {
        printf("Memory allocation error! \n");
        return NULL;
    } else {
        for (long int i = 0; i < numberOfElements; i++) {
            int multiplicador = -40 + rand() % 20;
            vector[i] = (32767 * multiplicador + 2 * rand());
        }
    }
    return vector;
}