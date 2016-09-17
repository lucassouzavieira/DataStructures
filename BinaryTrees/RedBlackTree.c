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


#include "RedBlackTree.h"
#include <stdlib.h>
#include <stdio.h>
/******************************************************************************
Fun��es Utilit�rias
******************************************************************************/

/* Retorna o pai do n� atual */
noderb* Father(noderb* mynode)
{
	return mynode->father;
}

/* Retorna o irm�o do n� atual */
noderb* Brother(noderb* mynode) 
{
	noderb* father = Father(mynode);
	if (father == NULL)
		return NULL;
	if (father->key > mynode->key) {
		return father->right;
	} else {
		return father->left;
	}
}

/* Rota��o � direita sobre o n�  */
noderb* RotateRightRedBlackTree(noderb* mynode) 
{
	noderb* aux = mynode->left;
	if (aux->right != NULL) {
		/* Se o filho do n� atual tem sub-�rvore � direita
		Ent�o o n� atual ter� como filho a sub-�rvore esquerda do filho*/
		mynode->left = aux->right;
	}
	else {
		mynode->left = NULL;
	}
	/* O n� atual vira filho direito do seu pr�prio filho */
	aux->right = mynode;
	return aux;
}

/* Rota��o � esquerda sobre o n�  */
noderb* RotateLeftRedBlackTree(noderb* mynode) 
{
	noderb* aux = mynode->right;
	if (aux->left != NULL) {
		/* Se o filho do n� atual tem sub-�rvore � esquerda
		Ent�o o n� atual ter� como filho a sub-�rvore direita do filho */
		mynode->right = aux->left;
	}
	else {
		mynode->right = NULL;
	}
	/* O n� atual vira filho esquerda do seu pr�prio filho  */
	aux->left = mynode;
	return aux;
}

/* Balanceia a altura negra de todos os n�s  */
int BlackHeight(noderb* mynode) 
{
	if (mynode == NULL) {
		/* N� nulo � por defini��o negro */
		return 1;
	} else if (mynode->color == BLACK) {
		/* N� preto conta na altura negra */
		int rightBlackHeight = BlackHeight(mynode->right);
		int leftBlackHeight = BlackHeight(mynode->left);
		if (rightBlackHeight == leftBlackHeight) {
			/* return rightBlackHeight + 1;  */
			return leftBlackHeight + 1;
		} else {
			/* �rvore desbalanceada */
			return EXIT_FAILURE;
		}
	} else {
		/* N� vermelho n�o conta na altura negra */
		int rightBlackHeight = BlackHeight(mynode->right);
		int leftBlackHeight = BlackHeight(mynode->left);
		if (rightBlackHeight == leftBlackHeight) {
			/* return rightBlackHeight;  */
			return leftBlackHeight;
		} else {
			/* �rvore desbalanceada  */
			return EXIT_FAILURE;
		}
	}
}

/* Calcula a altura da �rvore  */
int Height(noderb* mytree) 
{
	if (mytree == NULL) {
		/* A �rvore ou n� n�o tem elementos,
		nesse caso tem altura n-1*/
		return -1;
	} else {
		/* Nesse caso, calcular a altura das sub-�rvores
		Nesse caso, recursivamente */
		int heightLeft = Height(mytree->left) + 1;
		int heightRight = Height(mytree->right) + 1;
		if (heightLeft < heightRight) {
			return heightRight;
		} else {
			return heightLeft;
		}
	}
}

/* Recalcula a altura negra de todos os n�s da �rvore  */
void SetBlackHeight(noderb* mytree)
{
	if (mytree != NULL) {
		/* Percorre as sub-�rvores configurando as alturas negras */ 
		SetBlackHeight(mytree->left);
		SetBlackHeight(mytree->right);
		/* Ajusta o fator de balaceamento do n� current  */
		if ((BlackHeight(mytree->left) == BlackHeight(mytree->right))) {
			/* Nesse caso, a �rvore est� perfeitamente balaceada */
			mytree->blackHeight = BlackHeight(mytree->left);
			/* mytree->BlackHeight = BlackHeight(mytree->right); */
		} else {
			/* Retorna -1 para a altura negra do n� que est� desbalanceado  */
			mytree->blackHeight = -1;
		}
	} else {
		/* Retorna se n�o houver �rvore  */
		return;
	}
	return;
}

/* Altera a cor de um n� */
void ChangeColor(noderb* mynode) {
	if (mynode == NULL) {
		return;
	}
	if (mynode->color == RED) {
		mynode->color = BLACK;
	} else {
		mynode->color = RED;
	}
	return;
}

/* Verifica as condi��es das cores de todos os n�s e promove ajustes  */
void ColorFixUp(noderb* mytree) {
	if (mytree == NULL) {
		return;
	} else {
		ColorFixUp(mytree->right);
		ColorFixUp(mytree->left);
		if (mytree->blackHeight == -1) {
			if (Brother(mytree) == NULL) {
				if (mytree->right != NULL) {
					mytree->right->color = RED;
					return;
				}
			} else {
				mytree->color = BLACK;
				return;
			}
		} else {
			return;
		}
	}
	return;
}

/* Inicializa um n�  */
noderb* CreateRedBlackNode(long int key) 
{
	noderb* newNode = (noderb*) malloc(sizeof(noderb));
	newNode->key = key;
	newNode->blackHeight = 0;
	newNode->color = RED;
	newNode->father = NULL;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

/* Troca as cores  */
void swapColors(noderb* firstNode, noderb* secondNode) 
{
	Color tempColor = firstNode->color;
	firstNode->color = secondNode->color;
	secondNode->color = tempColor;
}

/******************************************************************************
Fun��es Gerais
******************************************************************************/

/* Criar uma �rvore Red-Black  */
RBTree CreateRedBlackTree()
{
	RBTree myTree;
	myTree.nodes = 0;
	myTree.root = NULL;
	return myTree;
}

/* Ajusta as propriedades da �rvore ap�s a inser��o  */
void InsertFixUp(noderb* root, noderb* newNode) 
{
	noderb* father = NULL;
	noderb* uncle = NULL;
	noderb* grandFather = NULL;
	while ((newNode != root) && (newNode->color != BLACK)
		&& (Father(newNode)->color == RED)) {
		father = Father(newNode);
		grandFather = Father(Father(newNode));

		/* Caso 1:
		   O pai do novo n� � o filho esquerdo do av�  */
		if (father == grandFather->left) {
			uncle = grandFather->right;
			if ((uncle != NULL) && (uncle->color == RED)) {
				grandFather->color = RED;
				father->color = BLACK;
				uncle->color = BLACK;
				newNode = grandFather;
			}
			else {
				/* Caso 2:
				   O novo n� � filho direito  */
				if (newNode == father->right) {
					RotateLeftRedBlackTree(father);
					newNode = father;
					father = newNode->father;
				}

				/* Caso 3:
				   O novo n� � filho esquerdo  */
				RotateRightRedBlackTree(grandFather);
				swapColors(father, grandFather);
				newNode = father;
			}
		} else {
			noderb* uncle = grandFather->left;
			/* Caso 1:
			   O tio � vermelho  */
			if ((uncle != NULL) && (uncle->color == RED)){
				grandFather->color = RED;
				father->color = BLACK;
				uncle->color = BLACK;
				newNode = grandFather;
			} else {
				/* Caso 2:
				   Novo n� � filho esquerdo  */
				if (newNode == father->left){
					RotateRightRedBlackTree(father);
					newNode = father;
					father = newNode->father;
				}
				/* Caso 3:
				   Novo n� � filho direito  */
				RotateLeftRedBlackTree(grandFather);
				swapColors(father, grandFather);
				newNode = father;
			}
		}
	 }
	root->color = BLACK;
	SetBlackHeight(root);
}

/* Inserir elementos na �rvore Red-Black */
void InsertInRedBlackTree(RBTree* myTree, long int key)
{
	noderb* newNode = (noderb *)(malloc(sizeof(noderb)));
	if (myTree->root == NULL) {
		/* �rvore vazia */
		if (newNode != NULL) {
			newNode->key = key;
			newNode->right = NULL;
			newNode->left = NULL;
			newNode->father = NULL;
			newNode->blackHeight = 0;
			newNode->color = RED;
		}
		myTree->root = newNode;
	} else {
		if (newNode != NULL) {
			newNode->key = key;
			newNode->right = NULL;
			newNode->left = NULL;
			newNode->father = NULL;
			newNode->blackHeight = 0;
			newNode->color = RED;
		}
		/* Buscar a posi��o da nova folha  */
		noderb* father = NULL;
		noderb* current = myTree->root;
		while (current != NULL) {
			if (current->key <= newNode->key) {
				father = current;
				current = current->right;
			} else if (current->key > newNode->key) {
				father = current;
				current = current->left;
			}
		}
		if (father->key > newNode->key) {
			father->left = newNode;
			newNode->father = father;
		} else if (father->key <= newNode->key) {
			father->right = newNode;
			newNode->father = father;
		}
	}
	myTree->nodes++;
	InsertFixUp(myTree->root, newNode);
}

/* Buscar elementos na �rvore Red-Black */
noderb* SearchRedBlackTree(RBTree* mytree, long int key);

/* Remover elemento na �rvore Red-Black */
noderb* RemoveRedBlackTree(RBTree* mytree, long int key);

void DestroyRedBlackTree(RBTree* myTree);

/* Destruir a �rvore Red-Black */
void DrawRedBlackTree(RBTree* myTree);