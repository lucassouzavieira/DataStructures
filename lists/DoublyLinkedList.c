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

#include <stdlib.h>
#include <stdio.h>
#include "../Types.h"

doublylist create_doubly_linked_list() {
    doublylist myDoublyList;
    myDoublyList.list = NULL;
    myDoublyList.startOfList = NULL;
    myDoublyList.endOfList = NULL;
    myDoublyList.nodes = 0;
    return myDoublyList;
}

int check_doubly_linked_list(doublylist *myDoublyList) {
    if (myDoublyList->list == NULL) {
        return -1;
    }
    return 1;
}

void insert_start_doubly_linked_list(doublylist *myDoublyList, long int element) {
    dnode *newNode;
    newNode = (dnode *) (malloc(sizeof(dnode)));

    if (newNode != NULL) {
        if (myDoublyList->list == NULL) {
            newNode->key = element;
            myDoublyList->list = newNode;
            myDoublyList->startOfList = newNode;
            myDoublyList->endOfList = newNode;
            newNode->previous = NULL;
            newNode->next = NULL;
        } else {
            newNode->key = element;
            newNode->next = myDoublyList->list;
            newNode->previous = NULL;
            myDoublyList->list->previous = newNode;
            myDoublyList->startOfList = newNode;
            myDoublyList->list = newNode;
        }
    }
}

void insert_middle_doubly_linked_list(doublylist *myDoublyList, long int element) {
    dnode *newNode;
    newNode = (dnode *) (malloc(sizeof(dnode)));
    if (newNode != NULL) {
        if (myDoublyList->list == NULL) {
            newNode->key = element;
            myDoublyList->list = newNode;
            myDoublyList->startOfList = newNode;
            myDoublyList->endOfList = newNode;
            newNode->previous = NULL;
            newNode->next = NULL;
        } else {
            newNode->key = element;
            dnode *aux = myDoublyList->startOfList;
            dnode *previous = NULL;
            while (aux != NULL && newNode->key > aux->key) {
                previous = aux; /* Guarda a posicao do no previous e aux */
                aux = aux->next;
            }
            if (aux == myDoublyList->startOfList) {
                newNode->next = myDoublyList->list;
                newNode->previous = NULL;
                myDoublyList->startOfList->previous = newNode;
                myDoublyList->list = newNode;
                myDoublyList->startOfList = newNode;
            } else if (aux == NULL) {
                myDoublyList->endOfList->next = newNode;
                newNode->previous = myDoublyList->endOfList;
                newNode->next = NULL;
                myDoublyList->endOfList = newNode;
            } else {
                /* Meio */
                newNode->next = aux;
                previous->next = newNode; /* No anterior aponta para o novo no */
                newNode->previous = previous;
                aux->previous = newNode;
            }
        }
    }
}

/* Insere elementos no fim da lista */
void insert_end_doubly_linked_list(doublylist *myDoublyList, long int element) {
    dnode *newNode;
    newNode = (dnode *) (malloc(sizeof(dnode)));
    if (newNode != NULL) {
        if (myDoublyList->list == NULL) {
            newNode->key = element;
            myDoublyList->list = newNode;
            myDoublyList->startOfList = newNode;
            myDoublyList->endOfList = newNode;
            newNode->previous = NULL;
            newNode->next = NULL;
        } else {
            newNode->key = element;
            myDoublyList->endOfList->next = newNode;
            newNode->previous = myDoublyList->endOfList;
            newNode->next = NULL;
            myDoublyList->endOfList = newNode;
        }
    }
}

/* Busca um dado elemento na lista */
dnode *search_doubly_linked_list(doublylist *myDoublyList, long int element) {
    int parametro;
    dnode *aux;
    printf("Busca Lista Duplamente Encadeada\n1 - Do inicio para o final \t2 - Do final para o inicio\n");
    scanf("%ld", &parametro);
    if (parametro == 1) {
        aux = myDoublyList->startOfList;
        while (aux != NULL) {
            if (aux->key == element) {
                return aux;
            } else {
                aux = aux->next;
            }
        }
    } else if (parametro == 2) {
        aux = myDoublyList->endOfList;
        while (aux != NULL) {
            if (aux->key == element) {
                return aux;
            } else {
                aux = aux->previous;
            }
        }

    } else {
        printf("Escolha invalida! \n");
        return NULL;
    }
    return NULL;
}

void list_elements_doubly_linked_list(doublylist *myDoublyList) {
    int parametro;
    dnode *current;

    printf("Mostrar elementos Lista Duplamente Encadeada\n1 - Do inicio para o final \t2 - Do final para o inicio\n");
    scanf("%ld", &parametro);
    if (parametro == 1) {
        current = myDoublyList->startOfList;
        while (current != NULL) {
            printf("%ld ->", current->key);
            current = current->next;
        }
    } else if (parametro == 2) {
        current = myDoublyList->endOfList;
        while (current != NULL) {
            printf("%ld ->", current->key);
            current = current->previous;
        }
    } else {
        printf("Escolha invalida! \n");
    }
}

/* Remove um dado elemento da lista */
void remove_doubly_linked_list(doublylist *myDoublyList, long int element) {
    dnode *aux = myDoublyList->list;
    while (aux != NULL) {
        if (aux->key == element) {
            if (aux == myDoublyList->startOfList) {
                /* Remove no inicio */
                myDoublyList->startOfList = aux->next;
                myDoublyList->startOfList->previous = NULL;
                free(aux);
                break;
            } else if (aux != myDoublyList->endOfList) {
                /* Remove no meio */
                aux->previous->next = aux->next;
                aux->previous->previous = aux->previous;
                dnode *aux2;
                aux2 = aux->next;
                free(aux);
                aux = aux2;
                break;
            } else {
                /* Remove no fim */
                myDoublyList->endOfList = myDoublyList->endOfList->previous;
                myDoublyList->endOfList->next = NULL;
                free(aux);
                break;
            }
        }
        aux = aux->next;
    }
}

int destroy_doubly_linked_list(doublylist *myDoublyList) {
    dnode *aux = NULL;
    int teste = 0;
    while (myDoublyList->list != NULL) {
        aux = myDoublyList->list->next;
        free(myDoublyList->list);
        myDoublyList->list = aux;
    }
    return check_doubly_linked_list(myDoublyList);
}