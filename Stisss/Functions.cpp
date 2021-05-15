#include "Functions.h"

void FillTheStack(Stack* stack, char example[])
{
	int Index = 0;
	while (example[Index] != '\0')
	{
		if (example[Index] == '(' || example[Index] == '{' || example[Index] == '[')
			Push(stack, example[Index]);
		if (example[Index] == ')' || example[Index] == '}' || example[Index] == ']')
		{
			if (CompOfBrackets(TopElem(stack),example[Index]))
				DeleteTopElem(stack);
		}
		Index++;
	}
}

bool CompOfBrackets(char FirstBracket, char SecondBracket)
{
	if(FirstBracket=='(' && SecondBracket==')')
		return true;
	if (FirstBracket == '{' && SecondBracket == '}')
		return true;
	if (FirstBracket == '[' && SecondBracket == ']')
		return true;
	return false;
}
