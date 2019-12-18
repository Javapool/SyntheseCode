#pragma once
#include "Space.h"
#include <chrono>
#include "View.h"

class Game
{
private :
	int MOUSE_POSX = 1000;
	int MOUSE_POSY = 600;
	float ANGLE_MULTIPLIER = 0.01;

	sf::Vector2i mousePos;

	CONST double MS_PER_UPDATE = 20;
	Space gameSpace;
	View v;
	std::list<std::pair<Vertex*, Vertex*>> lines;
public:
	Game();
	~Game();

	void run();
	void populateSpace();
	void update();
	void loop();
	void display();
	void setup();
	void getInput();
};

