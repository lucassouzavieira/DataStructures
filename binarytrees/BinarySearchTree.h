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

#include "../Types.h"

bstree create_bstree();

void insert_bstree(bstree *myTree, long int key);

void remove_bstree(bstree *myTree, long int key);

nodetree *search_bstree(bstree *myTree, long int key);

void pre_order_bstree(bstree *myTree);

void in_order_bstree(bstree *myTree);

void post_order_bstree(bstree *myTree);

void draw_bstree(bstree *myTree);

int height_bstree(bstree *myTree);

void destroy_bstree(bstree *myTree);

#endif /* !BST_H */