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

// Converte um char em um inteiro
int charToInt(char character)
{
	return 0;
}

// Converte um inteiro para string
string* intToString(int integer)
{
	string* myString = (string*)malloc(sizeof(string));
	// itoa(integer, myString->string, DECIMAL); // Usada em alguns compiladores mais antigos
	_itoa(integer, myString->string, DECIMAL);
	strOptimize(myString);
	return myString;
}

// Converte um inteiro para binário
string* intToBin(int toConvert)
{
	string* binarySequence;
	//itoa(toConvert, binarySequence->string, BINARY); // Usada em alguns compiladores mais antigos
	_itoa(toConvert, binarySequence->string, BINARY);
	binarySequence->length = strlen(binarySequence->string);
	return binarySequence;
}

// Converte uma string para o correspondente em binário
string* strToBin(string* myString)
{
	strOptimize(myString);
	int character;
	string* binarySequence = (string*)malloc(sizeof(string));
	binarySequence->string = (char*)malloc(LINE_MAX_LENGTH*sizeof(char));
	for (int i = 0; i < myString->length; i++) {
		character = charToInt(myString->string[i]);
		strConcatenate(binarySequence, intToBin(character));
	}
	return binarySequence;
}

// Obtem o número de linhas do arquivo
unsigned int getLines(char* fileName)
{
	unsigned int countLines = 0;
	int character = 0;
	FILE* file = fopen(fileName, "r");
	while ((character = fgetc(file) != EOF)) {
		if (character == '\n')
			countLines++;
	}
	return countLines++;
}

// Obtem o número de caracteres no arquivo
unsigned int getCharacteres(char* fileName)
{
	unsigned int countChars = 0;
	int character = 0;
	FILE* file = fopen(fileName, "r");
	while ((character = fgetc(file) != EOF)) {
		if (character != '\n')
			countChars++;
	}
	return countChars;
}

// Salva a string em um arquivo incluindo informações sobre a compressão realizada
int toFile(string* myString, char* filename, CompressionAlgorithm algorithm)
{
	FILE* file;
	file = fopen(filename, "w");
	if (file == NULL) {
		printf("Failed to save file! \n");
		return IO_ERROR;;
	}
	fflush(stdout);
	//fprintf(file, "%s \n", intToBin(algorithm));
	for (int i = 0; i < strlen(myString->string); i++) {
		fflush(stdout);
		fputc(myString->string[i], file);
	}
	fclose(file);
	printf("Successfully saved file! \n");
	return IO_SUCESS;
}

// Recupera a string de um arquivo
string* fromFile(char* filename)
{
	FILE* file;
	file = fopen(filename, "r");
	int lines;
	string* myString = (string*)malloc(sizeof(string));
	myString->string = (char*)malloc(LINE_MAX_LENGTH*sizeof(char));
	myString->length = 50;
	if (file == NULL)
		return NULL;
	lines = getLines(filename);
	while (fgets(myString->string, LINE_MAX_LENGTH, file)){}
	strOptimize(myString);
	return myString;
}

// Concatena duas strings
void strConcatenate(string * firstString, string * sndString)
{
	if (firstString == NULL || sndString == NULL || 
		firstString->string == NULL || sndString->string == NULL) 
		return;
	strOptimize(firstString);
	strOptimize(sndString);
	char* strConcat = (char*)malloc((firstString->length + sndString->length + 1)*sizeof(char));
	strcat(strConcat, firstString->string);
	strcat(strConcat, sndString->string);
	free(firstString->string);
	firstString->string = strConcat;
	strOptimize(firstString);
}

// Copia uma string para outra
void strCopy(string * firstString, string * sndString)
{
	if (firstString == NULL || sndString == NULL ||
		firstString->string == NULL || sndString->string == NULL)
		return;
	strOptimize(firstString);
	strOptimize(sndString);
	char* strCopy = (char*)malloc((firstString->length + sndString->length)*sizeof(char));
	strcpy(firstString->string, sndString->string);
	strOptimize(firstString);
}

// Compara duas strings
int strCompare(string * firstString, string * sndString)
{
	if (firstString == NULL || sndString == NULL ||
		firstString->string == NULL || sndString->string == NULL)
		return IO_ERROR;
	strOptimize(firstString);
	strOptimize(sndString);
	return strcmp(firstString->string, sndString->string);
}

// Otimiza o uso de memória para armazenar a string
void strOptimize(string* myString)
{
	if (myString == NULL || myString->string == NULL)
		return;
	int length = strlen(myString->string);
	char* strTemp = myString->string;
	myString->string = (char*)malloc(length*(sizeof(char)));
	myString->string = strTemp;
}