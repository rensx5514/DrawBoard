#include "stdafx.h"
#include "FillRect.h"


CFillRect::CFillRect()
{
}


CFillRect::~CFillRect()
{
}
void CFillRect::draw(CDC *pDC) {
	for (int i = 0; i <lineList.GetSize(); i++) {
		CMapElement* pMap = (CMapElement*)lineList.GetAt(i);
		pMap->draw(pDC);
	}
}
int CFillRect::GetType() {
	return 3;//返回多边形类型
}

void CFillRect::AddLine(CPoint point1,CPoint point2) {
	int mm = point2.x;
	ptArray.Add(point2);
	CLine* c = new CLine();
	c->SetStartPoint(point1);
	c->SetEndPoint(point2);
	lineList.Add(c);
}
CObject* CFillRect::GetLine(int i) {
	return lineList.GetAt(i);
}

// 边标志算法
void CFillRect::EdgeMarkFill(CDC *pDC,COLORREF color)
{
	int fx, fy;
	int fx1, fy1, fx2, fy2;
	fx1 = (ptArray.GetAt(0).x);
	fx2 = 0;
	fy1 = (ptArray.GetAt(0).y);
	fy2 = 0;
	//bool MASK[][] 
	for (int i = 0; i < ptArray.GetSize(); i++){
		if (fx2 < (ptArray.GetAt(i)).x) {
			fx2 = (ptArray.GetAt(i)).x;
		}
		if (fx1 > (ptArray.GetAt(i)).x) {
			fx1 = (ptArray.GetAt(i)).x;
		}
		if (fy1 > (ptArray.GetAt(i)).y) {
			fy1 = (ptArray.GetAt(i)).y;
		}
		if (fy2 < (ptArray.GetAt(i)).y) {
			fy2 = (ptArray.GetAt(i)).y;
		}
	}
	bool** MASK = new bool*[fy2+1];
	bool** Fill = new bool*[fy2 + 1];
	//int tempdy = y2 - y1 + 2;
	//int tempdx = x2 - x1 + 2;
	//bool *MASK = new bool[y2+1];
	for (int j = 0; j < fy2+1; j++) {
		MASK[j] = new bool[fx2+1];
		Fill[j] = new bool[fx2 + 1];
	}
	int qnx = 0;
	int qny = 0;
	int qtempx = 4;
	int qtempy = 0;
	for (fy = fy1; fy <= fy2; fy++) { //形成轮廓线
		for (fx = fx1; fx <= fx2; fx++) {
			
			MASK[fy][fx] = false;
			Fill[fy][fx] = false;
			//pDC->SetPixel(fx, fy, color);
		}
	}
	int pattern[10][49] = {
		{ 0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,1 },
		{ 0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1 },
		{ 0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1 },
		{ 0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1 },
		{ 0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1 },
		{ 0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1 },
		{ 0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1 },
		{ 0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1 },
		{ 0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
	for (fy = fy1; fy <= fy2; fy++) { //形成轮廓线
		for (fx = fx1; fx <= fx2; fx++) {
			if (pattern[qny][qnx])  Fill[fy][fx] = true;//pDC->SetPixel(fx, fy, color);
			if (qtempx % 4 == 0) {
				if (qnx == 48) {
					qnx = 0;
				}
				else {
					qnx++;
				}
			}
			qtempx++;
		}
		qnx = 0;
		qtempx = 0;
		if (qtempy % 4 == 0) {
	    if (qny == 9) {
				qny = 0;
	     }
	     else {
				qny++;
	      }
		}
		qtempy++;
	}
	
	//for()

	bool inside;
	
	
	double xs = 0;
	double dxs;
	int ys = 0;
	int lxs = 0;
	for (int i = 0; i < ptArray.GetSize(); i++) {//区域D内的每一条边PiPi+1
		int x1, x2, y1, y2;

		if (i == (ptArray.GetSize() - 1)) {
			x1 = ptArray.GetAt(i).x;
			x2 = ptArray.GetAt(0).x;
			y1 = ptArray.GetAt(i).y;
			y2 = ptArray.GetAt(0).y;
		}
		else
		{
			x1 = ptArray.GetAt(i).x;
			x2 = ptArray.GetAt(i + 1).x;
			y1 = ptArray.GetAt(i).y;
			y2 = ptArray.GetAt(i + 1).y;
		}

		if (y1 >= y2) {
			int t = 0;
			t = y1;
			y1 = y2;
			y2 = t;
			t = x1;
			x1 = x2;
			x2 = t;
		}
		xs = x1;
		dxs = (x2 - x1)*1.0 / (y2 - y1);
		for (ys = y1; ys < y2; ys++) {
			xs = xs + dxs;
			lxs = int(xs + 0.5);
			//pDC->SetPixel(lxs, ys, RGB(255,0,0));
			MASK[ys][lxs] = !MASK[ys][lxs];

		}


	}
	


	for (fy = fy1; fy <= fy2; fy++) {  //按轮廓线填充

		inside = false;
		for (fx = fx1; fx <= fx2; fx++) {
			if (MASK[fy][fx])
				inside = !inside;
			if ((inside)&&(Fill[fy][fx]))
				pDC->SetPixel(fx, fy, fillcolor);
		}
	}
}

/*

*/

double CFillRect::maxdistance()
{
	return 0.0;
}
/*
for (int i = 0; i<ptArray.GetSize(); i++) {//区域D内的每一条边PiPi+1
//绘制直线段
int x1, x2, y1, y2;

if (i == (ptArray.GetSize() - 1)) {
x1 = ptArray.GetAt(i).x;
x2 = ptArray.GetAt(0).x;
y1 = ptArray.GetAt(i).y;
y2 = ptArray.GetAt(0).y;
}
else
{
x1 = ptArray.GetAt(i).x;
x2 = ptArray.GetAt(i + 1).x;
y1 = ptArray.GetAt(i).y;
y2 = ptArray.GetAt(i + 1).y;
}

COLORREF color = GetM_LineColor();
int x, y, dx, dy, p;
if (x1 == x2) {
if (y1 < y2) {
for (int i = y1; i <= y2; i++) {
//pDC->SetPixel(x1, i, color);
MASK[i][x1] = !MASK[i][x1];
}
}
else {
for (int i = y2; i <= y1; i++) {
//pDC->SetPixel(x1, i, color);
MASK[i][x1] = !MASK[i][x1];
}
}
return;
}
if (y1 == y2) {
if (x1 < x2) {
for (int i = x1; i <= x2; i++) {
//pDC->SetPixel(i, y1, color);
MASK[y1][i] = !MASK[y1][i];
}
}
else {
for (int i = x2; i <= x1; i++) {
//pDC->SetPixel(i, y1, color);
MASK[y1][i] = !MASK[y1][i];
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
//pDC->SetPixel(x, y, color);
MASK[y][x] = !MASK[y][x];
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
//pDC->SetPixel(x, y, color);
MASK[y][x] = !MASK[y][x];
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
//pDC->SetPixel(x, y, color);
MASK[y][x] = !MASK[y][x];
if (p < 0) { y++; p = p + (dx << 1); }
else { x++; y++; p = p + ((dx - dy) << 1); }
}
}
//第四种情况 y递减
else {
p = (dx << 1) + dy;
while (y >= y2) {
//pDC->SetPixel(x, y, color);
MASK[y][x] = !MASK[y][x];
if (p < 0) { y--; p = p + (dx << 1); }
else { x++; y--; p = p + ((dx + dy) << 1); }
}
}


}

}
*/