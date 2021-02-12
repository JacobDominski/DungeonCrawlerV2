#include "Commands.h"

/*
List of commands
/help - shows list of all commands
/playerstats - shows player stats
/inventory - shows player their inventory
/drop - deletes item from inventory
/playeritem - shows item details of specific item
/equip - equips item to player like ring, sword, armor
/dequip - dequips item from player like ring, sword, armor
/equipped - shows list of all items equipped to player
/save - saves player progress
/quit - checks if user wants to save first then exits the program
*/


void Commands(std::string command, Player* player)
{

	if (command == "/help") {
		std::cout << "\nthese are all of the commands you can do\n";
		std::cout << "/help  | /inventory          | /equip (item name)\n";
		std::cout << "/stats | /drop (item name)   | /dequip (item name)\n";
		std::cout << "/quit  | /item (item name)   | /equipped\n";
		std::cout << "/save  |  ";
	}
	else if (command == "/stats") {
		player->PlayerStats();
	}
	else if (command == "/inventory") {
		player->DisplayInventory();
	}
	else if (command.find("/drop")) {
		DropItem(&command, player);
	}
	else if (command.find("/item")) {
		DisplayItem(&command, player);
	}
	else if (command.find("/equip")) {

	}
	else if (command.find("/dequip")) {

	}
	else if (command == "/equipped") {

	}
	else if (command == "/save") {

	}
	else if (command == "/quit") {
		//do you want to save?
		//if yes then save then exit
		//if no just exit
		exit(EXIT_SUCCESS);
	}
	else {
		std::cout << "\nUnrecognized command. Type '/help' to see the list of commands.\n";
	}

}

int GetItem(std::string* command, Player* player)
{
	if (player->GetInventory().empty()) {
		std::cout << "You have no items!\n";
		return -2;
	}

	std::string itemname = command->substr(6, (command->length() - 6));

	int id = player->SearchPlayerItem(itemname);

	return id;

}

void DropItem(std::string* command, Player* player) {
	
	int id = GetItem(command, player);

	if (id == -1) {
		std::cout << "\nCould not find the item you wanted. Try double checking if the name is spelled correctly\n";
	}
	else if (id >= 0) {
		player->SetCarryingCapacity(player->GetCarryingCapacity() + player->GetInventory()[id].weight);
		player->DeleteItem(&player->GetInventory()[id]);
		std::cout << "Item Dropped. You cannot get this back.\n";
	}

}

void DisplayItem(std::string* command, Player* player)
{
	
	int id = GetItem(command, player);

	if (id == -1) {
		std::cout << "\nCould not find the item you wanted. Try double checking if the name is spelled correctly\n";
	}
	else {
		player->ShowItem(&player->GetInventory()[id]);
	}
}

void EquipItem(std::string* command, Player* player)
{

}

void DequipItem(std::string* command, Player* player)
{

}

void Equipped(std::string* command, Player* player)
{

}

void Save(Player* player)
{

}

