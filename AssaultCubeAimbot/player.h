#pragma once
#include "game.h"
#include "vector3.h"

class Player
{
public:
	Player(Game&);
	Player(Game&, void* baseaddr);
	void AimAt(Vector3&);
	Vector3 GetPosition();
	Player GetClosestEnemy();

private:
	Game& m_game;
	unsigned int baseaddr;
	void ReadMember(unsigned int offset, void* buffer);
	void WriteMember(unsigned int offset, void* buffer);
};
