//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit3.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
extern char** positions;
extern int size;
int lturn = 0;
int wk = 0;
int bk = 0;
int reversed = 0;
Tile local[64];
int index = 0;
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormActivate(TObject *Sender)
{
	Helper::LoadPositionNoReverse(positions[0], local, &lturn, Form4->Image1, &wk, &bk);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{
	if (index < size - 1)
	{
		index ++;
		Helper::LoadPositionNoReverse(positions[index], local, &lturn, Form4->Image1, &wk, &bk);
		if (reversed == 1)
			Helper::ReverseField(local, Form4->Image1);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button2Click(TObject *Sender)
{
	if (index >= 1)
	{
		index--;
		Helper::LoadPositionNoReverse(positions[index], local, &lturn, Form4->Image1, &wk, &bk);
		if (reversed == 1)
			Helper::ReverseField(local, Form4->Image1);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button3Click(TObject *Sender)
{
    Form4->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button5Click(TObject *Sender)
{
	Helper::ReverseField(local, Form4->Image1);
	reversed = 1 - reversed;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormClose(TObject *Sender, TCloseAction &Action)
{
	index = 0;
    reversed = 0;
}
//---------------------------------------------------------------------------

