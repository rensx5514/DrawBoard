
// DrawView.h : CDrawView ��Ľӿ�
//

#pragma once
#include "atltypes.h"
#include"Circle.h"
#include"Rectangle.h"
#include"FillRect.h"
#include"Line.h"
#include"math.h"
#include"Cube.h"
typedef enum {
	TRF_NONE,TRF_TRANSLATE,TRF_SCALE,TRF_ROTATE
}Type_Transform;
const int N = 3;
const int k = 4;
const int npoints = 100;//��npoints+1���㹹�ɵ����߱ƽ�B��������
class CDrawView : public CView
{
protected: // �������л�����
	CDrawView();
	DECLARE_DYNCREATE(CDrawView)

// ����
public:
	CDrawDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawCircle();
	afx_msg void OnDrawRect();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	void DrawLButtonDown(UINT nFlags, CPoint point);
private:
	HCURSOR m_Cursor;
public:
	// ����ͼʱ����ƶ�������
	void DrawMouseMove(UINT nFlags, CPoint point);
	CPoint m_StartPoint;
private:
	CPoint m_EndPoint;
	// �������Ƿ���
	BOOL m_LButtonDown;
	int m_DrawType;
	int m_R;
	BOOL m_isDraw;
	COLORREF m_LineColor;//������ɫ
	Circle* tempc = new Circle();
	CLine* templine = new CLine();
	BOOL m_isDrawRects = false;
	//asdasdasdadasdasdas
	CFillRect* tempcfr = new CFillRect();
	CPoint ptPts[npoints + 1];
	int m_nCount=0;//��ס���������µĴ���
	CPoint m_Newpoint;//��ס����ƶ�ʱ��λ��
	CPoint ptControlPts[N + 1];
	double* knots;//�ڵ�����
	int nMethod;//����B�������ߵķ���
	int nType;//B�������ߵ�����
	int step = 10;//ƽ�ƾ���
	CCube* cu = new CCube();
public:
	// ����ͼʱ���̧������
	void DrawLButtonUp(UINT nFlags, CPoint point);
	// ����Բ�İ뾶
	int CalCircleR(CPoint point1, CPoint point2);
	afx_msg void OnSetColor();
	afx_msg void OnDrawRects();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	// ����ͼʱ�������˫��������
	void DrawLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDrawBezier();
	void DrawBezier(CDC* pDC, CPoint P[]);
	double maxdistance(CPoint  p[]);
	afx_msg void OnDrawB();
	void GenerateKnots(int type);
	void bspline_to_points(CPoint  P[], int n, int k, double  knot[], CPoint  pts[], int npoints);
	CPoint deboor(CPoint  CP[], int j, int k, double  knot[], double u);
	afx_msg void OnDrawCube();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnRetateX();
	afx_msg void OnRetateY();
	afx_msg void OnRetateZ();
	afx_msg void OnCircleZ();
	afx_msg void OnCircleX();
	afx_msg void OnCircleY();
	afx_msg void OnSetColorFill();
	afx_msg void OnSetStep();
	afx_msg void OnBnClickedOk();
};

#ifndef _DEBUG  // DrawView.cpp �еĵ��԰汾
inline CDrawDoc* CDrawView::GetDocument() const
   { return reinterpret_cast<CDrawDoc*>(m_pDocument); }
#endif

