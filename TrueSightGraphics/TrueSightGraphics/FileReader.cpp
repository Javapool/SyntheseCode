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

	resizeVectorsNormalize(path, BP);
	fillVectors(path, BP);

	return BP;
}

void FileReader::stringVertexToValues(std::string line, float * values)
{
	std::stringstream ss(line);
	std::string token;

	ss >> token;
	ss >> values[0];
	ss >> values[1];
	ss >> values[2];
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

	BP.addVertex((x-mOffsetX)*mResizeFactor, (y-mOffsetY)*mResizeFactor, (z-mOffsetZ)*mResizeFactor, 1);
	//std::cout << x<<" - "<< y<< " - " << z<< std::endl;
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

	BP.addPlane(vertexindexA-1, vertexindexB-1, vertexindexC-1);

	//check if lines are a<b to add them only once
	if (vertexindexA < vertexindexB) {
		BP.addLine(vertexindexA-1, vertexindexB-1);
	}
	if (vertexindexB < vertexindexC) {
		BP.addLine(vertexindexB - 1, vertexindexC - 1);
	}
	if (vertexindexC < vertexindexA) {
		BP.addLine(vertexindexC - 1, vertexindexA - 1);
	}
}

void FileReader::resizeVectorsNormalize(const std::string path, ShapeBlueprint & BP)
{
	std::string currLine;
	uint16_t verticesVectorSize{ 0 };
	uint16_t planesVectorSize{ 0 };
	float maxX;
	float minX;	
	float maxY;
	float minY;
	float maxZ;
	float minZ;
	bool firstLine{ true };
	float values[3];
	std::ifstream file(path);

	while (std::getline(file, currLine)) {
		// using printf() in all tests for consistency
		if (currLine != "")
		{

			switch (currLine.at(0))
			{
			case 'v':
				if (currLine.at(1) == ' ') {
					++verticesVectorSize;
					stringVertexToValues(currLine, values);
					if (firstLine) {
						minX = maxX = values[0];
						minY = maxY = values[1];
						minZ = maxZ = values[2];

						firstLine = false;
					}
					else {
						if (values[0] < minX)
						{
							minX = values[0];
						}
						else if (values[0] > maxX) {
							maxX = values[0];
						}
						if (values[1] < minY)
						{
							minY = values[1];
						}
						else if (values[1] > maxY) {
							maxY = values[1];
						}
						if (values[2] < minZ)
						{
							minZ = values[2];
						}
						else if (values[2] > maxZ) {
							maxZ = values[2];
						}
					}
				}
				break;
			case 'f':
				++planesVectorSize;
				break;
			default:
				break;
			}
		}

	}
	if (!firstLine)
	{
	mOffsetX = (maxX + minX)/2;
	mOffsetY = (maxY + minY) / 2;
	mOffsetZ = (maxZ + minZ) / 2;

	float biggestDifference;

	if ((maxX-minX)>=(maxY-minY))
	{
		if ((maxX - minX) >= (maxZ - minZ)) {
			biggestDifference = (maxX - minX);
		}
		else {
			biggestDifference = (maxZ - minZ);
		}
	}
	else {
		if ((maxY-minY)>=(maxZ-minZ)) {
			biggestDifference = (maxY - minY);
		}
		else {
			biggestDifference = maxZ - minZ;
		}

	}
	mResizeFactor = 2 / biggestDifference;
	}
	file.close();
}

void FileReader::fillVectors(const std::string path, ShapeBlueprint & BP)
{
	std::ifstream file(path);
	std::string currLine;

	while (std::getline(file, currLine)) {
		// using printf() in all tests for consistency
		if (currLine != "")
		{

			switch (currLine.at(0))
			{
			case 'v':
				if (currLine.at(1) == ' ') {
					stringToVertex(currLine, BP);
				}
				break;
			case 'f':
				stringToPlane(currLine, BP);
				break;
			default:
				break;
			}
		}

	}
	file.close();
}
