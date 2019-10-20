#include <Windows.h>
#include <vector>
#include <memory>
#include <math.h>
#include "player.h"

Player::Player(Game& game) : m_game(game)
{
	void* self = (void*)0x509B74;
	ReadProcessMemory(m_game.handle, self, &baseaddr, sizeof(baseaddr), NULL);
}

Player::Player(Game& game, std::uint32_t baseaddr) : m_game(game), baseaddr(baseaddr) {}

void Player::SetHealth(std::uint32_t hp) { WriteMember(0xF8, &hp, sizeof(hp)); }

std::uint32_t Player::GetHealth()
{
	std::uint32_t hp;
	ReadMember(0xF8, &hp, sizeof(hp));
	return hp;
}

Vector3 Player::GetPosition()
{
	coords_t coords;
	unsigned int coords_offset = 0x34;
	ReadMember(coords_offset, &coords, sizeof(coords));
	return Vector3(coords);
}

void Player::SetAmmo(std::uint32_t ammo) { WriteMember(0x150, &ammo, sizeof(ammo)); }

std::uint32_t Player::GetTeamId()
{
	std::uint32_t team_id;
	ReadMember(0x32C, &team_id, sizeof(team_id));
	return team_id;
}

void Player::AimAt(Vector3 target)
{
	unsigned int camera_offset = 0x40;
	Vector3 my_pos = GetPosition();
	camera_t camera{ my_pos.GetYawAngle(target), my_pos.GetPitchAngle(target) };
	WriteMember(camera_offset, &camera, sizeof(camera));
}

std::unique_ptr<Player> Player::GetClosestEnemy()
{
	std::uint32_t playeraddr;
	std::unique_ptr<Player> closest_player;
	Vector3 my_pos = GetPosition();

	for (unsigned int i = 1; i <= m_game.player_count; i++)
	{
		ReadProcessMemory(m_game.handle, (void*)(m_game.entity_list + (4 * i)), &playeraddr, sizeof(playeraddr), NULL);
		auto player = std::make_unique<Player>(m_game, playeraddr);
		if (player->GetHealth() > 100) continue;
		if (player->GetTeamId() == GetTeamId()) continue;
		if (!closest_player) closest_player = std::move(player);
		else if (my_pos.DistanceFrom(player->GetPosition()) < my_pos.DistanceFrom(closest_player->GetPosition()))
			closest_player = std::move(player);
	}
	return closest_player;
}

bool Player::IsShooting()
{
	bool is_shooting;
	ReadMember(0x224, &is_shooting, sizeof(is_shooting));
	return is_shooting;
}

void Player::ReadMember(unsigned int offset, void* buffer, unsigned int size)
{
	ReadProcessMemory(m_game.handle, (void*)(baseaddr + offset), buffer, size, NULL);
}

void Player::WriteMember(unsigned int offset, void* buffer, unsigned int size)
{
	WriteProcessMemory(m_game.handle, (void*)(baseaddr + offset), buffer, size, NULL);
}
