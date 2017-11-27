/*
 * Copyright (C) 2016  Lucas S. Vieira
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <stdio.h>
#include "types.h"

bstree create_bstree() {
    bstree myBSTree;
    myBSTree.root = NULL;
    myBSTree.nodes = 0;
    return myBSTree;
}

void insert_bstree(bstree *myTree, long int key) {
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

nodetree *most_right(nodetree *tree) {
    if (tree->right != NULL) {
        return most_right(tree->right);
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

nodetree *most_left(nodetree *tree) {
    if (tree->left != NULL) {
        return most_left(tree->left);
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

nodetree *remove_bst(nodetree *myTree, long int key) {
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

void remove_bstree(bstree *myTree, long int key) {
    myTree->root = remove_bst(myTree->root, key);
    myTree->nodes--;
}

nodetree *search_bstree(bstree *myTree, long int key) {
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

void pre_order_bst(nodetree *tree) {
    if (tree == NULL) {
        return;
    } else {
        printf("%ld", tree->key);
        pre_order_bst(tree->left);
        pre_order_bst(tree->right);
    }
}

void pre_order_bstree(bstree *myTree) {
    pre_order_bst(myTree->root);
}

void in_order_bst(nodetree *tree) {
    if (tree == NULL) {
        return;
    } else {
        in_order_bst(tree->left);
        printf("%ld ", tree->key);
        in_order_bst(tree->right);
    }
}

void in_order_bstree(bstree *myTree) {
    in_order_bst(myTree->root);
}

void post_order_bst(nodetree *tree) {
    if (tree == NULL) {
        return;
    } else {
        post_order_bst(tree->left);
        post_order_bst(tree->right);
        printf("%ld", tree->key);
    }
}

void post_order_bstree(bstree *myTree) {
    post_order_bst(myTree->root);
}

int height_bst(nodetree *myTree) {
    if (myTree == NULL) {
        return 1;
    } else {
        int leftSubtreeHeight = height_bst(myTree->left) + 1;
        int rightSubtreeHeight = height_bst(myTree->right) + 1;
        if (leftSubtreeHeight < rightSubtreeHeight) {
            return rightSubtreeHeight;
        } else {
            return leftSubtreeHeight;
        }
    }
}

int height_bstree(bstree *myTree) {
    return height_bst(myTree->root);
}

void destroy_bst(nodetree *myTree) {
    if (myTree == NULL) {
        return;
    } else {
        destroy_bst(myTree->left);
        destroy_bst(myTree->right);
        free(myTree);
        myTree = NULL;
    }
}

void destroy_bstree(BSTree *myTree) {
    destroy_bst(myTree->root);
}

void show_branch_bstree(branches *t) {
    if (!t) {
        return;
    }
    show_branch_bstree(t->previous);
    printf(t->str);
}

void draw_bst(nodetree *myTree, branches *previous, int Left) {
    if (myTree == NULL) {
        return;
    }

    branches show = {previous, "    "};
    char *show_str = show.str;

    draw_bst(myTree->left, &show, 1);
    if (!previous) {
        show.str = "---";
    } else if (Left) {
        show.str = ".--";
        show_str = "  |";
    } else {
        show.str = "`--";
        previous->str = show_str;
    }
    show_branch_bstree(&show);
    printf("%ld \n", myTree->key);

    if (previous) {
        previous->str = show_str;
    }
    show.str = "   |";

    draw_bst(myTree->right, &show, 0);
    if (!previous) {
        printf("");
    }
}

void draw_bstree(BSTree *myTree) {
    draw_bst(myTree->root, 0, 0);
}