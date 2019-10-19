#pragma once
#include "game.h"
#include "vector3.h"

class Player
{
public:
	Player(Game&);
	Player(Game&, unsigned int baseaddr);
	void SetHealth(unsigned int);
	unsigned int GetHealth();
	void AimAt(Vector3);
	Vector3 GetPosition();
	void SetAmmo(unsigned int);
	unsigned int GetTeamId();
	std::unique_ptr<Player> GetClosestEnemy();
	void Shoot();
	void StopShooting();

private:
	Game& m_game;
	unsigned int baseaddr;
	void ReadMember(unsigned int offset, void* buffer);
	void ReadMember(unsigned int offset, void* buffer, unsigned int size);
	void WriteMember(unsigned int offset, void* buffer);
	void WriteMember(unsigned int offset, void* buffer, unsigned int size);
};
