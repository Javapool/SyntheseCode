#include "ShapeBuilder.h"

void ShapeBuilder::readFiles()
{
	std::string folder{ "..\\OBJFILES" };
	std::string search_path{"..\\OBJFILES\\*.obj" };
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			std::cout << fd.cFileName<<"\n";
									  
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
