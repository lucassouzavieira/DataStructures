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

Arquivo: CircleList.h
Descrição: Definições para lista circular simples
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef CIRCLELIST_H
#define CIRCLELIST_H

#include "..\TAD.h"
#include "LinkedList.h" 

//Cria uma lista circular 
circlelist CreateCircleList(); 

//Verifica se a lista está vazia ou não  
int CheckCircleList(circlelist* myList);

//Insere novos elementos na lista 
void InsertAtCircleList(circlelist* myList, long int element);

//Busca um dado valor na lista 
node* SearchElementCircleList(circlelist* myList, long int element);

//Imprime todos os elementos da lista 
void ListElementsCircleList(circlelist* myList);

//Remove um dado elemento da lista 
void RemoveElementCircleList(circlelist* myList, long int element);

//Apaga toda a lista e libera a memória 
int DestroyCircleList(circlelist* myList);

#endif // !CIRCLELIST_H