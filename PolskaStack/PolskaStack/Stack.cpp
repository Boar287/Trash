#include "Stack.h"

void Stack::Add(int Data)
{
    if (Size < MaxSize)
    {
        Top = new Node(Data, Top);
        Size++;
    }
    else
        cout << "Only 7 element can be stacked" << endl;
}

void Stack::DeleteTopElem()
{
    Node* temp = Top;
    Top = Top->pNext;
    delete temp;
    Size--;
}

void Stack::Clear()
{
    while (Size)
        DeleteTopElem();
}

int Stack::GetSize()
{
    return Size;
}

void Stack::PrintStack()
{
    Node* temp = Top;
    for (int i = 0; i < this->Size; i++)
    {
        cout << temp->Data << " ";
        temp = temp->pNext;
    }
}

int Stack::GetTopElem()
{
    return this->Top->Data;
}

Stack::Stack()
{
    Size = 0;
    Top = nullptr;
}

Stack::~Stack()
{
    Size = 0;
    Top = nullptr;
}
