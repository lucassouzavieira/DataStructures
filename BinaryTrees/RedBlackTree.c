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

Arquivo: RedBlackTree.c
Descrição: Implementação para estruturas do tipo árvore rubro-negras
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#include "RedBlackTree.h"
#include <stdlib.h>
#include <stdio.h>
/******************************************************************************
Funções Utilitárias
******************************************************************************/

//Retorna o pai do nó atual
noderb* Father(noderb* mynode)
{
	return mynode->father;
}

//Retorna o irmão do nó atual
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

//Rotação à direita sobre o nó
noderb* RotateRightRedBlackTree(noderb* mynode) 
{
	noderb* aux = mynode->left;
	if (aux->right != NULL) {
		/* Se o filho do nó atual tem sub-árvore à direita
		Então o nó atual terá como filho a sub-árvore esquerda do filho*/
		mynode->left = aux->right;
	}
	else {
		mynode->left = NULL;
	}
	// O nó atual vira filho direito do seu próprio filho
	aux->right = mynode;
	return aux;
}

//Rotação à esquerda sobre o nó
noderb* RotateLeftRedBlackTree(noderb* mynode) 
{
	noderb* aux = mynode->right;
	if (aux->left != NULL) {
		/* Se o filho do nó atual tem sub-árvore à esquerda
		Então o nó atual terá como filho a sub-árvore direita do filho*/
		mynode->right = aux->left;
	}
	else {
		mynode->right = NULL;
	}
	// O nó atual vira filho esquerda do seu próprio filho
	aux->left = mynode;
	return aux;
}

//Balanceia a altura negra de todos os nós
int BlackHeight(noderb* mynode) 
{
	if (mynode == NULL) {
		/*Nó nulo é por definição negro*/
		return 1;
	} else if (mynode->color == BLACK) {
		/*Nó preto conta na altura negra*/
		int rightBlackHeight = BlackHeight(mynode->right);
		int leftBlackHeight = BlackHeight(mynode->left);
		if (rightBlackHeight == leftBlackHeight) {
			//return rightBlackHeight + 1;
			return leftBlackHeight + 1;
		} else {
			// Árvore desbalanceada
			return EXIT_FAILURE;
		}
	} else {
		/*Nó vermelho não conta na altura negra*/
		int rightBlackHeight = BlackHeight(mynode->right);
		int leftBlackHeight = BlackHeight(mynode->left);
		if (rightBlackHeight == leftBlackHeight) {
			//return rightBlackHeight;
			return leftBlackHeight;
		} else {
			// Árvore desbalanceada
			return EXIT_FAILURE;
		}
	}
}

//Calcula a altura da árvore
int Height(noderb* mytree) 
{
	if (mytree == NULL) {
		/* A árvore ou nó não tem elementos,
		nesse caso tem altura n-1*/
		return -1;
	} else {
		/*Nesse caso, calcular a altura das sub-árvores
		Nesse caso, recursivamente*/
		int heightLeft = Height(mytree->left) + 1;
		int heightRight = Height(mytree->right) + 1;
		if (heightLeft < heightRight) {
			return heightRight;
		} else {
			return heightLeft;
		}
	}
}

//Recalcula a altura negra de todos os nós da árvore
void SetBlackHeight(noderb* mytree)
{
	if (mytree != NULL) {
		//Percorre as sub-árvores configurando as alturas negras
		SetBlackHeight(mytree->left);
		SetBlackHeight(mytree->right);
		// Ajusta o fator de balaceamento do nó current
		if ((BlackHeight(mytree->left) == BlackHeight(mytree->right))) {
			// Nesse caso, a árvore está perfeitamente balaceada
			mytree->blackHeight = BlackHeight(mytree->left);
			//mytree->BlackHeight = BlackHeight(mytree->right);
		} else {
			// Retorna -1 para a altura negra do nó que está desbalanceado
			mytree->blackHeight = -1;
		}
	} else {
		// Retorna se não houver árvore
		return;
	}
	return;
}

//Altera a cor de um nó
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

// Verifica as condições das cores de todos os nós e promove ajustes
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

// Inicializa um nó
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

// Troca as cores
void swapColors(noderb* firstNode, noderb* secondNode) 
{
	Color tempColor = firstNode->color;
	firstNode->color = secondNode->color;
	secondNode->color = tempColor;
}

/******************************************************************************
Funções Gerais
******************************************************************************/

// Criar uma Árvore Red-Black
RBTree CreateRedBlackTree()
{
	RBTree myTree;
	myTree.nodes = 0;
	myTree.root = NULL;
	return myTree;
}

// Ajusta as propriedades da árvore após a inserção
void InsertFixUp(noderb* root, noderb* newNode) 
{
	noderb* father = NULL;
	noderb* uncle = NULL;
	noderb* grandFather = NULL;
	while ((newNode != root) && (newNode->color != BLACK)
		&& (Father(newNode)->color == RED)) {
		father = Father(newNode);
		grandFather = Father(Father(newNode));

		// Caso 1:
		// O pai do novo nó é o filho esquerdo do avô
		if (father == grandFather->left) {
			uncle = grandFather->right;
			if ((uncle != NULL) && (uncle->color == RED)) {
				grandFather->color = RED;
				father->color = BLACK;
				uncle->color = BLACK;
				newNode = grandFather;
			}
			else {
				// Caso 2:
				// O novo nó é filho direito
				if (newNode == father->right) {
					RotateLeftRedBlackTree(father);
					newNode = father;
					father = newNode->father;
				}

				// Caso 3:
				// O novo nó é filho esquerdo
				RotateRightRedBlackTree(grandFather);
				swapColors(father, grandFather);
				newNode = father;
			}
		} else {
			noderb* uncle = grandFather->left;
			// Caso 1:
			// O tio é vermelho 
			if ((uncle != NULL) && (uncle->color == RED)){
				grandFather->color = RED;
				father->color = BLACK;
				uncle->color = BLACK;
				newNode = grandFather;
			} else {
				// Caso 2:
				// Novo nó é filho esquerdo
				if (newNode == father->left){
					RotateRightRedBlackTree(father);
					newNode = father;
					father = newNode->father;
				}
				// Caso 3:
				// Novo nó é filho direito
				RotateLeftRedBlackTree(grandFather);
				swapColors(father, grandFather);
				newNode = father;
			}
		}
	 }
	root->color = BLACK;
	SetBlackHeight(root);
}

// Inserir elementos na Árvore Red-Black
void InsertInRedBlackTree(RBTree* myTree, long int key)
{
	noderb* newNode = (noderb *)(malloc(sizeof(noderb)));
	if (myTree->root == NULL) {
		// Árvore vazia
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
		// Buscar a posição da nova folha
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

/*Buscar elementos na Árvore Red-Black*/
noderb* SearchRedBlackTree(RBTree* mytree, long int key);

/*Remover elemento na Árvore Red-Black*/
noderb* RemoveRedBlackTree(RBTree* mytree, long int key);

void DestroyRedBlackTree(RBTree* myTree);

/*Destruir a árvore Red-Black*/
void DrawRedBlackTree(RBTree* myTree);