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
			self.SetHealth(1337);
			self.SetAmmo(6969);

			std::unique_ptr<Player> closest_enemy = self.GetClosestEnemy();
			if (closest_enemy)
			{
				self.AimAt(closest_enemy->GetPosition());
				self.Shoot();
			}
			Sleep(16);
		}
	}
	else
	{
		std::cout << "No players in the server.";
	}
}
