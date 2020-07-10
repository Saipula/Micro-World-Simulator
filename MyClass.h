// ---------------------------------------------------------------------------

#ifndef MyClassH
#define MyClassH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <vector>

// ---------------------------------------------------------------------------

struct Micro{ //Структура для выдачи инф, о нажатом объекте
	short player; //Кому пренадлежит Игрок/Бот
	short sila;   //Сила
	Micro(short player, short sila);  //Конструктор
};

class MicroObj {
	void draw(int col1, int col2); // Ф-я рисования

	TCanvas *device;
	short size; // Размер
	int col2; // Цвет контура

public:
	int x, y; // Координаты нахождения
	int col1; // Цвет (Основное отличие груп микробов)
    short sila;  //Сила объекта
	// Новый ли микроб (нужно чтобы только созданый микроб не перемещался)

	MicroObj(TCanvas *canv, short x, short y, short size, int col);

	void show() { // Рисовка квадрата (микроба)
		draw(col1, col2);
	}
};

class Player {
	TCanvas *device;
	short size; // Канва на которой рисуется всё
    TPoint max; //Максимальные размеры поля

public:
	short Money; //Количество очков
	int color; // Цвет микроба
	std::vector<MicroObj*>microbs; // Вектор микробов =)

	Player(TCanvas *canv, short size, int col, TPoint max, short colv, short StartMoney);

	void show(); // Отрисовка всех
	void del(short num); //Удалить микроба "num" из вектора
	void add();          //Добавить микроба в вектор
};

class Game {
	TCanvas *device;
	short w, h; // Размеры поля
	Player *player; // Игрок
	Player *bot; // Бот
	short size; // Размер одной ячейки поля
	short colvo; // Количество микробов на старте
    bool rezim; //Авто игра или игрок сам распределяет очки

    short last; //последний микроб, на который нажали

	void PlayerHod(); //Ход игрока
	void BotHod();    //Ход бота

public:
	Game(TCanvas *canv, short w, short h, short colvo, short size, short StartMoney, bool rezim);
	void show();      //Отрисовка всего
	void live();      //Жизнь
	int GetBotSize(){return bot->microbs.size(); } //Выдаёт количество микробов у бота
	int GetPlayerSize(){return player->microbs.size(); } //Выдаёт количество микробов у игрока
	Micro GetMicro(TPoint last);
	int GetPlayerMoney(){return player->Money; }   //Выдаёт количество очков у игрока
	int GetBotMoney(){return bot->Money; }         //Выдаёт количество очков у бота
	int update();                                  //Увеличение силы последнего выбраного микроба
};

#endif
