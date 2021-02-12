
#include "Item.h"


//this function displays all of the items in the game
void Store(std::vector<Item>& list)
{
	std::cout << "\n\n";
	int id = 0;//this stores the id of each item
	int NameSize = 0;//these two variables organize the store to make it look nice
	int format = 0;
	std::cout << "\nSTORE\n";
	std::cout << "-----------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			//this first part lists the name
			//20 characters
			NameSize = (int)list[id].name.size();
			format = 21 - NameSize;
			std::cout << list[id].name;
			for (int space = 0; space < format; space++)
			{
				std::cout << " ";
			}
			//this part list the costs
			std::cout << " | Cost: " << list[id].cost;
			format = 5 - (int)std::to_string(list[id].cost).size();
			for (int space = 0; space < format; space++)
			{
				std::cout << " ";
			}
			//this part lists the weight
			std::cout << " | Weight: " << list[id].weight;
			format = 5 - (int)std::to_string(list[id].weight).size();
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

int SearchItem(std::vector<Item> StoreItem, std::string ItemName)
{
	//goes through a while loop to check if the name argument matches the item name
	int id = -1;
	std::cout << ItemName << std::endl;
	do
	{
		++id;
	} while (ItemName != StoreItem[id].name && id < 37);


	//if there is a match, it returns the id from the inventory vector
	if (ItemName == StoreItem[id].name)
	{
		return id;
	}//else it returns a -1 which will be used to see if it came back false and -1 is impossible to return from a vector

	return -1;
}

void ShowItem(Item& inventoryItem)
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

std::vector<Item> CreateItems()
{
	std::vector<Item> items;
	//weapons
	Item ShortSword(0, "Short Sword", Weapon, "A basic sword that measures 1 - 1.5ft in length", 10, 10, "OneHanded", 1, 6);
	Item Club(1, "Club", Weapon, "A blunt object that can be swung with force", 2, 5, "OneHanded", 1, 4);
	Item Axe(2, "Axe", Weapon, "A long wooden handler with a sharp blade on the end used for chopping", 8, 10, "OneHanded", 2, 4);
	Item LongSword(3, "Longsword", Weapon, "Longer than a shortsword, this weapon can cause more damage while being OneHanded", 15, 15, "OneHanded", 2, 6);
	Item GreatClub(4, "Great Club", Weapon, "This great club is an upgrade from a regular club in both size and damage.", 5, 10, "OneHanded", 2, 6);
	Item BattleAxe(5, "Battleaxe", Weapon, "Used in battle, this weapon has a deadly force behind it when used", 20, 15, "TwoHanded", 3, 8);
	Item Rapier(6, "Rapier", Weapon, "This light weapon is used for quick and consistent attacks to weaken your enemy", 20, 5, "OneHanded", 3, 8);
	Item Warhammer(7, "Warhammer", Weapon, "This weapon is extermely heavy and used for doing lots of damage in one hit.", 25, 25, "TwoHanded", 3, 10);
	Item Glaive(8, "Glaive", Weapon, "A pole arm that is a large knife mounted to a pole.", 30, 20, "TwoHanded", 4, 10);
	Item GreatAxe(9, "Greataxe", Weapon, "The largest member of axes. It requires two hands to wield.", 30, 25, "TwoHanded", 4, 12);
	Item GreatSword(10, "Greatsword", Weapon, "The largest member of swords. It requires two hands to wield.", 50, 20, "TwoHanded", 4, 12);
	//armor
	Item LeatherArmor(11, "Leather Armor", Armor, "Armor made from stiff leather", 10, 10, "Light", 1, 11);
	Item PaddedArmor(12, "Padded Armor", Armor, "Armor made from regular clothes padded together", 5, 10, "Light", 1, 11);
	Item StuddedArmor(13, "Studded Leather Armor", Armor, "Armor made from stiff leather but reinforced with rivets", 45, 15, "Light", 1, 12);
	Item ChainShirt(14, "Chain Shirt", Armor, "made of small interlocking metal rings, the chain shirt gives decent protection", 50, 20, "Medium", 2, 13);
	Item Breastplate(15, "Breastplate", Armor, "made of fitted metal with leather, it leaves the arms and legs unprotected but good protection around the vital organs", 100, 25, "Medium", 2, 14);
	Item HalfPlate(16, "Half Plate", Armor, "consists of shaped metal plates the cover most of the wearer's body", 150, 40, "Medium", 2, 15);
	Item ChainMail(17, "Chain Mail", Armor, "Made of interlocking rings and includes a layer of quilted fabric to prevent chafing", 75, 55, "Heavy", 3, 16);
	Item Splint(18, "Splint", Armor, "Armor made from vertical strips of metal with flexible chain mail to protect the joints", 200, 60, "Heavy", 3, 17);
	Item Plate(19, "Plate", Armor, "Armor made from interlocking metal that covers the entire body", 10, 10, "Heavy", 4, 18);
	Item Shield(20, "Shield", Armor, "it's a shield", 10, 10, "Light", 2, 2);
	//potions 
	Item SmallHealthPotion(21, "Small Health Potion", Potion, "S small potion that restores some HP", 10, 2, "Health", 1, 5);
	Item MediumHealthPotion(22, "Medium Health Potion", Potion, "Restores some HP, more than the small potion", 20, 5, "Health", 1, 10);
	Item LargeHealthPotion(23, "Large Health Potion", Potion, "This large potion restores a lot of HP", 40, 10, "Health", 1, 20);
	Item ACBoostPotion(24, "Potion of Protection", Potion, "Drinking this potion will increase your armor class temporarily", 50, 10, "Buff", 1, 2);
	Item StrengthBuffPotion(25, "Strength Potion", Potion, "Drinking this potion gives you a buff to strength", 50, 10, "Buff", 1, 2);
	Item DexterityBuffPotion(26, "Dexterity Potion", Potion, "Drinking this potion gives you a buff to dexterity", 50, 10, "Buff", 1, 2);
	Item ConstitutionBuffPotion(27, "Constitution Potion", Potion, "Drinking this potion gives you a buff to constitution", 50, 10, "Buff", 1, 2);
	Item IntelligenceBuffPotion(28, "Intelligence Potion", Potion, "Drinking this potion gives you a buff to intelligence", 50, 10, "Buff", 1, 2);
	Item WisdomBuffPotion(29, "Wisdom Potion", Potion, "Drinking this potion gives you a buff to wisdom", 50, 10, "Buff", 1, 2);
	Item CharismaBuffPotion(30, "Charisma Potion", Potion, "Drinking this potion gives you a buff to charisma", 50, 10, "Buff", 1, 2);
	//rings
	Item RingOfProtection(31, "Ring of Protection", Ring, "This ring grants a bonus to the wearers armor class", 100, 1, "Buff", 3, 1);
	Item RingOfAction(32, "Ring of Free Action", Ring, "This ring grants an extra attack to the wearer", 100, 1, "Buff", 3, 1);
	Item RingOfResistance(33, "Ring of Resistance", Ring, "This ring grants the wearer resistance to any damage (kinda op)", 300, 1, "Buff", 4, 0);
	Item RingOfRegeneration(34, "Ring of Regeneration", Ring, "This ring grants a bonus to the wearer that heals the player 1 hp every 10 turns", 200, 1, "Buff", 3, 1);
	//misc.
	//bags for extra storage
	Item SmallBag(35, "Small Bag", Misc_Item, "This item gives the user 20 extra storage space", 50, 0, "Bag", 1, 20);
	Item MediumBag(36, "Medium Bag", Misc_Item, "This item gives the user 50 extra storage space", 100, 0, "Bag", 2, 50);
	Item LargeBag(37, "Large Bag", Misc_Item, "This item gives the user 100 extra storage space", 200, 0, "Bag", 3, 100);

	//added all items to the master list
	items.push_back(ShortSword);
	items.push_back(Club);
	items.push_back(Axe);
	items.push_back(LongSword);
	items.push_back(GreatClub);
	items.push_back(BattleAxe);
	items.push_back(Rapier);
	items.push_back(Warhammer);
	items.push_back(Glaive);
	items.push_back(GreatAxe);
	items.push_back(GreatSword);
	items.push_back(LeatherArmor);
	items.push_back(PaddedArmor);
	items.push_back(StuddedArmor);
	items.push_back(ChainShirt);
	items.push_back(Breastplate);
	items.push_back(HalfPlate);
	items.push_back(ChainMail);
	items.push_back(Splint);
	items.push_back(Plate);
	items.push_back(Shield);
	items.push_back(SmallHealthPotion);
	items.push_back(MediumHealthPotion);
	items.push_back(LargeHealthPotion);
	items.push_back(ACBoostPotion);
	items.push_back(StrengthBuffPotion);
	items.push_back(DexterityBuffPotion);
	items.push_back(ConstitutionBuffPotion);
	items.push_back(IntelligenceBuffPotion);
	items.push_back(WisdomBuffPotion);
	items.push_back(CharismaBuffPotion);
	items.push_back(RingOfProtection);
	items.push_back(RingOfAction);
	items.push_back(RingOfResistance);
	items.push_back(RingOfRegeneration);
	items.push_back(SmallBag);
	items.push_back(MediumBag);
	items.push_back(LargeBag);

	return items;
}
