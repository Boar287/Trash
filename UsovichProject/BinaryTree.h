#pragma once
#include <iostream>
using namespace std;


class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	void Add(int Key,string Data);
	string Search(int Key);
	void DeleteItem(int Key);
	void PrintNLR();
	void PrintLNR();
	void PrintLRN();
	void PrintTask(char symbol);
private:
	class TNode
	{
	public:
		TNode(int Key, string Data)
		{
			this->Key = Key;
			this->Data = Data;
			this->left = nullptr;
			this->right = nullptr;
		}
		TNode(TNode& other)
		{
			this->Key = other.Key;
			this->Data = other.Data;
			this->right = other.right;
			this->left = other.left;
		}
		int Key;
		string Data;
		TNode* left;
		TNode* right;
	};
	TNode* Root;
	void DeleteRoot(TNode* node);
	string IsExist(TNode* node, int Key);
	void AddInfo(TNode*& node, int Key, string Data);
	void Delete(TNode*& node, int Key);
	void NLR(TNode* node);
	void LNR(TNode* node);
	void LRN(TNode* node);
	void Task(TNode* node, char symbol);
};

