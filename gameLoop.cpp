#include "gameLoop.h"
#include "windows.h"
#include <iostream>
#include <string>
#include <conio.h>
#include "consts.h"
using namespace std;

gameLoop::gameLoop()
{
	gameOver = false;
	mapChange = false;
	location_name = "location0.txt";
	setup();
}

void gameLoop::setup()
{
	/*������ �����, ������ ���, �������� ����, �����, ... , � ����������� �� ������ ���������� switch case ������� ��������������
	���������� �� �����. � ������ � �����, ����� ��������� �� �����, ���������� ������� ����������� ���������*/
	system("cls");

	int temp{ 0 };
	cout << "Character editor" << endl;
	// ���
	string name;
	cout << "Input the name of your character: " << endl;
	getline(cin, name);
	cout << "The name of your character " << name << endl;
	//����
	ch_race race;
	cout << "Select the race of your character: \n    0 - Human\n    1 - Elf\n    2 - Dwarf" << endl;
	cin >> temp;
	switch (temp)
	{
	case 0: race = HUMAN; cout << "Character race is Human" << endl; break;
	case 1: race = ELF; cout << "Character race is Elf" << endl; break;
	case 2: race = DWARF; cout << "Character race is Dwarf" << endl; break;
	default: race = HUMAN; cout << "Character race is Human" << endl; break;
	}
	//���
	ch_gender gender;
	cout << "Select the gender of your character: \n    0 - Male\n    1 - Female" << endl;
	cin >> temp;
	switch (temp)
	{
	case 0: gender = MALE; cout << "The gender of your character male" << endl; break; //ch_skin = 'T'; break;
	case 1: gender = FEMALE; cout << "The gender of your character female" << endl; break; //ch_skin = 'Y'; break;
	default: gender = MALE; cout << "The gender of your character male" << endl; break; //ch_skin = 'T'; break; // ������� - �, ������� - Y
	}
	//�����
	ch_class cls;
	cout << "Select the class of your character: \n    0 - Wizard\n    1 - Assasin\n    2 - Prist\n    3 - Warrior\n    4 - Necromancer" << endl;
	cin >> temp;
	switch (temp)
	{
	default: cls = WIZARD; cout << "The class of your character Wizard" << endl; break;
	case 0: cls = WIZARD; cout << "The class of your character Wizard" << endl; break;
	case 1: cls = ASSASIN; cout << "The class of your character Assasin" << endl; break;
	case 2: cls = PRIST; cout << "The class of your character Prist" << endl; break;
	case 3: cls = WARRIOR; cout << "The class of your character Warrior" << endl; break;
	case 4: cls = NECROMANCER; cout << "The class of your character Necromancer" << endl; break;
	}
	//������ ���������
	string autobiography;
	cout << "Biography of your character: " << endl;
	getline(cin, autobiography, ';'); //�� ������ cin (�.� ������ �����) �������� ������, ���� �� �������� ������-����������� (��������)
	//� ���������� ��� ������ � ���� _autobography ��������� Character
	cout << "Biography:" << autobiography << endl;

	p = new protagonist(name, 0, 0, 'T', race, gender, cls, NAKED, NONWEAPON);

	//DrawMap(character.ch_skin, current_map_name, character.ch_move); //������������ �����
	//cout << "Character: " << character._name << " Race: " << character._race << " Class: " <<character._class<< " Gender: " << character._gender << endl;
}

void gameLoop::drawMap()
{
	system("cls");
	string mapLine{""};
	if (!mapChange) return;
	currentLocation.open(location_name);
	if (!currentLocation.is_open())//��������� ������ �� ����
	{//���� �� ������ - ������� ��������� �� ������
		cout << "Error. Map file " << location_name << " not open." << endl;
		return; //������ �� �������
	}
	while (getline(currentLocation, mapLine))// ���� �� ������ current_map (������ ����� �� ����� (ifstream - input file stream))
			//�������� ������ (�� ���� ��� ��� ���������), ���������� �� � ���������� ���������� ���� str
	{
		currentDrawLocation.push_back(mapLine); //� ������ ����� current_draw_map � ��������� ������� (������ ������� ����� ������� - ������)
		//��������� ������ str. ���� �����������, ���� � ����� �� �������� ������. � ����� ���� ���� ��������� � ������ ����� (���������).
		//cout << current_draw_map.back()<<endl;
	}
	mapChange = false; //���������� �������� false ����� ��������� �����. (����� ������������ ����� ������ �����, ����� ��� �� �� ��� ����������)
	locationHeight = currentDrawLocation.size(); //167 �. ������ - ���������� ��������� � ������� ����� (�.� ���������� ����� � �����)
	locationWidth = currentDrawLocation.back().size();//38 Y. ������ - ���������� �������� � ������ ������.
	for (int i = 0; i < locationHeight; ++i)
	{
		//������ ������� ����� �������(������) ��� �� ��������� �����������
		for (int j = 0; j < locationWidth; ++j)
		{
			//������� ���������� ������ ��������� (�� ����� ���� - 2 ������, 2 ������� ���� ������)
			if ((i == p->getX()) && (j == p->getY()))
			{
				//�������� ���� ������� �� ������ ���������
				currentDrawLocation[i][j] = p->getSkin();
				//� ���������� ����� ���������� ��������� ������ ������ � ����������� �� ����������� ��������
				switch (p->getMove())
				{
				case LEFT: currentDrawLocation[i][j + 1] = ' '; break;
				case UP: currentDrawLocation[i + 1][j] = ' '; break;
				case RIGHT: currentDrawLocation[i][j - 1] = ' '; break;
				case DOWN: currentDrawLocation[i - 1][j] = ' '; break;
				}
			}
		}
		//����������� � ������� ������� ������ �������
		cout << currentDrawLocation[i] << endl;
	}
	// ��������� ���� �����(�����������!������ ������)
	currentLocation.close();
}
