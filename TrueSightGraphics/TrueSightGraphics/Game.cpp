#include "Game.h"



Game::Game()
	:v(1200,800,1)
{

}


Game::~Game()
{
}



void Game::run()
{
	populateSpace();
	loop();
}

void Game::populateSpace()
{
	gameSpace.createObject(0, 1, 0, 0, -3, 0);
}

void Game::update()
{
	gameSpace.update();
}

void Game::loop()
{
	double previous = GetTickCount();
	double lag = 0.0;
	while (true)
	{
		double current = GetTickCount();
		double elapsed = current - previous;
		previous = current;
		lag += elapsed;

		//processInput();

		while (lag >= MS_PER_UPDATE)
		{
			update();
			lag -= MS_PER_UPDATE;
		}

		display();
	}
}



void Game::display()
{
	v.display(gameSpace.getLines());
}
