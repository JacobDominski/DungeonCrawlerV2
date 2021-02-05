#include "Character.h"

char Character::GetChar()
{
	return Char;
}

void Character::SetCurrentTile(char tile)
{
	CurrentTile = tile;
}

char Character::GetCurrentTile()
{
	return CurrentTile;
}

void Character::SetAC(int num)
{
	ac = num;
}

int Character::GetAC()
{
	return ac;
}

void Character::SetHealth(int health)
{
	Health = health;
}

int Character::GetHealth()
{
	return Health;
}

void Character::SetCharacterLevel(int level)
{
	CharacterLevel = level;
}

int Character::GetCharacterLevel()
{
	return CharacterLevel;
}

void Character::SetPosition(int x, int z)
{

}

int* Character::GetPosition()
{
	return nullptr;
}

void Character::SetStrMod(int strength)
{
	StrMod = std::floor((strength - 10) / 2);
}

int Character::GetStrMod()
{
	return StrMod;
}

void Character::SetDexMod(int dexterity)
{
	DexMod = std::floor((dexterity - 10) / 2);
}

int Character::GetDexMod()
{
	return DexMod;
}

void Character::SetConMod(int constitution)
{
	ConMod = std::floor((constitution - 10) / 2);
}

int Character::GetConMod()
{
	return ConMod;
}

void Character::SetIntMod(int intelligence)
{
	IntMod = std::floor((intelligence - 10) / 2);
}

int Character::GetIntMod()
{
	return IntMod;
}

void Character::SetWisMod(int wisdom)
{
	WisMod = std::floor((wisdom - 10) / 2);
}

int Character::GetWisMod()
{
	return WisMod;
}

void Character::SetChaMod(int charisma)
{
	ChaMod = std::floor((charisma - 10) / 2);
}

int Character::GetChaMod()
{
	return ChaMod;
}
