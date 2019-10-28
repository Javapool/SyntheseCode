#include "FileReader.h"



FileReader::FileReader()
{
}


FileReader::~FileReader()
{
}

ShapeBlueprint FileReader::readFile(const std::string path)
{
	ShapeBlueprint BP;
	std::ifstream file(path);
	std::string currLine;
	


	if (!file.is_open())
	{
		std::cout << errorBadFile;
		_getch();
		exit(1);
	}

	if (path.substr(path.size() - 4, 4) != ".obj")
	{
		std::cout << errorBadFileType;
		_getch();
		exit(2);
	}

	while (std::getline(file, currLine)) {
		// using printf() in all tests for consistency
		if (currLine != "")
		{
	
			switch (currLine.at(0))
			{
			case 'v':
				stringToVertex(currLine, BP);
				break;
			case 'f':
				stringToPlane(currLine, BP);
				break;
			default:
				break;
			}
		}

		}
	_getch();
	file.close();


	
	return BP;
}

void FileReader::stringToVertex(std::string line, ShapeBlueprint &BP)
{
	std::stringstream ss(line);
	std::string token;
	float x, y, z;


	ss >> token;
	ss >> x;
	ss >> y;
	ss >> z;

	BP.addVertex(x, y, z, 1);
	std::cout << x<<" - "<< y<< " - " << z<< std::endl;
}

void FileReader::stringToPlane(std::string line, ShapeBlueprint &BP)
{
	std::stringstream ss(line);
	std::stringstream subss;
	std::string token;
	int vertexindexA;
	int vertexindexB;
	int vertexindexC;

	ss >> token;
	ss >> token;
	std::stringstream subssA(token,'/');
	ss >> token;
	std::stringstream subssB(token, '/');
	ss >> token;
	std::stringstream subssC(token, '/');
	subssA >> vertexindexA;
	subssB >> vertexindexB;
	subssC >> vertexindexC;

	BP.addPlane(vertexindexA, vertexindexB, vertexindexC);

	//check if lines are a<b to add them only once
	if (vertexindexA < vertexindexB) {
		BP.addLine(vertexindexA, vertexindexB);
	}
	if (vertexindexB < vertexindexC) {
		BP.addLine(vertexindexB, vertexindexC);
	}
	if (vertexindexC < vertexindexA) {
		BP.addLine(vertexindexC, vertexindexA);
	}
	std::cout << vertexindexA << " - " << vertexindexB << " - " << vertexindexC << std::endl;
}
