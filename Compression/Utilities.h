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

Arquivo: Utilities.h
Descrição: Definições para funções utilitarias de manipulação de texto
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef UTILITIES_H
#define UTILITIES_H

#include "..\TAD.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Converte um inteiro em uma string
char* intToString(int integer);

// Salva a string em um arquivo incluindo informações sobre a compressão realizada
int toFile(char* myString, char* filename);

// Recupera a string de um arquivo
char* fromFile(char* filename);

#endif // !UTILITIES_H