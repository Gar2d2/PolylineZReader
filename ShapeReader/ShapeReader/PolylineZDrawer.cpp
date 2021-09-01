#include "pch.h"
#include <cmath>
#include "PolylineZ.h"
#include "PolylineZDrawer.h"
#include "ShapeReaderDoc.h"


PolylineZDrawer::PolylineZDrawer(PolylineZ* shapeToDraw, CShapeReaderDoc* doc)
{
	this->doc = doc;
	this->shapeToDraw = shapeToDraw;
	pDC = nullptr;
}

void PolylineZDrawer::DrawShape(CDC* pDC, CPoint offset, int zoom)
{
	if (!pDC) { return; }

	for (auto vertex : shapeToDraw->shapeVertices)
	{
		pDC->MoveTo(round(vertex[0].X * zoom + offset.x), round(vertex[0].Y * -zoom + offset.y));
		int count = vertex.size();
		if (count > 1)
		{
			for (int i = 1; i < count; i++)
			{
				pDC->LineTo(round(vertex[i].X * zoom + offset.x), round(vertex[i].Y * -zoom + offset.y));
			}
		}
	}
}
