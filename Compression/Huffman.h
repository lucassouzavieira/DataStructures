#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "..\TAD.h"

huffmantreenode* encodeHuffman(char* myString);

char* decodeHuffman(huffmantreenode* huffmanTree);

#endif // !HUFFMAN_H