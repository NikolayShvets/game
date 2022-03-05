#include "character.h"
#include <string>
#include "consts.h"
#include <iostream>
using namespace std;


character::character(string n, int x, int y, char skin) {
	name = n;
	this->x = x;
	this->y = y;
	healthPoints = 100.0;
	this->skin = skin;
	this->move = STOP;
}

char character::getSkin()
{
	return skin;
}

string character::getName()
{
	return name;
}

ch_move character::getMove()
{
	return move;
}
