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

Arquivo: BST.h
Descrição: Definições para árvores binárias
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "TAD.h"

// Criar a árvore  
nodetree* CreateBST();

// Insere um elemento na árvore 
nodetree* InsertInBST(nodetree* myTree);

// Remove um elemento da árvore 
nodetree* RemoveBST(nodetree* myTree, long int key);

// Busca um elemento na Árvore 
nodetree* SearchBST(nodetree* myTree, long int key);

// Maneiras de percorrer a árvore 
void PreOrderBST(nodetree* myTree);
void InorderBST(nodetree* myTree);
void PostOrderBST(nodetree* myTree);

// Ilustra a estrutura da árvore - r-e-d (Préordem)  
void DrawBST(nodetree* myTree, branches *previous, int left);

// Descobrir a altura da árvore 
int HeightOfBST(nodetree* myTree);

// Destruir a árvore 
void DestroyBST(nodetree* myTree);
#endif // !BST_H