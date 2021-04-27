#include <iostream>
#include <thread> //sleep
#include <chrono> //sleep
#include "GameStructure.h"


void pause(const char* prompt)
{
	std::cin.clear(); // clear failed/error states of the stream if they are set

	if (std::cin.rdbuf()->in_avail()) // if there are any characters in the input buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // throw them away

	std::cout << prompt;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Sleep(int milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void Help() {
	std::cout << "Type '/help' to view list of commands\n";
}

void ClearScreen() {
	system("cls");
	// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
	//std::cout << "\x1B[2J\x1B[H";
	//instead of clearing the screen, only clear necessary characters surrounding the player and enemies that move
	//NOTE: modify display map function as well as this.
}