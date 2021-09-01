
#pragma once
#include <vector>
#include "shapefil.h"

struct vertex
{
	double X;
	double Y;
};

class PolylineZ
{
public:
	PolylineZ();
	PolylineZ(SHPHandle handle);
	~PolylineZ();
	int* entities = new int;
	int* shapeType = new int;
	vertex minBound;
	vertex maxBound;
	std::vector<std::vector<vertex>> shapeVertices;

};

