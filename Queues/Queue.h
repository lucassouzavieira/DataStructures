/**
Este arquivo � parte do projeto Data Structures
Este � um software livre; voc� pode redistribu�-lo e/ou
modific�-lo dentro dos termos da Licen�a P�blica Geral GNU como
publicada pela Funda��o do Software Livre (FSF); na vers�o 3 da
Licen�a, ou (na sua opini�o) qualquer vers�o.

Este programa � distribu�do na esperan�a de que possa ser  �til,
mas SEM NENHUMA GARANTIA; sem uma garantia impl�cita de ADEQUA��O
a qualquer MERCADO ou APLICA��O EM PARTICULAR. Veja a
Licen�a P�blica Geral GNU para maiores detalhes.

Voc� deve ter recebido uma c�pia da Licen�a P�blica Geral GNU junto
com este programa, Se n�o, veja <http:/*www.gnu.org/licenses/>.

Arquivo: Queue.h
Descri��o: Defini��es para estruturas tipo fila
Autor: Lucas de Souza Vieira <lucassouzavieiraengcomp@gmail.com>	*/

#ifndef QUEUE_H
#define QUEUE_H

#include "..\TAD.h"

/* Cria uma fila */ 
queue CreateQueue();

/* Verifica se h� elementos na fila */
int CheckQueue(queue* myQueue);

/* Insere elementos na fila */
void Enqueue(queue* myQueue, long int element);

/* Remove elementos da fila */
void Dequeue(queue* myQueue);

/* Imprime os elementos da fila */
void ConsultQueue(queue* myQueue);

/* Apaga todos os elementos e libera mem�ria */
int DestroyQueue(queue* myQueue);

#endif /* !QUEUE_H */