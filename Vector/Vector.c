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

Arquivo: Vector.c
Descrição: Implementação de funções auxiliares para tratamento de vetores
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#define _CRT_SECURE_NO_WARNINGS 1 /* Desabilita verificações de segurança */
#define MAX 4000000
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "..\TAD.h"

/* Imprime os elementos do vetor */
void ShowVector (long int *vector, long int numberOfElements)
{
	long int* aux = vector;
	for (long int i = 0; i < numberOfElements; i++) {
		printf("%ld \n", aux[i]);
	}
}

/* Salva o vetor em um arquivo txt */
int SaveVector (const char* address, long int *vector, long int numberOfElements)
{
	FILE* file;
	file = fopen(address, "w");
	if (file == NULL) {
		printf("Failed to save file! \n"); 
		return -1;
	}
	for (long int i = 0; i < numberOfElements; i++) {
		fflush(stdout);
		fprintf(file, "%ld \n", vector[i]);
	}
	fclose(file);
	printf("Successfully saved file! \n");
	return 0;
}

/* Recupera o vetor de um arquivo */
long int* RetrieveVector (const char* address, long *vector, long int numberOfElements)
{
	vector = (long int*)malloc((numberOfElements)*sizeof(long int));
	*vector = 0;
	FILE* file;
	file = fopen(address, "r");
	if (file == NULL) {
		printf("Falha ao ler arquivo! \n");
		return NULL;
	}
	for (int i = 0; i <= (numberOfElements - 1); i++) {
		fflush(stdin);
		fscanf(file, "%ld", &vector[i]);
	}
	fclose(file);
	printf( "Arquivo lido com sucesso! \n");
	return vector;
}

/* Cria um vetor com números aleatórios */
long int* CreateRandomVector (long int numberOfElements)
{
	/* A função gera inteiros aleatórios entre -1.310.680 e +1.638.350
	Última modificação de faixa em 05/12/2015, às 4:42PM */
	srand(time(NULL));
	long int* vector; 
	vector = (long int *)(malloc(numberOfElements*sizeof(long int)));
	if (vector == NULL) {
		printf("Erro durante a alocação de memória! \n");
		return NULL;
	}
	else {
		for (long int i = 0; i < numberOfElements; i++) {
			int multiplicador = -40 + rand() % 50;
			vector[i] = (32767 * multiplicador + 40 * rand());
		}
	}
	return vector;
}