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

Arquivo: RedBlackTree.h
Descrição: Definição para estruturas do tipo árvore rubro-negra
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "..\TAD.h"

/*Criar uma Árvore Red-Black*/
RBTree CreateRedBlackTree();

/*Inserir elementos na Árvore Red-Black*/
void InsertInRedBlackTree(RBTree* mytree, long int key);

/*Buscar elementos na Árvore Red-Black*/
noderb* SearchRedBlackTree(RBTree* mytree, long int key);

/*Remover elemento na Árvore Red-Black*/
noderb* RemoveRedBlackTree(RBTree* mytree, long int key);

void DestroyRedBlackTree(RBTree* myTree);

/*Destruir a árvore Red-Black*/
void DrawRedBlackTree(RBTree* myTree);

#endif //!REDBLACKTREE_H