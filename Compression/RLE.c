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

Arquivo: RLE.c
Descrição: Implementação das funções para decodificação RLE
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#include "RLE.h"
#define _CRT_SECURE_NO_WARNINGS 1;

/*********************************************************************************************
Run-Length Encoding:
	*Conjunto de Caracteres: A-Za-z ; 0-9;
	*Delimitadores: '@' para repetição de letras (A-Za-z); 
					'#' para repetição de números (0-9)
					'-' para espaços em branco
					'$' para repetição de espaços em branco
					'&' para repetição dos demais caracteres
					'R' para identificação dessa codificação no arquivo

	*Exemplo:	Input:	'aaaaawwwwab   hhhhrrttttt332'
				Output: '@4a@4wab$3-@4h@2r@5t#232'

Tabela ASCII usada como base: <http://ic.unicamp.br/~everton/aulas/hardware/tabelaASCII.pdf>
**********************************************************************************************/

// Avalia as repetições
char* generateRLECode(rlecodenode* codingVector, int vectorSize)
{
	if (codingVector == NULL || vectorSize <= 0)
		return NULL;
	char rleEncoded[LINE_MAX_LENGTH];
	for (int i = 0; i <= vectorSize; i++) {
		int character = charToInt(codingVector[i].character);
		if (character == 32) {
			// Caractere é um espaço em branco (' ')
			if (codingVector[i].occurrences == 1) {
				strcat(rleEncoded, '-');
			} else {
				strcat(rleEncoded,'$');
				strcat(rleEncoded, intToString(codingVector[i].occurrences));
				strcat(rleEncoded, '-');
			}
		} else if ((character > 64 && character < 91) || (character > 96 && character < 123)) {
			// Caractere está em [A - Z] ou em [a - z]
			if (codingVector[i].occurrences == 1) {
				strcat(rleEncoded, codingVector[i].character);
			} else {
				strcat(rleEncoded, '@');
				strcat(rleEncoded, intToString(codingVector[i].occurrences));
				strcat(rleEncoded, codingVector[i].character);
			}
		} else if ((character > 47 && character < 59)) {
			// Caractere está entre [0 - 9]
			if (codingVector[i].occurrences == 1) {
				strcat(rleEncoded, codingVector[i].character);
			} else {
				strcat(rleEncoded, '#');
				strcat(rleEncoded, intToString(codingVector[i].occurrences));
				strcat(rleEncoded, codingVector[i].character);
			} 
		} else {
			// Caractere é outro qualquer
			/*
			if (codingVector[i].occurrences == 1) {
				strcat(rleEncoded, codingVector[i].character);
			} else {
				strcat(rleEncoded, '&');
				strcat(rleEncoded, intToString(codingVector[i].occurrences));
				strcat(rleEncoded, codingVector[i].character);
			}*/
		}
	} // End for
	return rleEncoded;
}

// Codifica uma string e retorna a sequência codificada
string* encodeRLE(string* myString)
{
	//strOptimize(myString);
	printf("encodeRLE: %s \n", myString->string);
	string* encodedString = (string*)malloc(sizeof(string));
	rlecodenode* coding = (rlecodenode*)malloc((myString->length)*(sizeof(rlecodenode)));
	for (int i = 0; i < myString->length; i++) {
		if (i == 0) {
			coding[i].character = myString->string[i];
			coding[i].occurrences = 1;
		} else if (coding[i - 1].character == myString->string[i]) {
			coding[i - 1].occurrences++;
		} else {
			coding[i].character = myString->string[i];
			coding[i].occurrences = 1;
		}
	}
	encodedString->string = generateRLECode(coding, myString->length);
	strOptimize(encodedString);
	return encodedString;
}

// Decodifica uma string e retorna a sequência decodificada
string* decodeRLE(string* myString)
{
	return NULL;
}