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

	static unsigned int BASE_ADDR_OFFSET;
	static unsigned short HORIZONTAL_CROSS_OFFSET;
	static unsigned short VERTICAL_CROSS_OFFSET;
};
