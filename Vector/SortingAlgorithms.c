/*
 Algoritmos de ordenacao

 Copyright (C) 2016  Lucas S. Vieira

 This program is free software: you can redistribute it and/or modify it
 under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License,
 or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>. */


#include <stdlib.h>
#include <stdio.h>
#include "../TAD.h"
#include "SortingAlgorithms.h"

long int _count_merge_sort = 0;

/* BUBBLE SORT */
long int *BubbleSort(long int *vector, long int numberOfElements) {
    long int aux = 0;
    for (long int i = 1; i <= numberOfElements; i++) {
        /* Segundo laço percorre da primeira à penúltima posição
        do vetor */
        for (long int j = 0; j < (numberOfElements - 1); j++) {
            /* Se o valor da posição j for maior que o valor da posição
            j+1, então trocar a posição dos dois valores */
            if (vector[j] > vector[j + 1]) {
                aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
        }
    }

    return vector;
}

long int *BubbleSortImproved(long int *vector, long int numberOfElements) {
    long int aux;
    for (long int i = 0; i <= numberOfElements; i++) {
        /*O segundo laço não mais percorre as posições já ordenadas do vector */
        for (long int j = (numberOfElements - 1); j >= i; j--) {
            /* Se o valor da posição j for maior que o valor da posição
            j+1, então trocar a posição dos dois valores */
            if (vector[j] > vector[j + 1]) {
                aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
        }
    }
    return vector;
}

/* INSERTION SORT */
long int *InsertionSort(long int *vector, long int numberOfElements) {
    long int j;
    long int eleito;
    /* Primeiro laço percorre o vector , menos a primeira posição */
    for (long int i = 1; i <= numberOfElements; i++) {
        eleito = vector[i];
        j = i - 1;
        /* laço que percorre apenas os elementos à esquerda do nmero eleito
        ou até encontrar a posição para a recolocação do número eleito respeitando
        a ordenação desejada */
        while (j >= 0 && vector[j] > eleito) {
            vector[j + 1] = vector[j];
            j = j - 1;
        }
        vector[j + 1] = eleito;
    }
    return vector;
}

/* SELECTION SORT */
long int *SelectionSort(long int *vector, long int numberOfElements) {
    long int i;
    long int pos; /* Posição */
    long int eleito;
    for (i = numberOfElements; i > 0; i--) {
        /*percorre o vector inteiro de trás pra frente, exceto a primeira posição */
        eleito = vector[0];
        pos = 0;
        for (long int j = 1; j <= i; j++) {
            /* percorre o vector de frente para trás, verificando se há elementos
            maiores que o eleito */
            if (vector[j] > eleito) {
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
void merge(long int *vector, long int numberOfElements) {
    long int meio;
    long int i, j, k;
    long int *tmp;
    /* Vetor temporário */
    tmp = (long int *) malloc(numberOfElements * sizeof(long int));
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
        } else {
            tmp[k] = vector[j++];
        }
        ++k;
    }

    /* Concatena as duas "partes" ordenadas */
    if (i == meio) {
        while (j < numberOfElements) {
            tmp[k++] = vector[j++];
        }
    } else {
        while (i < meio) {
            tmp[k++] = vector[i++];

        }
    }
    /* Retorna os elementos de forma ordenada ao vector recebido
    como parâmetro */
    for (i = 0; i < numberOfElements; ++i) {
        vector[i] = tmp[i];
    }
    free(tmp);
}

void MergeSort(long int *vector, long int numberOfElements) {
    long int meio;
    /*Divide o vector ao meio e efetua as chamadas recursivas*/
    if (numberOfElements > 1) {
        meio = numberOfElements / 2;
        MergeSort(vector, meio);
        MergeSort(vector + meio, numberOfElements - meio);
        merge(vector, numberOfElements);
    }
}

/* QUICK SORT */
void quick(long int *vector, long int pos_inicio, long int pos_final) {
    long int i = pos_inicio;
    long int j = pos_final;
    long int pivo = vector[(pos_inicio + pos_final) / 2]; /* Pivo é o elemento central do vector */
    long int aux;
    /*Inicio do procedimento */
    while (i < j) {
        while (vector[i] < pivo) {
            i++;
        }
        while (vector[j] > pivo) {
            j--;
        }
        if (i <= j) {
            aux = vector[i];
            vector[i] = vector[j];
            vector[j] = aux;
            i++;
            j--;
        }
    }
    if (j > pos_inicio) {
        quick(vector, pos_inicio, j);
    }
    if (i < pos_final) {
        quick(vector, i, pos_final);
    }
}

long int *QuickSort(long int *vector, long int numberOfElements) {
    long int pos_inicio = 0;
    long int pos_final = numberOfElements;
    /*Efetua a chamada ao procedimento quick */
    quick(vector, pos_inicio, pos_final);
    /*Retorna um pointer para o vector ordenado */
    return vector;
}

/* HEAP SORT */
void HeapSort(long int *vector, long int numberOfElements) {
    /*Checar se o Heap está vazio */
    if (numberOfElements == 0) {
        printf("Empty Heap! \n");
    }
    long int aux;
    long int n = numberOfElements;
    long int father = numberOfElements / 2;
    long int index, child;

    while (1) {
        if (father > 0) {
            /*Ordenar o Heap */
            aux = vector[--father];
        } else {
            /* Extrair os elementos */
            n--;
            if (n == 0) {
                /* Quando o heap fica vazio, o algoritmo termina */
                return;
            }
            aux = vector[n];
            vector[n] = vector[0];
        }
        /* Empurrando t para baixo para recolocar o pai */
        index = father;
        child = index * 2 + 1;
        while (child < n) {
            if (child + 1 < n && vector[child + 1] > vector[child]) {
                child++;
            }
            if (vector[child] > aux) {
                vector[index] = vector[child];
                index = child; /* índice fica igual ao filho */
                child = index * 2 + 1; /* Pega o filho da esquerda e repetir o processo */
            } else {
                break;
            }
        }
        /* Novos valores são salvos temporáriamente em novas posições */
        vector[index] = aux;
    }
}

/* COMB SORT */
long int *CombSort(long int *vector, long int numberOfElements) {
    long int i, j, jump, aux, changes = 1;
    jump = numberOfElements;

    while (jump > 1 || changes == 1) {
        /* Configura o jump */
        jump = jump * 10 / 13;
        if (jump == 9 || jump == 10) {
            jump = 11;
        }
        if (jump < 1) {
            jump = 1;
        }
        changes = 0;
        for (i = 0, j = jump; j < numberOfElements; i++, j++) {
            /* Efetua compara��es e trocas */
            if (vector[i] > vector[j]) {
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
void shell_sort_phase(long int *vector, long int numberOfElements, int jump) {
    /*Executa como se fosse um Insertion Sort em elementos de []
    na faixa dada
    Se o jump = 1, então executa como o Insertion Sort comum
    Se o jump >= numberOfElements, então o algoritmo não faz nada */
    long int i;

    for (i = jump; i < numberOfElements; i++) {
        long int valor = vector[i];
        long int j;
        for (j = (i - jump); j >= 0 && vector[j] > valor; j = j - jump) {
            vector[j + jump] = vector[j];
        }
        vector[j + jump] = valor;
    }
}

long int *ShellSort(long int *vector, long int numberOfElements) {
    /* o jump deve se aproximar de uma progressão geométrica.
    A seguinte sequência é a mais conhecida em termos de número médio
    de comparações feitas */
    numberOfElements = numberOfElements + 1; /* + 1 para ajuste de posição */
    static const int jump[] = {1, 4, 10, 23, 57, 132, 301, 701};
    long int sizeIndex; /* �ndice de tamanho */
    for (sizeIndex = (sizeof(jump) / sizeof(jump[0]) - 1); sizeIndex >= 0; --sizeIndex) {
        shell_sort_phase(vector, numberOfElements, jump[sizeIndex]);
    }
    return vector;
}

/* GNOME SORT */
long int *GnomeSort(long int *vector, long int numberOfElements) {
    long int aux;
    for (long int i = 0; i <= numberOfElements;) {
        if (vector[i - 1] <= vector[i]) {
            /* Faz as comparações */
            ++i;
        } else {
            /* Faz as trocas */
            aux = vector[i];
            vector[i] = vector[i - 1];
            vector[i - 1] = aux;
            --i;
            if (i == 0) {
                i = 1;
            }
        }
    }
    return vector;
}


/* BOGO SORT */
int sorting(long int *vector, long int elements) {
    long int n = elements;
    /* Compara todos os elementos do vector a partir do último */
    while (--n >= 1) {
        if (vector[n] < vector[n - 1]) {
            return 0;
        }
    }
    return 1;
}

void shuffle(long int *vector, long int elements) {
    long int aux, r;
    for (long int i = 0; i < elements; i++) {
        /* Realiza a troca de posi��es */
        aux = vector[i];
        r = rand() % elements;
        vector[i] = vector[r];
        vector[r] = aux;
    }
}

long int *BogoSort(long int *vector, long int elements) {
    while (!sorting(vector, elements)) {
        shuffle(vector, elements);
    }
    return vector;
}

/* COUTING SORT */
int CSorting(long int *vector, long int elements, long int min, long int max) {
    long int i, k;

    long int range = max - min + 1; /* Determinando faixa */
    long int *count = (long int *) malloc(range * sizeof(*vector)); /* Declara vector auxiliar */

    for (i = 0; i < range; i++) {
        /* Inicializa o vector auxiliar de contagem */
        count[i] = 0;
    }

    for (int i = 0; i < elements; i++) {
        /* vector de contagem recebe a qtde. de vezes (n) que um número k se repete */
        count[vector[i] - min]++;
    }

    /* Substitui 'k' n vezes no vector original */
    for (i = min, k = 0; i <= max; i++) {
        for (long int j = 0; j < count[i - min]; j++) {
            vector[k++] = i;
        }
    }
    free(count);
    return EXIT_SUCCESS;
}

long int *CoutingSort(long int *vector, long int elements) {
    /* Algoritmo de ordenação Couting Sort (Ordenação por contagem)
        Determina uma faixa de valores em que os elementos dos vectores estão,
        encontramdo maior e o menor elemento do vector; Logo, para cada
        elemento k do vector vale que min <= k <= max. O algoritmo então conta
        para cada k quantas vezes esse elemento se repete no vector. Sabendo disso,
        basta repor no vector original (ou em um auxiliar) os valores k ordenados. */
    long int i, min, max;

    min = max = vector[0];

    /* Primeiro passo: Achar o maior e o menor elemento do vector a ser ordenado */
    for (i = 1; i < elements; i++) {
        if (vector[i] < min) {
            min = vector[i];
        } else if (vector[i] > max) {
            max = vector[i];
        }
    }

    CSorting(vector, elements, min, max); /* Passa para a função auxiliar */

    return vector; /* Retorna o vector ordenado */
}