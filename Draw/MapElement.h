#pragma once

// CMapElement 命令目标
#include<afxtempl.h>
class CMapElement : public CObject
{
public:
	CMapElement();
	virtual ~CMapElement();
private:
	CPoint m_StartPoint;//图元起始控制点
	CPoint m_EndPoint;//图元终止控制点
	COLORREF m_LineColor;//画线颜色
public:
	void SetStartPoint(CPoint point);
	void SetEndPoint(CPoint point);
	CPoint GetStartPoint();
	CPoint GetEndPoint();
	void SetM_LineColor(COLORREF color);
	COLORREF GetM_LineColor();
	virtual void draw(CDC* pDC);//绘制图元 由具体的图元子类覆盖实现
	virtual int GetType();//获得图元类型，由具体的图元子类实现
	CPen* GetPen();

};


