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

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <util.h>
#include <types.h>
#include <linked_list.h>
#include <assert.h>

#ifdef __cplusplus
extern "C" {
#endif

list *create_linked_list() {
    list *ptr = init(ptr);

    ptr->list = NULL;
    ptr->last = NULL;
    ptr->nodes = 0;

    return ptr;
}

bool is_empty_linked_list(list *ptr) {
    if (ptr->last != NULL && ptr->list != NULL) {
        return false;
    }

    return true;
}

bool prepend_linked_list(list *ptr, node *elem) {
    if (ptr == NULL || elem == NULL) {
        return false;
    }

    node *current = ptr->list;

    if (is_empty_linked_list(ptr)) {
        return append_linked_list(ptr, elem);
    }

    ptr->list = elem;
    elem->pointer = current;
    ptr->nodes++;

    return true;
}

bool append_linked_list(list *ptr, node *elem) {
    if (ptr == NULL || elem == NULL) {
        return false;
    }

    node *last = NULL;
    node *current = ptr->list;

    if (is_empty_linked_list(ptr)) {
        ptr->list = ptr->last = elem;
        ptr->nodes++;
        return true;
    }

    while (current != NULL && current->pointer != NULL) {
        last = current;
        current = last->pointer;
    }

    current->pointer = elem;
    ptr->last = elem;
    ptr->nodes++;

    return true;
}

bool destroy_linked_list(list *ptr) {

    node *last = NULL;
    node *current = ptr->list;

    while (current != NULL && current->pointer != NULL) {
        node_destroy(last);

        last = current;
        current = last->pointer;
    }

    free(ptr);

    return is_empty_linked_list(ptr);
}

#ifdef __cplusplus
};
#endif

#endif // LINKED_LIST_H
