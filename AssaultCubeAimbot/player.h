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

	unsigned int base_addr_offset = 0x109B74;
	unsigned short horizontal_cross_offset = 0x40;
	unsigned short vertical_cross_offset = 0x44;
};
