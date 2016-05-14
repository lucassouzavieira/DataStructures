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
com este programa, Se não, veja <http:/*www.gnu.org/licenses/>.

Arquivo: DoublyLinkedList.h
Descrição: Definições para listas duplas
Autor: Lucas de Souza Vieira <lucassouzavieiraengcomp@gmail.com>	*/

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "..\TAD.h"

/* Cria uma lista duplamente encadeada */
doublylist CreateDLinkedList();

/* Verifica se há elementos na lista */
int CheckDLinkedList(doublylist* myDoublyList);

/* Insere elementos no início da lista */
void InsertAtStartDLinkedList(doublylist* myDoublyList, long int element);

/* Insere elementos no meio da lista */
void InsertAtMiddleDLinkedList(doublylist* myDoublyList, long int element);

/* Insere elementos no fim da lista */
void InsertAtEndDLinkedList(doublylist* myDoublyList, long int element);

/* Busca um dado elemento na lista */
dnode* SearchElementDLinkedList(doublylist* myDoublyList, long int element);

/* Imprime todos os elementos da lista */
void ListElementsDLinkedList(doublylist* myDoublyList);

/* Remove um dado elemento da lista */
void RemoveElementDLinkedList(doublylist* myDoublyList, long int element);

/* Apaga toda a lista e libera memória */
int DestroyDLinkedList(doublylist* myDoublyList);

#endif 