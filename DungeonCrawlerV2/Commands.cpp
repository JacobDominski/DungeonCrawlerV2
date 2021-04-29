#include "Commands.h"

/*
List of commands
/help - shows list of all commands
/info - gives information on how to play the game
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
		std::cout << "/info  | /drop (item name)   | /dequip (item name)\n";
		std::cout << "/quit  | /item (item name)   | /equipped\n";
		std::cout << "/save  | /stats";
	}
	else if (command == "/stats") {
		player->PlayerStats();
	}
	else if (command == "/info") {
		Info();
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
	else if (command.find("/equip ") == 0) {
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

int GetItem(std::string* command, Player* player, int len)
{
	if (player->GetInventory().empty()) {
		std::cout << "\nYou have no items!\n";
		return -2;
	}

	std::string itemname = command->substr(len, (command->length() - len));

	int id = player->SearchPlayerItem(itemname);

	return id;

}

void DropItem(std::string* command, Player* player) {
	
	int id = GetItem(command, player, 6);

	if (id == -1) {
		std::cout << "\nCould not find the item you wanted. Try double checking if the name is spelled correctly\n";
	}
	else if (id >= 0) {
		//check if item is in use in a slot and delete it
		//call the dequip function
		if (player->GetInventory().at(id).name == player->GetWeapon().name ||
			player->GetInventory().at(id).name == player->GetArmor().name ||
			player->GetInventory().at(id).name == player->GetRingOne().name ||
			player->GetInventory().at(id).name == player->GetRingTwo().name ) 
		{
			std::cout << "\nYou cannot drop this item as it is currently equipped. Dequip the item first to drop it.";
			return;
		}
		else if (player->GetInventory().at(id).property == "Bag") {
			//check if there is not enough space
			if (player->GetCarryingCapacity() - player->GetInventory().at(id).effect < 0) {
				//does not let you drop the bag
				std::cout << "\nYou cannot drop this item as there would not be enough space left over for other items";
				return;
			}
		}
		player->SetCarryingCapacity(player->GetCarryingCapacity() + player->GetInventory()[id].weight);
		player->DeleteItem(&player->GetInventory()[id]);
		std::cout << "Item Dropped. You cannot get this back.\n";
	}

}

void DisplayItem(std::string* command, Player* player)
{
	
	int id = GetItem(command, player, 6);

	if (id == -1) {
		std::cout << "\nCould not find the item you wanted. Try double checking if the name is spelled correctly\n";
	}
	else if (id >= 0) {
		player->ShowItem(&player->GetInventory()[id]);
	}
}

void EquipItem(std::string* command, Player* player)
{
	int id = GetItem(command, player, 7);
	int prevItem;

	if (id == -1) {
		std::cout << "\nCould not find the item you wanted. Try double checking if the name is spelled correctly\n";
	}
	else if (id >= 0) {
		//if item is weapon
		if (player->GetInventory().at(id).type == Weapon) {
			//prevItem = player->SearchPlayerItem(player->GetWeapon().name);
			player->SetWeapon(id);
		}
		else if (player->GetInventory().at(id).type == Armor) {
			prevItem = player->SearchPlayerItem(player->GetArmor().name);
			player->SetArmor(id);
			//the item did change
			if (prevItem != player->GetArmor().id) {
				if (prevItem >= 0) {
					player->SetAC(player->GetAC() - player->GetInventory().at(prevItem).effect);
					player->SetAC(player->GetAC() + player->GetInventory().at(id).effect);
				}
				else {
					player->SetAC(player->GetAC() + player->GetInventory().at(id).effect);
				}
				
			}

			
		}
		else if (player->GetInventory().at(id).type == Ring) {
			//Ask which slot 1 or 2
			int choice = 0;
			std::cout << "Which slot would you like to equip your ring?\n1 or 2 : ";
			do {
				choice = _getch();
			} while (choice != 49 && choice != 50);

			if (choice == 49) {
				//slot 1
				prevItem = player->SearchPlayerItem(player->GetRingOne().name);
				player->SetRingOne(id);
				if (prevItem != player->GetRingOne().id) {
					if (prevItem >= 0) {
						//player->SetAC(player->GetAC() - player->GetInventory().at(prevItem).effect);
						//player->SetAC(player->GetAC() + player->GetInventory().at(id).effect);
					}
					else {
						//player->SetAC(player->GetAC() + player->GetInventory().at(id).effect);
					}

				}
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
	int id = GetItem(command, player, 8);

	if (id == -1) {
		std::cout << "\nCould not find the item you wanted. Try double checking if the name is spelled correctly\n";
	}
	else if (id >= 0) {
		//if item is weapon
		if (player->GetInventory()[id].type == Weapon) {
			//reset modifiers
			player->SetWeapon(-1);
		}
		else if (player->GetInventory()[id].type == Armor) {
			//reset modifiers
			player->SetArmor(-1);
			player->SetAC(player->GetAC() - player->GetInventory().at(id).effect);
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
	std::cout << "\n------------------------------";
	std::cout << "\nWeapon Slot   | " << player->GetWeapon().name;
	std::cout << "\nArmor Slot    | " << player->GetArmor().name;
	std::cout << "\nRing One Slot | " << player->GetRingOne().name;
	std::cout << "\nRing Two Slot | " << player->GetRingTwo().name;
	std::cout << "\n------------------------------";
}

void Save(Player* player)
{

}

void Info()
{
	std::cout << "\nHello! This is a game where you fight";
	std::cout << "\nyour way out of the dungeon and go on";
	std::cout << "\nan adventure. - Page 1";
	pause("\nPress any key to continue . . . ");
	std::cout << "\nHere is a description of the different";
	std::cout << "\ncommands available";
	std::cout << "\n1. /stats - this will display your player's stats";
	std::cout << "\n2. /inventory - this will display your player's inventory";
	std::cout << "\n3. /drop - this will let you delete an";
	std::cout << "\n           item from your inventory - page 2";
	pause("\nPress any key to continue . . . ");
	std::cout << "\n4. /item - this will display an item from";
	std::cout << "\n		   your inventory along with all ";
	std::cout << "\n		   it's properties. ";
	std::cout << "\n5. /equip - this will let you equip an item";
	std::cout << "\n		    to be used to fight against enemies";
	std::cout << "\n		    - page 3";
	pause("\nPress any key to continue . . . ");
	std::cout << "\n6. /dequip - this will let you dequip an item";
	std::cout << "\n             from your character to swap with";
	std::cout << "\n             another item";
	std::cout << "\n7. /equipped - this will show all the eqiupped";
	std::cout << "\n               items you have - page 4";
	pause("\nPress any key to continue . . . ");
	std::cout << "\n8. /save - will save your progress";
	std::cout << "\n9. /quit - will exit your game. Make";
	std::cout << "\n           sure you save first! - page 5";

}

