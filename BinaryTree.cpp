//---------------------------------------------------------------------------

#pragma hdrstop

#include "BinaryTree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void BinaryTree::DestroyNode(TNode*node)
{
	if (node!=nullptr)//Проверка на существование нода
	{
		DestroyNode(node->left);
		DestroyNode(node->right);
		delete node;
	}
}

void BinaryTree::AddItem(int x,String Surname)
{
	Insert(x,Surname, Root);
}

void BinaryTree::DeleteItem(int x)
{
	Delete(x,Root);
}


void BinaryTree::Insert(int x,String Surname,TNode*&node)
{
	if (!ElementExist(Root, x))
	{
		if (node == nullptr)
			node = new TNode(x, Surname);
		else
		{
			if (x < node->Key)
				Insert(x, Surname, node->left);

			if (x > node->Key)
				Insert(x, Surname, node->right);

		}
	}
	else
		throw Exception("The key "+IntToStr(x)+" is alredy exist");
}

void BinaryTree::Delete(int x, TNode*& node)
{
	if (ElementExist(Root, x))
	{
		if (x == node->Key)
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
					temp = ptr;
					node = new TNode(*temp);
					delete temp;
					return;
				}
			}
		}
		else if (x < node->Key)
			Delete(x, node->left);
		else
			Delete(x, node->right);
	}
	else
		ShowMessage("There is no element with such index");
}

void BinaryTree::NLR(TNode*& node,TMemo *Memo1)
{
	if (node != nullptr)
	{
		Memo1->Lines->Strings[0]+=(IntToStr(node->Key)+" ");
		NLR(node->left,Memo1);
		NLR(node->right,Memo1);
	}
}

void BinaryTree::LNR(TNode*&node,TMemo *Memo1)
{
	if (node != nullptr)
	{
		LNR(node->left,Memo1);
		Memo1->Lines->Strings[0]+=(IntToStr(node->Key)+" ");
		LNR(node->right,Memo1);
	}
}

void BinaryTree::LRN(TNode*& node,TMemo *Memo1)
{
	if (node != nullptr)
	{
		LRN(node->left,Memo1);
		LRN(node->right,Memo1);
		Memo1->Lines->Strings[0]+=(IntToStr(node->Key)+" ");
	}
}

void BinaryTree::ReReBalance()
{
	ReBalance(Root);
}
////////////////////////////////////////////////////////////
int BinaryTree::GetHeight(TNode* node)
{
	if (node == nullptr)
		return 0;
	else
	{
		if (GetHeight(node->left) > GetHeight(node->right))
			return 1 + GetHeight(node->left);
		else
			return 1 + GetHeight(node->right);
	}
}

int BinaryTree::Balance(TNode* node)
{
	if (node == nullptr)
		return 0;
	return GetHeight(node->right) - GetHeight(node->left);
}

void BinaryTree::FixHeight(TNode* node)
{
	int HeightLeft = GetHeight(node->left);
	int HeightRight = GetHeight(node->right);
	node->height = (HeightLeft > HeightRight ? HeightLeft : HeightRight) + 1;
}

void BinaryTree::RotateRight(TNode*&node)
{
	TNode* temp = node->left;
	node->left = temp->right;
	temp->right = node;
	FixHeight(node);
	FixHeight(temp);
	node =new TNode(*temp);
	delete temp;
}

void BinaryTree::RotateLeft(TNode*&node)
{
	TNode* temp = node->right;
	node->right = temp->left;
	temp->left = node;
	FixHeight(temp);
	FixHeight(node);
	node = new TNode(*temp);
	delete temp;
}

void BinaryTree::ReBalance(TNode*&node)
{
	while(!isBalanced(Root))
	{
		if (node != nullptr)
		{
			FixHeight(node);
			if (Balance(node) >= 2)
			{
				if (Balance(node->right) < 0)
					RotateRight(node->right);
				RotateLeft(node);

			}
			if (Balance(node) <= -2)
			{
				if (Balance(node->left) > 0)
					RotateLeft(node->left);
				RotateRight(node);
			}
		}
	}
}

bool BinaryTree::isBalanced(TNode* node)
{
	int lh;
	int rh;
	if (Root == nullptr)
		return 1;
	lh = GetHeight(Root->left);
	rh = GetHeight(Root->right);

	if (abs(lh - rh) <= 1) /*&& isBalanced(Root->left) && isBalanced(Root->right))*/
		return 1;
	return 0;
}


bool BinaryTree::IsBalanced()
{
    return isBalanced(Root);
}
////////////////////////////////////////////////////////

String BinaryTree::Search(TNode* node,int x)
{
	if (ElementExist(Root, x))
	{
		if (node->Key == x)
			return node->Surname;
		if (x < node->Key)
			return Search(node->left, x);
		else
			return Search(node->right, x);
	}
	else
		ShowMessage("No element with such key");

}

bool BinaryTree::ElementExist(TNode* node, int x)
{
	if (node == nullptr)
		return false;
	else if (node->Key == x)
		return true;

	if (x < node->Key)
		return ElementExist(node->left, x);
	else
		return ElementExist(node->right, x);
}

void BinaryTree::PrintNLR(TMemo*Memo1)
{
	NLR(Root,Memo1);
}

void BinaryTree::PrintLNR(TMemo*Memo1)
{
	LNR(Root,Memo1);
}

void BinaryTree::PrintLRN(TMemo*Memo1)
{
	LRN(Root,Memo1);
}

String BinaryTree::SearchFor(int x)
{
	return Search(Root, x);
}

void BinaryTree::GetNumberOfTwoDaughter(TMemo *Memo2)
{
	CountTwoDaughterBranches(Root,Memo2);
    Memo2->Lines->Clear();
	Memo2->Lines->Strings[0]="Number of branches with two daughters:"+IntToStr(TwoDaughters);
	TwoDaughters = 0;
}

void BinaryTree::CountTwoDaughterBranches(TNode*& node,TMemo* Memo2)
{
	if (node != nullptr)
	{
		if ((node->left != nullptr) && (node->right != nullptr))
		{
			node->Alone=true;
			TwoDaughters++;
		}

		CountTwoDaughterBranches(node->left,Memo2);
		CountTwoDaughterBranches(node->right,Memo2);
	}
}

void BinaryTree::ShowTree(TTreeView*TreeView1)
{
	int index=0;
	TreeView1->Items->Clear();
	if(Root)
	{
		TreeView1->Items->Add(nullptr,Root->Surname);
		PrintTreeR(Root,TreeView1,index);
	}
    TreeView1->FullExpand();
}

void BinaryTree::PrintTreeR(TNode*temp,TTreeView*TreeView1,int&index)
{
	 int i=index;
	 if(temp->left)
	 {
		 TreeView1->Items->AddChild(TreeView1->Items->Item[i],temp->left->Surname);
		 PrintTreeR(temp->left,TreeView1,++index);
	 }
	 if(temp->right)
	 {
		 TreeView1->Items->AddChild(TreeView1->Items->Item[i],temp->right->Surname);
		 PrintTreeR(temp->right,TreeView1,++index);
	 }
}



