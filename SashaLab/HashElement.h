#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct hashElement
{
	int Key;
	int Data[5];
}HashElement;

int HashFunction(int Data);
void PrintHashTable(int SIZE, HashElement* HashTable);
void AddHashElement(int key, HashElement*& HashTable);
int SearchForMax(HashElement* HashTable,int SIZE);


