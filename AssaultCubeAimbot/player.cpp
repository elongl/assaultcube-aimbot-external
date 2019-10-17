#include <Windows.h>
#include <math.h>
#include "player.h"

Player::Player(Game& game) : m_game(game)
{
	void* self = (void*)0x509B74;
	ReadProcessMemory(m_game.handle, self, &baseaddr, sizeof(baseaddr), NULL);
}

Player::Player(Game& game, void* baseaddr) : m_game(game)
{
	ReadProcessMemory(m_game.handle, baseaddr, &this->baseaddr, sizeof(baseaddr), NULL);
}

Vector3 Player::GetPosition()
{
	float x_coord, y_coord, z_coord;
	unsigned int x_offset = 0x34, y_offset = 0x38, z_offset = 0x3C;
	ReadMember(x_offset, &x_coord);
	ReadMember(y_offset, &y_coord);
	ReadMember(z_offset, &z_coord);
	return Vector3(x_coord, y_coord, z_coord);
}

void Player::AimAt(Vector3& target)
{
	unsigned int yaw_offset = 0x40, pitch_offset = 0x44;
	Vector3 my_pos = GetPosition();
	float yaw_angle = my_pos.GetYawAngle(target);
	float pitch_angle = my_pos.GetPitchAngle(target);
	WriteMember(yaw_offset, &yaw_angle);
	WriteMember(pitch_offset, &pitch_angle);
}

Player Player::GetClosestEnemy()
{
	return Player(m_game);
}

void Player::ReadMember(unsigned int offset, void* buffer)
{
	ReadProcessMemory(m_game.handle, (void*)(baseaddr + offset), buffer, sizeof(buffer), NULL);
}

void Player::WriteMember(unsigned int offset, void* buffer)
{
	WriteProcessMemory(m_game.handle, (void*)(baseaddr + offset), buffer, sizeof(buffer), NULL);
}
