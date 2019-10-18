#include <Windows.h>
#include <memory>
#include <math.h>
#include "player.h"

Player::Player(Game& game) : m_game(game)
{
	void* self = (void*)0x509B74;
	ReadProcessMemory(m_game.handle, self, &baseaddr, sizeof(baseaddr), NULL);
}

Player::Player(Game& game, unsigned int baseaddr) : m_game(game), baseaddr(baseaddr) {}

Vector3 Player::GetPosition()
{
	float x_coord, y_coord, z_coord;
	unsigned int x_offset = 0x34, y_offset = 0x38, z_offset = 0x3C;
	// Consider reading them all at once.
	ReadMember(x_offset, &x_coord);
	ReadMember(y_offset, &y_coord);
	ReadMember(z_offset, &z_coord);
	return Vector3(x_coord, y_coord, z_coord);
}

unsigned int Player::GetTeamId()
{
	unsigned int team_id;
	ReadMember(0x32C, &team_id);
	return team_id;
}

void Player::AimAt(Vector3 target)
{
	unsigned int yaw_offset = 0x40, pitch_offset = 0x44;
	Vector3 my_pos = GetPosition();
	float yaw_angle = my_pos.GetYawAngle(target);
	float pitch_angle = my_pos.GetPitchAngle(target);
	// Consider writing them all at once.
	WriteMember(yaw_offset, &yaw_angle);
	WriteMember(pitch_offset, &pitch_angle);
}

std::unique_ptr<Player> Player::GetClosestEnemy()
{
	unsigned int player_addr;
	std::unique_ptr<Player> closest_player;
	Vector3 my_pos = GetPosition();

	for (int i = 1; i <= m_game.player_count; i++)
	{
		ReadProcessMemory(m_game.handle, (void*)(m_game.entity_list + (4 * i)), &player_addr, sizeof(player_addr), NULL);
		std::unique_ptr<Player> player(new Player(m_game, player_addr));
		if (player->GetTeamId() == GetTeamId())
			continue;
		if (!closest_player)
			closest_player = std::move(player);
		else if (my_pos.DistanceFrom(player->GetPosition()) < my_pos.DistanceFrom(closest_player->GetPosition()))
			closest_player = std::move(player);
	}
	return closest_player;
}

void Player::ReadMember(unsigned int offset, void* buffer)
{
	ReadProcessMemory(m_game.handle, (void*)(baseaddr + offset), buffer, sizeof(buffer), NULL);
}

void Player::WriteMember(unsigned int offset, void* buffer)
{
	WriteProcessMemory(m_game.handle, (void*)(baseaddr + offset), buffer, sizeof(buffer), NULL);
}
