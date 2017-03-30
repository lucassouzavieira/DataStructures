/*
 Algoritmo RLE para compressao de texto

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

#include "RLE.h"
#include "Utilities.h"

/*********************************************************************************************
Run-Length Encoding:
*Conjunto de Caracteres: A-Za-z ; 0-9;
*Delimitadores: '@' para repeticao de caracteres (A-Za-z);
				'-' para espacos em branco
				'RLE' para identificacao dessa codificacao no arquivo

*Exemplo:	Input:	'aaaaawwwwab   hhhhrrttttt332'
			Output: '@4a@4wab$3-@4h@2r@5t#232'

Tabela ASCII usada como base: <http:/*ic.unicamp.br/~everton/aulas/hardware/tabelaASCII.pdf>
**********************************************************************************************/


/* Retorna a string codificada pelo RLE */
char *encodeRLE(char *myString) {
    FILE *tmpFile = fopen("tmpOutPutFile", "w");
    int occurrences = 1;
    const char *encodedString = NULL;

    if (myString == NULL)
        return NULL;
    for (int i = 1; myString[i - 1] != '\0'; i++) {
        if (myString[i] == myString[i - 1]) {
            occurrences++;
        } else if (occurrences < 4) {
            /* Otimizacao para RLE  */
            for (int j = 1; j <= occurrences; j++) {
                fflush(stdout);
                fprintf(tmpFile, "%c", myString[i - 1]);
            }
            occurrences = 1;
        } else {
            fflush(stdout);
            fprintf(tmpFile, "@%c%d", myString[i - 1], occurrences);
            occurrences = 1;
        }
    }

    fclose(tmpFile);
    encodedString = fromFile("tmpOutPutFile");

    return encodedString;
}

/* Decodifica uma string codificada pelo RLE  */
char *decodeRLE(char *myString) {
    FILE *tmpFile = fopen("tmpInputFile", "w");
    int stringSize = 0;
    int i = 0;
    int charOccurrences = 0;
    char character = 0;
    char ocurrences[3] = {"\0"};

    if (myString == NULL)
        return NULL;

    stringSize = strlen(myString);
    for (i = 0; i <= stringSize;) {
        fflush(stdout);
        if (myString[i] == '@') {
            character = myString[i + 1];
            ocurrences[0] = myString[i + 2];
            if ((myString[i + 3] > 47 && myString[i + 3] < 59)) {
                ocurrences[1] = myString[i + 3];
                i = i + 4;
            } else {
                i = i + 3;
            }
            charOccurrences = atoi(ocurrences);
            for (int j = 1; j <= charOccurrences; j++) {
                fflush(stdout);
                fprintf(tmpFile, "%c", character);
            }
            ocurrences[1] = "\0";
        } else {
            fflush(stdout);
            fprintf(tmpFile, "%c", myString[i]);
            i = i + 1;
        }
    }
    fclose(tmpFile);
    return "NULL";
}