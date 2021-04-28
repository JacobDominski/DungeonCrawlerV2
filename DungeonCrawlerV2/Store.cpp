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

		DisplayItems(catalog);

		BuyItem(player, catalog);

	}

}

void BuyItem(Player* player, std::vector<Item>* catalog)
{
	std::cout << "You have $" << player->GetMoney() << " and a space of " << player->GetCarryingCapacity() << std::endl;
	std::cout << "What Item would you like to buy? ";

	std::string itemName;

	std::getline(std::cin, itemName);

	int itemID = SearchItem(catalog, itemName);

	if (itemID == -1) {
		std::cout << "\nCould not find the item you wanted. Try double checking if the name is spelled correctly\n";
	}
	else {

		if (player->GetMoney() >= catalog->at(itemID).cost && player->GetCarryingCapacity() >= catalog->at(itemID).weight) {
			player->SetMoney(player->GetMoney() - catalog->at(itemID).cost);
			player->SetCarryingCapacity(player->GetCarryingCapacity() - catalog->at(itemID).weight);
			player->AddItem(catalog->at(itemID));
			std::cout << "Item Bought!\n";
		}
		else {
			std::cout << "\nYou do not have enough Money and/or Space \nin your inventory. Try buying a bag to \nincrease your carrying capacity.\n";
		}
	}


}
