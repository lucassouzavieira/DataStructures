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
Descrição: Implementação de Árvores RedBlack
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#include "RedBlackTree.h"

/******************************************************************************
Funções Utilitárias
******************************************************************************/
/*Funções utilitárias para as rotações*/
void RotateRightRedBlackTree(noderb* mytree, noderb* root, noderb* pivot);
void RotateLeftRedBlackTree(noderb* mytree, noderb* root, noderb* pivot);

/*Funções utilitárias para 'parentes'*/
int CountChildren(noderb* mynode);
noderb* Brother(noderb* mynode);
noderb* Uncle(noderb* mynode);
noderb* Father(noderb* mynode);
noderb* GrandFather(noderb* mynode);
noderb* GreatGrandFather(noderb* mynode);

/*Funções utilitárias para Altura Negra*/
int BlackHeight(noderb* mynode);
int Height(noderb* mynode);
void SetBlackHeight(noderb* mytree);

/* Desenha a Árvore Red-Black*/
void DrawRedBlackTree(noderb* mytree, branches *previous, int left);

/******************************************************************************
Funções Gerais
******************************************************************************/
/*Criar uma Árvore Red-Black*/
RBTree CreateRedBlackTree();

/*Inserir elementos na Árvore Red-Black*/
void InsertInRedBlackTree(RBTree* mytree);

/*Buscar elementos na Árvore Red-Black*/
noderb* SearchRedBlackTree(RBTree* mytree, long int key);

/*Remover elemento na Árvore Red-Black*/
void RemoveRedBlackTree(RBTree* mytree, long int key);

/*Destruir a árvore Red-Black*/
void DestroyRedBlackTree(AVLTree* myTree);

/*Destruir a árvore Red-Black*/
void DrawRedBlackTree(RBTree* myTree);