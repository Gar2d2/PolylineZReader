#pragma once
#include "ShapeDrawer.h"
class PolylineZ;
class CShapeReaderDoc;


class PolylineZDrawer :  public ShapeDrawer
{
	
public:
	PolylineZDrawer(PolylineZ*, CShapeReaderDoc*);
	~PolylineZDrawer() { delete shapeToDraw; }

	virtual void DrawShape(CDC* pDC, CPoint offset, int zoom) override;
private:
	CDC* pDC = nullptr;
	CShapeReaderDoc* doc;
	PolylineZ* shapeToDraw;
};

