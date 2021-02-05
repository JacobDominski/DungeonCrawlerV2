#pragma once
#include <string>
#include "Item.h"
#include "GameStructure.h"

class Character
{
protected:

	int ac;

	//stats
	int Strength;
	int Dexterity;
	int Constitution;
	int Intelligence;
	int Wisdom;
	int Charisma;

	//modifiers
	int StrMod = (Strength - 10) / 2;
	int DexMod = (Dexterity - 10) / 2;
	int ConMod = (Constitution - 10) / 2;
	int IntMod = (Intelligence - 10) / 2;
	int WisMod = (Wisdom - 10) / 2;
	int ChaMod = (Charisma - 10) / 2;

	//health
	int Health;

	//character level
	int CharacterLevel;

	//character
	char Char;

	//current Tile
	char CurrentTile;

	//position
	int Position[2];
	//slots for equipment
	//weapon slot
	//armor slot
	//ring 1 slot
	//ring 2 slot
public:

	void SetStrMod(int strength);
	int GetStrMod();

	void SetDexMod(int dexterity);
	int GetDexMod();

	void SetConMod(int constitution);
	int GetConMod();

	void SetIntMod(int intelligence);
	int GetIntMod();

	void SetWisMod(int wisdom);
	int GetWisMod();

	void SetChaMod(int charisma);
	int GetChaMod();

	char GetChar();

	void SetCurrentTile(char tile);
	char GetCurrentTile();

	void SetAC(int num);
	int GetAC();

	void SetHealth(int health);
	int GetHealth();

	void SetCharacterLevel(int level);
	int GetCharacterLevel();

	void SetPosition(int x, int z);
	int* GetPosition();
};

