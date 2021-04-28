
#include "GameStructure.h"

//function that clears the buffer and displays a message
void pause(const char* prompt)
{
	std::cin.clear(); // clear failed/error states of the stream if they are set

	if (std::cin.rdbuf()->in_avail()) // if there are any characters in the input buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // throw them away

	std::cout << prompt;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
//function that stops the thread for a certain number of milliseconds
void Sleep(int milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
//displays a simple help command for the user
void Help() {
	std::cout << "Type '/help' to view list of commands\n";
}
//clears the screen (Might need to figure out a better way?)
void ClearScreen() {
	system("cls");
	// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
	//std::cout << "\x1B[2J\x1B[H";
	//instead of clearing the screen, only clear necessary characters surrounding the player and enemies that move
	//NOTE: modify display map function as well as this.
}
//function that gets a random integer
int GetRandom(int min, int max)
{
	return min + rand() % ((max + 1) - min);
}
