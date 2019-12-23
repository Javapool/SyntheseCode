#include "Game.h"

const int SCREEN_WIDTH = 1680;
const int SCREEN_HEIGHT = 1050;
const float FOV = 90;
const float NEAR_PLANE = 1;
const float FAR_PLANE = 100;

Game::Game()
	:v(SCREEN_WIDTH,SCREEN_HEIGHT,1)
{

}


Game::~Game()
{
}



void Game::run()
{
	setup();
	populateSpace();
	loop();
}

void Game::populateSpace()
{

	gameSpace.createObject(0, 8, 0, -1,  -5, 0, 0);
	gameSpace.createObject(1, 8, 0, 0, -5, 0, 0.4);
	gameSpace.createObject(2, 8, 0, 0, -5, 0, 0);
	gameSpace.createObject(3, 8, -10, 0, -5, 0, 0);


}


void Game::update()
{
	mousePos = sf::Mouse::getPosition();
	float patente = static_cast<float>(MOUSE_POSX);

	gameSpace.turnPlayer((static_cast<float>(MOUSE_POSX) - static_cast<float>(mousePos.x))*ANGLE_MULTIPLIER);

	sf::Mouse::setPosition(sf::Vector2i(MOUSE_POSX, MOUSE_POSY));
	v.update();
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

		getInput();
		//gameSpace.move(1);
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
	std::list<std::pair<Vertex*, Vertex*>> tempListe(gameSpace.getLines());
	v.display(tempListe);
}

void Game::setup()
{
	gameSpace.setup(FOV, NEAR_PLANE, FAR_PLANE);
}

void Game::getInput()
{



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		gameSpace.movePlayer(Player::DIRECTION::FORWARD);
	}
	else {
		gameSpace.deceleratePlayer(Player::DIRECTION::FORWARD);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		gameSpace.movePlayer(Player::DIRECTION::LEFT);
	}
	else {
		gameSpace.deceleratePlayer(Player::DIRECTION::LEFT);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		gameSpace.movePlayer(Player::DIRECTION::BACK);
	}
	else {
		gameSpace.deceleratePlayer(Player::DIRECTION::BACK);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		gameSpace.movePlayer(Player::DIRECTION::RIGHT);
	}
	else {
		gameSpace.deceleratePlayer(Player::DIRECTION::RIGHT);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		gameSpace.movePlayer(Player::DIRECTION::UP);
	}
	else {
		gameSpace.deceleratePlayer(Player::DIRECTION::UP);
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
		gameSpace.movePlayer(Player::DIRECTION::DOWN);
	}
	else {
		gameSpace.deceleratePlayer(Player::DIRECTION::DOWN);
	}


}
