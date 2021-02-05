#include <iostream>
#include "GameStructure.h"


void pause(const char* prompt)
{
	std::cin.clear(); // clear failed/error states of the stream if they are set

	if (std::cin.rdbuf()->in_avail()) // if there are any characters in the input buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // throw them away

	std::cout << prompt;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}