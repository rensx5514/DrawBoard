#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle()
{
}


CRectangle::~CRectangle()
{
}
void CRectangle::draw(CDC *pDC) {
	//����Rectangle
	//pDC->MoveTo(GetStartPoint());
	BresenhamLine(pDC, GetStartPoint().x, GetStartPoint().y, GetEndPoint().x,GetStartPoint().y,GetM_LineColor());
	BresenhamLine(pDC, GetEndPoint().x, GetStartPoint().y, GetEndPoint().x, GetEndPoint().y, GetM_LineColor());
	BresenhamLine(pDC, GetEndPoint().x, GetEndPoint().y, GetStartPoint().x, GetEndPoint().y, GetM_LineColor());
	BresenhamLine(pDC, GetStartPoint().x, GetEndPoint().y, GetStartPoint().x, GetStartPoint().y, GetM_LineColor());
	
}
int CRectangle::GetType() {
	//����ͼԪ����ΪRectangle
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
	//б���жϣ�б�ʾ���ֵ����1��mΪfalse ����Ϊtrue
	BOOL m = (fabs(y2 - y1) <= fabs(x2 - x1));
	//���x1����x2��������ֵ
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
	//б�ʾ���ֵС�ڵ���1
	if (m) {
		//��һ����� y����
		if (y1 <= y2) {
			p = (dy << 1) - dx;
			while (x <= x2) {
				pDC->SetPixel(x, y, color);
			}
		}
	}*/
}