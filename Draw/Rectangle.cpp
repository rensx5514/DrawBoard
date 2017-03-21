#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle()
{
}


CRectangle::~CRectangle()
{
}
void CRectangle::draw(CDC *pDC) {
	//绘制Rectangle
	//pDC->MoveTo(GetStartPoint());
	BresenhamLine(pDC, GetStartPoint().x, GetStartPoint().y, GetEndPoint().x,GetStartPoint().y,GetM_LineColor());
	BresenhamLine(pDC, GetEndPoint().x, GetStartPoint().y, GetEndPoint().x, GetEndPoint().y, GetM_LineColor());
	BresenhamLine(pDC, GetEndPoint().x, GetEndPoint().y, GetStartPoint().x, GetEndPoint().y, GetM_LineColor());
	BresenhamLine(pDC, GetStartPoint().x, GetEndPoint().y, GetStartPoint().x, GetStartPoint().y, GetM_LineColor());
	
}
int CRectangle::GetType() {
	//返回图元类型为Rectangle
	return 2;
}
void CRectangle::BresenhamLine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color) {
	int x, y, dx, dy, p;
	if (x1 == x2) {
		if (y1 < y2) {
			for (int i = y1; i <= y2; i++) {
				pDC->SetPixel(x1, i, color);
			}
		}else{
			for (int i = y2; i <= y1; i++) {
				pDC->SetPixel(x1, i, color);
			}
		}
		return;
	}
	if (y1 = y2) {
		if (x1 < x2) {
			for (int i = x1; i <= x2; i++) {
				pDC->SetPixel(i, y1, color);
			}
		}
		else {
			for (int i = x2; i <= x1; i++) {
				pDC->SetPixel(i, y1, color);
			}
		}
		return;
	}
	return;
	/*
	//斜率判断，斜率绝对值大于1则m为false 否则为true
	BOOL m = (fabs(y2 - y1) <= fabs(x2 - x1));
	//如果x1大于x2交换坐标值
	if (x1 > x2) {
		p = x1;
		x1 = x2;
		x2 = p;
		p = y1;
		y1 = y2;
		y2 = p;
	}
	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	//斜率绝对值小于等于1
	if (m) {
		//第一种情况 y递增
		if (y1 <= y2) {
			p = (dy << 1) - dx;
			while (x <= x2) {
				pDC->SetPixel(x, y, color);
			}
		}
	}*/
}