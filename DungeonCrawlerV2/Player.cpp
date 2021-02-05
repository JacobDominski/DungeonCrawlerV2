#include "Player.h"

Player::Player()
{
	Char = 'P';
	CharacterLevel = 1;
	SetName();
	SetStats(Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma);

	SetStrMod(Strength);
	SetDexMod(Dexterity);
	SetConMod(Constitution);
	SetIntMod(Intelligence);
	SetWisMod(Wisdom);
	SetChaMod(Charisma);

	Health = 10 + ConMod;
	ac = 10 + DexMod;

	SetMoney(RollDice(5, 4, 0, false));
	//giving myself some extra money for demo testing
	SetMoney(GetMoney() * 10);

	std::cout << "\nWelcome " << GetName() << "! Here is your stats";

	PlayerStats();
	pause("Press any key to continue . . . ");
}

void Player::SetMoney(int money)
{
	Money = money;
}

int Player::GetMoney()
{
	return Money;
}

void Player::SetName()
{
	std::string name = "";

	std::cout << "Enter your name (38 characters max): ";

	std::getline(std::cin, name);

	Name = name;
}

std::string Player::GetName()
{
	return Name;
}

void Player::SetCarryingCapacity(int carrycapacity)
{
	carrying_capacity = carrycapacity;
}

int Player::GetCarryingCapacity()
{
	return carrying_capacity;
}

void Player::SetInventory(std::vector<Item> inventory)
{
	Inventory = inventory;
}

std::vector<Item> Player::GetInventory()
{
	return Inventory;
}

void Player::SetStats(int& strength, int& dexterity, int& constitution, int& intelligence, int& wisdom, int& charisma)
{
	//create an array to store all of the rolls
	int statID[6];
	std::cout << "Let's roll a dice to determine your stats!\n";
	//this for loop goes through 6 times and adds the roll to the array
	for (int i = 0; i < 6; i++)
	{
		//calls the function and stores the roll in the current index 
		statID[i] = RollDice(4, 6, 0, true);
	}
	std::cout << "\n\nThere are six stats: Strength, Dexterity, Constitution, Intelligence, Wisdom, and Charisma";
	std::cout << "\nPick which index (starting with 1) you want to put into your stat\n";
	//displays all of your rolls
	for (int i = 0; i < 6; i++) { std::cout << statID[i] << "  "; }
	std::cout << "\n\n";

	//calls the function to add the roll to each stat
	strength = AddStat("Strength", statID);
	dexterity = AddStat("Dexterity", statID);
	constitution = AddStat("Constitution", statID);
	intelligence = AddStat("Intelligence", statID);
	wisdom = AddStat("Wisdom", statID);
	charisma = AddStat("Charisma", statID);
}

int Player::AddStat(std::string stat, int arr[])
{
	//creates two variables: one for the players choice to choose which roll to use for the particular stat
	//and the added stat variable which applies the new stat to the stat
	int choice;
	int addStat = 0;

	do {
		do {
			try {
				std::cout << stat << ": ";
				std::cin >> choice;

				if (!(int)choice) {
					throw "Error";
				}

				choice--;

				if (!(arr[choice] == 0)) {
					break;
				}
				else {
					std::cout << "\nThis stat has already been used; pick another one!\n";
				}
			}
			catch (...) {
				std::cout << "Enter a number 1 through 6\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				//continues the function
				continue;
			}
			

		} while (true);
		addStat = arr[choice];
		arr[choice] = 0;
	} while (choice < 0 || choice > 6);
	

	//this for loop displays the current array after it's been modified
	for (int i = 0; i < 6; i++) { std::cout << arr[i] << " "; }
	std::cout << "\n";
	//returns the new stat that has been added
	return addStat;
}

void Player::addItem(Item& inventoryItem)
{
	Inventory.push_back(inventoryItem);

	if (inventoryItem.id > 34 && inventoryItem.id < 38) {
		SetCarryingCapacity(GetCarryingCapacity() + inventoryItem.effect);
	}
}

void Player::DeleteItem(Item& inventoryItem)
{
	auto it = Inventory.begin();
	int id = -1;//starts at the beginning of the index of the player inventory
	do
	{
		++id;
	} while (inventoryItem.name != Inventory[id].name && it != Inventory.end());//it keeps looping until it finds the item or until it makes it to the end of the array

	std::advance(it, id);
	Inventory.erase(it);

	if (inventoryItem.id > 34 && inventoryItem.id < 38) {
		SetCarryingCapacity(GetCarryingCapacity() - inventoryItem.effect);
	}
}

void Player::ShowItem(Item& inventoryItem)
{
	std::cout << "\n\n----------------------------------\n";
	std::cout << inventoryItem.name;
	std::cout << "\nType: " << inventoryItem.type;
	std::cout << "\nDescription: " << inventoryItem.flavor_text;
	std::cout << "\nCost: " << inventoryItem.cost;
	std::cout << "\nWeight: " << inventoryItem.weight;
	std::cout << "\nProperty: " << inventoryItem.property;
	std::cout << "\nRequired Level: lvl " << inventoryItem.requirement_level;
	switch (inventoryItem.type)
	{
	case Weapon:
		std::cout << "\nDamage: 1d" << inventoryItem.effect;
		break;
	case Armor:
		std::cout << "\nArmor: +" << inventoryItem.effect;
		break;
	case Potion:
		std::cout << "\nPotion: +" << inventoryItem.effect;
		break;
	case Ring:
		std::cout << "\nRing: +" << inventoryItem.effect;
		break;
	case Misc_Item:
		std::cout << "\n+" << inventoryItem.effect << " Carrying Capacity";
		break;
	}
	std::cout << "\n----------------------------------\n";
}

int Player::SearchPlayerItem(std::string name)
{
	//goes through a while loop to check if the name argument matches the item name
	int id = -1;
	do
	{
		++id;
	} while (name != Inventory[id].name && id < Inventory.size() - 1);

	//if there is a match, it returns the id from the inventory vector
	if (name == Inventory[id].name)
	{
		return id;
	}//else it returns a -1 which will be used to see if it came back false and -1 is impossible to return from a vector

	return -1;
}

void Player::DisplayInventory()
{
	std::cout << "\n\n";
	int id = 0;//this stores the id of each item
	int NameSize = 0;//these two variables organize the store to make it look nice
	int format = 0;
	int x = round(Inventory.size() / 2);
	std::cout << "\nPLAYER INVENTORY\n";
	std::cout << "-----------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < 19; i++)
	{

		for (int j = 0; j < 2; j++)
		{
			if (id >= Inventory.size()) {
				break;
			}
			//this first part lists the name
			//20 characters
			NameSize = Inventory[id].name.size();
			format = 21 - NameSize;
			std::cout << Inventory[id].name;
			for (int space = 0; space < format; space++)
			{
				std::cout << " ";
			}
			//this part list the costs
			std::cout << " | Cost: " << Inventory[id].cost;
			format = 5 - std::to_string(Inventory[id].cost).size();
			for (int space = 0; space < format; space++)
			{
				std::cout << " ";
			}
			//this part lists the weight
			std::cout << " | Weight: " << Inventory[id].weight;
			format = 5 - std::to_string(Inventory[id].weight).size();
			for (int space = 0; space < format; space++)
			{
				std::cout << " ";
			}
			std::cout << " | ";
			//increases the id to keep track of the item listed
			id++;
		}
		std::cout << "\n";
	}
	std::cout << "-----------------------------------------------------------------------------------------------------------\n";
	std::cout << "\n\n";
}

void Player::PlayerStats()
{
	//displays stats
	std::cout << "\n------------------------------";
	std::cout << "\nPLAYER STATS:";
	std::cout << "\nName: " << Name;
	std::cout << "\nStrength:     " << Strength << " | StrMod: " << StrMod;
	std::cout << "\nDexterity:    " << Dexterity << " | DexMod: " << DexMod;
	std::cout << "\nConstitution: " << Constitution << " | ConMod: " << ConMod;
	std::cout << "\nIntelligence: " << Intelligence << " | IntMod: " << IntMod;
	std::cout << "\nWisdom:       " << Wisdom << " | WisMod: " << WisMod;
	std::cout << "\nCharisma:     " << Charisma << " | ChaMod: " << ChaMod;
	std::cout << "\nPlayer Health: " << Health;
	std::cout << "\nArmor Class: " << ac;
	std::cout << "\nPlayer Money: $" << Money;
	std::cout << "\nPlayer Carrying Capacity: " << carrying_capacity;
	std::cout << "\n------------------------------\n\n";
}

void Player::EquipItem()
{
}

int RollDice(int numOfDice, int numOfSides, int modifier, bool playerStats)
{
	//these two variables are for the total value, and the current die value
	int total = 0;
	int dieValue = 0;


	//rolling for player stats is special because you roll 4d6 and take the highest 3
	if (playerStats)
	{
		//stores the all 4 roles in an array
		int die[4];
		//these variables store the first second and third highest numbers in the array
		int firstHigh, secondHigh, thirdHigh;
		//initializes the three variables to the lowest value
		firstHigh = secondHigh = thirdHigh = INT_MIN;

		std::cout << "\nto roll, ";
		pause("Press any key to continue . . . ");

		//the for loop rolls 4 dice
		for (int i = 0; i < numOfDice; i++)
		{

			//this gets the value of the die and stores it into the array
			die[i] = (rand() % numOfSides) + 1;

			//it then checks to see if it is the highest, the second highest, or the third highest
			if (die[i] > firstHigh)
			{
				thirdHigh = secondHigh;
				secondHigh = firstHigh;
				firstHigh = die[i];
			}
			else if (die[i] > secondHigh)
			{
				thirdHigh = secondHigh;
				secondHigh = die[i];
			}
			else if (die[i] > thirdHigh)
			{
				thirdHigh = die[i];
			}
		}

		//after all 4 rolls are made, it adds them to the total value
		total = firstHigh + secondHigh + thirdHigh;
		//displays the total
		std::cout << "\nYou Rolled a total of " << total;

	}
	else//if it's not a regular roll
	{
		std::cout << "\nLet's roll to see your starting cash";
		//it loops the amount of time there are number of dice
		for (int i = 0; i < numOfDice; i++)
		{
			std::cout << "\nto roll, ";
			pause("Press any key to continue . . . ");
			//this gets the value of the die
			dieValue = (rand() % numOfSides) + 1;
			std::cout << "You rolled a " << dieValue << "!\n";
			total += dieValue;//it adds the die value to the current total value
		}
		std::cout << "\nYour starting cash is " << total*10 << std::endl;
		
	}

	//lastly, it adds the modifier to the total variable
	total += modifier;

	

	//it then returns the total
	return total;
}
