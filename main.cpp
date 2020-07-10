// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "settings.h"
#include "MyClass.h"
#include <ctime>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Game *game;
short w, h, size, StartMoney, colvo; //������, ������ ����. ������ ������, ��������� ������, ���������� ��������
bool Auto; //����� ����

//-------------------����������� �����---------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	srand(time(NULL));                                       

	w = 50, h = 50, size = 10, StartMoney = 30, colvo = 100;
	Auto = 1;
	
	game = new Game(this->Canvas, w, h, colvo, size, StartMoney, Auto);
	this->ClientHeight = h*size;
}
// ------------------������ �����--------------------------------------------

void __fastcall TForm1::Start1Click(TObject *Sender)
{
	Timer1->Enabled = 1;
}
//-------------------������ ����---------------------------------------------

void __fastcall TForm1::Stop1Click(TObject *Sender)
{
	Timer1->Enabled = 0;
}
//-------------------������ ����������---------------------------------------

void __fastcall TForm1::Restart1Click(TObject *Sender)
{
	game = new Game(this->Canvas, w, h, colvo, size, StartMoney, Auto);
	game->show();
	Label2->Caption = "������: " + String(game->GetBotSize()) + "\n������: " + String(game->GetBotMoney());
	Label3->Caption = "���������: " + String(game->GetPlayerSize()) + "\n������: " + String(game->GetPlayerMoney());;
}
//-------------------������ "����� ����"-------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	if (game->GetBotSize() <= colvo * 0.1) {
		Stop1Click(Sender);
		ShowMessage("�o������ ��������!");
		Restart1Click(Sender);
		return;
	}
	if (game->GetPlayerSize() <= colvo * 0.1) {
		Stop1Click(Sender);
		ShowMessage("���������� ��������!");
		Restart1Click(Sender);
		return;	
	}

	game->live();
	Label2->Caption = "������: " + String(game->GetBotSize()) + "\n������: " + String(game->GetBotMoney());
	Label3->Caption = "���������: " + String(game->GetPlayerSize()) + "\n������: " + String(game->GetPlayerMoney());;
	
	Label4->Visible = false;
	Label5->Visible = false;
	Button1->Visible = false;
}
//-------------------��������� ��������--------------------------------------

void __fastcall TForm1::SpeedChange(TObject *Sender)
{
	Label1->Caption = "�������� �" + String(Speed->Position);
	Timer1->Interval = 1000/Speed->Position;
}
//-------------------��� ����������� �����-----------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
	Restart1Click(Sender);
}
//-------------------������ ��������-----------------------------------------

void __fastcall TForm1::Settings1Click(TObject *Sender)
{
	if (w == 50)  Form2->RadioGroup1->ItemIndex = 1;
	else Form2->RadioGroup1->ItemIndex = 0;

	short sloshnost = Form2->RadioGroup1->ItemIndex;
	Form2->ScrollBar1->Position = colvo;
	Form2->Auto1->Checked = Auto;

	bool last = Timer1->Enabled;
	Stop1Click(Sender);
	if (Form2->ShowModal() == mrOk){
		if (Form2->RadioGroup1->ItemIndex != sloshnost || Form2->ScrollBar1->Position != colvo
			|| Form2->Auto1->Checked != Auto) {
			sloshnost = Form2->RadioGroup1->ItemIndex;
			if (sloshnost == 1) {w = 50; h = 50; size = 10;}
			else if (sloshnost == 0) {w = 25; h = 25; size = 20;}
			colvo = Form2->ScrollBar1->Position; 
			Auto = Form2->Auto1->Checked;

			if (Auto) Speed->Max = 20;
			else Speed->Max = 5;

			Restart1Click(Sender);
		}
	}
    Timer1->Enabled = last;
}
//-------------------������� �� �����----------------------------------------

void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	if (Button == mbLeft) {
		if (X < w*size && Y < h*size) {
			short x = X/size;
			short y = Y/size;

			Micro tmp = game->GetMicro(TPoint(x,y));
			if (tmp.player == 2) return;

			Stop1Click(Sender);
			if (tmp.player == 1) Label4->Caption = "�������";
			else Label4->Caption = "���������"; 
			Label5->Caption = "����: " + String(tmp.sila);
			
			Label4->Visible = true;   
			Label5->Visible = true;
			if (!Auto && tmp.player == 1){ 
				Button1->Visible = true; 
				game->show();
			}
			else Button1->Visible = false;
		}	
	}
}
//-------------------�������� "������" �������-------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Label5->Caption = "����: " + String(game->update());
	Label3->Caption = "���������: " + String(game->GetPlayerSize()) + "\n������: " + String(game->GetPlayerMoney());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N1Click(TObject *Sender)
{            	
	AnsiString tmp = "��� ������� �� �������, ����� �������� ��� ����������\n";  
	tmp += "���� ����� �� ���� � ������ �� ��������, ��� ����� �������\n";
	tmp += "��������� ��� � ���� �������� ������ 10% ��������";
	ShowMessage(tmp);
}
//---------------------------------------------------------------------------

