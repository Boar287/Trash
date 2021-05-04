//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "BinaryTree.h"
#include "Unit13.h"
#include "string.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
BinaryTree Oak;
String* arr;
int Size=0;
TForm13 *Form13;
bool ShowElement=false;
int TreeIndex;
TTreeNode *TempNode=nullptr;
bool Process=true;
//---------------------------------------------------------------------------
__fastcall TForm13::TForm13(TComponent* Owner)
	: TForm(Owner)
{
}

class TPublicGrid: public  TStringGrid
{
    public:
        using TStringGrid::DeleteRow;
};
//---------------------------------------------------------------------------


void __fastcall TForm13::FormCreate(TObject *Sender)
{
Add->Enabled=false;
Delete->Enabled=false;
Panel1->Hide();
Panel2->Hide();
Panel3->Hide();
Size=(StringGrid1->RowCount)-1;
	arr=new String[Size];
	arr[0]="Timofey Dudich";
	arr[1]="Dmitry Ermolovich";
	arr[2]="Alex Snetko";
	arr[3]="Stanislav Pushkov";
	arr[4]="Eugen Mazur-Grabovskiy";
	StringGrid1->Cells[0][0]="Full Name";
	StringGrid1->Cells[1][0]="¹";
	for(int i=1;i<Size+1;i++)
	{
		StringGrid1->Cells[0][i]=arr[i-1];
	}
	bool isUnique;
	for(int i=1;i<Size+1;i++)
	{
		do
		{
			StringGrid1->Cells[1][i]=IntToStr(rand()%30);
			isUnique=true;
			for(int j=1;j<i;j++)
			{
				if(StringGrid1->Cells[1][i]==StringGrid1->Cells[1][j])
				{
					isUnique=false;
					break;
				}
			}
		}while(!isUnique);
	}
	for(int i=0;i<Size;i++)
	{
		Oak.AddItem(StrToInt(StringGrid1->Cells[1][i+1]),arr[i]);
	}

	Oak.GetNumberOfTwoDaughter(Memo2);
	TreeView1->FullExpand();
	if(Oak.IsBalanced()==false)
	{
		Rebalance->Enabled=true;
	}
	Oak.ShowTree(TreeView1);
}
//---------------------------------------------------------------------------
void __fastcall TForm13::FormClose(TObject *Sender, TCloseAction &Action)
{
	delete[]arr;
	delete TempNode;
}
//---------------------------------------------------------------------------
void __fastcall TForm13::PrintClick(TObject *Sender)
{
Memo1->Lines->Clear();
if(StringGrid1->RowCount!=1)
{
	if(ShowElement==true)
	{
		for(int i=1;i<Show->Text.Length();i++)
	{
		if(!((Show->Text[i]>='0')&&(Show->Text[i]<='9')))
		{
		   ShowMessage("Only numbers are avelaible");
		   return;
		}
	}
		Memo1->Lines->Strings[0]=Oak.SearchFor(StrToInt(Show->Text));
        Show->Text="";
		return;
	}
	switch(ComboBox1->ItemIndex)
	{
		case 0:
			Oak.PrintNLR(Memo1);
		break;
		case 1:
			Oak.PrintLNR(Memo1);
		break;
		case 2:
			Oak.PrintLRN(Memo1);
		break;
	}
	Print->Enabled=false;
}
else
{
ShowMessage("Empty tree");
return;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm13::ComboBox1Change(TObject *Sender)
{
    Print->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall TForm13::Button1Click(TObject *Sender)
{
if(Add->Enabled==true)
{
	Name->Text="";
	Number->Text="";
	Add->Enabled=false;
	Panel1->Hide();
	return;
}

	Panel1->Show();
	Add->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm13::AddClick(TObject *Sender)
{

	String SNumber=Number->Text;
	String SName=Name->Text;
	if((SName=="")||(SNumber==""))
	{
		ShowMessage("Empty field");
		return;
	}

	for(int i=1;i<SNumber.Length();i++)
	{
		if(!((SNumber[i]>='0')&&(SNumber[i]<='9')))
		{
		   ShowMessage("Only numbers are avelaible");
		   return;
		}
	}
	for(int i=1;i<SName.Length();i++)
	{
		if(!(((int)SName[i]>=65))&&(((int)SName[i]<=122)))
		{
			if(SName[i]!=' ')
			{
			ShowMessage("Only letters are avelaible");
			return;
			}
		}
	}


	try
	{
		Oak.AddItem(StrToInt(Number->Text),Name->Text);
	}
	catch(String&ex)
	{
		ShowMessage(ex);
		return;
	}
	StringGrid1->RowCount++;
	StringGrid1->Cells[0][StringGrid1->RowCount-1]=SName;
	StringGrid1->Cells[1][StringGrid1->RowCount-1]=SNumber;
	Name->Text="";
	Number->Text="";
	Add->Enabled=false;
	Panel1->Hide();
	Oak.GetNumberOfTwoDaughter(Memo2);
	if(Oak.IsBalanced()==false)
	{
		Rebalance->Enabled=true;
	}
    Oak.ShowTree(TreeView1);
}
//---------------------------------------------------------------------------

void __fastcall TForm13::Button2Click(TObject *Sender)
{
if(Delete->Enabled==true)
{
	DeleteP->Text="";
	Delete->Enabled=false;
	Panel2->Hide();
	return;
}
if(StringGrid1->RowCount==1)
{
	ShowMessage("Empty tree");
    return;
}
	Panel2->Show();
    Delete->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm13::DeleteClick(TObject *Sender)
{

	String SNumber=DeleteP->Text;

	if(SNumber=="")
	{
		ShowMessage("Empty field");
		return;
	}

	for(int i=1;i<SNumber.Length();i++)
	{
		if(!((SNumber[i]>='0')&&(SNumber[i]<='9')))
		{
		   ShowMessage("Only numbers are avelaible");
		   return;
		}
	}
	for(int i=0;i<StringGrid1->RowCount;i++)
	{
		if(StringGrid1->Cells[1][i]==SNumber)
		{
			((TPublicGrid*)StringGrid1)->DeleteRow(i);
		}
	}
	Oak.DeleteItem(StrToInt(SNumber));
	DeleteP->Text="";
	Delete->Enabled=false;
	Panel2->Hide();
	Oak.GetNumberOfTwoDaughter(Memo2);
	if(Oak.IsBalanced()==false)
	{
		Rebalance->Enabled=true;
	}
    Oak.ShowTree(TreeView1);
}
//---------------------------------------------------------------------------


void __fastcall TForm13::Button3Click(TObject *Sender)
{
if(Print->Enabled==true)
{
	ShowElement=false;
	Print->Enabled=false;
	Panel3->Hide();
    Memo1->Lines->Clear();
	return;
}
	Panel3->Show();
	ShowElement=true;
	Print->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm13::ClearClick(TObject *Sender)
{
	Memo1->Lines->Clear();
	Show->Text="";
	DeleteP->Text="";
	Name->Text="";
	Number->Text="";
}
//---------------------------------------------------------------------------



void __fastcall TForm13::RebalanceClick(TObject *Sender)
{
	Oak.GetNumberOfTwoDaughter(Memo2);
	Oak.ReReBalance();
	Rebalance->Enabled=false;
	Oak.ShowTree(TreeView1);
	Oak.GetNumberOfTwoDaughter(Memo2);
}
//---------------------------------------------------------------------------

