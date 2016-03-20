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

Arquivo: StringUtilities.c
Descrição: Implementação de funções auxiliares para manipulação de Strings
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#include "StringUtilities.h"

// Obtem o número de linhas do arquivo
unsigned int getLines(char* fileName)
{
	unsigned int countLines = 0;
	int character = 0;
	FILE* file = fopen(fileName, "rb");
	while ((character = fgetc(file) != EOF)){
		if (character == '\n')
			countLines++;
	}
	return countLines++;
}

// Converte um inteiro para binário
inline char* intToBin(int toConvert)
{
	char* binarySequence;
	itoa(toConvert, binarySequence, BINARY);
	return binarySequence;
}

// Salva a string em um arquivo incluindo informações sobre a compressão realizada
inline int toFile(char * string, char * filename, CompressionAlgorithm algorithm)
{
	FILE* file;
	file = fopen(filename, "wb");
	if (file == NULL) {
		printf("Failed to save file! \n");
		return IO_ERROR;;
	}
	fflush(stdout);
	fprintf(file, "%s \n", intToBin(algorithm));
	for (int i = 0; i < strlen(string); i++) {
		fflush(stdout);
		fprintf(file, "%s \n", string[i]);
	}
	fclose(file);
	printf("Successfully saved file! \n");
	return IO_SUCESS;
}

// Recupera a string de um arquivo
inline char* fromFile(char * filename)
{
	
}

