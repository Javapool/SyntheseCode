#include "ShapeBuilder.h"

void ShapeBuilder::generateGrid(float lines)
{
	ShapeBlueprint bp;
	for (float i{0}; i < lines; ++i) {
		bp.addVertex(-1, 0, 1-((i*(1 / lines))*2), 1);
		bp.addVertex(1, 0, 1 - ((i*(1 / lines)) * 2), 1);
	}
	for (float i{0}; i < lines; ++i) {
		bp.addVertex(1 - ((i*(1 / lines)) * 2), 0, -1 , 1);
		bp.addVertex(1 - ((i*(1 / lines)) * 2), 0, 1, 1);
	}
	for (float i{ 0 }; i < lines*2; ++i) {
		bp.addLine((2*i),(2*i)+1);
	}

	mBlueprints.push_back(bp);
}

void ShapeBuilder::readFiles()
{
	std::string folder{ "..\\OBJFILES" };
	std::string search_path{"..\\OBJFILES\\*.obj" };
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			//std::cout << fd.cFileName<<"\n";
									  
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				mBlueprints.push_back(reader.readFile(folder+"\\"+fd.cFileName));
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
	
}


void ShapeBuilder::showFiles()
{
	int c{ 1 };
	for (ShapeBlueprint sb : mBlueprints) {
		std::cout << "Forme # "<< c;
		_getch();
		sb.afficher();
	}
}

ShapeBlueprint ShapeBuilder::getShape(int index)
{
	return mBlueprints[index];
}
