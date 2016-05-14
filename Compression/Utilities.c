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
com este programa, Se não, veja <http:/*www.gnu.org/licenses/>.

Arquivo: Utilities.c
Descrição: Implementações de funções utilitarias de manipulação de texto
Autor: Lucas de Souza Vieira <lucassouzavieiraengcomp@gmail.com>	*/

#define _CRT_SECURE_NO_WARNINGS 1
#include "Utilities.h"

/* Converte um inteiro em uma string */
char* intToString(int integer)
{
	char buffer[10] = {'0'};
	sprintf(buffer, '%d', integer);
	printf("intToString: %s \n", buffer);
	return (buffer);
}

/* Obtem o numero de linhas de um arquivo */
int getLines(char* filename) 
{
	int countLines = 0;
	int character = 0;
	FILE* file = fopen(filename, "r");
	while ((character = fgetc(file) != EOF)) {
		if (character == '\n')
			countLines++;
	}
	return countLines++;
}

/* Salva a string em um arquivo incluindo informações sobre a compressão realizada */
int toFile(char* myString, char* filename)
{
	FILE* file;
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
char* fromFile(char* filename)
{
	FILE* file;
	int lines;
	file = fopen(filename, "r");
	lines = getLines(filename);
	char* string = (char*)malloc(LINE_MAX_LENGTH*sizeof(char));
	if (file == NULL)
		return NULL;
	while (fgets(string, LINE_MAX_LENGTH, file)) {}
	fclose(file);
	return string;
}