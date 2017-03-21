#pragma once
#include "MapElement.h"
class CRectangle :
	public CMapElement
{
public:
	CRectangle();
	~CRectangle();
	void draw(CDC *pDC);
	int GetType();
	void BresenhamLine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color);
};

