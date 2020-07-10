//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "settings.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ScrollBar1Change(TObject *Sender)
{
    Label1->Caption = "Количество: " + String(ScrollBar1->Position);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormShow(TObject *Sender)
{
    Label1->Caption = "Количество: " + String(ScrollBar1->Position);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioGroup1Click(TObject *Sender)
{
	if (RadioGroup1->ItemIndex == 1){
		ScrollBar1->Max = 100;
		ScrollBar1->Position *= 2;
	}
	else if (RadioGroup1->ItemIndex == 0) {
		ScrollBar1->Position /= 2;
		ScrollBar1->Max = 50;
	}

	Label1->Caption = "Количество: " + String(ScrollBar1->Position);
}
//---------------------------------------------------------------------------

