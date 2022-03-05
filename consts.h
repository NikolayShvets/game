#pragma once
enum ch_move { STOP = 0, LEFT, RIGHT, UP, DOWN }; // перечисление возможных перемещений
enum ch_race { HUMAN = 0, ELF, DWARF }; // вариант расы
enum ch_gender { MALE = 0, FEMALE }; // пол персонажа (м, ж)
enum ch_class { WIZARD = 0, ASSASIN, PRIST, WARRIOR, NECROMANCER }; // вариант класса персонажа (маг, вор, жрец, воин, некромант)
enum ch_armour { DRESS = 0, LEATHER, CHAIN, PLATE, NAKED }; // броня (тряпки, кожа, кольчуга, латы, голый)
enum ch_weapon {
	DAGGER = 0, DDAGGER, SWORD, DSWORD, AXE, DAXE, MACE, THSWORD, THAXE, BOW, SHIELD,
	GRIMUAR, MAGIC_STAFF, MAGIC_STICK, MAGIC_SCROLL, NONWEAPON
}; // оружие (кинжал, два кинажал, меч, два меча, 
		  //топор, два топора, булава, двуручный меч, 
		  //двуручный топор, лук, щит, гримуар, волшебный посох, 
		  //волшебная палочка, свиток заклинаний, безоружный)
