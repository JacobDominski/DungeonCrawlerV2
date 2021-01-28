#include "Level.h"
#include <iostream>
#include <tuple>
#include <vector>

//displays copy of the map then gets popped off the stack
void Level::DisplayMap(std::vector<std::vector<char>> level, int render)
{
	//takes the current map and the render distance
	//NOTE: render not implemented

	//nested for loop iterates through the 2d vector and formats it nicely
	for (int x = 0; x < level.size(); x++) {

		for (int z = 0; z < level[x].size(); z++) {

			//displays current character at the location
			std::cout << level[x][z] << " ";

		}
		std::cout << std::endl;
	}
}

//this function moves the player character or non player character up, down, left, or right if allowed
void Level::Move(std::vector<std::vector<char>>* level, direction d, char c)
{
	//Not completed!

	//get location of player
	std::tuple<int, int> coordinates = Location(level, c);



}

//this function moves the player to the start of the level
void Level::Start(std::vector<std::vector<char>>* level)
{
	//get starting location for the player
	std::tuple<int, int> coordinates = Location(level, 'S');

	//place location
	level->at(std::get<0>(coordinates)).at(std::get<1>(coordinates)) = 'P';


}

//this function gets the coordinates of a certain character (mostly used for player and enemy)
std::tuple<int, int> Level::Location(std::vector<std::vector<char>>* level, char c)
{
	//initializes variables to hold coordinates
	int x, z;

	//setup iterator for both directions
	std::vector<std::vector<char>>::iterator i;
	std::vector<char>::iterator j;

	//iterate through the 2d vector
	for (i = level->begin(); i != level->end(); i++) {

		for (j = i->begin(); j != i->end(); j++) {

			//if the current character is equivalent to specified character
			if (*j == c) {
				//set the x and z position to the current location
				x = std::distance(level->begin(), i);
				z = std::distance(i->begin(), j);;
			}

		}
	}

	//if it could not find character
	if (!x || !z) {
		//return negative values
		return std::make_tuple(-1, -1);
	}
	else {
		//return tuple of the coordinates
		return std::make_tuple(x, z);
	}
	
	
}

//function to create a legend for the map
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
