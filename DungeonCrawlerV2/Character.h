#pragma once
#include <string>
#include "Item.h"
#include "GameStructure.h"

class Character
{
protected:

	int ac = 0;

	//stats
	int Strength = 0;
	int Dexterity = 0;
	int Constitution = 0;
	int Intelligence = 0;
	int Wisdom = 0;
	int Charisma = 0;

	//modifiers
	int StrMod = 0;
	int DexMod = 0;
	int ConMod = 0;
	int IntMod = 0;
	int WisMod = 0;
	int ChaMod = 0;

	//health
	int Health = 10;

	//character level
	int CharacterLevel = 1;

	//character
	char Char = '~';

	//current Tile
	char CurrentTile = '~';

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

