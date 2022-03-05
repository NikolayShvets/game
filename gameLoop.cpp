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
	/*чистим экран, вводим имя, выбираем расу, класс, ... , в зависимости от выбора оператором switch case выводим соответсвующую
	информацию на экран. В случае с полом, кроме сообщения на экран, определяем симовол отображения персонажа*/
	system("cls");

	int temp{ 0 };
	cout << "Character editor" << endl;
	// имя
	string name;
	cout << "Input the name of your character: " << endl;
	getline(cin, name);
	cout << "The name of your character " << name << endl;
	//раса
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
	//пол
	ch_gender gender;
	cout << "Select the gender of your character: \n    0 - Male\n    1 - Female" << endl;
	cin >> temp;
	switch (temp)
	{
	case 0: gender = MALE; cout << "The gender of your character male" << endl; break; //ch_skin = 'T'; break;
	case 1: gender = FEMALE; cout << "The gender of your character female" << endl; break; //ch_skin = 'Y'; break;
	default: gender = MALE; cout << "The gender of your character male" << endl; break; //ch_skin = 'T'; break; // мужской - Т, женский - Y
	}
	//класс
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
	//вводим биографию
	string autobiography;
	cout << "Biography of your character: " << endl;
	getline(cin, autobiography, ';'); //из потока cin (т.е потока ввода) получаем строку, пока не встретим символ-разделитель (делиметр)
	//и записываем эту строку в поле _autobography структуры Character
	cout << "Biography:" << autobiography << endl;

	p = new protagonist(name, 0, 0, 'T', race, gender, cls, NAKED, NONWEAPON);

	//DrawMap(character.ch_skin, current_map_name, character.ch_move); //отрисовываем карту
	//cout << "Character: " << character._name << " Race: " << character._race << " Class: " <<character._class<< " Gender: " << character._gender << endl;
}

void gameLoop::drawMap()
{
	system("cls");
	string mapLine{""};
	if (!mapChange) return;
	currentLocation.open(location_name);
	if (!currentLocation.is_open())//проверяем открыт ли файл
	{//если не котрыт - выводим сообщение об ошибке
		cout << "Error. Map file " << location_name << " not open." << endl;
		return; //выодим из функции
	}
	while (getline(currentLocation, mapLine))// пока из потока current_map (потока ввода из файла (ifstream - input file stream))
			//получаем строку (на этот раз без делиметра), записываем ее в переменную строкового типа str
	{
		currentDrawLocation.push_back(mapLine); //в вектор строк current_draw_map в последний элемент (каждый элемент этого вектора - строка)
		//записваем строку str. Цикл повторяется, пока в файле не кончатся строки. В итоге весь файл запишется в вектор строк (построчно).
		//cout << current_draw_map.back()<<endl;
	}
	mapChange = false; //возвращаем значение false флагу изменения карты. (чтобы отрисовывать карту только тогда, когда что то на нец изменилось)
	locationHeight = currentDrawLocation.size(); //167 Х. Высота - количество элементов в векторе строк (т.е количество строк в файле)
	locationWidth = currentDrawLocation.back().size();//38 Y. Ширина - количество символов в каждой строке.
	for (int i = 0; i < locationHeight; ++i)
	{
		//каждый элемент этого вектора(строку) так же пробегаем поэлементно
		for (int j = 0; j < locationWidth; ++j)
		{
			//находим координаты нашего персонажа (на старт игры - 2 строка, 2 элемент этой строки)
			if ((i == p->getX()) && (j == p->getY()))
			{
				//заменяем этот элемент на символ персонажа
				currentDrawLocation[i][j] = p->getSkin();
				//в предыдущее место нахождения персонажа рисуем пробел в зависимости от направления движения
				switch (p->getMove())
				{
				case LEFT: currentDrawLocation[i][j + 1] = ' '; break;
				case UP: currentDrawLocation[i + 1][j] = ' '; break;
				case RIGHT: currentDrawLocation[i][j - 1] = ' '; break;
				case DOWN: currentDrawLocation[i - 1][j] = ' '; break;
				}
			}
		}
		//отрисовывем в консоль текущую строку вектора
		cout << currentDrawLocation[i] << endl;
	}
	// закрываем файл карты(обязательно!иначен ошибка)
	currentLocation.close();
}
