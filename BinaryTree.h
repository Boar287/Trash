//---------------------------------------------------------------------------

#ifndef BinaryTreeH
#define BinaryTreeH
#include <vcl.h>

class BinaryTree
{
public:
	class TNode
	{
	public:
		TNode(int Key,String Surname)
		{
			this->Key = Key;
			this->Surname = Surname;
			this->right = nullptr;//Данный нод является листом (нет потомков)
			this->left = nullptr;
		}
		TNode(TNode&other)
		{
			this->Key = other.Key;
			this->Surname = other.Surname;
			this->right = other.right;
			this->left = other.left;
			this->height=other.height;
			this->Alone=other.Alone;
		}
		int height;
		int Key;
		String Surname;
		TNode* left;
		TNode* right;
		bool Alone;
	};
	~BinaryTree()
	{
		DestroyNode(Root);
	}
	BinaryTree()
	{
		Root = nullptr;
	}

	void DestroyNode(TNode* node);
	void AddItem(int x,String Surname);
	void DeleteItem(int x);
	void PrintNLR(TMemo*Memo1);
	void PrintLNR(TMemo*Memo1);
	void PrintLRN(TMemo*Memo1);
	void ReReBalance();
	bool IsBalanced();
	String SearchFor(int x);
    void GetNumberOfTwoDaughter(TMemo* Memo2);
	void ShowTree(TTreeView*TTreeView1);
protected:
	void Insert(int x,String Surname,TNode*&node);
	void Delete(int x, TNode*& node);
	void NLR(TNode*& node,TMemo *Memo1);
	void LNR(TNode*& node,TMemo *Memo1);
	void LRN(TNode*& node,TMemo *Memo1);
	////////////////////////////////Rotations
	int GetHeight(TNode* node);
	int Balance(TNode* node);
	void FixHeight(TNode* node);
	void RotateRight(TNode*&node);
	void RotateLeft(TNode*&node);
	void ReBalance(TNode*&node);
	bool isBalanced(TNode* node);
	///////////////////////////////////
	String Search(TNode* node,int x);
	bool ElementExist(TNode* node, int x);
    void CountTwoDaughterBranches(TNode*&node,TMemo *Memo2);
	void PrintTreeR(TNode*temp,TTreeView*TreeVIew1,int&index);
	TNode* Root;
	int TwoDaughters=0;
};

//---------------------------------------------------------------------------
#endif
