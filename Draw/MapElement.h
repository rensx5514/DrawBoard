#pragma once

// CMapElement ����Ŀ��
#include<afxtempl.h>
class CMapElement : public CObject
{
public:
	CMapElement();
	virtual ~CMapElement();
private:
	CPoint m_StartPoint;//ͼԪ��ʼ���Ƶ�
	CPoint m_EndPoint;//ͼԪ��ֹ���Ƶ�
	COLORREF m_LineColor;//������ɫ
public:
	void SetStartPoint(CPoint point);
	void SetEndPoint(CPoint point);
	CPoint GetStartPoint();
	CPoint GetEndPoint();
	void SetM_LineColor(COLORREF color);
	COLORREF GetM_LineColor();
	virtual void draw(CDC* pDC);//����ͼԪ �ɾ����ͼԪ���า��ʵ��
	virtual int GetType();//���ͼԪ���ͣ��ɾ����ͼԪ����ʵ��
	CPen* GetPen();

};


