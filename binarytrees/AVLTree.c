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


#include <stdlib.h>
#include <stdio.h>
#include "../Types.h"

avl_tree_node *MaintenanceAVLTree(avl_tree_node *myTree);

int CalculateBalanceFactor(avl_tree_node *mynode);

/* Recebe a arvore e calcula sua altura  */
int HeightAVLTree(avl_tree_node *myTree) {
    if (myTree == NULL) {
        return 0;
    } else {
        int leftSubtreeHeight = HeightAVLTree(myTree->left) + 1;
        int rightSubtreeHeight = HeightAVLTree(myTree->right) + 1;
        if (leftSubtreeHeight < rightSubtreeHeight) {
            return rightSubtreeHeight;
        } else {
            return leftSubtreeHeight;
        }
    }
}

/* Criar uma arvore AVL  */
avl_tree CreateAVLTree() {
    avl_tree myTree;
    myTree.root = NULL;
    myTree.nodes = 0;
    return myTree;
}

/* Inserir elementos na arvore AVL */
avl_tree_node *InsertAVLTree(avl_tree_node *myTree, long int key) {
    if (myTree == NULL) {
        avl_tree_node *newNode = (avl_tree_node *) malloc(sizeof(avl_tree_node));;
        if (newNode == NULL) {
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
            myTree->left = InsertAVLTree(myTree->left, key);
        } else {
            myTree->right = InsertAVLTree(myTree->right, key);
        }
    }
    myTree = MaintenanceAVLTree(myTree); /* Verifica a manutencao  */
    return myTree;
}

void InsertInAVLTree(AVLTree *myTree, long int key) {
    myTree->root = InsertAVLTree(myTree->root, key);
    myTree->nodes++;
}

/* Buscar elementos na arvore AVL  */
avl_tree_node *SearchAVLTree(AVLTree *myTree, long int key) {
    avl_tree_node *aux = myTree->root;
    while (aux != NULL) {
        if (key < aux->key) {
            aux = aux->left;
        } else if (key > aux->key) {
            aux = aux->right;
        } else {
            printf("Elemento encontrado: %ld \n", aux->key);
            return aux;
        }
    }
    printf("Elemento nao encontrado! \n");
    return NULL;
}

/* Recebe um no, faz a busca e o remove da arvore  */
avl_tree_node *RemoveAVL(avl_tree_node *myTree, long int key) {
    avl_tree_node *toRemove = myTree;
    avl_tree_node *father = NULL;
    avl_tree_node *substitute;
    avl_tree_node *aux;
    avl_tree_node *heritor;
    /* Busca o n� a ser removido  */
    while (toRemove != NULL && toRemove->key != key) {
        father = toRemove;
        if (key < toRemove->key) {
            toRemove = toRemove->left;
        } else if (key > toRemove->key) {
            toRemove = toRemove->right;
        }
    }
    if (toRemove == NULL) {
        printf("Elemento nao encontrado ! \n");
        return myTree;
    }
    /* Dois primeiros casos: O no tem 0 ou 1 filho  */
    if (toRemove->left == NULL) {
        substitute = toRemove->right;
    } else if (toRemove->right == NULL) {
        substitute = toRemove->left;
    } else {
        /* ultimo caso: no com 2 filhos  */
        aux = toRemove;
        substitute = toRemove->right;
        heritor = substitute->left; /* Sucessor e sempre o filho mais esquerdo do substituto */
        while (heritor != NULL) {
            aux = substitute;
            substitute = heritor;
            heritor = heritor->left;
        }
        if (aux != toRemove) {
            aux->left = substitute->right;
            substitute->right = toRemove->right;
        }
        /*O substituto ocupa o lugar de n� removido,
        o filho esquerda do substituto � manipulado
        para permitir isso*/
        substitute->left = toRemove->left;
    }
    if (father == NULL) {
        myTree = substitute;
    } else {
        if (toRemove == father->left) {
            father->left = substitute;
        } else {
            father->right = substitute;
        }
    }
    free(toRemove);
    myTree = MaintenanceAVLTree(myTree);
    return myTree;
}

void RemoveAVLTree(AVLTree *myTree, long int key) {
    myTree->root = RemoveAVL(myTree->root, key);
    myTree->nodes--;
}

/* Destruir a arvore AVL  */
void DestroyAVL(avl_tree_node *myTree) {
    if (myTree == NULL) {
        return;
    } else {
        DestroyAVL(myTree->left);
        DestroyAVL(myTree->right);
        free(myTree);
        myTree = NULL;
    }
}

void DestroyAVLTree(AVLTree *myTree) {
    DestroyAVL(myTree->root);
    myTree->nodes = 0;
}

/* Calcular o Fator de Balaceamento  */
int CalculateBalanceFactor(avl_tree_node *mynode) {
    if (mynode == NULL) {
        return 0;
    } else {
        /* Calcula a diferenca de alturas entre as subarvores
        esquerda e direita de cada no */
        return (HeightAVLTree(mynode->left) - HeightAVLTree(mynode->right));
    }
}

/* Ajustar os Fatores de Balanceamento de todos os nos da arvore  */
void SetbalanceFactor(avl_tree_node *myTree) {
    if (myTree != NULL) {
        myTree->balanceFactor = (HeightAVLTree(myTree->left) - HeightAVLTree(myTree->right));
        SetbalanceFactor(myTree->left);
        SetbalanceFactor(myTree->right);
    } else {
        return;
    }
    return;
}

/* Funcoes utilitarias para as rotacoes */
avl_tree_node *RotateRightAVLTree(avl_tree_node *mynode) {
    avl_tree_node *aux = mynode->left;
    if (aux->right != NULL) {
        /* Se o filho do no atual tem sub-arvore a direita
        Entao o no atual tera como filho a sub-arvore esquerda do filho*/
        mynode->left = aux->right;
    } else {
        mynode->left = NULL;
    }
    /* O no atual vira filho direito do seu proprio filho  */
    aux->right = mynode;
    return aux;
}

avl_tree_node *RotateLeftAVLTree(avl_tree_node *mynode) {
    avl_tree_node *aux = mynode->right;
    if (aux->left != NULL) {
        /* Se o filho do no atual tem sub-arvore a esquerda
        Entao o no atual tera como filho a sub-arvore direita do filho*/
        mynode->right = aux->left;
    } else {
        mynode->right = NULL;
    }
    /* O no atual vira filho esquerda do seu proprio filho  */
    aux->left = mynode;
    return aux;
}

avl_tree_node *DoubleRotateRightAVLTree(avl_tree_node *mynode) {
    avl_tree_node *leftChild = mynode->left;
    avl_tree_node *rightGrandson = leftChild->right;
    if (rightGrandson->left != NULL) {
        /*Se existe o filho esquerda do filho direito do filho esquerda do
        no atual, entao o filho direito do filho esquerda do no atual recebe
        o filho esquerda do filho direito do filho esquerda do no atual*/
        leftChild->right = rightGrandson->left;
    } else {
        leftChild->right = NULL;
    }
    if (rightGrandson->right != NULL) {
        /*Se existe o filho direito do filho direito do filho esquerda do
        no atual, entao o filho direito do filho esquerda do no atual recebe
        o filho esquerda do filho direito do filho esquerda do no atual*/
        leftChild->right = rightGrandson->left;
    } else {
        mynode->right = NULL;
    }
    rightGrandson->left = leftChild;
    rightGrandson->right = mynode;
    return rightGrandson;
}

avl_tree_node *DoubleRotateLeftAVLTree(avl_tree_node *mynode) {
    avl_tree_node *rightChild = mynode->right;
    avl_tree_node *leftGrandson = rightChild->left;
    if (leftGrandson->left != NULL) {
        /*Se existe o filho esquerda do filho esquerda do filho direito do
        no atual, entao o filho direito do no atual passa a ser entao o filho
        esquerda do filho esquerda do filho direito do no atual*/
        mynode->right = leftGrandson->left;
    } else {
        mynode->right = NULL;
    }
    if (leftGrandson->right != NULL) {
        /*Se existe o filho direito do filho esquerda do filho direito do
        no atual, entao o filho esquerda do filho direito passa a ser entoo o filho
        direito do filho esquerda do filho direito do no atual*/
        rightChild->left = leftGrandson->right;
    } else {
        rightChild->left = NULL;
    }
    leftGrandson->left = mynode;
    leftGrandson->right = rightChild;
    return leftGrandson;
}

/* Manter a arvore Balanceada  */
avl_tree_node *MaintenanceAVLTree(avl_tree_node *myTree) {
    if (myTree != NULL) {
        SetbalanceFactor(myTree);
        myTree->balanceFactor = CalculateBalanceFactor(myTree);
        if (myTree->balanceFactor == 2) {
            myTree->left->balanceFactor = CalculateBalanceFactor(myTree->left);
            if (myTree->left->balanceFactor > 0) {
                myTree = RotateRightAVLTree(myTree);
            } else {
                myTree = DoubleRotateRightAVLTree(myTree);
            }
        } else if (myTree->balanceFactor == -2) {
            myTree->right->balanceFactor = CalculateBalanceFactor(myTree->right);
            if (myTree->right->balanceFactor < 0) {
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

/* Desenha a arvore binaria  */
void ShowBranchAVL(branches *t) {
    if (!t) {
        return;
    }
    ShowBranchAVL(t->previous);
    printf(t->str);
}

void DrawAVL(avl_tree_node *myTree, branches *previous, int left) {
    if (myTree == NULL) {
        return;
    }

    branches show = {previous, "    "};
    char *show_str = show.str;

    DrawAVL(myTree->left, &show, 1);
    if (!previous) {
        show.str = "---";
    } else if (left) {
        show.str = ".--";
        show_str = "  |";
    } else {
        show.str = "`--";
        previous->str = show_str;
    }
    ShowBranchAVL(&show);
    printf("%ld \n", myTree->key);

    if (previous) {
        previous->str = show_str;
    }
    show.str = "   |";

    DrawAVL(myTree->right, &show, 0);
    if (!previous) {
        printf("");
    }
}

void DrawAVLTree(AVLTree *myTree) {
    DrawAVL(myTree->root, 0, 0);
}