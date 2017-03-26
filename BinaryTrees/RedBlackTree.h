/*
 Implementacao de Arvore red-black

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


#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "../TAD.h"

/* Criar uma arvore Red-Black */
RBTree CreateRedBlackTree();

/* Inserir elementos na arvore Red-Black */
void InsertInRedBlackTree(RBTree* mytree, long int key);

/* Buscar elementos na arvore Red-Black */
noderb* SearchRedBlackTree(RBTree* mytree, long int key);

/* Remover elemento na arvore Red-Black */
noderb* RemoveRedBlackTree(RBTree* mytree, long int key);

/* Destruir a arvore Red-Black */
void DestroyRedBlackTree(RBTree* myTree); 

/* Desenhar a arvore Red-Black */
void DrawRedBlackTree(RBTree* myTree);

#endif /* !REDBLACKTREE_H */