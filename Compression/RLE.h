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
Descrição: Definição de funções para decodificação RLE
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef RLE_H
#define RLE_H
#include "../TAD.h"
#include <stdio.h>
#include <string.h>

// Codifica uma string e retorna a sequência codificada
char* encodeRLE(char* myString);

// Decodifica uma string e retorna a sequência decodificada
char* decodeRLE(char* myString);

#endif // !RLE_H
