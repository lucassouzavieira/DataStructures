/*
 Implementacao de Arvore AVL

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

#ifndef AVLTREE_H
#define AVLTREE_H

#include "../TAD.h"

/* Criar uma arvore AVL */
AVLTree CreateAVLTree();

/* Inserir elementos na arvore AVL */
void InsertInAVLTree(AVLTree *myTree, long int key);

/* Buscar elementos na arvore AVL */
nodeavl *SearchAVLTree(AVLTree *myTree, long int key);

/* Remover elemento na arvore AVL */
void RemoveAVLTree(AVLTree *myTree, long int key);

/* Destruir a arvore AVL */
void DestroyAVLTree(AVLTree *myTree);

/* Desenha a arvore AVL */
void DrawAVLTree(AVLTree *myTree);

#endif /* AVLTREE_H */