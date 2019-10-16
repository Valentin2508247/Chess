//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
Tile here[4];
TColor bbTile = clDkGray;
TColor wwTile = clCream;
extern int turn;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::FormActivate(TObject *Sender)
{
	TColor coltile;
	here[0].left = 0;
	here[0].top = 0;
	here[0].right = 80;
	here[0].bottom = 80;
	here[0].piece = 2;
	here[0].colr = turn;
	here[0].color = wwTile;
	here[1].left = 80;
	here[1].top = 0;
	here[1].right = 160;
	here[1].bottom = 80;
	here[1].piece = 3;
	here[1].colr = turn;
	here[1].color = bbTile;
	here[2].left = 160;
	here[2].top = 0;
	here[2].right = 240;
	here[2].bottom = 80;
	here[2].piece = 5;
	here[2].colr = turn;
	here[2].color = wwTile;
	here[3].left = 240;
	here[3].top = 0;
	here[3].right = 320;
	here[3].bottom = 80;
	here[3].piece = 8;
	here[3].colr = turn;
	here[3].color = bbTile;
	for (int i = 0; i < 4; i++)
		here[i].Show(Form5->Image1);
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if (X >= 0 && X <= 80 && Y >= 0 && Y <= 80)
	{
		Form5->ModalResult = 2;
	}
	if (X >= 80 && X <= 160 && Y >= 0 && Y <= 80)
	{
		Form5->ModalResult = 3;
	}
	if (X >= 160 && X <= 240 && Y >= 0 && Y <= 80)
	{
		Form5->ModalResult = 5;
	}
	if (X >= 240 && X <= 320 && Y >= 0 && Y <= 80)
	{
		Form5->ModalResult = 8;
	}
}
//---------------------------------------------------------------------------