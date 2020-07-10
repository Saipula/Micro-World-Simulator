// ---------------------------------------------------------------------------

#pragma hdrstop

#include "MyClass.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

Micro::Micro(short player, short sila){
	this->player = player;
	this->sila = sila;
}

MicroObj::MicroObj(TCanvas *canv, short x, short y, short size, int col) {
	device = canv;
	col1 = col;
	col2 = clBlack;
	this->x = x;
	this->y = y;
	this->size = size;

    sila = rand()%9;
}
void MicroObj::draw(int col1, int col2) {
	device->Pen->Color = (TColor)col2;
	device->Brush->Color = (TColor)col1;
	device->Rectangle(x, y, x + size, y + size);
}

Player::Player(TCanvas *canv, short size, int col, TPoint max, short colv, short StartMoney) {
	device = canv;
	color = col;
	this->size = size;
	this->max = max;
	this->Money = StartMoney;

	for (int i = 0; i < colv; i++){
		short x = rand()%(max.x-1)*size, y = rand()%(max.y-1)*size;
		microbs.push_back(new MicroObj(canv, x, y, size, col));
	}
}
void Player::show() {
	for (int i = 0; i < microbs.size(); i++)
		microbs[i]->show();
}
void Player::del(short num){
    microbs.erase(microbs.begin() + num);
}
void Player::add(){
    short x = rand()%(max.x-1)*size, y = rand()%(max.y-1)*size;
	microbs.push_back(new MicroObj(device, x, y, size, color));
}

Game::Game(TCanvas *canv, short w, short h, short colvo, short size, short StartMoney, bool rezim) {
	device = canv;
	this->w = w;
	this->h = h;
	this->size = size;
	this->colvo = colvo;
    this->rezim = rezim;

	bot = new Player(canv, size, clRed, TPoint(w, h), colvo, StartMoney);
	player = new Player(canv, size, clLime, TPoint(w, h), colvo, StartMoney);

tp:
	while (bot->microbs.size() < colvo) bot->add();
	while (player->microbs.size() < colvo) player->add();

	if (bot->microbs.size() < colvo || player->microbs.size() < colvo)
		goto tp;
}
void Game::show(){
	device->Pen->Color = clBlack;
	device->Brush->Color = clWhite;
	device->Rectangle(0, 0, w*size, h*size);
	player->show();
	bot->show();
}
void Game::live(){
	PlayerHod();
	BotHod();

    show();
}
void Game::PlayerHod(){
	if (rezim)
		while (player->Money > 0){
			short tmp = rand() % player->microbs.size();
			player->microbs[tmp]->sila++;
			player->Money--;
		}

	for (int i = 0; i < player->microbs.size(); i++){
		bool move = 0;

		short tmpX = (rand() % 3 - 1) * size + player->microbs[i]->x, tmpY =
			(rand() % 3 - 1) * size + player->microbs[i]->y;
		if (tmpX < 0 || tmpY < 0) continue;
		if (tmpX / size >= w || tmpY / size >= h) continue;

		for (int j = 0; j < player->microbs.size(); j++) {
			if (i == j)
				continue;
			if (tmpX == player->microbs[j]->x && tmpY == player->microbs[j]->y){
				move = 1;
                break;
			}
		}

		for (int j = 0; j < bot->microbs.size(); j++) {
			if (tmpX == bot->microbs[j]->x && tmpY == bot->microbs[j]->y){
				if (player->microbs[i]->sila > bot->microbs[j]->sila) {
					player->Money += bot->microbs[j]->sila;
					bot->del(j);
					break;
				}
				bot->Money += player->microbs[i]->sila;
				player->del(i);
                move = 1;
				break;
			}
		}

		if (!move) {
			player->microbs[i]->x = tmpX;
			player->microbs[i]->y = tmpY;
		}
	}
}
void Game::BotHod(){
	while (bot->Money > 0){
		short tmp = rand() % bot->microbs.size();
		bot->microbs[tmp]->sila++;
		bot->Money--;
	}

	for (int i = 0; i < bot->microbs.size(); i++){
		bool move = 0;

		short tmpX = (rand() % 3 - 1) * size + bot->microbs[i]->x, tmpY =
			(rand() % 3 - 1) * size + bot->microbs[i]->y;
		if (tmpX < 0 || tmpY < 0) move = 1;
		if (tmpX / size >= w || tmpY / size >= h) move = 1;

		for (int j = 0; j < bot->microbs.size(); j++) {
			if (i == j)
				continue;
			if (tmpX == bot->microbs[j]->x && tmpY == bot->microbs[j]->y){
				move = 1;
                break;
			}
		}

		for (int j = 0; j < player->microbs.size(); j++) {
			if (tmpX == player->microbs[j]->x && tmpY == player->microbs[j]->y){
				if (player->microbs[j]->sila > bot->microbs[i]->sila) {
					player->Money += bot->microbs[i]->sila;
					move = 1;
					bot->del(i);
					break;
				}
				bot->Money += player->microbs[j]->sila;
				player->del(j);
				break;
			}
		}

		if (!move) {
			bot->microbs[i]->x = tmpX;
			bot->microbs[i]->y = tmpY;
		}
	}
}
Micro Game::GetMicro(TPoint last){
	for (int i = 0; i < player->microbs.size(); i++) {
		if (last.x == player->microbs[i]->x/size && last.y == player->microbs[i]->y/size) {
            this->last = i;
			return Micro(1, player->microbs[i]->sila);
		}
	}

	for (int i = 0; i < bot->microbs.size(); i++) {
		if (last.x == bot->microbs[i]->x/size && last.y == bot->microbs[i]->y/size) {
			return Micro(0, bot->microbs[i]->sila);
		}
	}

    return Micro(2, 0);;
}
int Game::update(){
	if (player->Money > 0) {
		player->microbs[last]->sila++;
		player->Money--;
	}

	return player->microbs[last]->sila;
}
