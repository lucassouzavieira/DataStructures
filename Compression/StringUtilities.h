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

#define CHAR_TO_INT(char)character){return atoi(character);} // Converte um char em um inteiro

// Converte um inteiro para binário
char* intToBin(int toConvert);

// Salva a string em um arquivo incluindo informações sobre a compressão realizada
int toFile(char* string, char* filename,CompressionAlgorithm algorithm);

// Recupera a string de um arquivo
char* fromFile(char* filename);

#endif // STRINGUTILITIES_H