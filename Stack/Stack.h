/*
 Implementacao de Pilha

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

#ifndef STACK_H
#define STACK_H
#include "../TAD.h"

/* Cria uma pilha */
stack CreateStack();

/* Verifica se a pilha esta vazia ou nao */
int CheckStack(stack* myStack);

/* Remove um elemento da pista */
void Pop(stack* myStack);

/* Insere um elemento na pilha */
void Push(stack* myStack, int element);

/* Imprime todos os elementos da pilha */
void ConsultStack(stack* myStack);

/* Apaga os elementos e libera memoria */
int DestroyStack(stack* myStack);

#endif /* STACK_H */