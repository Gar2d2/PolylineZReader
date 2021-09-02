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
	CRect client;
	
	
	CPen drawPen(PS_SOLID, 0.4*zoom/2, RGB(0, 0, 255)); //TODO create dialog box for parametrizing thickness and color 
	CPen elipsePen(PS_SOLID, 0.5*zoom, RGB(255, 165, 0));
	
	pDC->SelectObject(&drawPen);

	for (auto vertex : shapeToDraw->shapeVertices)
	{
		pDC->MoveTo(round(vertex[0].X * zoom + offset.x), round(vertex[0].Y * -zoom + offset.y));
	
		int count = vertex.size();
		if (count > 1)
		{
			for (int i = 1; i < count; i++)
			{

				pDC->SelectObject(&drawPen);
				pDC->LineTo(round(vertex[i].X * zoom + offset.x), round(vertex[i].Y * -zoom + offset.y));

				
				pDC->SelectObject(&elipsePen);
				pDC->Ellipse(
					round(vertex[i-1].X * zoom + offset.x + zoom/8),
					round(vertex[i-1].Y * -zoom + offset.y + zoom/8), 
					round(vertex[i-1].X * zoom + offset.x - zoom/8), 
					round(vertex[i-1].Y * -zoom + offset.y - zoom/8));
			
			}

			pDC->SelectObject(&elipsePen);
			
			pDC->Ellipse(
				round(vertex[count - 1].X * zoom + offset.x + zoom / 8),
				round(vertex[count - 1].Y * -zoom + offset.y + zoom / 8),
				round(vertex[count - 1].X * zoom + offset.x - zoom / 8),
				round(vertex[count - 1].Y * -zoom + offset.y - zoom / 8));
		}
	}
}
