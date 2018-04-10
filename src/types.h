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

#include <stdlib.h>
#include <stdbool.h>

#ifndef TYPES_H
#define TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
Lists, stacks and queues
******************************************************************************/
typedef
struct node {
    void *data;
    struct node *pointer;
} node;


/**
 * Init any struct type
 * @param type
 * @return
 */
void *init(void* type) {
    return (typeof(type)*) malloc(sizeof(type));
}

/**
 * Initialize a new node element
 *
 * @param void* data
 * @param node* pointer
 * @return node* new node element
 */
node *new_node(void *data, node *pointer) {
    node *element = (node *) malloc(sizeof(node));
    element->data = data;
    element->pointer = pointer;

    return element;
}

/**
 * Compares two nodes
 *
 * @param node* first
 * @param node* second
 * @param bool* function function to compare
 * @return bool
 */
bool node_compare(node *first, node *second, bool *function(node *a, node *b)) {

    if (function != NULL) {
        return (bool) *function(first, second);
    }

    // Fallback to size
    return false;
}

// Linked lists
typedef struct list {
    node *list;
    node *last;
    long int nodes;
} list;


#ifdef __cplusplus
};
#endif

#endif //TYPES.H