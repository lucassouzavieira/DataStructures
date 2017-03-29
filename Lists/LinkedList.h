/*
 Implementacao de Lista simples

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

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../Types.h"

/* Cria uma lista encadeada */
list CreateLinkedList();

/* Verifica uma lista encadeada (se vazia) */
int CheckLinkedList(list *myList);

/* Insere no inicio da lista */
void InsertAtStartLinkedList(list *myList, long int element);

/* Insere no meio da lista */
void InsertAtMiddleLinkedList(list *myList, long int element);

/* Insere no fim da lista */
void InsertAtEndLinkedList(list *myList, long int element);

/* Busca */
node *SearchLinkedList(list *myList, long int element);

/* Mostrar os elementos */
void ListElementsLinkedList(list *myList);

/* Retorna uma lista com os elementos em ordem invertida */
list ReverseLinkedList(list *myList);

/* Remove elementos */
void RemoveElementLinkedList(list *myList, long int element);

/* Destruir a lista */
int DestroyLinkedList(list *myList);

#endif