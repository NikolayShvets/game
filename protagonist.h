#pragma once
#include "character.h"
#include "consts.h"

class protagonist :
    public character
{
private:
    ch_race race;
    ch_gender gender;
    ch_class ch_cls;
    ch_armour armour;
    ch_weapon weapon;
public:
    protagonist(string n, int x, int y, char skin, ch_race r,
        ch_gender g, ch_class c, ch_armour a, ch_weapon w);
    int getX();
    int getY();
    void setX(const int new_x);
    void setY(const int new_y);
};

