#include "protagonist.h"
#include "consts.h"

protagonist::protagonist(string n, int x, int y, char skin,
    ch_race r, ch_gender g, ch_class c,
    ch_armour a, ch_weapon w) : character(n, x, y, skin)
{
    race = r; gender = g; ch_cls = c;
    armour = a; weapon = w;
}

int protagonist::getX()
{
    return x;
}

int protagonist::getY()
{
    return y;
}

void protagonist::setX(const int new_x)
{
    x = new_x;
}

void protagonist::setY(const int new_y)
{
    y = new_y;
}
