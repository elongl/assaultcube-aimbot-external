#pragma once
#include "game.h"

class Player
{
public:
	Player(Game&);
	void SetCrosshair(float horizontal, float vertical);
private:
	Game& m_game;
	void ResolveBaseAddress();
	unsigned int base_addr;

	static unsigned int base_addr_offset;
	static unsigned short horizontal_cross_offset;
	static unsigned short vertical_cross_offset;
};
