#pragma once
#include "MapElement.h"
#include"MapList.h"
#include"Line.h"
struct EDGE {  //边结构，保存边信息的同时作为ET表中和AET表中的吊桶
	int ymin;  //最小y值 等同于ET表中登记的y值
	int ymax;  //最大y值 吊桶数据
	double xmin; //萧y值端点的x值 吊桶数据
	double fm;  // 斜率倒数
	EDGE* next;
	EDGE* last;
};
class CFillRect :        //绘制多边形
	public CMapElement
{
private:
	CMapList lineList;//当前绘制的图元的列表
	CArray<CPoint> ptArray;
public:
	/*void Polygonfill(CDC *pDC,CArray<CPoint,CPoint>* points,COLORREF color);//多边形扫描转换算法
	EDGE* GetET(CArray<CPoint, CPoint>* points);//获得多边形的最初的ET表
	void SortET(EDGE* pEDGE);//将传入的ET表排序
	void SortAET(EDGE* pEDGE);//将传入的AET表排序*/
	CObject* GetLine(int i);//获得lineList
	//void SetLineList(CMapList cml);
	COLORREF fillcolor;
	void  Setfillcolor(COLORREF m) {
		fillcolor = m;
	}
	void AddLine(CPoint point1, CPoint point2);
	CFillRect();
	~CFillRect();
	void draw(CDC *pDC);
	int GetType();
	// 边标志算法
	void EdgeMarkFill(CDC *pDC,COLORREF color);
	double maxdistance();
};

