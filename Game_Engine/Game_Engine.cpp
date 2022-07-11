// Game_Engine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "SDL.h"
#include "RS_EngineCore.h"

using namespace std;

int main(int argc, char* argv[])
{
	RS_EngineCore game;
	return game.start();
}
