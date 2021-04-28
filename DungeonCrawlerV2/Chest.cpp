#include "Chest.h"

void TileCheck(Player* player)
{
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

			//get an item


			player->SetCurrentTile('c');
		}
		else {
			//be able to move away
		}
		
	}

	if (player->GetCurrentTile() == 'e' || player->GetCurrentTile() == 'E') {

	}

}
