#pragma once

class Game
{
public:
	Game();
	~Game();

	void initializeSpace();
	void populateSpace();
	void tick();
	void display();
};

