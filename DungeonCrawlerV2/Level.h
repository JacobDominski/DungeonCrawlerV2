#pragma once
#include <vector>
#include <tuple>
#include <map>
#include <string>
#include <iostream>

#define MAX_WIDTH 16
#define MAX_HEIGHT 16

//directions for the player and enemy to move
enum direction
{
	up,
	down,
	left,
	right
};


//struct to hold all the data for the maps
struct Level
{
	//constructor to create the legend
	std::map<char, std::string> Legend = CreateLegend();
	char CurrentTile = 'S';

	//first map
	const std::vector<std::vector<char>> level1
	{
		{'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},
		{'w', ' ', 'C', 'w', 'w', ' ', ' ', ' ', ' ', ' ', ' ', 'w', ' ', ' ', ' ', 'w'},
		{'w', ' ', 'w', ' ', 'e', ' ', 'w', ' ', 'w', 'w', ' ', ' ', ' ', 'w', 'C', 'w'},
		{'w', ' ', 'w', ' ', 'w', 'w', 'w', ' ', 'w', 'w', 'w', 'w', ' ', 'w', 'w', 'w'},
		{'w', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', 'w'},
		{'w', ' ', 'w', ' ', 'w', 'w', 'w', ' ', 'w', 'w', 'w', 'w', 'w', 'w', ' ', 'w'},
		{'w', 'w', 'w', ' ', 'D', 's', 'w', ' ', 'w', 'C', ' ', ' ', ' ', 'w', ' ', 'w'},
		{'w', ' ', 'w', ' ', 'w', 'w', 'w', ' ', 'w', 'w', ' ', 'w', ' ', 'w', ' ', 'w'},
		{'w', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'w', ' ', 'w', ' ', 'w'},
		{'w', 'w', 'w', ' ', 'w', 'w', 'w', ' ', 'w', 'w', 'w', 'w', ' ', 'w', ' ', 'w'},
		{'w', 'C', 'w', ' ', ' ', ' ', 'w', ' ', ' ', ' ', ' ', ' ', ' ', 'w', ' ', 'w'},
		{'w', ' ', 'w', ' ', 'w', ' ', 'w', 'w', ' ', 'w', 'w', ' ', 'w', 'w', ' ', 'w'},
		{'w', ' ', 'w', ' ', 'w', ' ', ' ', ' ', ' ', ' ', 'w', ' ', ' ', 'e', ' ', 'w'},
		{'w', ' ', ' ', ' ', 'w', 'w', 'w', 'w', 'w', ' ', 'w', ' ', 'w', ' ', 'w', 'w'},
		{'w', ' ', 'w', ' ', ' ', ' ', 'e', ' ', ' ', ' ', 'w', 'S', 'w', ' ', ' ', 'w'},
		{'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},
	};

	//second map
	std::vector<std::vector<char>> level2
	{
		{'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},
		{'w', 'w', ' ', 'w', ' ', 'w', 'C', ' ', ' ', 'w', ' ', ' ', ' ', 'w', ' ', 'w'},
		{'w', 'e', ' ', 'w', ' ', 'w', 'w', 'w', ' ', ' ', ' ', 'w', ' ', 'E', ' ', 'w'},
		{'w', ' ', 'w', 'w', ' ', ' ', ' ', ' ', ' ', 'w', ' ', 'w', 'D', 'w', 'w', 'w'},
		{'w', ' ', ' ', ' ', ' ', 'w', ' ', 'w', ' ', 'w', ' ', 'w', 's', 'w', 'w', 'w'},
		{'w', ' ', 'w', ' ', 'w', 'w', ' ', 'w', 'w', 'w', ' ', 'w', 'w', 'w', 'C', 'w'},
		{'w', ' ', 'w', ' ', 'w', 'S', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'w', ' ', 'w'},
		{'w', ' ', 'w', ' ', 'w', 'w', ' ', 'w', 'w', ' ', 'w', 'w', ' ', 'w', ' ', 'w'},
		{'w', ' ', ' ', 'e', ' ', 'w', ' ', 'w', ' ', ' ', 'e', 'w', ' ', ' ', ' ', 'w'},
		{'w', 'w', ' ', 'w', ' ', 'w', ' ', ' ', ' ', 'w', ' ', 'w', ' ', 'w', ' ', 'w'},
		{'w', 'w', ' ', 'w', ' ', ' ', ' ', 'w', 'C', 'w', ' ', 'w', 'w', 'w', ' ', 'w'},
		{'w', ' ', ' ', 'w', 'w', ' ', 'w', 'w', 'w', 'w', ' ', ' ', ' ', ' ', ' ', 'w'},
		{'w', ' ', 'w', 'w', 'w', ' ', ' ', ' ', ' ', 'w', 'w', 'w', ' ', 'w', ' ', 'w'},
		{'w', ' ', 'w', ' ', 'w', ' ', 'w', 'w', ' ', ' ', ' ', ' ', ' ', 'w', 'w', 'w'},
		{'w', 'C', 'w', ' ', 'e', ' ', 'w', 'C', 'w', 'w', 'w', ' ', ' ', ' ', ' ', 'w'},
		{'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},
	};
	//third map not implemented
	std::vector<std::vector<char>> level3;

	//method prototypes
	void DisplayMap(std::vector<std::vector<char>> level, int render = 0);

	char Move(std::vector<std::vector<char>>* level, direction d, char currentTile, char c);

	void Start(std::vector<std::vector<char>>* level);

	std::tuple<int, int> Location(std::vector<std::vector<char>>* level, char c);

	std::map<char, std::string> CreateLegend();

};

