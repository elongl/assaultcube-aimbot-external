#include <Windows.h>
#include "player.h"


unsigned int Player::BASE_ADDR_OFFSET = 0x109B74;
unsigned short Player::HORIZONTAL_CROSS_OFFSET = 0x40;
unsigned short Player::VERTICAL_CROSS_OFFSET = 0x44;

Player::Player(Game& game) : m_game(game)
{
	ResolveBaseAddress();
}

void Player::SetCrosshair(float horizontal, float vertical)
{
	WriteProcessMemory(m_game.handle, (LPVOID)(base_addr + HORIZONTAL_CROSS_OFFSET), &horizontal, sizeof(horizontal), NULL);
	WriteProcessMemory(m_game.handle, (LPVOID)(base_addr + VERTICAL_CROSS_OFFSET), &vertical, sizeof(vertical), NULL);
}

void Player::ResolveBaseAddress()
{
	ReadProcessMemory(m_game.handle, (LPCVOID)(m_game.MODULE_ADDR + BASE_ADDR_OFFSET), &base_addr, sizeof(base_addr), NULL);
}
