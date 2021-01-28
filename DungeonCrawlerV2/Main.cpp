#include <iostream>
#include <vector>
#include <conio.h>
#include "Level.h"

#define KEY_UP    72
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_DOWN  80

void ClearScreen();
void Instructions();

int main() {
	Level level;

	std::string choice = "";
	bool GameRunning = true;
	std::vector<std::vector<char>> CurrentLevel = level.level1;

	
    while (GameRunning) {

		level.DisplayMap(CurrentLevel);
		std::cin >> choice;
		ClearScreen();
	}
    


	return 0;
}

void Instructions() {
	std::cout << "use arrow keys to move\n";
}

void ClearScreen() {
	// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
	std::cout << "\x1B[2J\x1B[H";
}