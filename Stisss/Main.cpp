#include "Functions.h"

int main()
{
	Stack stack;
	char theExample[30];
	printf("Enter the example:");
	fgets(theExample, 30, stdin);
	FillTheStack(&stack, theExample);
	PrintStack(&stack);
	return 0;
}