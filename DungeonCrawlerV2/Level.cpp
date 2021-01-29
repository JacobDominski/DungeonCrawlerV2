#include "Level.h"
#include <iostream>
#include <tuple>
#include <vector>

//displays copy of the map then gets popped off the stack
void Level::DisplayMap(std::vector<std::vector<char>> level, int render)
{
	//takes the current map and the render distance
	//NOTE: render not implemented

	int x, z;

	//setup iterator for both directions
	std::vector<std::vector<char>>::iterator i;
	std::vector<char>::iterator j;

	for (i = level.begin(); i != level.end(); i++) {

		for (j = i->begin(); j != i->end(); j++) {

			x = std::distance(level.begin(), i);
			z = std::distance(i->begin(), j);
			//displays current character at the location
			std::cout << level[x][z] << " ";

		}

		std::cout << std::endl;

	}

}

//this function moves the player character or non player character up, down, left, or right if allowed
char Level::Move(std::vector<std::vector<char>>* level, direction d, char currentTile, char c)
{
	//Not completed!

	//get location of player
	std::tuple<int, int> coordinates = Location(level, c);

	//stores coordinates in an array
	//z first then x
	int position[2] = { std::get<0>(coordinates), std::get<1>(coordinates) };
	std::cout << "x: " << position[0] << ", z: " << position[1] << std::endl;
	//places the original tile back on the map
	std::cout << "Tile: " << currentTile << std::endl;
	

	//moves changes the characters position
	if (position[1] > 0 && position[1] < 15 && position[0] > 0 && position[0] < 15) {
		
		level->at(position[1]).at(position[0]) = currentTile;
		
		if (d == up) {
			position[1]--;
		}
		else if (d == down) {
			position[1]++;
		}
		else if (d == left) {
			position[0]--;
		}
		else if (d == right) {
			position[0]++;
		}
	}
	

	//saves the new location of the tile
	currentTile = level->at(position[1]).at(position[0]);
	std::cout << "New Position - x: " << position[0] << ", z: " << position[1];
	//places the character on that tile
	std::cout << ", character: -" << level->at(position[1]).at(position[0]) << "-\n";
	//z goes first then x
	level->at(position[1]).at(position[0]) = c;

	return currentTile;
}

//this function moves the player to the start of the level
void Level::Start(std::vector<std::vector<char>>* level)
{
	//get starting location for the player
	std::tuple<int, int> coordinates = Location(level, 'S');

	//place location z first x second
	level->at(std::get<1>(coordinates)).at(std::get<0>(coordinates)) = 'P';


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
				z = std::distance(i->begin(), j);
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
		//z first then x
		return std::make_tuple(z, x);
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
