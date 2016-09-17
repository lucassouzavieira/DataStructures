/*
 Funcoes auxiliares para vetores

 Copyright (C) 2016  Lucas S. Vieira

 This program is free software: you can redistribute it and/or modify it
 under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License,
 or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef VECTOR_H
#define VECTOR_H

/* Imprime os elementos do vetor */
void ShowVector(long int *vector, long int numberOfElements);

/* Salva o vetor em um arquivo txt */
int SaveVector(const char* address, long int *vector, long int numberOfElements);

/* Recupera o vetor de um arquivo */
long int* RetrieveVector(const char* address, long *vector, long int numberOfElements);

/* Cria um vetor com valores randomicos */
long int* CreateRandomVector(long int numberOfElements);

#endif