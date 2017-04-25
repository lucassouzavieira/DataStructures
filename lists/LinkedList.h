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

list create_linked_list();

int check_linked_list(list *myList);

void insert_start_linked_list(list *myList, long int element);

void insert_middle_linked_list(list *myList, long int element);

void insert_end_linked_list(list *myList, long int element);

node *search_linked_list(list *myList, long int element);

void list_elements_linked_list(list *myList);

list reverse_linked_list(list *myList);

void remove_linked_list(list *myList, long int element);

int destroy_linked_list(list *myList);

#endif