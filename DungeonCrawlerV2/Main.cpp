#include "GameStructure.h" //pause
#include "Level.h"
#include "Item.h"
#include "Player.h"
#include "Commands.h"
#include "Chest.h"
#include "Store.h"

#define KEY_UP    72
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_DOWN  80

//function prototypes
void Input(Level* lvl, std::vector<std::vector<char>>* level, Player* player);

//main function
int main() {
	//
	srand(time(NULL));
	//creates new instance of the levels
	Level level;

	//create player
	Player player;

	//list of items
	std::vector<Item> Items = CreateItems();

	bool GameRunning = true;
	//saves map to current level
	std::vector<std::vector<char>> CurrentLevel = level.level1;

	//calls the start method to move the character to the starting position
	level.Start(&CurrentLevel);

	//ask if the player wants to but anything.
	Store(&player, &Items);
	
	//game loop
    while (GameRunning) {
		//clears screen to repeat
		ClearScreen();

		//displays the map
		level.DisplayMap(CurrentLevel);
		Help();
		//check tile for enemy or chest
		TileCheck(&player, &Items);
		//sleep
		Sleep(100);
		//gets input
		Input(&level, &CurrentLevel, &player);

	}

	return 0;
}

//function of the input
void Input(Level* lvl, std::vector<std::vector<char>>* level, Player* player) {

	//ch is the key, ex is for the arrow key
	int ch, ex;
	std::string answer = "";

	//gets character
	ch = _getch();
	//if a character is given and 224 is for the arrow keys
	if (ch && ch != 224) {
		//if a slash is pressed type command
		if (ch == 47) {
			std::cout << '/';
			std::getline(std::cin, answer);
			std::cout << "Command - /" << answer << std::endl;
			Commands("/"+answer, player);
			pause("\npress a key to continue...");
		}
	}
	else {
		//else get the arrow keys
		switch (ex = _getch()) {
			case KEY_UP:
				//std::cout << std::endl << "Up" << std::endl;
				player->SetCurrentTile(lvl->Move(level, up, player->GetCurrentTile(), player->GetChar()));
				break;
			case KEY_DOWN:
				//std::cout << std::endl << "Down" << std::endl;
				player->SetCurrentTile(lvl->Move(level, down, player->GetCurrentTile(), player->GetChar()));
				break;
			case KEY_LEFT:
				//std::cout << std::endl << "Left" << std::endl;
				player->SetCurrentTile(lvl->Move(level, left, player->GetCurrentTile(), player->GetChar()));
				break;
			case KEY_RIGHT:
				//std::cout << std::endl << "Right" << std::endl;
				player->SetCurrentTile(lvl->Move(level, right, player->GetCurrentTile(), player->GetChar()));
				break;
			default:
				std::cout << std::endl << "null" << std::endl;
				break;
		}
	}
	
}
