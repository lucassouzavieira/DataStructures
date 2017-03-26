/*
 Implementacao de Lista Circular

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

#ifndef CIRCLELIST_H
#define CIRCLELIST_H

#include "../TAD.h"

/* Cria uma lista circular  */
circlelist CreateCircleList(); 

/* Verifica se a lista esta vazia ou nao  */
int CheckCircleList(circlelist* myList);

/* Insere novos elementos na lista  */
void InsertAtCircleList(circlelist* myList, long int element);

/* Busca um dado valor na lista  */
node* SearchElementCircleList(circlelist* myList, long int element);

/* Imprime todos os elementos da lista  */
void ListElementsCircleList(circlelist* myList);

/* Remove um dado elemento da lista  */
void RemoveElementCircleList(circlelist* myList, long int element);

/* Apaga toda a lista e libera a memoria  */
int DestroyCircleList(circlelist* myList);

#endif /* !CIRCLELIST_H