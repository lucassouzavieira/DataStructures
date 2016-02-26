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
/*Funções utilitárias para as rotações*/
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

//Funções utilitárias para 'parentes'
//Retorna o número de filhos diretos de um nó
int CountChildren(noderb* mynode) 
{
	int Children = 0;
	if (mynode == NULL) {
		return Children;
	}
	if (mynode->left != NULL) {
		Children = Children + 1;
	}
	if (mynode->right != NULL) {
		Children = Children + 1;
	}
	return Children;
}

//Retorna o irmão de um nó, se existir
noderb* Brother(noderb* mynode) 
{
	if (mynode == NULL) {
		// Não existe nó
		return NULL;
	}
	else {
		if (Father(mynode) == NULL) {
			// Nó não tem father (Raiz)
			return NULL;
		}
		else {
			if (mynode->key >= Father(mynode)->key) {
				// Filho maior que o father, logo, este filho é da direita
				// e seu irmão da esquerda
				return Father(mynode)->left;
			}
			else {
				// Filho menor que o father, logo, este filho é da esquerda
				// e seu irmão da direita
				return Father(mynode)->right;
			}
		}
	}
}

//Retorna o tio de um nó
noderb* Uncle(noderb* mynode)
{
	if (mynode == NULL) {
		return NULL;
	}
	else {
		noderb* child = mynode;
		noderb* father = Father(mynode);
		noderb* grandfather = GrandFather(mynode);
		if ((Father(mynode) == NULL) && (GrandFather(mynode) == NULL)) {
			return NULL;
		}
		// Descobrir se o tio é filho righteito ou leftuerdo do avô
		if (father == grandfather->left) {
			// Se o father é o filho da left, então o tio é filho da righteita
			return grandfather->right;
		}
		else {
			// E se o father é o filho da righteita, então o tio é da left
			return grandfather->left;
		}
	}
}

//Retorna o pai de um nó
noderb* Father(noderb* mynode)
{
	if (mynode == NULL) {
		return NULL;
	}
	else {
		return mynode->father;
	}
}

//Retorna o avô de um nó
noderb* GrandFather(noderb* mynode)
{
	if (mynode == NULL) {
		return NULL;
	}
	else {
		return mynode->father->father;
	}
}

//Retorna o bisavô de um nó
noderb* GreatGrandFather(noderb* mynode) 
{
	if (mynode == NULL) {
		return NULL;
	}
	else {
		return GrandFather(Father(mynode));
	}
}

/*Funções utilitárias para Altura Negra e Cores*/
// Balanceia a altura negra de todos os nós
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
			// mytree->BlackHeight = BlackHeight(mytree->right);
		} else {
			// Retorna -1 para a altura negra do nó que está desbalanceado
			mytree->blackHeight = -1;
		}

	} else {
		// Retorna se não houver árvore
		return;
	}
	// Retorna ao fim do ajuste
	return;
}

// Muda a color de um nó
void ChangeColor(noderb* mynode) {
	if (mynode == NULL) {
		return;
	}
	if (mynode->color == RED) {
		// Se nó for vermelho, muda para preto
		mynode->color = BLACK;
	} else {
		// Se for preto, muda pra vermelho
		mynode->color = RED;
	}
	return;
}

// Verifica as condições das cores de todos os nós e promove ajustes
void ColorFixUp(noderb* mytree) {
	if (mytree == NULL) {
		return;
	} else {
		ColorFixeUp(mytree->right);
		ColorFixeUp(mytree->left);
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
	noderb* newNode;
	newNode->key = key;
	newNode->blackHeight = 0;
	newNode->color = RED;
	newNode->father = NULL;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
/* Desenha a Árvore Red-Black*/
void DrawRedBlackTree(noderb* mytree, branches *previous, int left);

/******************************************************************************
Funções Gerais
******************************************************************************/
/*Criar uma Árvore Red-Black*/
RBTree CreateRedBlackTree() {
	RBTree myTree;
	myTree.nodes = 0;
	myTree.root = NULL;
	return myTree;
}

/*Inserir elementos na Árvore Red-Black*/
void FixUpRedBlackTree(noderb* tree, noderb* newNode) {
	while (Father(newNode)->color == RED) {
		if (Father(newNode) == GrandFather(newNode)->left) {
			noderb* uncle = Uncle(newNode);
			uncle = GrandFather(newNode)->right;
			if (uncle->color == RED) {
				Father(newNode)->color = BLACK;
				uncle->color = BLACK;
				GrandFather(newNode)->color = RED;
				newNode = GrandFather(newNode);
			} else {

			}
		} 
	}
}

void InsertInRedBlackTree(RBTree* mytree, long int key)
{
	noderb* newNode = CreateRedBlackNode(key);
	noderb* current = mytree->root;
	noderb* father = NULL;
	// Encontra e define o pai
	while (current != NULL)
	{
		if (current->key <= newNode->key) {
			father = current;
			current = current->right;
		} else {
			father = current;
			current = current->left;
		}
	}
	if (father->key > newNode->key) {
		father->left = newNode;
		newNode->father = father;
	}
	else if (father->key <= newNode->key) {
		father->right = newNode;
		newNode->father = father;
	}
	mytree->nodes++;
	FixUpRedBlackTree(mytree->root, newNode);
}

/*Buscar elementos na Árvore Red-Black*/
noderb* SearchRedBlackTree(RBTree* mytree, long int key);

/*Remover elemento na Árvore Red-Black*/
noderb* RemoveRedBlackTree(RBTree* mytree, long int key) {
	if (mytree == NULL) {

	} else {

	}
}

/*Destruir a árvore Red-Black*/
void DestroyRedBlackTree(RBTree* myTree);