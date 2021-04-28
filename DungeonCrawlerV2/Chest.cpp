#include "Chest.h"

void TileCheck(Player* player, std::vector<Item>* catalog)
{
	//stores the id of the item in the chest
	int itemID;
	//checks if item is found in the chest
	bool itemFound = false;
	//gets the user choice on whether to open the chest or not
	int choice = 0;
	//if the player is standing on top of a C or unopened chest
	if (player->GetCurrentTile() == 'C') {
		//asks user to open or remain close
		std::cout << "Would you like to open the Chest?\n";
		do {
			std::cout << "\rType (Y/N): ";
			choice = _getch();
			//choices could be y, Y, n, or N
		} while (!(choice == 89 || choice == 121 || choice == 78 || choice == 110));

		//if yes
		if (choice == 89 || choice == 121) {
			//gets a random number and checks if it's a valid item to be put into the chest
			do {
				//get an item and check if it's the same level as the map level
				itemID = GetRandom(0, 34);
				//if the item is the same level or lower than the map level
				if (catalog->at(itemID).requirement_level <= player->GetFloorNum()) {
					//we have found the item
					itemFound = true;
				}
			} while (!itemFound);
			//displays the item to the user and asks if they would like the item
			std::cout << "You found a " << catalog->at(itemID).name << " in the chest!\nWould you like to add this to your inventory?\n";
			choice = 0;
			do {
				std::cout << "\rType (Y/N): ";
				choice = _getch();

			} while (!(choice == 89 || choice == 121 || choice == 78 || choice == 110));
			//if yes
			if (choice == 89 || choice == 121) {
				//check if you have enough space
				if (player->GetCarryingCapacity() > catalog->at(itemID).weight) {
					std::cout << "\nItem added!";
					//item gets added to the inventory
					player->AddItem(catalog->at(itemID));
					//subtracts the carrying capacity
					player->SetCarryingCapacity(player->GetCarryingCapacity() - catalog->at(itemID).weight);
				}
				else {
					std::cout << "\nOh No! It looks like you don't have enough space left!";
				}
				
			}
			//set the tile to an opened chest or c
			player->SetCurrentTile('c');
		}
		
	}

	if (player->GetCurrentTile() == 'e' || player->GetCurrentTile() == 'E') {

	}

}
