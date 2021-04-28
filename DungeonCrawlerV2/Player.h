#pragma once
#include <vector>
#include <conio.h>// _getch()
#include "Character.h"

class Player : public Character
{
private:
	int Money;
	std::string Name;
	int Level;
	std::vector<Item> Inventory;
	int carrying_capacity = 20;
	int floorNum = 1;
	
	int WeaponSlot = -1;
	int ArmorSlot = -1;
	int RingOneSlot = -1;
	int RingTwoSlot = -1;
	

public:

	//Item Punch(1, "Punch", Weapon, "Default Attack", 0, 0, "OneHanded", 0, 1);

	Player();

	void SetMoney(int money);
	int GetMoney();

	void SetName();
	std::string GetName();

	void SetLevel(int level);
	int GetLevel();

	void SetCarryingCapacity(int carrycapacity);
	int GetCarryingCapacity();

	void SetFloorNum(int floornum);
	int GetFloorNum();

	void SetInventory(std::vector<Item> inventory);
	std::vector<Item> GetInventory();

	void SetStats(int* strength, int* dexterity, int* constitution, int* intelligence, int* wisdom, int* charisma);
	int AddStat(std::string stat, int arr[]);

	//adds item to player inventory
	void AddItem(Item inventoryItem);
	//deletes item from player inventory
	void DeleteItem(Item* inventoryItem);

	void ShowItem(Item* inventoryItem);

	int SearchPlayerItem(std::string name);

	void DisplayInventory();

	void PlayerStats();

	
	void SetWeapon(int id);
	Item GetWeapon();

	void SetArmor(int id);
	Item GetArmor();

	void SetRingOne(int id);
	Item GetRingOne();

	void SetRingTwo(int id);
	Item GetRingTwo();
	
};

int RollDice(int numOfDice, int numOfSides, int modifier, bool playerStats);