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

Arquivo: StringUtilities.h
Descrição: Definições de funções auxiliares para manipulação de Strings
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef STRINGUTILITIES_H
#define STRINGUTILITIES_H

#include "../TAD.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define IO_ERROR -1
#define IO_SUCESS 0
#define BINARY 2
#define LINE_MAX_LENGTH 5000

#define CHAR_TO_INT(char)character){return atoi(character);} // Converte um char em um inteiro

/******************************************************************************
Funções Utilitárias
******************************************************************************/

// Converte um inteiro para binário
string* intToBin(int toConvert);

// Converte uma string para binário
string* strToBin(string myString);

// Salva a string em um arquivo incluindo informações sobre a compressão realizada
int toFile(string* myString, char* filename, CompressionAlgorithm algorithm);

// Recupera a string de um arquivo
string* fromFile(char* filename);

// Concatena duas strings
void strConcatenate(string* firstString, string* sndString);

// Copia uma string para outra
void strCopy(string* firstString, string* sndString);

// Compara duas strings
int strCompare(string* firstString, string* sndString);


/******************************************************************************
Funções para otimização da estrutura string
******************************************************************************/
// Otimiza o uso de memória para armazenar a string
void strOptimize(string* myString);

#endif // STRINGUTILITIES_H