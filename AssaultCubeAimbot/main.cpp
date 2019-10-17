#include <Windows.h>
#include "game.h"
#include "player.h"
#include "vector3.h"

int main()
{
	Game game;
	Player self(game);
	Vector3 target = self.GetPosition();
	while (true)
	{
		self.AimAt(target);
		Sleep(16);
	}
}
