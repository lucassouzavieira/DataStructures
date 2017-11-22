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

#ifndef CIRCLELIST_H
#define CIRCLELIST_H

#include "Types.h"

circlelist create_circle_list();

int check_circle_list(circlelist *myList);

void insert_circle_list(circlelist *myList, long int element);

node *search_circle_list(circlelist *myList, long int element);

void list_elements_circle_list(circlelist *myList);

void remove_circle_list(circlelist *myList, long int element);

int destroy_circle_list(circlelist *myList);

#endif /* !CIRCLELIST_H