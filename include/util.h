/*
 * Copyright (C) 2018  Lucas S. Vieira
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

#include <stdlib.h>
#include <stdbool.h>
#include <types.h>

#ifndef UTIL
#define UTIL

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Alloc memory and cast any struct type
 *
 * @param type
 * @return
 */
void *init(void* type);

/**
 * Destroys any pointer
 *
 * @param ptr
 * @return bool
 */
bool destroy(void *ptr);

/**
 * Initialize a new node element
 *
 * @param void* data
 * @param node* pointer
 * @return node* new node element
 */
node *new_node(void *data, node *pointer);

/**
 * Compares two nodes
 *
 * @param node* first
 * @param node* second
 * @param bool* function function to compare
 * @return bool
 */
bool node_compare(node *first, node *second, bool function(node *a, node *b));

/**
 * Gets the node data with proper typecast
 *
 * @param ptr
 * @return *void with node data
 */
void* node_data(node* ptr);

/**
 * Destroys a node
 *
 * @param elem
 * @return boolean
 */
bool node_destroy(node *elem);

#ifdef __cplusplus
};
#endif

#endif //TYPES.H