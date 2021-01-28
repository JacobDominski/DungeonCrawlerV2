#include <iostream>
#include <vector>
#include <conio.h>
#include "Level.h"

#define KEY_UP    72
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_DOWN  80

//function prototypes
void ClearScreen();
void Instructions();
void Input();

//main function
int main() {
	//creates new instance of the levels
	Level level;

	//player character
	char player = 'P';
	bool GameRunning = true;
	//saves map to current level
	std::vector<std::vector<char>> CurrentLevel = level.level1;
	
	//calls the start method to move the character to the starting position
	level.Start(&CurrentLevel);
	
	//game loop
    while (GameRunning) {
		//displays the map
		level.DisplayMap(CurrentLevel);
		//gets input
		Input();
		//clears screen to repeat
		ClearScreen();
	}

	return 0;
}

//function of the input
void Input() {

	//ch is the key, ex is for the arrow key
	int ch, ex;
	//will change later
	while (1) {
		//gets character
		ch = _getch();
		//if a character is given and 224 is for the arrow keys
		if (ch && ch != 224) {
			std::cout << std::endl << "Not arrow: " << (char)ch << std::endl;
			//if a slash is pressed type command
			//TODO: implement if for command
		}
		else {
			//else get the arrow keys
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
	
}

void Instructions() {
	std::cout << "use arrow keys to move\n";
}

void ClearScreen() {
	// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
	std::cout << "\x1B[2J\x1B[H";
}