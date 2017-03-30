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

#include "Utilities.h"

char *int_to_string(int integer) {

    char buffer[10] = {'0'};
    sprintf(buffer, '%d', integer);

    return (buffer);
}

int get_file_lines(FILE *file) {

    int countLines = 0;
    int character = 0;

    while ((character = fgetc(file) != EOF)) {
        if (character == '\n')
            countLines++;
    }

    return countLines++;
}

int to_file(char *myString, char *filename) {

    FILE *file;
    file = fopen(filename, "w");

    if (file == NULL) {
        printf("Failed to save file! \n");
        return -1;
    }

    fflush(stdout);
    fprintf(file, "%s", myString);
    fclose(file);
    printf("Successfully saved file! \n");

    return 1;
}

char *from_file(char *filename) {

    FILE *file = fopen(filename, "r");
    int lines = get_file_lines(file);

    char *string = (char *) malloc(LINE_MAX_LENGTH * sizeof(char));

    if (file == NULL)
        return NULL;

    // TODO review this
    while (fgets(string, LINE_MAX_LENGTH, file)) {}
    fclose(file);

    return string;
}