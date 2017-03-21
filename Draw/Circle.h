#pragma once
#include "MapElement.h"
class Circle :
	public CMapElement
{
private:
	int Cr;//Բ�뾶
public:
	void SetCr(int r) {
		Cr = r;
	}
	int GetCr() {
		return Cr;
	}
	Circle();
	~Circle();
	void draw(CDC *pDC);
	int GetType();
	int CalCircleR(CPoint point1, CPoint point2);
};

