#pragma once
#include "game.h"
#include "vector3.h"

class Player
{
public:
	Player(Game&);
	Player(Game&, std::uint32_t baseaddr);
	void SetHealth(std::uint32_t);
	std::uint32_t GetHealth();
	void AimAt(Vector3);
	Vector3 GetPosition();
	void SetAmmo(std::uint32_t);
	std::uint32_t GetTeamId();
	std::unique_ptr<Player> GetClosestEnemy();
	bool IsShooting();

private:
	Game& m_game;
	std::uint32_t baseaddr;
	void ReadMember(unsigned int offset, void* buffer, unsigned int size);
	void WriteMember(unsigned int offset, void* buffer, unsigned int size);
};
