
#include <iostream> 
#include "Game.h"
#include <conio.h>



int main()
{
	Game g;
	g.run();
	//TMatrix translationX = MatrixCreator::translation(10, 0, 0);
	//TMatrix translationY = MatrixCreator::translation(0, 10, 0);
	//TMatrix translationZ = MatrixCreator::translation(0, 0, 10);
	//TMatrix rotation90deg = MatrixCreator::rotationY(90);
	//TMatrix rotation180 = MatrixCreator::rotationY(180);
	//std::cout << "\n";
	//rotation90deg.afficher();
	//std::cout << "\n";
	//std::cout << "\n";

	//rotation180.afficher();

	//std::cout << "\n";
	//std::cout << "\n";



	//TMatrix composite = translationX*rotation90deg*translationX*rotation90deg;

	//TMatrix composite2 = composite * rotation90deg*translationY*rotation180;

	//composite.afficher();

	//std::cout << "\n";
	//std::cout << "\n";


	//

	//Vertex v1(1,0,0,1);
	//Vertex v2(0,0,0,0);

	////v1 = v1 * rotation90deg;
	//v1.afficher();

	//v2 = v1 * composite;
	//v2.afficher();

	//v1 = v1 * composite2;
	//v1.afficher();


	//_getch();
	return 0;
}