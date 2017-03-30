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

#ifndef UTILITIES_H
#define UTILITIES_H

#include "../Types.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Converte um inteiro em uma string  */
char *intToString(int integer);

/* Salva a string em um arquivo incluindo informacoes sobre a compressao realizada */
int toFile(char *myString, char *filename);

/* Recupera a string de um arquivo */
char *fromFile(char *filename);

#endif /* !UTILITIES_H */