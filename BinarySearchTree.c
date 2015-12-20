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

Arquivo: BST.c
Descrição: Implementação para árvore binária 
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#define _CRT_SECURE_NO_WARNINGS 1;
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "TAD.h"

//Criar a árvore
nodetree* CreateBST(){
	nodetree* myTree;
	myTree = NULL;
	return myTree;
}

//Insere um elemento na árvore
nodetree* InsertInBST(nodetree* myTree){
	if (myTree == NULL){
		// Árvore vazia
		nodetree* newNode = (nodetree *)(malloc(sizeof(nodetree)));
		if (newNode != NULL){
			printf("Inserir valor da raiz da Arvore Binaria: ");
			scanf("%ld", &newNode->key);
			newNode->right = NULL;
			newNode->left = NULL;
		}
		myTree = newNode;
		return myTree;
	} else {
		nodetree* newNode = (nodetree *)(malloc(sizeof(nodetree)));
		if (newNode != NULL){
			printf("Inserir novo elemento: ");
			scanf("%ld", &newNode->key);
			newNode->right = NULL;
			newNode->left = NULL;
		}
		else {
			printf("Falha na alocacao de memoria!! ");
			return myTree;
		}
		// Buscar a posição da nova folha
		nodetree* father = NULL;
		nodetree* current = myTree;
		while (current != NULL){
			if (current->key <= newNode->key){
				father = current;
				current = current->right;
			} else if (current->key > newNode->key){
				father = current;
				current = current->left;
			}
		}
		if (father->key > newNode->key){
			father->left = newNode;
		}
		else if (father->key <= newNode->key){
			father->right = newNode;
		}
	}
	return myTree;
}

// Remoção de um elemento qualquer da árvore
nodetree* RemoveBST(nodetree* myTree, long int key){
	nodetree* current = myTree;
	if (current == NULL) {
		return myTree;
	} else if (current->key > key) {
		current->left = RemoveBST(current->left, key);
	} else if (current->key < key) {
		current->right = RemoveBST(current->right, key);
	} else {
		if (current->left == NULL && current->right == NULL) {
			// Nó não tem filhos
			free(current);
			return NULL;
		} else if (current->left == NULL) {
			// Nó só tem filho direito
			nodetree* toRemove = current;
			current = current->right;
			free(toRemove);
		} else if (current->right == NULL) {
			// Nó só tem filho esquerdo
			nodetree* toRemove = current;
			current = current->left;
			free(toRemove);
		} else {
			// Nó tem dois filhos
			nodetree* aux = current->left;
			nodetree* father = current;
			while (aux->right != NULL){
				aux = aux->right;
				father = aux;
			}
			current->key = aux->key;
			free(aux);
			father->right = NULL;
		}
	}
	return myTree;
}

//Busca um elemento na Árvore
nodetree* SearchBST(nodetree* myTree, long int key){
	nodetree* aux = myTree;
	while (aux != NULL){
		if (key < aux->key){
			aux = aux->left;
		}
		else if (key > aux->key){
			aux = aux->right;
		} else {
			printf("Elemento encontrado!: %ld \n ", aux->key);
			return aux;
		}
	}
	printf("Elemento nao encontrado! \n");
	return NULL;
}

//Percorrer a árvore
//Pré-ordem
void PreOrderBST(nodetree* myTree){
	if (myTree == NULL){
		return;
	} else {
		printf("%ld",myTree->key);
		PreOrderBST(myTree->left);
		PreOrderBST(myTree->right);
	}
}

//Em Ordem
void InorderBST(nodetree* myTree){
	if (myTree == NULL){
		return;
	}
	else {
		InorderBST(myTree->left);
		printf("%ld", myTree->key);
		InorderBST(myTree->right);
	}
}

//Pos-Órdem
void PostOrderBST(nodetree* myTree){
	if (myTree == NULL){
		return;
	}
	else{
		PostOrderBST(myTree->left);
		PostOrderBST(myTree->right);
		printf("%ld", myTree->key);
	}
}

//Descobrir a altura da árvore
int HeightOfBST(nodetree* myTree){
	if (myTree == NULL){
		return 1;
	} else {
		int leftSubtreeHeight = HeightOfBST(myTree->left) + 1;
		int rightSubtreeHeight = HeightOfBST(myTree->right) + 1;
		if (leftSubtreeHeight < rightSubtreeHeight){
			return rightSubtreeHeight;
		} else {
			return leftSubtreeHeight;
		}
	}
}

//Destruir a árvore
void DestroyBST(nodetree* myTree){
	if (myTree == NULL){
		return;
	} else {
		DestroyBST(myTree->left);
		DestroyBST(myTree->right);
		free(myTree);
		myTree = NULL;
	}
}

// Desenha a árvore binária
// Mostra traços ligando os nós
void ShowBranch(branches *t){
	if (!t){
		return;
	}
	ShowBranch(t->previous);
	printf(t->str);
}

// Desenha a árvore
void DrawBST(nodetree* myTree, branches *previous, int Left){
	if (myTree == NULL){
		return;
	}

	branches show = { previous, "    " };
	char *show_str = show.str;

	DrawBST(myTree->left, &show, 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	if (!previous){
		show.str = "---";
	} else if (Left){
		show.str = ".--";
		show_str = "  |";
	} else {
		show.str = "`--";
		previous->str = show_str;
	}
	ShowBranch(&show);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("%ld \n",myTree->key);
	
	if (previous){
		previous->str = show_str;
	}
	show.str = "   |";

	DrawBST(myTree->right, &show, 0);
	if (!previous){
		printf("");
	}
}