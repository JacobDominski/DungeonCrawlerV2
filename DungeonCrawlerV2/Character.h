#pragma once
//gets access to items and functions from the game structure
#include "Item.h"
#include "GameStructure.h"

//player and enemies and possibly other things in the future to 
//inherit the character class
class Character
{
	//only inherited class can access the values
protected:
	//armor class
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
	
	//anyone has access to the functions
public:
	//sets the str mod by entering the strength stat
	void SetStrMod(int strength);
	int GetStrMod();
	//sets the dex mod by entering the dexterity stat
	void SetDexMod(int dexterity);
	int GetDexMod();
	//sets the con mod by entering the constitution stat
	void SetConMod(int constitution);
	int GetConMod();
	//sets the int mod by entering the intelligence stat
	void SetIntMod(int intelligence);
	int GetIntMod();
	//sets the wis mod by entering the wisdom stat
	void SetWisMod(int wisdom);
	int GetWisMod();
	//sets the cha mod by entering the charisma stat
	void SetChaMod(int charisma);
	int GetChaMod();
	//returns the character of the thing
	char GetChar();
	//sets the tile of the character that it's stanging on
	void SetCurrentTile(char tile);
	char GetCurrentTile();
	//sets the armor class
	void SetAC(int num);
	int GetAC();
	//sets the health
	void SetHealth(int health);
	int GetHealth();
	//sets the level
	void SetCharacterLevel(int level);
	int GetCharacterLevel();

	
};

