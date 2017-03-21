#pragma once
#include "MapElement.h"
#include"Point3d.h"
#include"Line.h"
class CCube :
	public CMapElement
{

public:
	double Matri[4][4];
	CPoint3d pn[8];
	CPoint p2d[8];
	int m_x0=450;
	int m_y0=150;
	int d = 80;
	double x0 = 80.0;
	double y0 = -50.0;
	double z0 = -50.0;
	CCube();
	~CCube();
	void draw(CDC *pDC);
	void Convert(CPoint3d  p[]);
	void Perspective();
	void RotateX(int x);
	void RotateY(int x);
	void RotateZ(int x);
	void CircleX(double x);
	void CircleY(double x);
	void CircleZ(double x);
};

