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

Arquivo: Stack.h
Descrição: Definições para estruturas do tipo pilhas 
Autor: Lucas de Souza Vieira <lucassouzavieiraengcomp@gmail.com>	*/

#ifndef STACK_H
#define STACK_H
#include "..\TAD.h"

/* Cria uma pilha */
stack CreateStack();

/* Verifica se a pilha está vazia ou não */
int CheckStack(stack* myStack);

/* Remove um elemento da pista */
void Pop(stack* myStack);

/* Insere um elemento na pilha */
void Push(stack* myStack, int element);

/* Imprime todos os elementos da pilha */
void ConsultStack(stack* myStack);

/* Apaga os elementos e libera memória */
int DestroyStack(stack* myStack);

#endif /* STACK_H */