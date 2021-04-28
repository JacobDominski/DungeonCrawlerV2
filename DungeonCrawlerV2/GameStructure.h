#pragma once
#include <iostream>
#include <thread> //sleep
#include <chrono> //sleep
#include <string>
//function prototypes
void pause(const char* prompt);

void Sleep(int milliseconds);

void Help();

void ClearScreen();

int GetRandom(int min, int max);