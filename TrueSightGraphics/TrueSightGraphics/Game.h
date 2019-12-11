#pragma once
#include "Space.h"
#include <chrono>
#include "View.h"

class Game
{
private :
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
};

