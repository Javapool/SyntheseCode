#pragma once
#include <vector>
#include "Vertex.h"
#include "ShapeBlueprint.h"
#include <string>
#include <fstream>
#include <iostream>
#include <conio.h>
#include <sstream>

class FileReader
{
	const std::string errorBadFile="Probleme de lecture du fichier";
	const std::string errorBadFileType="Mauvaise extension de fichier";
	std::string currentFile;

public:
	FileReader();
	~FileReader();
	ShapeBlueprint readFile(const std::string path);

private:
	void stringToVertex(std::string line, ShapeBlueprint &BP);
	void stringToPlane(std::string line, ShapeBlueprint &BP);

};

