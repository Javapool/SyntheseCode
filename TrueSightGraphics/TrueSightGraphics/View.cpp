#include "View.h"


View::View(uint16_t screenWidth, uint16_t screenHeight, uint8_t ratioToZ)
	:mScreenWidth{ screenWidth }, mScreenHeight{ screenHeight }, window(sf::VideoMode(screenWidth, screenHeight), "TrueSight GFX")
{
	//HWND hWnd = GetConsoleWindow();
	//ShowWindow(hWnd, SW_HIDE);
	window.setMouseCursorVisible(false);



}

View::~View()
{
}

void View::update()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void View::display(std::list<std::pair<Vertex*, Vertex*>> lines)
{




		window.clear();
		std::vector<sf::Vertex> vertices;

		for(std::pair<Vertex*, Vertex*> laLigne : lines)
		{

			vertices.push_back(sf::Vertex(sf::Vector2f((laLigne.first->getCoords())[0]*(mScreenHeight / 2) + (mScreenWidth / 2), (-(laLigne.first->getCoords()[1]))*(mScreenHeight / 2) + (mScreenHeight / 2))));
			vertices.push_back(sf::Vertex(sf::Vector2f(((laLigne.second->getCoords()[0]))*(mScreenHeight / 2) + (mScreenWidth / 2), (-(laLigne.second->getCoords()[1]))*(mScreenHeight / 2) + (mScreenHeight / 2))));

		}
		if (vertices.size() > 0) {
		window.draw(&vertices[0], vertices.size(), sf::Lines);

		}

		window.display();
	
}
