/*
 Define funcoes para manipulacao de strings

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

#include "Utilities.h"

/* Converte um inteiro em uma string */
char *intToString(int integer) {
    char buffer[10] = {'0'};
    sprintf(buffer, '%d', integer);
    printf("intToString: %s \n", buffer);
    return (buffer);
}

/* Obtem o numero de linhas de um arquivo */
int getLines(char *filename) {
    int countLines = 0;
    int character = 0;
    FILE *file = fopen(filename, "r");
    while ((character = fgetc(file) != EOF)) {
        if (character == '\n')
            countLines++;
    }
    return countLines++;
}

/* Salva a string em um arquivo incluindo informacoes sobre a compressao realizada */
int toFile(char *myString, char *filename) {
    FILE *file;
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to save file! \n");
        return -1;
    }
    fflush(stdout);
    /*for (int i = 0; i < strlen(myString); i++) {
        fflush(stdout);
        fputc(myString, file);
    }*/
    fprintf(file, "%s", myString);
    fclose(file);
    printf("Successfully saved file! \n");
    return 1;
}

/* Recupera a string de um arquivo */
char *fromFile(char *filename) {
    FILE *file;
    int lines;
    file = fopen(filename, "r");
    lines = getLines(filename);
    char *string = (char *) malloc(LINE_MAX_LENGTH * sizeof(char));
    if (file == NULL)
        return NULL;
    while (fgets(string, LINE_MAX_LENGTH, file)) {}
    fclose(file);
    return string;
}