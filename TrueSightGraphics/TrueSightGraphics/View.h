#pragma once
#include <cstdint>
class View
{
	uint16_t screenWidth;
	uint16_t screenheight;
	uint8_t ratioToZ;
public:
	View(uint16_t screenWidth, uint16_t screenheight,uint8_t ratioToZ);
	~View();
};

