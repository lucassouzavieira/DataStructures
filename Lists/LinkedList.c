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
#include "../TAD.h"

/* Cria uma lista encadeada */
list CreateLinkedList() {
    list myList;
    myList.list = NULL;
    myList.last = NULL;
    myList.nodes = 0;
    return myList;
}

/* Verifica uma lista encadeada (se vazia) */
int CheckLinkedList(list *myList) {
    if (myList->nodes == 0) {
        return -1;
    }
    return 1;
}

/* Insere no inicio da lista */
void InsertAtStartLinkedList(list *myList, long int element) {
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
void InsertAtMiddleLinkedList(list *myList, long int element) {
    node *newNode;
    newNode = (node *) (malloc(sizeof(node)));
    if (newNode != NULL) {
        newNode->key = element;
    }
    /* Buscar a posicao do novo no
    Criterio = element armazenado */
    node *previous = NULL;
    node *current = myList->list;
    while (current != NULL && current->key < element) {
        previous = current;
        current = current->pointer;
    }
    /* Insere no comeco caso previous = NULL*/
    if (previous == NULL) {
        newNode->pointer = myList->list;
        myList->list = newNode;
    } else {
        /* Insere no meio ou no fim*/
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

/* Insere no fim da lista */
void InsertAtEndLinkedList(list *myList, long int element) {
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

/* Busca */
node *SearchLinkedList(list *myList, long int element) {
    node *current;
    current = myList->list;
    while (current != NULL && current->key != element) {
        current = current->pointer;
    }
    return current;
}

/* Mostrar os elements */
void ListElementsLinkedList(list *myList) {
    node *current;
    current = myList->list;
    while (current != NULL) {
        printf("%ld \n", current->key);
        current = current->pointer;
    }
}

/* Retorna uma lista com os elementos em ordem invertida */
list ReverseLinkedList(list *myList) {
    list reverseList = CreateLinkedList();
    node *current = myList->list;
    while (current != NULL) {
        InsertAtStartLinkedList(&reverseList, current->key);
        current = current->pointer;
    }
    return reverseList;
}

/* Remove elements */
void RemoveElementLinkedList(list *myList, long int element) {
    node *current = myList->list;
    node *previous = NULL;
    while (current != NULL && current->key != element) {
        previous = current;
        current = current->pointer;
    }
    if (current == NULL) {
        printf("Elemento nao encontrado\n");
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

/* Destruir a lista */
int DestroyLinkedList(list *myList) {
    node *current = NULL;
    while (myList->list != NULL) {
        current = myList->list->pointer;
        free(myList->list);
        myList->list = current;
    }
    return CheckLinkedList(myList);
}