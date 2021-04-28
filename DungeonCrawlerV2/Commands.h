#pragma once
#include "Player.h"
#include <map>


/*
List of commands
/help - shows list of all commands
/stats - shows player stats
/inventory - shows player their inventory
/drop - deletes item from inventory
/item - shows item details of specific item
/equip - equips item to player like ring, sword, armor
/dequip - dequips item from player like ring, sword, armor
/equipped - shows list of all items equipped to player
/save - saves player progress
/quit - checks if user wants to save first then exits the program
*/

//main function that diverts to different functions
void Commands(std::string command, Player* player);

//gets item from the command and returns the id
int GetItem(std::string* command, Player* player, int len);

//drops specified item
void DropItem(std::string* command, Player* player);

//displays stats of specified item
void DisplayItem(std::string* command, Player* player);

//equips specified item to a slot
void EquipItem(std::string* command, Player* player);

//dequips specified item from a slot
void DequipItem(std::string* command, Player* player);

//displays all equipped items
void Equipped(Player* player);

//saves player progress
void Save(Player* player);

//displays information about the game to the user
void Info();