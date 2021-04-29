#include "Character.h"
//returns the character of the character
char Character::GetChar()
{
	return Char;
}
//sets the tile the character stands on
void Character::SetCurrentTile(char tile)
{
	CurrentTile = tile;
}
//returns the tile the character stands on
char Character::GetCurrentTile()
{
	return CurrentTile;
}
//sets the ac of the character
void Character::SetAC(int num)
{
	ac = num;
}
//returns the ac of the character
int Character::GetAC()
{
	return ac;
}
//sets the health of the character
void Character::SetHealth(int health)
{
	Health = health;
}
//gets the health of the character
int Character::GetHealth()
{
	return Health;
}
void Character::SetMaxHealth(int health)
{
	MaxHealth = health;
}
int Character::GetMaxHealth()
{
	return MaxHealth;
}
//sets the level of the character
void Character::SetCharacterLevel(int level)
{
	CharacterLevel = level;
}
//returns the health of the character
int Character::GetCharacterLevel()
{
	return CharacterLevel;
}
//sets the strength mod of the character
void Character::SetStrMod(int strength)
{
	StrMod = (int)std::floor((strength - 10) / 2);
}
//returns the strength mod of the character
int Character::GetStrMod()
{
	return StrMod;
}
//sets the dexterity mod of the character
void Character::SetDexMod(int dexterity)
{
	DexMod = (int)std::floor((dexterity - 10) / 2);
}
//returns the dex mod of the character
int Character::GetDexMod()
{
	return DexMod;
}
//sets the constitution mod of the character
void Character::SetConMod(int constitution)
{
	ConMod = (int)std::floor((constitution - 10) / 2);
}
//returns the constitution mod of the character
int Character::GetConMod()
{
	return ConMod;
}
//sets the intelligence mod of the character
void Character::SetIntMod(int intelligence)
{
	IntMod = (int)std::floor((intelligence - 10) / 2);
}
//returns the constitution mod of the character
int Character::GetIntMod()
{
	return IntMod;
}
//sets the wisdom mod of the character
void Character::SetWisMod(int wisdom)
{
	WisMod = (int)std::floor((wisdom - 10) / 2);
}
//returns the wisdom mod of the character.
int Character::GetWisMod()
{
	return WisMod;
}
//sets the charisma mod of the character
void Character::SetChaMod(int charisma)
{
	ChaMod = (int)std::floor((charisma - 10) / 2);
}
//returns the charisma mod of the character
int Character::GetChaMod()
{
	return ChaMod;
}
