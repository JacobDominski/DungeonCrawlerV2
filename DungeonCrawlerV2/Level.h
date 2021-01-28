#pragma once
#include <vector>
#include <tuple>
#include <map>
#include <string>

#define MAX_WIDTH 16
#define MAX_HEIGHT 16

enum direction
{
	up,
	down,
	left,
	right
};



struct Level
{
	Level() {

		std::map<char, std::string> Legend = CreateLegend();
	}


	const std::vector<std::vector<char>> level1
	{
		{'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},
		{'w', ' ', 'c', 'w', 'w', ' ', ' ', ' ', ' ', ' ', ' ', 'w', ' ', ' ', ' ', 'w'},
		{'w', ' ', 'w', ' ', 'e', ' ', 'w', ' ', 'w', 'w', ' ', ' ', ' ', 'w', 'c', 'w'},
		{'w', ' ', 'w', ' ', 'w', 'w', 'w', ' ', 'w', 'w', 'w', 'w', ' ', 'w', 'w', 'w'},
		{'w', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', 'w'},
		{'w', ' ', 'w', ' ', 'w', 'w', 'w', ' ', 'w', 'w', 'w', 'w', 'w', 'w', ' ', 'w'},
		{'w', 'w', 'w', ' ', 'D', 's', 'w', ' ', 'w', 'c', ' ', ' ', ' ', 'w', ' ', 'w'},
		{'w', ' ', 'w', ' ', 'w', 'w', 'w', ' ', 'w', 'w', ' ', 'w', ' ', 'w', ' ', 'w'},
		{'w', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'w', ' ', 'w', ' ', 'w'},
		{'w', 'w', 'w', ' ', 'w', 'w', 'w', ' ', 'w', 'w', 'w', 'w', ' ', 'w', ' ', 'w'},
		{'w', 'c', 'w', ' ', ' ', ' ', 'w', ' ', ' ', ' ', ' ', ' ', ' ', 'w', ' ', 'w'},
		{'w', ' ', 'w', ' ', 'w', ' ', 'w', 'w', ' ', 'w', 'w', ' ', 'w', 'w', ' ', 'w'},
		{'w', ' ', 'w', ' ', 'w', ' ', ' ', ' ', ' ', ' ', 'w', ' ', ' ', 'e', ' ', 'w'},
		{'w', ' ', ' ', ' ', 'w', 'w', 'w', 'w', 'w', ' ', 'w', ' ', 'w', ' ', 'w', 'w'},
		{'w', ' ', 'w', ' ', ' ', ' ', 'e', ' ', ' ', ' ', 'w', 'S', 'w', ' ', ' ', 'w'},
		{'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},
	};

	std::vector<std::vector<char>> level2
	{
		{'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},
		{'w', 'w', ' ', 'w', ' ', 'w', 'c', ' ', ' ', 'w', ' ', ' ', ' ', 'w', ' ', 'w'},
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
		{'w', 'c', 'w', ' ', 'e', ' ', 'w', 'c', 'w', 'w', 'w', ' ', ' ', ' ', ' ', 'w'},
		{'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'},
	};
	std::vector<std::vector<char>> level3;

	void DisplayMap(std::vector<std::vector<char>> level, int render = 0);

	void Move(std::vector<std::vector<char>>* level, direction d);

	void Start(std::vector<std::vector<char>>* level);

	std::tuple<int, int> Location(std::vector<std::vector<char>>* level, char c);

	std::map<char, std::string> CreateLegend();

};

