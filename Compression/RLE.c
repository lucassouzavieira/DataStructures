/**
Este arquivo é parte do projeto Data Structures
Este é um software livre; você pode redistribuí-lo e/ou
modificá-lo dentro dos termos da Licença Pública Geral GNU como
publicada pela Fundação do Software Livre (FSF); na versão 3 da
Licença, ou (na sua opinião) qualquer versão.

Este programa é distribuído na esperança de que possa ser  útil,
mas SEM NENHUMA GARANTIA; sem uma garantia implícita de ADEQUAÇÃO
a qualquer MERCADO ou APLICAÇÃO EM PARTICULAR. Veja a
Licença Pública Geral GNU para maiores detalhes.

Você deve ter recebido uma cópia da Licença Pública Geral GNU junto
com este programa, Se não, veja <http://www.gnu.org/licenses/>.

Arquivo: RLE.h
Descrição: Algoritmo RLE para Compressão de Texto
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#include "RLE.h"
#include "Utilities.h"
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
/*********************************************************************************************
Run-Length Encoding:
*Conjunto de Caracteres: A-Za-z ; 0-9;
*Delimitadores: '@' para repetição de caracteres (A-Za-z);
				'-' para espaços em branco
				'RLE' para identificação dessa codificação no arquivo

*Exemplo:	Input:	'aaaaawwwwab   hhhhrrttttt332'
			Output: '@4a@4wab$3-@4h@2r@5t#232'

Tabela ASCII usada como base: <http://ic.unicamp.br/~everton/aulas/hardware/tabelaASCII.pdf>
**********************************************************************************************/


// Retorna a string codificada pelo RLE
char* encodeRLE(char* myString)
{
	FILE* tmpFile = fopen("tmpOutPutFile", "w");
	int occurrences = 1;
	const char* encodedString = NULL;
	if (myString == NULL)
		return NULL;
	for (int i = 1; myString[i - 1] != '\0'; i++) {
		if (myString[i] == myString[i - 1]) {
			occurrences++;
		} else if (occurrences < 4) {
			// Otimização para RLE
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
	//remove("tmpFile");
	return encodedString;
}

// Decodifica uma string codificada pelo RLE
char* decodeRLE(char * myString)
{
	int stringSize;
	int i = 0;
	int charOccurrences;
	FILE* tmpFile = fopen("tmpInputFile", "w");
	char character;
	char ocurrences[3] = { "\0" };
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