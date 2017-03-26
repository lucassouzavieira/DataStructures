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
Funcoes Utilitarias
******************************************************************************/

/* Retorna o pai do no atual */
noderb *Father(noderb *mynode) {
    return mynode->father;
}

/* Retorna o irmao do no atual */
noderb *Brother(noderb *mynode) {
    noderb *father = Father(mynode);
    if (father == NULL)
        return NULL;
    if (father->key > mynode->key) {
        return father->right;
    } else {
        return father->left;
    }
}

/* Rotacao a direita sobre o no  */
noderb *RotateRightRedBlackTree(noderb *mynode) {
    noderb *aux = mynode->left;
    if (aux->right != NULL) {
        /* Se o filho do no atual tem sub-arvore a direita
        Entao o no atual tera como filho a sub-arvore esquerda do filho*/
        mynode->left = aux->right;
    } else {
        mynode->left = NULL;
    }
    /* O no atual vira filho direito do seu proprio filho */
    aux->right = mynode;
    return aux;
}

/* Rotacao a esquerda sobre o no  */
noderb *RotateLeftRedBlackTree(noderb *mynode) {
    noderb *aux = mynode->right;
    if (aux->left != NULL) {
        /* Se o filho do no atual tem sub-arvore a esquerda
        Entao o no atual tera como filho a sub-arvore direita do filho */
        mynode->right = aux->left;
    } else {
        mynode->right = NULL;
    }
    /* O no atual vira filho esquerda do seu proprio filho  */
    aux->left = mynode;
    return aux;
}

/* Balanceia a altura negra de todos os nos  */
int BlackHeight(noderb *mynode) {
    if (mynode == NULL) {
        /* No nulo eh por definicao negro */
        return 1;
    } else if (mynode->color == BLACK) {
        /* No preto conta na altura negra */
        int rightBlackHeight = BlackHeight(mynode->right);
        int leftBlackHeight = BlackHeight(mynode->left);
        if (rightBlackHeight == leftBlackHeight) {
            /* return rightBlackHeight + 1;  */
            return leftBlackHeight + 1;
        } else {
            /* arvore desbalanceada */
            return EXIT_FAILURE;
        }
    } else {
        /* No vermelho nao conta na altura negra */
        int rightBlackHeight = BlackHeight(mynode->right);
        int leftBlackHeight = BlackHeight(mynode->left);
        if (rightBlackHeight == leftBlackHeight) {
            /* return rightBlackHeight;  */
            return leftBlackHeight;
        } else {
            /* Arvore desbalanceada  */
            return EXIT_FAILURE;
        }
    }
}

/* Calcula a altura da arvore  */
int Height(noderb *mytree) {
    if (mytree == NULL) {
        /* A arvore ou no nao tem elementos,
        nesse caso tem altura n-1*/
        return -1;
    } else {
        /* Nesse caso, calcular a altura das sub-arvores
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

/* Recalcula a altura negra de todos os nos da arvore  */
void SetBlackHeight(noderb *mytree) {
    if (mytree != NULL) {
        /* Percorre as sub-arvores configurando as alturas negras */
        SetBlackHeight(mytree->left);
        SetBlackHeight(mytree->right);
        /* Ajusta o fator de balaceamento do no current  */
        if ((BlackHeight(mytree->left) == BlackHeight(mytree->right))) {
            /* Nesse caso, a arvore esta perfeitamente balaceada */
            mytree->blackHeight = BlackHeight(mytree->left);
            /* mytree->BlackHeight = BlackHeight(mytree->right); */
        } else {
            /* Retorna -1 para a altura negra do no que esta desbalanceado  */
            mytree->blackHeight = -1;
        }
    } else {
        /* Retorna se nao houver arvore  */
        return;
    }
    return;
}

/* Altera a cor de um no */
void ChangeColor(noderb *mynode) {
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

/* Verifica as condicoes das cores de todos os nos e promove ajustes  */
void ColorFixUp(noderb *mytree) {
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

/* Inicializa um no  */
noderb *CreateRedBlackNode(long int key) {
    noderb *newNode = (noderb *) malloc(sizeof(noderb));
    newNode->key = key;
    newNode->blackHeight = 0;
    newNode->color = RED;
    newNode->father = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Troca as cores  */
void swapColors(noderb *firstNode, noderb *secondNode) {
    Color tempColor = firstNode->color;
    firstNode->color = secondNode->color;
    secondNode->color = tempColor;
}

/******************************************************************************
Funcoes Gerais
******************************************************************************/

/* Criar uma arvore Red-Black  */
RBTree CreateRedBlackTree() {
    RBTree myTree;
    myTree.nodes = 0;
    myTree.root = NULL;
    return myTree;
}

/* Ajusta as propriedades da arvore apos a insercao  */
void InsertFixUp(noderb *root, noderb *newNode) {
    noderb *father = NULL;
    noderb *uncle = NULL;
    noderb *grandFather = NULL;
    while ((newNode != root) && (newNode->color != BLACK)
           && (Father(newNode)->color == RED)) {
        father = Father(newNode);
        grandFather = Father(Father(newNode));

        /* Caso 1:
           O pai do novo no eh o filho esquerdo do avo  */
        if (father == grandFather->left) {
            uncle = grandFather->right;
            if ((uncle != NULL) && (uncle->color == RED)) {
                grandFather->color = RED;
                father->color = BLACK;
                uncle->color = BLACK;
                newNode = grandFather;
            } else {
                /* Caso 2:
                   O novo no eh filho direito  */
                if (newNode == father->right) {
                    RotateLeftRedBlackTree(father);
                    newNode = father;
                    father = newNode->father;
                }

                /* Caso 3:
                   O novo no e filho esquerdo  */
                RotateRightRedBlackTree(grandFather);
                swapColors(father, grandFather);
                newNode = father;
            }
        } else {
            noderb *uncle = grandFather->left;
            /* Caso 1:
               O tio eh vermelho  */
            if ((uncle != NULL) && (uncle->color == RED)) {
                grandFather->color = RED;
                father->color = BLACK;
                uncle->color = BLACK;
                newNode = grandFather;
            } else {
                /* Caso 2:
                   Novo no eh filho esquerdo  */
                if (newNode == father->left) {
                    RotateRightRedBlackTree(father);
                    newNode = father;
                    father = newNode->father;
                }
                /* Caso 3:
                   Novo no eh filho direito  */
                RotateLeftRedBlackTree(grandFather);
                swapColors(father, grandFather);
                newNode = father;
            }
        }
    }
    root->color = BLACK;
    SetBlackHeight(root);
}

/* Inserir elementos na arvore Red-Black */
void InsertInRedBlackTree(RBTree *myTree, long int key) {
    noderb *newNode = (noderb *) (malloc(sizeof(noderb)));
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
        /* Buscar a posicao da nova folha  */
        noderb *father = NULL;
        noderb *current = myTree->root;
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

/* Buscar elementos na arvore Red-Black */
noderb *SearchRedBlackTree(RBTree *mytree, long int key);

/* Remover elemento na arvore Red-Black */
noderb *RemoveRedBlackTree(RBTree *mytree, long int key);

void DestroyRedBlackTree(RBTree *myTree);

void DrawRedBlackTree(RBTree *myTree);