#pragma once
#include "Item.h"
#include "Player.h"

void Store(Player* player, std::vector<Item>* catalog);

void BuyItem(Player* player, std::vector<Item>* catalog);