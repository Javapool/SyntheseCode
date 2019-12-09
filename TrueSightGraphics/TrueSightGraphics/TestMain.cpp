#include "SFML\Graphics.hpp"
#include "ShapeBuilder.h"
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <iostream> 
#include "TMatrix.h"
#include "CoordsMatrix.h"
#include <conio.h>

int main()
{

	//sf::RenderWindow window(sf::VideoMode(600, 400), "TrueSight GFX");
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);
	//sf::Vertex line[] =
	//{
	//	sf::Vertex(sf::Vector2f(10, 10)),
	//	sf::Vertex(sf::Vector2f(150, 150))
	//};
	//HWND hWnd = GetConsoleWindow();
	////ShowWindow(hWnd, SW_HIDE);

	//while (window.isOpen())
	//{
	//	sf::Event event;
	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::Closed)
	//			window.close();
	//	}

	//	window.clear();
	//	//window.draw(shape);
	//	window.draw(line, 2, sf::Lines);
	//	window.display();
	//}
	ShapeBuilder sb;
	sb.readFiles();
	sb.showFiles();
	


	_getch();



	return 0;
}