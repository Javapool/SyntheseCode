#include "View.h"


View::View(uint16_t screenWidth, uint16_t screenheight, uint8_t ratioToZ)
	:window(sf::VideoMode(screenWidth, screenheight), "TrueSight GFX")
{

	//HWND hWnd = GetConsoleWindow();
	//ShowWindow(hWnd, SW_HIDE);



}

View::~View()
{
}

void View::update()
{
}

void View::display(std::list<std::pair<Vertex*, Vertex*>> lines)
{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		for(std::pair<Vertex*, Vertex*> laLigne : lines)
		{
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(*(laLigne.first->getCoords()), *(laLigne.first->getCoords()))),
				sf::Vertex(sf::Vector2f(*(laLigne.second->getCoords()+1), *(laLigne.second->getCoords()+1)))
			};

			window.draw(line, 2, sf::Lines);
		}
		window.display();
	
}
