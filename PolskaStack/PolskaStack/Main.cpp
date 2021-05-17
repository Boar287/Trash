#include "Stack.h"

int main()
{
    Stack stack;
    for (int i = 1; i <= 5; i++)
    {
        stack.Add(i);
    }
    for (int i = 0; i < 4; i++)
    {
        cout << stack.GetTopElem() << " ";
        stack.DeleteTopElem();
    }
    cout << endl;
    for (int i = 6; i <= 10; i++)
    {
        stack.Add(i);
    }
    stack.PrintStack();
    return 0;
}