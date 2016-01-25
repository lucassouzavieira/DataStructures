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

Arquivo: Vector.h
Descrição: Definições de funções auxiliares para vetores
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef VECTOR_H
#define VECTOR_H

#define VALOR_MIN 268435456	
#include <Windows.h>

// Imprime os elementos do vetor
void ShowVector(long int *vector, long int numberOfElements);

// Salva o vetor em um arquivo txt
int SaveVector(const char* address, long int *vector, long int numberOfElements);

// Recupera o vetor de um arquivo
long int* RetrieveVector(const char* address, long *vector, long int numberOfElements);

// Cria um vetor com números aleatórios
long int* CreateRandomVector(long int numberOfElements);

#endif