#pragma once
#include <string>
#include "consts.h"
using namespace std;

class character
{
protected:
    string name;
    char skin;
    int x, y;
    float healthPoints;
    ch_move move;
public:
    character(string, int, int, char);
    char getSkin();
    string getName();
    ch_move getMove();
};

