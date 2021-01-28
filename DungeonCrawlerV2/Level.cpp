#include "Level.h"
#include <iostream>
#include <tuple>
#include <vector>


void Level::DisplayMap(std::vector<std::vector<char>> level, int render)
{
	for (int x = 0; x < level.size(); x++) {

		for (int z = 0; z < level[x].size(); z++) {

			std::cout << level[x][z] << " ";

		}
		std::cout << std::endl;
	}
}

void Level::Move(std::vector<std::vector<char>>* level, direction d)
{
	//get location of player
	std::tuple<int, int> coordinates = Location(level, 'P');



}

void Level::Start(std::vector<std::vector<char>>* level)
{
	//get starting location
	std::tuple<int, int> coordinates = Location(level, 'S');

	//place location
	level->at(std::get<0>(coordinates)).at(std::get<1>(coordinates)) = 'P';


}

std::tuple<int, int> Level::Location(std::vector<std::vector<char>>* level, char c)
{
	//identify current location
	int x, z;

	std::vector<std::vector<char>>::iterator i;
	std::vector<char>::iterator j;

	for (i = level->begin(); i != level->end(); i++) {

		for (j = i->begin(); j != i->end(); j++) {

			if (*j == c) {
				std::cout << *j << std::endl;
				x = std::distance(level->begin(), i);
				z = std::distance(i->begin(), j);;
			}

		}
	}

	if (!x || !z) {
		return std::make_tuple(-1, -1);
	}
	else {
		return std::make_tuple(x, z);
	}
	
	
}

std::map<char, std::string> Level::CreateLegend()
{

	std::map<char, std::string> legend;

	legend['w'] = "Wall";
	legend['d'] = "Unlocked Door";
	legend['D'] = "Locked Door";
	legend['s'] = "Stairs";
	legend['S'] = "Start";
	legend['e'] = "Enemy";
	legend['E'] = "Enemy Boss";
	legend['c'] = "Chest";
	legend['C'] = "Locked Chest";
	legend['P'] = "Player";

	return legend;
}
