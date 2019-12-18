#pragma once
#undef min
#undef max
#include <SFML\Graphics.hpp>
#include "Vertex.h"
#include <list>
class View
{
	sf::Mouse mMouse;
	sf::Keyboard mKeyboard;
	sf::RenderWindow window;
	uint16_t mScreenWidth;
	uint16_t mScreenHeight;
	uint8_t ratioToZ;
public:
	View(uint16_t screenWidth, uint16_t screenHeight,uint8_t ratioToZ);
	~View();
	void update();
	void display(std::list<std::pair<Vertex*, Vertex*>> lines);
};

