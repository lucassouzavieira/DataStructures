/*
 Implementacao de Arvore Binaria de Busca

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

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "../TAD.h"

/* Criar a �rvore   */
BSTree CreateBST();

/* Insere um elemento na �rvore  */
void InsertInBST(BSTree* myTree, long int key);

/* Remove um elemento da �rvore  */
void RemoveBST(BSTree* myTree, long int key);

/* Busca um elemento na �rvore  */
nodetree* SearchBST(BSTree* myTree, long int key);

/* Maneiras de percorrer a �rvore  */
void PreOrderBST(BSTree* myTree);
void InOrderBST(BSTree* myTree);
void PostOrderBST(BSTree* myTree);

/* Ilustra a estrutura da �rvore - r-e-d (Pr�ordem)   */
void DrawBST(BSTree* myTree);

/* Descobrir a altura da �rvore */ 
int HeightOfBST(BSTree* myTree);

/* Destruir a �rvore */ 
void DestroyBST(BSTree* myTree);
#endif /* !BST_H */