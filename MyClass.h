// ---------------------------------------------------------------------------

#ifndef MyClassH
#define MyClassH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <vector>

// ---------------------------------------------------------------------------

struct Micro{ //��������� ��� ������ ���, � ������� �������
	short player; //���� ����������� �����/���
	short sila;   //����
	Micro(short player, short sila);  //�����������
};

class MicroObj {
	void draw(int col1, int col2); // �-� ���������

	TCanvas *device;
	short size; // ������
	int col2; // ���� �������

public:
	int x, y; // ���������� ����������
	int col1; // ���� (�������� ������� ���� ��������)
    short sila;  //���� �������
	// ����� �� ������ (����� ����� ������ �������� ������ �� �����������)

	MicroObj(TCanvas *canv, short x, short y, short size, int col);

	void show() { // ������� �������� (�������)
		draw(col1, col2);
	}
};

class Player {
	TCanvas *device;
	short size; // ����� �� ������� �������� ��
    TPoint max; //������������ ������� ����

public:
	short Money; //���������� �����
	int color; // ���� �������
	std::vector<MicroObj*>microbs; // ������ �������� =)

	Player(TCanvas *canv, short size, int col, TPoint max, short colv, short StartMoney);

	void show(); // ��������� ����
	void del(short num); //������� ������� "num" �� �������
	void add();          //�������� ������� � ������
};

class Game {
	TCanvas *device;
	short w, h; // ������� ����
	Player *player; // �����
	Player *bot; // ���
	short size; // ������ ����� ������ ����
	short colvo; // ���������� �������� �� ������
    bool rezim; //���� ���� ��� ����� ��� ������������ ����

    short last; //��������� ������, �� ������� ������

	void PlayerHod(); //��� ������
	void BotHod();    //��� ����

public:
	Game(TCanvas *canv, short w, short h, short colvo, short size, short StartMoney, bool rezim);
	void show();      //��������� �����
	void live();      //�����
	int GetBotSize(){return bot->microbs.size(); } //����� ���������� �������� � ����
	int GetPlayerSize(){return player->microbs.size(); } //����� ���������� �������� � ������
	Micro GetMicro(TPoint last);
	int GetPlayerMoney(){return player->Money; }   //����� ���������� ����� � ������
	int GetBotMoney(){return bot->Money; }         //����� ���������� ����� � ����
	int update();                                  //���������� ���� ���������� ��������� �������
};

#endif
