#include "Game.h"

int main()
{
	srand(time(0));

	//Init game engine
	Game game;

	while (game.running())
	{
		//Update
		game.update();
		

		//Render
		game.render();

	}

	return 0;
}