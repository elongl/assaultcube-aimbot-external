#include <Windows.h>
#include "game.h"
#include "player.h"
#include "vector3.h"

int main()
{
	Game game;
	Player player(game);
	Vector3 pos(121, 137, 0);
	while (true)
	{
		player.AimAt(pos);
		Sleep(16);
	}
}
