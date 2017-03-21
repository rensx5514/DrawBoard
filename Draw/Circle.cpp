#include "stdafx.h"
#include "Circle.h"


Circle::Circle()
{
}


Circle::~Circle()
{
}
void Circle::draw(CDC *pDC) {
	//采用中点画图法绘制圆形
	int x0 = GetStartPoint().x;
	int y0 = GetStartPoint().y;
	int R = Cr;
	//int R = CalCircleR(GetStartPoint(),GetEndPoint());
	COLORREF color = GetM_LineColor();
	int x, y, p;
	x = 0; y = R; p = 3 - (R << 1);
	for (; x <= y; x++) {
		pDC->SetPixel(x + x0, y + y0, color);
		pDC->SetPixel(-x + x0, y + y0, color);
		pDC->SetPixel(x + x0, -y + y0, color);
		pDC->SetPixel(-x + x0, -y + y0, color);
		pDC->SetPixel(y + x0, x + y0, color);
		pDC->SetPixel(-y + x0, x + y0, color);
		pDC->SetPixel(y + x0, -x + y0, color);
		pDC->SetPixel(-y + x0, -x + y0, color);
		if (p < 0) {
			p += ((x << 2) + 6);
		}
		else {
			p += (((x - y) << 2) + 10);
			y--;
		}
	}

}
int Circle::GetType() {
	//返回图元类型为圆
	return 1;
}

int Circle::CalCircleR(CPoint point1, CPoint point2)
{
	int temp1 = (point2.x - point1.x);
	int temp2 = (point2.y - point1.y);
	int temp = (int)sqrt(((temp1*temp1) + (temp2*temp2)));
	return temp;
}
