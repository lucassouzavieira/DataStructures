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

#include <stdlib.h>
#include <stdio.h>
#include "../Types.h"

BSTree CreateBST() {
    BSTree myBSTree;
    myBSTree.root = NULL;
    myBSTree.nodes = 0;
    return myBSTree;
}

void InsertInBST(BSTree *myTree, long int key) {
    if (myTree->root == NULL) {
        nodetree *newNode = (nodetree * )(malloc(sizeof(nodetree)));
        if (newNode != NULL) {
            newNode->key = key;
            newNode->right = NULL;
            newNode->left = NULL;
        }
        myTree->root = newNode;
    } else {
        nodetree *newNode = (nodetree * )(malloc(sizeof(nodetree)));
        if (newNode != NULL) {
            newNode->key = key;
            newNode->right = NULL;
            newNode->left = NULL;
        }

        nodetree *father = NULL;
        nodetree *current = myTree->root;

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
        } else if (father->key <= newNode->key) {
            father->right = newNode;
        }
    }
    myTree->nodes++;
}

nodetree *MostRight(nodetree *tree) {
    if (tree->right != NULL) {
        return MostRight(tree->right);
    } else {
        nodetree *aux = tree;
        if (tree->left != NULL) {
            tree = tree->left;
        } else {
            tree = NULL;
        }
        return aux;
    }
}

nodetree *MostLeft(nodetree *tree) {
    if (tree->left != NULL) {
        return MostLeft(tree->left);
    } else {
        nodetree *aux = tree;
        if (tree->right != NULL) {
            tree = tree->right;
        } else {
            tree = NULL;
        }
        return aux;
    }
}

nodetree *RemoveBSTree(nodetree *myTree, long int key) {
    nodetree *toRemove = myTree;
    nodetree *father = NULL;
    nodetree *substitute;
    nodetree *aux;
    nodetree *heritor;

    while (toRemove != NULL && toRemove->key != key) {
        father = toRemove;
        if (key < toRemove->key) {
            toRemove = toRemove->left;
        } else if (key > toRemove->key) {
            toRemove = toRemove->right;
        }
    }

    if (toRemove == NULL) {
        printf("Key not found ! \n");
        return myTree;
    }

    if (toRemove->left == NULL) {
        substitute = toRemove->right;
    } else if (toRemove->right == NULL) {
        substitute = toRemove->left;
    } else {
        aux = toRemove;
        substitute = toRemove->right;
        heritor = substitute->left;

        while (heritor != NULL) {
            aux = substitute;
            substitute = heritor;
            heritor = heritor->left;
        }

        if (aux != toRemove) {
            aux->left = substitute->right;
            substitute->right = toRemove->right;
        }
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
    return myTree;
}

void RemoveBST(BSTree *myTree, long int key) {
    myTree->root = RemoveBSTree(myTree->root, key);
    myTree->nodes--;
}

nodetree *SearchBST(BSTree *myTree, long int key) {
    nodetree *aux = myTree->root;
    while (aux != NULL) {
        if (key < aux->key) {
            aux = aux->left;
        } else if (key > aux->key) {
            aux = aux->right;
        } else {
            return aux;
        }
    }
    return NULL;
}

void PreOrderBSTree(nodetree *tree) {
    if (tree == NULL) {
        return;
    } else {
        printf("%ld", tree->key);
        PreOrderBSTree(tree->left);
        PreOrderBSTree(tree->right);
    }
}

void PreOrderBST(BSTree *myTree) {
    PreOrderBSTree(myTree->root);
}

void InOrderBSTree(nodetree *tree) {
    if (tree == NULL) {
        return;
    } else {
        InOrderBSTree(tree->left);
        printf("%ld ", tree->key);
        InOrderBSTree(tree->right);
    }
}

void InOrderBST(BSTree *myTree) {
    InOrderBSTree(myTree->root);
}

void PostOrderBSTree(nodetree *tree) {
    if (tree == NULL) {
        return;
    } else {
        PostOrderBSTree(tree->left);
        PostOrderBSTree(tree->right);
        printf("%ld", tree->key);
    }
}

void PostOrderBST(BSTree *myTree) {
    PostOrderBSTree(myTree->root);
}

int HeightOfBSTree(nodetree *myTree) {
    if (myTree == NULL) {
        return 1;
    } else {
        int leftSubtreeHeight = HeightOfBSTree(myTree->left) + 1;
        int rightSubtreeHeight = HeightOfBSTree(myTree->right) + 1;
        if (leftSubtreeHeight < rightSubtreeHeight) {
            return rightSubtreeHeight;
        } else {
            return leftSubtreeHeight;
        }
    }
}

int HeightOfBST(BSTree *myTree) {
    return HeightOfBSTree(myTree->root);
}

void DestroyBSTree(nodetree *myTree) {
    if (myTree == NULL) {
        return;
    } else {
        DestroyBSTree(myTree->left);
        DestroyBSTree(myTree->right);
        free(myTree);
        myTree = NULL;
    }
}

void DestroyBST(BSTree *myTree) {
    DestroyBSTree(myTree->root);
}

void ShowBranch(branches *t) {
    if (!t) {
        return;
    }
    ShowBranch(t->previous);
    printf(t->str);
}

void DrawBSTree(nodetree *myTree, branches *previous, int Left) {
    if (myTree == NULL) {
        return;
    }

    branches show = {previous, "    "};
    char *show_str = show.str;

    DrawBSTree(myTree->left, &show, 1);
    if (!previous) {
        show.str = "---";
    } else if (Left) {
        show.str = ".--";
        show_str = "  |";
    } else {
        show.str = "`--";
        previous->str = show_str;
    }
    ShowBranch(&show);
    printf("%ld \n", myTree->key);

    if (previous) {
        previous->str = show_str;
    }
    show.str = "   |";

    DrawBSTree(myTree->right, &show, 0);
    if (!previous) {
        printf("");
    }
}

void DrawBST(BSTree *myTree) {
    DrawBSTree(myTree->root, 0, 0);
}