/*
 Implementacao de Lista Dupla

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

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "../Types.h"

/* Cria uma lista duplamente encadeada */
doublylist CreateDLinkedList();

/* Verifica se ha elementos na lista */
int CheckDLinkedList(doublylist *myDoublyList);

/* Insere elementos no inicio da lista */
void InsertAtStartDLinkedList(doublylist *myDoublyList, long int element);

/* Insere elementos no meio da lista */
void InsertAtMiddleDLinkedList(doublylist *myDoublyList, long int element);

/* Insere elementos no fim da lista */
void InsertAtEndDLinkedList(doublylist *myDoublyList, long int element);

/* Busca um dado elemento na lista */
dnode *SearchElementDLinkedList(doublylist *myDoublyList, long int element);

/* Imprime todos os elementos da lista */
void ListElementsDLinkedList(doublylist *myDoublyList);

/* Remove um dado elemento da lista */
void RemoveElementDLinkedList(doublylist *myDoublyList, long int element);

/* Apaga toda a lista e libera memoria */
int DestroyDLinkedList(doublylist *myDoublyList);

#endif 