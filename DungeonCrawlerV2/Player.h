#pragma once
#include <vector>
#include "Character.h"

class Player : public Character
{
private:
	int Money;
	std::string Name;
	std::vector<Item> Inventory;
	int carrying_capacity = 20;

	

public:
	Player();

	void SetMoney(int money);
	int GetMoney();

	void SetName();
	std::string GetName();

	void SetCarryingCapacity(int carrycapacity);
	int GetCarryingCapacity();

	void SetInventory(std::vector<Item> inventory);
	std::vector<Item> GetInventory();

	void SetStats(int* strength, int* dexterity, int* constitution, int* intelligence, int* wisdom, int* charisma);
	int AddStat(std::string stat, int arr[]);

	//adds item to player inventory
	void addItem(Item inventoryItem);
	//deletes item from player inventory
	void DeleteItem(Item* inventoryItem);

	void ShowItem(Item* inventoryItem);

	int SearchPlayerItem(std::string name);

	void DisplayInventory();

	void PlayerStats();

	void EquipItem();
};

int RollDice(int numOfDice, int numOfSides, int modifier, bool playerStats);