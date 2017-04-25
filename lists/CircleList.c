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

#include <stdlib.h>
#include <stdio.h>
#include "../Types.h"

circlelist create_circle_list() {
    circlelist myList;
    myList.list = NULL;
    myList.nodes = 0;
    return myList;
}

int check_circle_list(circlelist *myList) {
    if (myList->list == NULL) {
        return -1;
    }
    return 1;
}

/* Insere novos elements na lista  */
void insert_circle_list(circlelist *myList, long int element) {
    if (myList->list == NULL) {
        node *newNode;
        newNode = (node *) (malloc(sizeof(node)));
        if (newNode != NULL) {
            newNode->key = element;
            myList->list = newNode;
            newNode->pointer = myList->list;
            myList->nodes++;
        }
    } else {
        node *newNode;
        newNode = (node *) (malloc(sizeof(node)));
        if (newNode != NULL) {
            newNode->pointer = myList->list;
            myList->list = newNode;
            myList->nodes++;
        }
    }
}

node *search_circle_list(circlelist *myList, long int element) {
    node *aux = myList->list;

    while (aux != myList->list && aux->key != element) {
        aux = aux->pointer;
    }
    if (aux->key == element) {
        return aux;
    } else {
        return NULL;
    }
}

void list_elements_circle_list(circlelist *myList) {
    node *aux = myList->list;
    if (myList->nodes == 0) {
        printf("Lista vazia! \n");
        return;
    } else {
        while (aux != myList->list) {
            printf("%ld ->", aux->key);
            aux = aux->pointer;
        }
    }
}

void remove_circle_list(circlelist *myList, long int element) {
    node *current = myList->list;
    node *previous = NULL;
    while (current != myList->list && current->key != element) {
        previous = current;
        current = current->pointer;
    }
    if (current == myList->list) {
        printf("Elemento nao encontrado\n");
        return;
    }
    if (previous == NULL) {
        myList->list = current->pointer;
    } else {
        previous->pointer = current->pointer;
    }
    free(current);
}

int destroy_circle_list(circlelist *myList) {
    node *aux = myList->list;
    while (aux != myList->list) {
        aux = myList->list;
        free(myList->list);
        myList->list = aux;
    }
    myList->list = NULL;
    return check_circle_list(myList);
}