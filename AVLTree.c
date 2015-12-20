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

Arquivo: AVLTree.c
Descrição: Implementação para árvore AVL
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

// Funções utilitárias
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "TAD.h"

nodeavl* MaintenanceAVLTree(nodeavl* myTree);
int CalculateBalanceFactor(nodeavl* mynode);

// Recebe a árvore (ou uma sub-árvore) e cálcula sua altura
int HeightAVLTree(nodeavl* myTree){
	if (myTree == NULL){
		return 0;
	} else {
		int leftSubtreeHeight = HeightAVLTree(myTree->left) + 1;
		int rightSubtreeHeight = HeightAVLTree(myTree->right) + 1;
		if (leftSubtreeHeight < rightSubtreeHeight){
			return rightSubtreeHeight;
		} else {
			return leftSubtreeHeight;
		}
	}
}

// Criar uma Árvore AVL
nodeavl* CreateAVLTree(){
	nodeavl* myTree;
	myTree = NULL;
	return myTree;
}

// Inserir elementos na Árvore AVL
nodeavl* InsertInAVLTree(nodeavl* myTree, long int key){
	if (myTree == NULL){
		nodeavl* newNode = (nodeavl*) malloc(sizeof(nodeavl));;
		if (newNode == NULL){
			printf("Falha ao inserir!");
			return myTree;
		}
		newNode->key = key;
		newNode->balanceFactor = 0;
		newNode->right = NULL;
		newNode->left = NULL;
		myTree = newNode;
		return myTree;
	} else {
		if (key < myTree->key) {
			myTree->left = InsertInAVLTree(myTree->left, key);
		} else {
			myTree->right = InsertInAVLTree(myTree->right, key);
		}
	}
	myTree = MaintenanceAVLTree(myTree); // Verifica a manutenção
	return myTree;
}

// Buscar elementos na Árvore AVL
nodeavl* SearchAVLTree(nodeavl* myTree, long int key){
	nodeavl* aux = myTree;
	while (aux != NULL){
		if (key < aux->key){
			aux = aux->left;
		} else if (key > aux->key){
			aux = aux->right;
		} else {
			printf("Elemento encontrado: %ld \n", aux->key);
			return aux;
		}
	}
	printf("Elemento nao encontrado! \n");
	return NULL;
}

// Recebe um nó, faz a busca e o remove da árvore
nodeavl* RemoveAVLTree(nodeavl* myTree, long int key){
	nodeavl *toRemove = myTree;
	nodeavl	*father = NULL;
	nodeavl	*substitute; 
	nodeavl *aux;
	nodeavl *heritor;
	// Busca o nó a ser removido
	while (toRemove != NULL && toRemove->key != key){
		father = toRemove;
		if (key < toRemove->key){
			toRemove = toRemove->left;
		} else if (key>toRemove->key){
			toRemove = toRemove->right;
		}
	} 
	if (toRemove == NULL){
		printf("Elemento nao encontrado ! \n");
		return myTree;
	}
	// Dois primeiros casos: O nó tem 0 ou 1 filho
	if (toRemove->left == NULL){
		substitute = toRemove->right;
	} else if (toRemove->right == NULL){
		substitute = toRemove->left;
	} else {
		// Último caso: nó com 2 filhos
		aux = toRemove;
		substitute = toRemove->right;
		heritor = substitute->left; //Sucessor é sempre o filho mais esquerdo do substituto
		while (heritor != NULL) {
			aux = substitute;
			substitute = heritor;
			heritor = heritor->left;
		}
		if (aux != toRemove){
			aux->left = substitute->right;
			substitute->right = toRemove->right;
		}
		/*O substituto ocupa o lugar de nó removido, 
		o filho esquerda do substituto é manipulado 
		para permitir isso*/
		substitute->left = toRemove->left;
	}
	if (father == NULL){
		myTree = substitute;
	} else {
		if (toRemove == father->left){
			father->left = substitute;
		} else {
			father->right = substitute;
		}
	}
	free(toRemove);
	myTree = MaintenanceAVLTree(myTree);
	return myTree;
}

// Destruir a árvore AVL
void DestroyAVLTree(nodeavl* myTree){
	if (myTree == NULL){
		return;
	} else {
		DestroyAVLTree(myTree->left);
		DestroyAVLTree(myTree->right);
		free(myTree);
		myTree = NULL;
	}
}

// Calcular o Fator de Balaceamento
int CalculateBalanceFactor(nodeavl* mynode){
	if (mynode == NULL){
		return 0;
	} else {
		/* Calcula a diferença de alturas entre as subárvores 
		esquerda e direita de cada nó */ 
		return (HeightAVLTree(mynode->left) - HeightAVLTree(mynode->right));
	}
}

// Ajustar os Fatores de Balanceamento de todos os nós da árvore
void SetbalanceFactor(nodeavl* myTree){
	if (myTree != NULL){
		myTree->balanceFactor = (HeightAVLTree(myTree->left) - HeightAVLTree(myTree->right));
		SetbalanceFactor(myTree->left);
		SetbalanceFactor(myTree->right);
	} else {
		return;
	}
	return;
}

// Funções utilitárias para as rotações
nodeavl* RotateRightAVLTree(nodeavl* mynode){
	nodeavl* aux = mynode->left;
	if (aux->right != NULL) {
		/* Se o filho do nó atual tem sub-árvore à direita
		Então o nó atual terá como filho a sub-árvore esquerda do filho*/
		mynode->left = aux->right;
	}else{
		mynode->left = NULL;
	}
	// O nó atual vira filho direito do seu próprio filho
	aux->right = mynode;
	return aux;
}

nodeavl* RotateLeftAVLTree(nodeavl* mynode){
	nodeavl* aux = mynode->right;
	if (aux->left != NULL){
		/* Se o filho do nó atual tem sub-árvore à esquerda
		Então o nó atual terá como filho a sub-árvore direita do filho*/
		mynode->right = aux->left;
	} else {
		mynode->right = NULL;
	}
	// O nó atual vira filho esquerda do seu próprio filho
	aux->left = mynode;
	return aux;
}

nodeavl* DoubleRotateRightAVLTree(nodeavl* mynode){
	nodeavl* leftChild = mynode->left;
	nodeavl* rightGrandson = leftChild->right;
	if (rightGrandson->left != NULL){
		/*Se existe o filho esquerda do filho direito do filho esquerda do
		nó atual, então o filho direito do filho esquerda do nó atual recebe
		o filho esquerda do filho direito do filho esquerda do nó atual*/
		leftChild->right = rightGrandson->left;
	} else {
		leftChild->right = NULL;
	}
	if (rightGrandson->right != NULL){
		/*Se existe o filho direito do filho direito do filho esquerda do
		nó atual, então o filho direito do filho esquerda do nó atual recebe
		o filho esquerda do filho direito do filho esquerda do nó atual*/
		leftChild->right = rightGrandson->left;
	} else {
		mynode->right = NULL;
	}
	rightGrandson->left = leftChild;
	rightGrandson->right = mynode;
	return rightGrandson;
}

nodeavl* DoubleRotateLeftAVLTree(nodeavl* mynode){
	nodeavl* rightChild = mynode->right;
	nodeavl* leftGrandson = rightChild->left;
	if (leftGrandson->left != NULL) {
		/*Se existe o filho esquerda do filho esquerda do filho direito do
		nó atual, então o filho direito do nó atual passa a ser então o filho
		esquerda do filho esquerda do filho direito do nó atual*/
		mynode->right = leftGrandson->left;
	} else {
		mynode->right = NULL;
	}
	if (leftGrandson->right != NULL){
		/*Se existe o filho direito do filho esquerda do filho direito do
		nó atual, então o filho esquerda do filho direito passa a ser então o filho
		direito do filho esquerda do filho direito do nó atual*/
		rightChild->left = leftGrandson->right;
	} else {
		rightChild->left = NULL;
	}
	leftGrandson->left = mynode;
	leftGrandson->right = rightChild;
	return leftGrandson;
}

//Manter a Árvore Balanceada
nodeavl* MaintenanceAVLTree(nodeavl* myTree){
	if (myTree != NULL){
		SetbalanceFactor(myTree);
		myTree->balanceFactor = CalculateBalanceFactor(myTree);
		if (myTree->balanceFactor == 2) {
			myTree->left->balanceFactor = CalculateBalanceFactor(myTree->left);
			if (myTree->left->balanceFactor > 0) {
				myTree = RotateRightAVLTree(myTree);
			} else {
				myTree = DoubleRotateRightAVLTree(myTree);
			}
		} else if (myTree->balanceFactor == -2){
			myTree->right->balanceFactor = CalculateBalanceFactor(myTree->right);
			if (myTree->right->balanceFactor < 0){
				myTree = RotateLeftAVLTree(myTree);
			} else {
				myTree = DoubleRotateLeftAVLTree(myTree);
			}
		}
		myTree->left = MaintenanceAVLTree(myTree->left);
		myTree->right = MaintenanceAVLTree(myTree->right);
	}
	SetbalanceFactor(myTree);
	return myTree;
}

// Desenha ligações entre os nós da árvore
void ShowBranchAVL(branches *t){
	if (!t){
		return;
	}
	ShowBranchAVL(t->previous);
	printf(t->str);
}

// Desenha a árvore binária
void DrawAVLTree(nodeavl* myTree, branches *previous, int left){
	if (myTree == NULL){
		return;
	}

	branches show = { previous, "    " };
	char *show_str = show.str;

	DrawAVLTree(myTree->left, &show, 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	if (!previous){
		show.str = "---";
	} else if (left){
		show.str = ".--";
		show_str = "  |";
	} else {
		show.str = "`--";
		previous->str = show_str;
	}
	ShowBranchAVL(&show);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("%ld \n", myTree->key);

	if (previous){
		previous->str = show_str;
	}
	show.str = "   |";

	DrawAVLTree(myTree->right, &show, 0);
	if (!previous){
		printf("");
	}
}