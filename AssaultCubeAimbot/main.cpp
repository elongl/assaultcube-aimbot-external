#include <Windows.h>
#include "game.h"
#include "player.h"
#include "vector3.h"

int main()
{
	Game game;
	Player self(game);
	Vector3 target(121, 137, 9);
	while (true)
	{
		self.AimAt(target);
		Sleep(16);
	}
}
