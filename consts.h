#pragma once
enum ch_move { STOP = 0, LEFT, RIGHT, UP, DOWN }; // ������������ ��������� �����������
enum ch_race { HUMAN = 0, ELF, DWARF }; // ������� ����
enum ch_gender { MALE = 0, FEMALE }; // ��� ��������� (�, �)
enum ch_class { WIZARD = 0, ASSASIN, PRIST, WARRIOR, NECROMANCER }; // ������� ������ ��������� (���, ���, ����, ����, ���������)
enum ch_armour { DRESS = 0, LEATHER, CHAIN, PLATE, NAKED }; // ����� (������, ����, ��������, ����, �����)
enum ch_weapon {
	DAGGER = 0, DDAGGER, SWORD, DSWORD, AXE, DAXE, MACE, THSWORD, THAXE, BOW, SHIELD,
	GRIMUAR, MAGIC_STAFF, MAGIC_STICK, MAGIC_SCROLL, NONWEAPON
}; // ������ (������, ��� �������, ���, ��� ����, 
		  //�����, ��� ������, ������, ��������� ���, 
		  //��������� �����, ���, ���, �������, ��������� �����, 
		  //��������� �������, ������ ����������, ����������)
