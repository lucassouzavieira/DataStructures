/*
 * Copyright (C) 2016  Lucas S. Vieira
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Types.h"

doublylist create_doubly_linked_list();

/* Verifica se ha elementos na lista */
int check_doubly_linked_list(doublylist *myDoublyList);

/* Insere elementos no inicio da lista */
void insert_start_doubly_linked_list(doublylist *myDoublyList, long int element);

void insert_middle_doubly_linked_list(doublylist *myDoublyList, long int element);

void insert_end_doubly_linked_list(doublylist *myDoublyList, long int element);

dnode *search_doubly_linked_list(doublylist *myDoublyList, long int element);

void list_elements_doubly_linked_list(doublylist *myDoublyList);

void remove_doubly_linked_list(doublylist *myDoublyList, long int element);

int destroy_doubly_linked_list(doublylist *myDoublyList);

#endif 