
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Huffman.h"
#define DEBUG

// Codifica uma string em uma árvore de Huffman
huffmantreenode* encodeHuffman(char* myString)
{
	int stringSize = strlen(myString);
	int vectorSize = 0;
	int position = 0;
	int occurrence = 0; 
	int sum = 0; // Quantidade Total de Strings
	double frequency;
	char character;
	if (myString == NULL)
		return NULL;
	int* occurrences = (int*)malloc(stringSize*sizeof(int));
	double* frequencies = (double*)malloc(stringSize*sizeof(double));
	char* characters = (char*)malloc((stringSize + 1)*sizeof(char));
	char* string = (char*)malloc((stringSize + 1)*sizeof(char));
	strcpy(string, myString);
	FILE* file = fopen("tmpHuffmanOutputFile", "w");
	// Conta as ocorrências de cada caractere
	for (int i = 0; i < stringSize; i++) {
		if (string[i] != '@') {
			occurrence = 1;
			character = string[i];
			characters[position] = string[i];
			string[i] = '@';
			for (int j = (i + 1); j < stringSize; j++) {
				if (string[j] == character) {
					occurrence++;
					string[j] = '@';
				}
			}
			occurrences[position] = occurrence;
			position++;
			vectorSize++;
		}
		occurrence = 0;
	}
#ifdef DEBUG
	for (int i = 0; i < vectorSize; i++) {
		printf("%c \t %d \n", characters[i], occurrences[i]);
	}
#endif
	for (int i = 0; i < vectorSize; i++) {
		sum = sum + occurrences[i];
	}
	// Ordena os caracteres pela quantidade de ocorrencias
	long int _intaux = 0;
	static unsigned char _charaux = ' ';
	for (long int i = 0; i < vectorSize; i++) {
		for (long int j = 0; j < (vectorSize - 1); j++) {
			if (occurrences[j] > occurrences[j + 1]) {
				_intaux = occurrences[j];
				occurrences[j] = occurrences[j + 1];
				occurrences[j + 1] = _intaux;
				
				_charaux = characters[j];
				characters[j] = characters[j + 1];
				characters[j + 1] = _charaux;
				
			}
		}
	}
#ifdef DEBUG
	printf("\nOrdenado \n");
	for (int i = 0; i < vectorSize; i++) {
		printf("%c \t %d \n", characters[i], occurrences[i]);
	}
#endif

	return NULL;
}

// Decodifica uma árvore de Huffman
char* decodeHuffman(huffmantreenode* huffmanTree){
	return NULL;
}

