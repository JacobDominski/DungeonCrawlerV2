#pragma once

#include <iostream>//this library is for cout and cin
#include <cstdlib>//this library is for the random function
#include <string>//this library lets you use strings
#include <ctime>//lets the computer perform random functions, without it, the random function would not be as random
#include <vector>//lets me store the items in a master list and the players inventory
#include <cmath>

//this data type is to categorize different items
enum itemType
{
	Armor,
	Potion,
	Ring,
	Weapon,
	Misc_Item
};



//this class creates all of the items the game will use
struct Item
{
	//id
	//name
	//flavor text
	//type
	//cost
	//weight
	//properties
	//requirement
	int id;
	std::string name;
	itemType type;
	std::string flavor_text;
	int cost;
	int weight;
	std::string property;
	int requirement_level;
	int effect;

	//creates a constructor of the class so everytime it is called, it creates a new item with its own set of properties
	Item(int Id, std::string Name, itemType Type, std::string Flavor_text, int Cost, int Weight, std::string Property, int Requirement, int Effect)
	{
		id = Id;
		name = Name;
		type = Type;
		flavor_text = Flavor_text;
		cost = Cost;
		weight = Weight;
		property = Property;
		requirement_level = Requirement;
		effect = Effect;
	}

	
};

//functions to be used for the items
std::vector<Item> CreateItems();
void DisplayItems(std::vector<Item>* list);
int SearchItem(std::vector<Item>* StoreItem, std::string ItemName);
void ShowItem(Item& inventoryItem);