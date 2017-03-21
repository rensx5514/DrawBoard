#include "stdafx.h"
#include "Line.h"


CLine::CLine()
{
}


CLine::~CLine()
{
}
void CLine::draw(CDC *pDC) {
	//绘制直线段
	int x1 = GetStartPoint().x;
	int y1 = GetStartPoint().y;
	int x2 = GetEndPoint().x;
	int y2 = GetEndPoint().y;
	COLORREF color = GetM_LineColor();
	int x, y, dx, dy, p;
	if (x1 == x2) {
		if (y1 < y2) {
			for (int i = y1; i <= y2; i++) {
				pDC->SetPixel(x1, i, color);
			}
		}
		else {
			for (int i = y2; i <= y1; i++) {
				pDC->SetPixel(x1, i, color);
			}
		}
		return;
	}
	if (y1 == y2) {
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
					if (p < 0) {
						x++;
						p = p + (dy << 1);
					}
					else {
						x++;
						y++;
						p = p + ((dy - dx) << 1);
					}
				}
			}
			//第三种情况 y递减
			else {
				p = dx - (dy << 1);
				while (x <= x2) {
					pDC->SetPixel(x, y, color);
					if (p < 0) { x++; p = p - (dy << 1); }
					else { x++; y--; p = p - ((dy + dx) << 1); }
				}
			}
	}
	//斜率绝对值大于1
	else
	{
		//第二种情况,y递增
		if (y1 <= y2) {
			p = (dx << 1) - dy;
			while (y <= y2) {
				pDC->SetPixel(x, y, color);
				if (p < 0) { y++; p = p + (dx << 1); }
				else { x++; y++; p = p + ((dx - dy) << 1); }
			}
		}
		//第四种情况 y递减
		else {
			p = (dx<<1)+dy;
			while (y >= y2) {
				pDC->SetPixel(x, y, color);
				if (p < 0) { y--; p = p + (dx << 1); }
				else { x++; y--; p = p + ((dx + dy) << 1); }
			}
		}


	}

}
int CLine::GetType() {
	//返回图元类型为直线段
	return 0;
}