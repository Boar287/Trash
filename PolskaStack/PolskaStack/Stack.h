#pragma once
#include <iostream>
using namespace std;

struct Stack
{
public:
	Stack();
	~Stack();
	void Add(int Data);
	void DeleteTopElem();
	void Clear();
	int GetSize();
	void PrintStack();
	int GetTopElem();
private:
	struct Node
	{
	public:
		Node* pNext;
		int Data;
		Node(int Data = 0, Node* pNext = nullptr)
		{
			this->Data = Data;
			this->pNext = pNext;
		}
	};
	int Size = 0;
	int MaxSize = 7;
	Node* Top;
};

