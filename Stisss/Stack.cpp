#include "Stack.h"
#include <stdio.h>

void Push(Stack* stack, char data)
{
	Node* temp = stack->top;
	stack->top = (Node*)malloc(sizeof(Node));
	stack->top->data = data;
	stack->top->pNext = temp;
	stack->Size++;
}

void PrintStack(Stack* stack)
{
	Node* current = stack->top;
	if (stack->Size==0)
	{
		printf("Stack is empty");
		return;
	}
	printf("The stack:");
	for (int i = 0; i < GetSize(stack); i++)
	{
		printf("%c", current->data);
		current = current->pNext;
	}
}

void DeleteTopElem(Stack* stack)
{
	Node* temp = stack->top;
	stack->top = stack->top->pNext;
	free(temp);
	stack->Size--;
}

char TopElem(Stack* stack)
{
	return stack->top->data;
}

void Clear(Stack* stack)
{
	while(stack->Size)
		DeleteTopElem(stack);
}

int GetSize(Stack* stack)
{
	return stack->Size;
}
