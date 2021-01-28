#include "Level.h"
#include <iostream>

void Level::DisplayMap(std::vector<std::vector<char>> level, int render)
{
	for (int x = 0; x < level.size(); x++) {

		for (int z = 0; z < level[x].size(); z++) {

			std::cout << level[x][z] << " ";

		}
		std::cout << std::endl;
	}
}
