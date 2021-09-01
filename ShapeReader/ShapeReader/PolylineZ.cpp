#include "pch.h"
#include <cmath>
#include "PolylineZ.h"



PolylineZ::PolylineZ(SHPHandle handle)
{
	double* minBound = new double[4];
	double* maxBound = new double[4];

	SHPGetInfo(handle, entities, shapeType, minBound, maxBound);

	this->minBound.X = minBound[0];
	this->minBound.Y = minBound[1];

	this->maxBound.X = maxBound[0];
	this->maxBound.Y = maxBound[1];

	shapeVertices.resize(*entities);


	for (int i = 0; i < *entities; i++)
	{
		SHPObject* Object = SHPReadObject(handle, i);
		int nVertices = Object->nVertices;
		shapeVertices[i].resize(nVertices);

		for (int j = 0;j < nVertices;j++)
		{
			shapeVertices[i][j].X = (Object->padfX[j] - this->minBound.X);
			shapeVertices[i][j].Y = (Object->padfY[j] - this->maxBound.Y);
		}

	}

	delete[] minBound;
	delete[] maxBound;

	SHPClose(handle);
}

PolylineZ::~PolylineZ()
{
	delete entities;
	delete shapeType;
}
