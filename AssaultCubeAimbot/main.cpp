#include "game.h"
#include "player.h"

int main()
{
	Game game;
	Player player{ game };
	player.SetCrosshair(0, 0);
}
