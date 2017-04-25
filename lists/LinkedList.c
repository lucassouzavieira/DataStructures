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

#include <stdlib.h>
#include <stdio.h>
#include "../Types.h"

list create_linked_list() {
    list myList;
    myList.list = NULL;
    myList.last = NULL;
    myList.nodes = 0;
    return myList;
}

int check_linked_list(list *myList) {
    if (myList->nodes == 0) {
        return -1;
    }
    return 1;
}

/* Insere no inicio da lista */
void insert_start_linked_list(list *myList, long int element) {
    node *newNode;
    newNode = (node *) (malloc(sizeof(node)));
    if (newNode != NULL) {
        newNode->key = element;
        newNode->pointer = myList->list;
        myList->list = newNode;
        myList->nodes++;
    }
    /* Atualiza o ultimo no da lista, caso necessario */
    if (myList->last == NULL) {
        node *current;
        node *previous;
        current = myList->list;
        while (current->pointer != NULL) {
            current = current->pointer;
            previous = current;
        }
        myList->last = current;
    }
}

/* Insere no meio da lista */
void insert_middle_linked_list(list *myList, long int element) {
    node *newNode;
    newNode = (node *) (malloc(sizeof(node)));

    if (newNode != NULL) {
        newNode->key = element;
    }

    node *previous = NULL;
    node *current = myList->list;

    while (current != NULL && current->key < element) {
        previous = current;
        current = current->pointer;
    }

    if (previous == NULL) {
        newNode->pointer = myList->list;
        myList->list = newNode;
    } else {
        if (previous->pointer == NULL) {
            newNode->pointer = previous->pointer;
            previous->pointer = newNode;
            myList->last = newNode;
        } else {
            newNode->pointer = previous->pointer;
            previous->pointer = newNode;
        }
    }
    myList->nodes++;
}

void insert_end_linked_list(list *myList, long int element) {
    node *newNode;
    newNode = (node *) (malloc(sizeof(node)));

    if (newNode != NULL) {
        newNode->key = element;
        newNode->pointer = NULL;
    }

    node *current = myList->list;
    node *previous = NULL;

    while (current->pointer != NULL) {
        current = current->pointer;
        previous = current;
    }

    current->pointer = newNode;
    myList->last = newNode;
    myList->nodes++;
}

node *search_linked_list(list *myList, long int element) {
    node *current;
    current = myList->list;

    while (current != NULL && current->key != element) {
        current = current->pointer;
    }

    return current;
}

void list_elements_linked_list(list *myList) {
    node *current;
    current = myList->list;
    while (current != NULL) {
        printf("%ld \n", current->key);
        current = current->pointer;
    }
}

list reverse_linked_list(list *myList) {
    list reverseList = create_linked_list();
    node *current = myList->list;
    while (current != NULL) {
        insert_start_linked_list(&reverseList, current->key);
        current = current->pointer;
    }
    return reverseList;
}

void remove_linked_list(list *myList, long int element) {
    node *current = myList->list;
    node *previous = NULL;
    while (current != NULL && current->key != element) {
        previous = current;
        current = current->pointer;
    }
    if (current == NULL) {
        printf("Element not found!\n");
        return;
    }
    if (previous == NULL) {
        myList->list = current->pointer;
        myList->nodes--;
    } else {
        previous->pointer = current->pointer;
        myList->nodes--;
    }
    free(current);
}

int destroy_linked_list(list *myList) {
    node *current = NULL;
    while (myList->list != NULL) {
        current = myList->list->pointer;
        free(myList->list);
        myList->list = current;
    }
    return check_linked_list(myList);
}