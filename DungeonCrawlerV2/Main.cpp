#include <iostream>
#include <vector>
#include <conio.h>
#include <thread>
#include <chrono>
#include "Level.h"
#include "Item.h"
#include "Player.h"

#define KEY_UP    72
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_DOWN  80

//function prototypes
void ClearScreen();
void Instructions();
void Input(Level* lvl, std::vector<std::vector<char>>* level);
void Sleep(int milliseconds);

//main function
int main() {
	//creates new instance of the levels
	Level level;

	//create player
	//Player player;

	//char player = 'P';
	//list of items
	std::vector<Item> Items = CreateItems();

	bool GameRunning = true;
	//saves map to current level
	std::vector<std::vector<char>> CurrentLevel = level.level1;
	
	//calls the start method to move the character to the starting position
	level.Start(&CurrentLevel);
	
	//game loop
    while (GameRunning) {
		//displays the map
		level.DisplayMap(CurrentLevel);
		//sleep
		Sleep(100);
		//gets input
		Input(&level, &CurrentLevel);
		
		//clears screen to repeat
		ClearScreen();
	}

	return 0;
}

//function of the input
void Input(Level* lvl, std::vector<std::vector<char>>* level) {

	//ch is the key, ex is for the arrow key
	int ch, ex;
	std::string answer = "";
	//will change later
	std::cout << "char: " << lvl->CurrentTile << std::endl;
	//gets character
	ch = _getch();
	//if a character is given and 224 is for the arrow keys
	if (ch && ch != 224) {
		//if a slash is pressed type command
		//TODO: implement if for command
		if (ch == 47) {
			std::cout << '/';
			std::getline(std::cin, answer);


		}
	}
	else {
		//else get the arrow keys
		switch (ex = _getch()) {
			case KEY_UP:
				//std::cout << std::endl << "Up" << std::endl;
				lvl->CurrentTile = lvl->Move(level, up, lvl->CurrentTile, 'P');
				break;
			case KEY_DOWN:
				//std::cout << std::endl << "Down" << std::endl;
				lvl->CurrentTile = lvl->Move(level, down, lvl->CurrentTile, 'P');
				break;
			case KEY_LEFT:
				//std::cout << std::endl << "Left" << std::endl;
				lvl->CurrentTile = lvl->Move(level, left, lvl->CurrentTile, 'P');
				break;
			case KEY_RIGHT:
				//std::cout << std::endl << "Right" << std::endl;
				lvl->CurrentTile = lvl->Move(level, right, lvl->CurrentTile, 'P');
				break;
			default:
				std::cout << std::endl << "null" << std::endl;
				break;
		}
	}
	
}

void Sleep(int milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void Instructions() {
	std::cout << "use arrow keys to move\n";
}

void ClearScreen() {
	// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
	std::cout << "\x1B[2J\x1B[H";
	//instead of clearing the screen, only clear necessary characters surrounding the player and enemies that move
	//NOTE: modify display map function as well as this.
}