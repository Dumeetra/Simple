/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>

#include "streets.h"

#include "game.h"
#include <iostream>


int main(int argc, char* args[])
{
	int crtnr = 0;
	int level = 0;
	std::cout << "Enter level (1 - 10): ";
	std::cin >> level; //level and present size of arrays
	const int max = 10; //maximum size of arrays

	
	cStreet streets;

	cGames game;
	

	//Start up SDL and create window
	if (!game.init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		std::string name;
		streets.setname(name);
		streets.setRenderer(game.getrend());
		streets.loadTexture(streets.getname());
		bool quit = false;
		while (!quit) {

			SDL_Rect topLeftViewport;
			topLeftViewport.x = 0;
			topLeftViewport.y = 0;
			topLeftViewport.w = game.gamewidth();
			topLeftViewport.h = game.gameheight();

			SDL_RenderSetViewport(game.getrend(), &topLeftViewport);
			SDL_RenderCopy(game.getrend(), streets.getTexture(), NULL, NULL);
			
			//Update screen
			SDL_RenderPresent(game.getrend());
		}
	}

	//Free resources and close SDL

	streets.close();
	game.~cGames();

	return 0;
}
