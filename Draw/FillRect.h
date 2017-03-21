#pragma once
#include "MapElement.h"
#include"MapList.h"
#include"Line.h"
struct EDGE {  //�߽ṹ���������Ϣ��ͬʱ��ΪET���к�AET���еĵ�Ͱ
	int ymin;  //��Сyֵ ��ͬ��ET���еǼǵ�yֵ
	int ymax;  //���yֵ ��Ͱ����
	double xmin; //��yֵ�˵��xֵ ��Ͱ����
	double fm;  // б�ʵ���
	EDGE* next;
	EDGE* last;
};
class CFillRect :        //���ƶ����
	public CMapElement
{
private:
	CMapList lineList;//��ǰ���Ƶ�ͼԪ���б�
	CArray<CPoint> ptArray;
public:
	/*void Polygonfill(CDC *pDC,CArray<CPoint,CPoint>* points,COLORREF color);//�����ɨ��ת���㷨
	EDGE* GetET(CArray<CPoint, CPoint>* points);//��ö���ε������ET��
	void SortET(EDGE* pEDGE);//�������ET������
	void SortAET(EDGE* pEDGE);//�������AET������*/
	CObject* GetLine(int i);//���lineList
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
	// �߱�־�㷨
	void EdgeMarkFill(CDC *pDC,COLORREF color);
	double maxdistance();
};

