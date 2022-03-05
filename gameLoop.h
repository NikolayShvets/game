#pragma once
#include "protagonist.h"
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class gameLoop
{
private:
	bool gameOver;
	bool mapChange;
	protagonist* p;
	string location_name;
	ifstream currentLocation;
	vector<string> currentDrawLocation;
	int locationHeight;
	int locationWidth;
public:
	gameLoop();
	void setup();
	void drawMap();
};

