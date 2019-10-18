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

Game::Game()
{
	ReadProcessMemory(handle, (void*)0x50F500, &player_count, sizeof(player_count), NULL);
	ReadProcessMemory(handle, (void*)0x50F4F8, &entity_list, sizeof(entity_list), NULL);
}
