#pragma once
class ShapeDrawer
{
public:
	virtual void DrawShape(CDC* pDC, CPoint Offset, int zoom) = 0;
};

