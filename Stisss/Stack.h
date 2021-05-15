#pragma once
#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct node
{
	struct node* pNext;
	char data;
} Node;

typedef struct stack
{
	int Size = 0;
	Node* top;
} Stack;

void Push(Stack* stack, char data);
void PrintStack(Stack* stack);
void DeleteTopElem(Stack* stack);
char TopElem(Stack* stack);
void Clear(Stack* stack);
int GetSize(Stack* stack);