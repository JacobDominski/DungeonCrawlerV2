#include "Store.h"

void Store(Player* player, std::vector<Item>* catalog)
{

	bool quit = false;
	int choice;
	while (!quit) {
		choice = 0;
		std::cout << "Would you like to leave the Shop?\n";
		do {
			std::cout << "\rType (Y/N): ";
			choice = _getch();
		} while (!(choice == 89 || choice == 121 || choice == 78 || choice == 110));

		if (choice == 89 || choice == 121) {
			quit = true;
			break;

		}

		DisplayItems(*catalog);

	}

}
