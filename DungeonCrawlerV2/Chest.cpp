#include "Chest.h"

void TileCheck(Player* player, std::vector<Item>* catalog)
{
	int itemID;
	bool itemFound = false;
	int choice = 0;
	if (player->GetCurrentTile() == 'C') {
		//asks user to open or remain close
		std::cout << "Would you like to open the Chest?\n";
		do {
			std::cout << "\rType (Y/N): ";
			choice = _getch();

		} while (!(choice == 89 || choice == 121 || choice == 78 || choice == 110));

		//if yes
		if (choice == 89 || choice == 121) {

			do {
				//get an item and check if it's the same level as the map level
				itemID = GetRandom(0, 34);
				if (catalog->at(itemID).requirement_level <= player->GetFloorNum()) {
					itemFound = true;
				}
			} while (!itemFound);

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
					player->AddItem(catalog->at(itemID));
					player->SetCarryingCapacity(player->GetCarryingCapacity() - catalog->at(itemID).weight);
				}
				else {
					std::cout << "\nOh No! It looks like you don't have enough space left!";
				}
				
			}

			player->SetCurrentTile('c');
		}
		
	}

	if (player->GetCurrentTile() == 'e' || player->GetCurrentTile() == 'E') {

	}

}
