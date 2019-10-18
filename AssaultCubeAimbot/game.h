#pragma once
#include <Windows.h>

class Game
{
private:
	unsigned int GetProcessId();

public:
	Game();
	unsigned int entity_list;
	unsigned int player_count;
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetProcessId());
};