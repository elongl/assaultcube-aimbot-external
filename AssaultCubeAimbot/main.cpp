#include <Windows.h>
#include <iostream>
#include <memory>
#include "game.h"
#include "player.h"
#include "vector3.h"

int main()
{
	Game game;
	Player self(game);
	if (game.player_count)
	{
		while (true)
		{
			std::unique_ptr<Player> closest_enemy = self.GetClosestEnemy();
			self.AimAt(closest_enemy->GetPosition());
			Sleep(16);
		}
	}
	else
	{
		std::cout << "No players in the server.";
	}
}
