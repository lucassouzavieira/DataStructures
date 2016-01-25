/**
Este arquivo é parte do projeto Data Structures
Este é um software livre; você pode redistribuí-lo e/ou
modificá-lo dentro dos termos da Licença Pública Geral GNU como
publicada pela Fundação do Software Livre (FSF); na versão 3 da
Licença, ou (na sua opinião) qualquer versão.

Este programa é distribuído na esperança de que possa ser  útil,
mas SEM NENHUMA GARANTIA; sem uma garantia implícita de ADEQUAÇÃO
a qualquer MERCADO ou APLICAÇÃO EM PARTICULAR. Veja a
Licença Pública Geral GNU para maiores detalhes.

Você deve ter recebido uma cópia da Licença Pública Geral GNU junto
com este programa, Se não, veja <http://www.gnu.org/licenses/>.

Arquivo: LinkedList.h
Descrição: Definições para Lista encadeada simples
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "..\TAD.h"
// Cria uma lista encadeada
list CreateLinkedList();

// Verifica uma lista encadeada (se vazia)
int CheckLinkedList(list* myList);

// Insere no início da lista
void InsertAtStartLinkedList(list* myList, long int element);

// Insere no meio da lista
void InsertAtMiddleLinkedList(list* myList, long int element);

// Insere no fim da lista
void InsertAtEndLinkedList(list* myList, long int element);

// Busca
node* SearchLinkedList(list* myList, long int element);

// Mostrar os elementos
void ListElementsLinkedList(list* myList);

// Retorna uma lista com os elementos em ordem invertida
list ReverseLinkedList(list* myList);

// Remove elementos
void RemoveElementLinkedList(list* myList, long int element); 

// Destruir a lista
int DestroyLinkedList(list* myList); 

#endif