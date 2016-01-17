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

Arquivo: Queue.h
Descrição: Definições para estruturas tipo fila
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef QUEUE_H
#define QUEUE_H

#include "..\TAD.h"

//Cria uma fila 
queue CreateQueue();

//Verifica se há elementos na fila 
int CheckQueue(queue* myQueue);

//Insere elementos na fila 
void Enqueue(queue* myQueue, long int element);

//Remove elementos da fila 
void Dequeue(queue* myQueue);

//Imprime os elementos da fila 
void ConsultQueue(queue* myQueue);

//Apaga todos os elementos e libera memória 
int DestroyQueue(queue* myQueue);

#endif // !QUEUE_H