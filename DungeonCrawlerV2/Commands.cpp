#include "Commands.h"

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
	else if (command.find("/drop") == 0) {
		DropItem(&command, player);
	}
	else if (command.find("/item") == 0) {
		DisplayItem(&command, player);
	}
	else if (command.find("/equip") == 0) {
		EquipItem(&command, player);
	}
	else if (command.find("/dequip") == 0) {
		DequipItem(&command, player);
	}
	else if (command == "/equipped") {
		Equipped(player);
	}
	else if (command == "/save") {
		//not implemented yet!
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
		std::cout << "\nYou have no items!\n";
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
		//check if item is in use in a slot and delete it
		//call the dequip function
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
	int id = GetItem(command, player);

	if (id == -1) {
		std::cout << "\nCould not find the item you wanted. Try double checking if the name is spelled correctly\n";
	}
	else {
		//if item is weapon
		if (player->GetInventory()[id].type == Weapon) {
			player->SetWeapon(id);
		}
		else if (player->GetInventory()[id].type == Armor) {
			player->SetArmor(id);
		}
		else if (player->GetInventory()[id].type == Ring) {
			//Ask which slot 1 or 2
			int choice = 0;
			do {
				choice = _getch();
			} while (choice != 49 && choice != 50);

			if (choice == 49) {
				//slot 1
				player->SetRingOne(id);
			}
			else if (choice == 50) {
				//slot 2
				player->SetRingTwo(id);
			}
		}
		else {
			std::cout << "This item cannot be equipped!\n";
		}
	}
}

void DequipItem(std::string* command, Player* player)
{
	int id = GetItem(command, player);

	if (id == -1) {
		std::cout << "\nCould not find the item you wanted. Try double checking if the name is spelled correctly\n";
	}
	else {
		//if item is weapon
		if (player->GetInventory()[id].type == Weapon) {
			//reset modifiers
			player->SetWeapon(-1);
		}
		else if (player->GetInventory()[id].type == Armor) {
			//reset modifiers
			player->SetArmor(-1);
		}
		else if (player->GetInventory()[id].type == Ring) {
			//Ask which slot 1 or 2
			int choice = 0;
			do {
				choice = _getch();
			} while (choice != 49 && choice != 50);

			if (choice == 49) {
				//slot 1
				//reset modifiers
				player->SetRingOne(-1);
			}
			else if (choice == 50) {
				//slot 2
				//reset modifiers
				player->SetRingTwo(-1);
			}
		}
		else {
			std::cout << "This item cannot be equipped!\n";
		}
	}
}

void Equipped(Player* player)
{
	std::cout << "------------------------------\n";
	std::cout << "Weapon Slot   | " << player->GetWeapon().name;
	std::cout << "Armor Slot    | " << player->GetArmor().name;
	std::cout << "Ring One Slot | " << player->GetRingOne().name;
	std::cout << "Ring Two Slot | " << player->GetRingTwo().name;
	std::cout << "------------------------------\n";
}

void Save(Player* player)
{

}

