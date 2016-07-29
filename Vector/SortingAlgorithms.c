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

Arquivo: SortingAlgorithms.c
Descrição: Implementação de algoritmos de ordenação
Autor: Lucas de Souza Vieira <lucassouzavieiraengcomp@gmail.com>	*/

#include <stdlib.h>
#include <stdio.h>
#include "..\TAD.h"
#include "SortingAlgorithms.h"

long int _count_merge_sort = 0;

/* BUBBLE SORT */
long int* BubbleSort (long int* vector, long int numberOfElements)
{
	/* Primeiro la�o percorre todo o vetor */
	long int aux = 0;
	for (long int i = 1; i <= numberOfElements; i++){
		/* Segundo la�o percorre da primeira � pen�ltima posi��o
		do vetor */
		for (long int j = 0; j < (numberOfElements); j++){
			/* Se o valor da posi��o j for maior que o valor da posi��o
			j+1, ent�o trocar a posi��o dos dois valores */
			if (vector[j] > vector[j + 1]){
				aux = vector[j];
				vector[j] = vector[j + 1];
				vector[j + 1] = aux;
			}
		}
	}

	return vector;
}

long int* BubbleSortImproved (long int* vector, long int numberOfElements)
{
	/* Primeiro la�o percorre todo o vector */
	long int aux;
	for (long int i = 0; i < numberOfElements; i++){
		/*O segundo la�o n�o mais percorrer� as posi��es j� ordenadas do vector */
		for (long int j = (numberOfElements - 1); j >= i; j--){
			/* Se o valor da posi��o j for maior que o valor da posi��o
			j+1, ent�o trocar a posi��o dos dois valores */
			if (vector[j] > vector[j + 1]){
				aux = vector[j];
				vector[j] = vector[j + 1];
				vector[j + 1] = aux;
			}
		}
	}
	return vector;
}

/* INSERTION SORT */
long int* InsertionSort (long int* vector, long int numberOfElements)
{
	long int j;
	long int eleito;
	/* Primeiro la�o percorre todo o vector , menos a primeira posi��o */
	for (long int i = 1; i <= numberOfElements; i++){
		eleito = vector[i];
		j = i - 1;
		/* la�o que percorre apenas os elementos � esquerda do n�mero eleito
		ou at� encontrar a posi��o para a recoloca��o do n�mero eleito respeitando
		a ordena��o desejada */
		while (j >= 0 && vector[j] > eleito){
			vector[j + 1] = vector[j];
			j = j - 1;
		}
		vector[j + 1] = eleito;
	}
	return vector;
}

/* SELECTION SORT */
long int* SelectionSort (long int* vector, long int numberOfElements)
{
	long int i;
	long int pos; /* Posi��o */
	long int eleito;
	for (i = numberOfElements; i > 0; i--){
		/*percorre o vector inteiro de tr�s pra frente, exceto a primeira posi��o */
		eleito = vector[0];
		pos = 0;
		for ( long int j = 1; j <= i; j++){
			/* percorre o vector de frente para tr�s, verificando se h� elementos
			maiores que o eleito */
			if (vector[j] > eleito){
				eleito = vector[j];
				pos = j;
			}
		}
		/* Ordena */
		vector[pos] = vector[i];
		vector[i] = eleito;
	}
	return vector;
}

/* MERGE SORT */
void merge (long int* vector, long int numberOfElements)
{
	long int meio;
	long int i, j, k;
	long int* tmp;
	/* Vetor tempor�rio */
	tmp = (long int* ) malloc(numberOfElements * sizeof(long int));
	if (tmp == NULL) {
		exit(1);
	}
	meio = numberOfElements / 2;
	i = 0;
	j = meio;
	k = 0;
	while (i < meio && j < numberOfElements) {
		if (vector[i] < vector[j]) {
			tmp[k] = vector[i++];
		}
		else {
			tmp[k] = vector[j++];
		}
		++k;
	}

	/* Concatena as duas "partes" ordenadas */
	if (i == meio) {
		while (j < numberOfElements) {
			tmp[k++] = vector[j++];
		}
	}
	else {
		while (i < meio) {
			tmp[k++] = vector[i++];

		}
	}
	/* Retorna os elementos de forma ordenada ao vector recebido
	como par�metro */
	for (i = 0; i < numberOfElements; ++i) {
		vector[i] = tmp[i];
	}
	/* Libera o vector auxiliar */
	free(tmp);
}

void MergeSort (long int* vector, long int numberOfElements)
{
	/* Vari�veis auxiliares */
	long int meio;
	/*Divide o vector ao meio e efetua as chamadas recursivas*/
	if (numberOfElements > 1){
		meio = numberOfElements / 2;
		MergeSort(vector, meio);
		MergeSort(vector + meio, numberOfElements - meio);
		merge(vector, numberOfElements);
	}
}

/* QUICK SORT */
void quick (long int* vector, long int pos_inicio, long int pos_final)
{
	long int i = pos_inicio;
	long int j = pos_final;
	long int pivo = vector[(pos_inicio + pos_final) / 2]; /* Pivo � o elemento central do vector */
	long int aux;
	/*Inicio do procedimento */
	while (i < j){
		while (vector[i] < pivo){
			i++;
		}
		while (vector[j] > pivo){
			j--;
		}
		if (i <= j){
			aux = vector[i];
			vector[i] = vector[j];
			vector[j] = aux;
			i++;
			j--;
		}
	}
	if (j > pos_inicio){
		quick(vector, pos_inicio, j);
	}
	if (i < pos_final){
		quick(vector, i, pos_final);
	}
}

long int* QuickSort (long int* vector, long int numberOfElements)
{
	long int pos_inicio = 0;
	long int pos_final = numberOfElements;
	/*Efetua a chamada ao procedimento quick */
	quick(vector, pos_inicio, pos_final);
	/*Retorna um pointer para o vector ordenado */
	return vector;
}

/* HEAP SORT */
void HeapSort (long int* vector, long int numberOfElements)
{
	/*Checar se o Heap est� vazio */
	if (numberOfElements == 0){
		printf("Empty Heap! \n");
	}
	long int aux; /* Vari�vel auxiliar */
	long int n = numberOfElements;
	long int father = numberOfElements / 2;
	long int index, child;

	while (1){
		if (father > 0){
			/*Ordenar o Heap */
			aux = vector[--father];
		}
		else {
			/* Extrair os elementos */
			n--;
			if (n == 0){
				/* Quando o heap fica vazio, o algoritmo termina */
				return;
			}
			aux = vector[n];
			vector[n] = vector[0]; 
		}
		/* Empurrando t para baixo para recolocar o pai */
		index = father;
		child = index * 2 + 1; 
		while (child < n){
			if (child + 1 < n && vector[child + 1] > vector[child]){
				child++;
			}
			if (vector[child] > aux){
				vector[index] = vector[child]; 
				index = child; /* �ndice fica igual ao filho */
				child = index * 2 + 1; /* Pega o filho da esquerda e repetir o processo */
			}
			else {
				break;
			}
		}
		/* Novos valores s�o salvos tempor�riamente em novas posi��es */
		vector[index] = aux;
	}
}

/* COMB SORT */
long int* CombSort (long int* vector, long int numberOfElements)
{
	long int i, j, jump, aux, changes = 1;
	jump = numberOfElements;

	while (jump > 1 || changes == 1){
		/* Configura o jump */
		jump = jump * 10 / 13;
		if (jump == 9 || jump == 10){
			jump = 11;
		}
		if (jump < 1){
			jump = 1;
		}
		changes = 0;
		for (i = 0, j = jump; j < numberOfElements; i++, j++){
			/* Efetua compara��es e trocas */
			if (vector[i]>vector[j]){
				aux = vector[i];
				vector[i] = vector[j];
				vector[j] = aux;
				changes = 1;
			}
		}
	}
	return vector;
}

/* SHELL SORT */
void shell_sort_phase (long int* vector, long int numberOfElements, int jump)
{
	/*Executa como se fosse um Insertion Sort em elementos de []
	na faixa dada
	Se o jump = 1, ent�o executa como o Insertion Sort comum
	Se o jump >= numberOfElements, ent�o o algoritmo n�o faz nada */
	long int i;

	for (i = jump; i < numberOfElements; i++){
		long int valor = vector[i];
		long int j;
		for (j = (i - jump); j >= 0 && vector[j] > valor; j = j - jump){
			vector[j + jump] = vector[j];
		}
		vector[j + jump] = valor;
	}
	/* Fim da fun��o */
}

long int* ShellSort (long int* vector, long int numberOfElements)
{
	/* o jump deve se aproximar de uma progress�o geom�trica.
	A seguinte sequ�ncia � a mais comhecida em termos de n�mero m�dio
	de compara��es feitas */
	numberOfElements = numberOfElements + 1; /* + 1 para ajuste de posi��o */
	static const int jump[] = { 1, 4, 10, 23, 57, 132, 301, 701 };
	long int sizeIndex; /* �ndice de tamanho */
	for (sizeIndex = (sizeof(jump) / sizeof(jump[0]) - 1); sizeIndex >= 0; --sizeIndex){
		shell_sort_phase(vector, numberOfElements, jump[sizeIndex]);
	}
	return vector;
}

/* GnoME SORT */
long int* GnomeSort (long int* vector, long int numberOfElements)
{
	long int aux;
	for (long int i = 0; i <= numberOfElements;){
		if (vector[i - 1] <= vector[i]){
			/* Faz as compara��es */
			++i;
		}
		else {
			/* Faz as trocas */
			aux = vector[i];
			vector[i] = vector[i - 1];
			vector[i - 1] = aux;
			--i;
			if (i == 0){
				i = 1;
			}
		}
	}
	return vector;
}


/* BOGO SORT */
int sorting (long int* vector, long int elements)
{
	long int n = elements; 
	/* Compara todos os elementos do vector a partir do �ltimo */
	while (--n >= 1) {
		if (vector[n] < vector[n - 1]){
			return 0;
		}
	}
	return 1;
}

void shuffle (long int* vector, long int elements)
{
	long int aux, r; 
	for (long int i = 0; i < elements; i++){
		/* Realiza a troca de posi��es */
		aux = vector[i];
		r = rand() % elements;
		vector[i] = vector[r];
		vector[r] = aux;
	}
}

long int* BogoSort (long int* vector, long int elements)
{
	while (!sorting(vector, elements)){
		shuffle(vector, elements);
	}
	return vector;
}

/* COUTING SORT */
int CSorting (long int* vector, long int elements, long int min, long int max)
{
	long int i, k;

	long int range = max - min + 1; /* Determinando faixa */
	long int *count = (long int*) malloc(range*sizeof(*vector)); /* Declara vector auxiliar */

	for (i = 0; i < range; i++){
		/* Inicializa o vector auxiliar de contagem */
		count[i] = 0;
	}

	for (int i = 0; i < elements; i++){
		/* vector de contagem recebe a qtde. de vezes (n) que um n�mero k se repete */
		count[vector[i] - min]++;
	}

	/* Substitui 'k' n vezes no vector original */
	for (i = min, k = 0; i <= max; i++){
		for (long int j = 0; j < count[i - min]; j++){
			vector[k++] = i;
		}
	}
	free(count);
	return EXIT_SUCCESS;
}

long int* CoutingSort (long int* vector, long int elements)
{
	/* Algoritmo de ordena��o Couting Sort (Ordena��o por contagem)
		Determina uma faixa de valores em que os elementos dos vectores est�o, 
		encontramdo maior e o menor elemento do vector; Logo, para todo 
		elemento k do vector vale que min <= k <= max. O algoritmo ent�o conta 
		para cada k qupreviousas vezes esse elemento se repete no vector. Sabendo disso, 
		basta repor no vector original (ou em um auxiliar) os valores k ordenados. */
	long int i, min, max;

	min = max = vector[0]; 

	/* Primeiro passo: Achar o maior e o menor elemento do vector a ser ordenado */
	for (i = 1; i < elements; i++){
		if (vector[i] < min){
			min = vector[i];
		} else if (vector[i] > max){
			max = vector[i];
		}
	}

	CSorting(vector, elements, min, max); /* Passa para a fun��o auxiliar */

	return vector; /* Retorna o vector ordenado */
}