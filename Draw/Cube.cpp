#include "stdafx.h"
#include "Cube.h"


CCube::CCube()
{
	pn[0].x = 0; pn[0].y = 0; pn[0].z = 0;
	pn[1].x = 0; pn[1].y = 100; pn[1].z = 0;
	pn[2].x = 100; pn[2].y = 100; pn[2].z = 0;
	pn[3].x = 100; pn[3].y = 0; pn[3].z = 0;
	pn[4].x = 0; pn[4].y = 0; pn[4].z = 100;
	pn[5].x = 0; pn[5].y = 100; pn[5].z = 100;
	pn[6].x = 100; pn[6].y = 100; pn[6].z = 100;
	pn[7].x = 100; pn[7].y = 0; pn[7].z = 100;

}


CCube::~CCube()
{
}
void CCube::draw(CDC *pDC) {
	Convert(pn);
	CLine p;
	p.SetStartPoint(p2d[0]);
	p.SetEndPoint(p2d[1]);
	p.draw(pDC);
	p.SetStartPoint(p2d[1]);
	p.SetEndPoint(p2d[2]);
	p.draw(pDC);
	p.SetStartPoint(p2d[2]);
	p.SetEndPoint(p2d[3]);
	p.draw(pDC);
	p.SetStartPoint(p2d[3]);
	p.SetEndPoint(p2d[0]);
	p.draw(pDC);
	p.SetStartPoint(p2d[4]);
	p.SetEndPoint(p2d[5]);
	p.draw(pDC);
	p.SetStartPoint(p2d[5]);
	p.SetEndPoint(p2d[6]);
	p.draw(pDC);
	p.SetStartPoint(p2d[6]);
	p.SetEndPoint(p2d[7]);
	p.draw(pDC);
	p.SetStartPoint(p2d[7]);
	p.SetEndPoint(p2d[4]);
	p.draw(pDC);
	p.SetStartPoint(p2d[0]);
	p.SetEndPoint(p2d[4]);
	p.draw(pDC);
	p.SetStartPoint(p2d[1]);
	p.SetEndPoint(p2d[5]);
	p.draw(pDC);
	p.SetStartPoint(p2d[2]);
	p.SetEndPoint(p2d[6]);
	p.draw(pDC);
	p.SetStartPoint(p2d[3]);
	p.SetEndPoint(p2d[7]);
	p.draw(pDC);
	
}

void CCube::Convert(CPoint3d  p[])
{
	Perspective();
	double x, y;
	for (int i = 0; i < 8; i++) {
		x = (p[i].x*Matri[0][0] + p[i].y*Matri[0][1] + p[i].z*Matri[0][2] + Matri[0][3])/((p[i].z)/d+1.0);
		y = (p[i].x*Matri[1][0] + p[i].y*Matri[1][1] + p[i].z*Matri[1][2] + Matri[1][3])/((p[i].z) / d + 1.0);
		p2d[i].x = m_x0 + (int) x;
		p2d[i].y = m_y0 + (int) y;
	}
	//x = p[]
	return ;
}


void CCube::Perspective()
{
	//ClearScreen();
	Matri[0][0] = 1;
	Matri[0][1] = 0;
	Matri[0][2] = x0 / d;
	Matri[0][3] = 0;
	Matri[1][0] = 0;
	Matri[1][1] = 1;
	Matri[1][2] = y0 / d;
	Matri[1][3] = 0;
	Matri[2][0] = 0;
	Matri[2][1] = 0;
	Matri[2][2] = 0;
	Matri[2][3] = 0;
	Matri[3][0] = 0;
	Matri[3][1] = 0;
	Matri[3][2] = 1.0 / d;
	Matri[3][3] = 1;
	
}
void CCube::RotateX(int x) {
	pn[0].x = pn[0].x+x;
	pn[1].x = pn[1].x+x;
	pn[2].x = pn[2].x + x; 
	pn[3].x = pn[3].x + x; 
	pn[4].x = pn[4].x + x; 
	pn[5].x = pn[5].x + x; 
	pn[6].x = pn[6].x + x; 
	pn[7].x = pn[7].x + x; 

}
void CCube::RotateY(int x) {
	pn[0].y = pn[0].y + x;
	pn[1].y = pn[1].y + x;
	pn[2].y = pn[2].y + x;
	pn[3].y = pn[3].y + x;
	pn[4].y = pn[4].y + x;
	pn[5].y = pn[5].y + x;
	pn[6].y = pn[6].y + x;
	pn[7].y = pn[7].y + x;

}
void CCube::RotateZ(int x) {
	pn[0].z = pn[0].z + x;
	pn[1].z = pn[1].z + x;
	pn[2].z = pn[2].z + x;
	pn[3].z = pn[3].z + x;
	pn[4].z = pn[4].z + x;
	pn[5].z = pn[5].z + x;
	pn[6].z = pn[6].z + x;
	pn[7].z = pn[7].z + x;

}
void CCube::CircleX(double x) {

}
void CCube::CircleZ(double x) {
	pn[0].x = (pn[0].x*cos(x) - pn[0].y*sin(x));	pn[0].y = (pn[0].x*sin(x) + pn[0].y*cos(x));
	pn[1].x = (pn[1].x*cos(x) - pn[1].y*sin(x));	pn[1].y = (pn[1].x*sin(x) + pn[1].y*cos(x));
	pn[2].x = (pn[2].x*cos(x) - pn[2].y*sin(x));	pn[2].y = (pn[2].x*sin(x) + pn[2].y*cos(x));
	pn[3].x = (pn[3].x*cos(x) - pn[3].y*sin(x));	pn[3].y = (pn[3].x*sin(x) + pn[3].y*cos(x));
	pn[4].x = (pn[4].x*cos(x) - pn[4].y*sin(x));	pn[4].y = (pn[4].x*sin(x) + pn[4].y*cos(x));
	pn[5].x = (pn[5].x*cos(x) - pn[5].y*sin(x));	pn[5].y = (pn[5].x*sin(x) + pn[5].y*cos(x));
	pn[6].x = (pn[6].x*cos(x) - pn[6].y*sin(x));	pn[6].y = (pn[6].x*sin(x) + pn[6].y*cos(x));
	pn[7].x = (pn[7].x*cos(x) - pn[7].y*sin(x));	pn[7].y = (pn[7].x*sin(x) + pn[7].y*cos(x));
}