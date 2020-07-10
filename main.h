// ---------------------------------------------------------------------------

#ifndef mainH
#define mainH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>

// ---------------------------------------------------------------------------
class TForm1 : public TForm {
__published: // IDE-managed Components
	TMainMenu *MainMenu1;
	TTimer *Timer1;
	TMenuItem *Start1;
	TMenuItem *Stop1;
	TMenuItem *Restart1;
	TLabel *Label1;
	TScrollBar *Speed;
	TLabel *Label2;
	TLabel *Label3;
	TMenuItem *Settings1;
	TLabel *Label4;
	TLabel *Label5;
	TButton *Button1;
	TMenuItem *N1;
	void __fastcall Start1Click(TObject *Sender);
	void __fastcall Stop1Click(TObject *Sender);
	void __fastcall Restart1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall SpeedChange(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Settings1Click(TObject *Sender);
	void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TForm1(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------
#endif
