#pragma once
#include <Windows.h>

class Game
{
private:
	unsigned int GetProcessId();

public:
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetProcessId());
	unsigned int MODULE_ADDR = 0x400000;
};