#include "Character.h"

char Character::GetCharacter()
{
    return Character;
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
