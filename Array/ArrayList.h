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

Arquivo: ArrayList.h
Descrição: Definições para estruturas do tipo listas estáticas
Autor: Lucas de Souza Vieira <lucassouzavieiraengcomp@gmail.com>	*/
#include "../TAD.h"

/* Cria uma lista estática */
array* ArrayListCreate(unsigned long int size);

/* Verifica se a lista esta vazia ou não  */
int ArrayListCheck(array* mystack);

/* Remove um elemento da lista  */
array* ArrayListRemove(array* mystack, long int key);

/* Insere um elemento na lista  */
array* ArrayListInsert(array* mystack, long int element);

/* Imprime todos os elementos da lista */ 
void ArrayListConsult(array* mystack);

/* Apaga os elementos e libera memória  */
array* ArrayListDestroy(array* mystack);
