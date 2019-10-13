#include <Windows.h>
#include "player.h"

Player::Player(Game& game) : m_game(game)
{
	ResolveBaseAddress();
}

void Player::SetCrosshair(float horizontal, float vertical)
{
	WriteProcessMemory(m_game.handle, (LPVOID)(base_addr + horizontal_cross_offset), &horizontal, sizeof(horizontal), NULL);
	WriteProcessMemory(m_game.handle, (LPVOID)(base_addr + vertical_cross_offset), &vertical, sizeof(vertical), NULL);
}

void Player::ResolveBaseAddress()
{
	ReadProcessMemory(m_game.handle, (LPCVOID)(m_game.MODULE_ADDR + base_addr_offset), &base_addr, sizeof(base_addr), NULL);
}
