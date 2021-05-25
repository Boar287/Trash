#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	Root = nullptr;
}

BinaryTree::~BinaryTree()
{
	DeleteRoot(Root);
}

void BinaryTree::Add(int Key, string Data)
{
	if (IsExist(Root, Key) == "0")
	{
		AddInfo(Root, Key, Data);
	}
	else
	{
		cout << "The key " << Key << " is already exist" << endl;
		return;
	}
}

string BinaryTree::Search(int Key)
{
	return IsExist(Root, Key);
}

void BinaryTree::DeleteItem(int Key)
{
	if (IsExist(Root, Key)!="0")
	{
		Delete(Root, Key);
	}
	else
	{
		cout << "There is no element with key:" << Key <<endl;
		return;
	}
}

void BinaryTree::PrintNLR()
{
	NLR(Root);
}

void BinaryTree::PrintLNR()
{
	LNR(Root);
}

void BinaryTree::PrintLRN()
{
	LRN(Root);
}

void BinaryTree::PrintTask(char symbol)
{
	Task(Root, symbol);
}

void BinaryTree::DeleteRoot(TNode* node)
{
	if (node != nullptr)
	{
		DeleteRoot(node->left);
		DeleteRoot(node->right);
		delete node;
	}
}

string BinaryTree::IsExist(TNode* node, int Key)
{
	if (node == nullptr)
		return "0";
	if (node->Key == Key)
		return node->Data;

	if (Key < node->Key)
		return IsExist(node->left,Key);
	else
		return IsExist(node->right,Key);
}

void BinaryTree::AddInfo(TNode*& node, int Key, string Data)
{
	if (node == nullptr)
		node = new TNode(Key, Data);
	else
	{
		if (Key < node->Key)
			AddInfo(node->left, Key, Data);
		else
			AddInfo(node->right, Key, Data);
	}
}

void BinaryTree::Delete(TNode*& node, int Key)
{
	if (Key == node->Key)
	{
		if (node->right == nullptr)
		{
			TNode* temp = node;
			node = node->left;
			delete temp;
			return;
		}
		else
		{
			TNode* temp = node->right;
			if (temp->left == nullptr)
			{
				temp->left = node->left;
				node = new TNode(*temp);
				delete temp;
				return;
			}
			else
			{
				TNode* ptr = temp->left;
				while (ptr->left != nullptr)
				{
					temp = ptr;
					ptr = ptr->left;
				}
				temp->left = ptr->right;
				ptr->left = node->left;
				ptr->right = node->right;
				node = new TNode(*ptr);
				delete temp;
				delete ptr;
				return;
			}
		}
	}
	else if (Key < node->Key)
		Delete(node->left, Key);
	else
		Delete(node->right, Key);
}

void BinaryTree::NLR(TNode* node)
{
	if (node != nullptr)
	{
		cout << node->Data << endl;
		NLR(node->left);
		NLR(node->right);
	}
}

void BinaryTree::LNR(TNode* node)
{
	if (node != nullptr)
	{
		LNR(node->left);
		cout << node->Data << endl;
		LNR(node->right);
	}
}

void BinaryTree::LRN(TNode* node)
{
	if (node != nullptr)
	{
		LRN(node->left);
		LRN(node->right);
		cout << node->Data << endl;
	}
}

void BinaryTree::Task(TNode* node, char symbol)
{
	if (node != nullptr)
	{
		if (node->Data[0] == symbol || node->Data[0] == char((int)symbol-32))
			cout << node->Data << endl;
		Task(node->left,symbol);
		Task(node->right,symbol);
	}
}
