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
void Input();

int main() {
	Level level;

	char player = 'P';
	bool GameRunning = true;
	std::vector<std::vector<char>> CurrentLevel = level.level1;
	

	level.Start(&CurrentLevel);
	
    while (GameRunning) {

		level.DisplayMap(CurrentLevel);
		Input();
		ClearScreen();
	}

	return 0;
}

void Input() {

	int ch, ex;
	while (1) {
		ch = _getch();
		if (ch && ch != 224) {
			std::cout << std::endl << "Not arrow: " << (char)ch << std::endl;
		}
		else {
			switch (ex = _getch()) {
				case KEY_UP:
					std::cout << std::endl << "Up" << std::endl;
					break;
				case KEY_DOWN:
					std::cout << std::endl << "Down" << std::endl;
					break;
				case KEY_LEFT:
					std::cout << std::endl << "Left" << std::endl;
					break;
				case KEY_RIGHT:
					std::cout << std::endl << "Right" << std::endl;
					break;
				default:
					std::cout << std::endl << "null" << std::endl;
					break;
			}
		}
		
	}
	//do

		//get character input

		//if arrow key

			//call move
			//break

		//if slash
			//call command
			//break

	//while character not arrow or slash
}

void Instructions() {
	std::cout << "use arrow keys to move\n";
}

void ClearScreen() {
	// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
	std::cout << "\x1B[2J\x1B[H";
}