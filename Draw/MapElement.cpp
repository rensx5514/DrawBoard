// MapElement.cpp : 实现文件
//

#include "stdafx.h"
#include "Draw.h"
#include "MapElement.h"


// CMapElement

CMapElement::CMapElement()
{
}

CMapElement::~CMapElement()
{
}
void CMapElement::SetStartPoint(CPoint point) {
	m_StartPoint = point;

}
void CMapElement::SetEndPoint(CPoint point) {
	m_EndPoint = point;
}
void CMapElement::SetM_LineColor(COLORREF color) {
	m_LineColor = color;
}

CPoint CMapElement::GetStartPoint() {
	return m_StartPoint;
}
CPoint CMapElement::GetEndPoint() {
	return m_EndPoint;
}
COLORREF CMapElement::GetM_LineColor(){
	return m_LineColor;
}
void CMapElement::draw(CDC *pDC) {
}
int CMapElement::GetType() {
	return 0;
}
CPen* CMapElement::GetPen() {
	//构造LOGBRUSH结构
	LOGBRUSH lb;
	lb.lbColor = m_LineColor;
	return new CPen(PS_GEOMETRIC,1,&lb,0,NULL);
}
// CMapElement 成员函数
