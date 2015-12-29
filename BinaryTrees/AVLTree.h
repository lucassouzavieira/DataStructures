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

Arquivo: AVLTree.h
Descrição: Definições para árvores AVL
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef AVLTREE_H
#define AVLTREE_H
#include "..\TAD.h"

/*Criar uma Árvore AVL*/
AVLTree CreateAVLTree();

/*Inserir elementos na Árvore AVL*/
void InsertInAVLTree(AVLTree* myTree, long int key);

/*Buscar elementos na Árvore AVL*/
nodeavl* SearchAVLTree(AVLTree* myTree, long int key);

/*Remover elemento na Árvore AVL*/
void RemoveAVLTree(AVLTree* myTree, long int key);

/*Destruir a árvore AVL*/
void DestroyAVLTree(AVLTree* myTree);

/*Desenha a árvore AVL*/
void DrawAVLTree(AVLTree* myTree);

#endif // AVLTREE_H