#include <Windows.h>
#include <iostream>
#include "game.h"

unsigned int Game::GetProcessId()
{
	DWORD pid;
	HWND window = FindWindowA(NULL, "AssaultCube");
	if (window == NULL)
	{
		std::cerr << "ERROR: Failed finding window." << std::endl;
		std::exit(1);
	}
	GetWindowThreadProcessId(window, &pid);
	return pid;
}
