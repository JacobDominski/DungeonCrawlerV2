#include "Level.h"

//displays copy of the map then gets popped off the stack
void Level::DisplayMap(std::vector<std::vector<char>> level, int render)
{
	//takes the current map and the render distance
	//NOTE: render not implemented

	__int64 x, z;

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

		std::cout << "\n";

	}

}

//this function moves the player character or non player character up, down, left, or right if allowed
char Level::Move(std::vector<std::vector<char>>* level, direction d, char currentTile, char c)
{
	const unsigned __int64 range = 1;
	//Not completed!
	char tileCheck = '~';
	//get location of player
	std::tuple<int, int> coordinates = Location(level, c);

	//stores coordinates in an array
	//z first then x
	int position[2] = { std::get<0>(coordinates), std::get<1>(coordinates) };
	

	//moves changes the characters position
	if (d == up) {
		//if true then move
		tileCheck = level->at(position[1] - range).at(position[0]);
		if (!(tileCheck == 'w' || tileCheck == 'D')) {
			//move character up
			position[1]--;
		}
		else {
			return currentTile;
		}

	}
	else if (d == down) {
		tileCheck = level->at(position[1] + range).at(position[0]);
		if (!(tileCheck == 'w' || tileCheck == 'D')) {
			//move character down
			position[1]++;
		}
		else {
			return currentTile;
		}
		
	}
	else if (d == left) {
		tileCheck = level->at(position[1]).at(position[0] - range);
		if (!(tileCheck == 'w' || tileCheck == 'D')) {
			//move character down
			position[0]--;
		}
		else {
			return currentTile;
		}
		
	}
	else if (d == right) {
		tileCheck = level->at(position[1]).at(position[0] + range);
		if (!(tileCheck == 'w' || tileCheck == 'D')) {
			//move character down
			position[0]++;
		}
		else {
			return currentTile;
		}
		
	}
	//place down current tile using old coordinates
	level->at(std::get<1>(coordinates)).at(std::get<0>(coordinates)) = currentTile;

	//saves the new location of the tile using new coordinates
	currentTile = level->at(position[1]).at(position[0]);

	//std::cout << "New Position - x: " << position[0] << ", z: " << position[1];
	//std::cout << ", character: -" << level->at(position[1]).at(position[0]) << "-\n";

	//z goes first then x and places the character on that tile
	level->at(position[1]).at(position[0]) = c;


	//returns the current tile to be replaced on the next move else send back the original tile
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
	__int64 x, z;

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
	legend['c'] = "Open Chest";
	legend['C'] = "Closed Chest";
	legend['P'] = "Player";

	return legend;
}

