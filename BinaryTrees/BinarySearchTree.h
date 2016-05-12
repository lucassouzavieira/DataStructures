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
com este programa, Se não, veja <http:/*www.gnu.org/licenses/>.

Arquivo: BinarySearchTree.h
Descrição: Definições para estruturas do tipo árvore binária de busca
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "..\TAD.h"

/* Criar a árvore   */
BSTree CreateBST();

/* Insere um elemento na árvore  */
void InsertInBST(BSTree* myTree, long int key);

/* Remove um elemento da árvore  */
void RemoveBST(BSTree* myTree, long int key);

/* Busca um elemento na Árvore  */
nodetree* SearchBST(BSTree* myTree, long int key);

/* Maneiras de percorrer a árvore  */
void PreOrderBST(BSTree* myTree);
void InOrderBST(BSTree* myTree);
void PostOrderBST(BSTree* myTree);

/* Ilustra a estrutura da árvore - r-e-d (Préordem)   */
void DrawBST(BSTree* myTree);

/* Descobrir a altura da árvore */ 
int HeightOfBST(BSTree* myTree);

/* Destruir a árvore */ 
void DestroyBST(BSTree* myTree);
#endif /* !BST_H */