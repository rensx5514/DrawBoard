
// DrawView.h : CDrawView 类的接口
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
const int npoints = 100;//由npoints+1个点构成的折线逼近B样条曲线
class CDrawView : public CView
{
protected: // 仅从序列化创建
	CDrawView();
	DECLARE_DYNCREATE(CDrawView)

// 特性
public:
	CDrawDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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
	// 鼠标绘图时鼠标移动处理函数
	void DrawMouseMove(UINT nFlags, CPoint point);
	CPoint m_StartPoint;
private:
	CPoint m_EndPoint;
	// 鼠标左键是否按下
	BOOL m_LButtonDown;
	int m_DrawType;
	int m_R;
	BOOL m_isDraw;
	COLORREF m_LineColor;//画线颜色
	Circle* tempc = new Circle();
	CLine* templine = new CLine();
	BOOL m_isDrawRects = false;
	//asdasdasdadasdasdas
	CFillRect* tempcfr = new CFillRect();
	CPoint ptPts[npoints + 1];
	int m_nCount=0;//记住鼠标左键按下的次数
	CPoint m_Newpoint;//记住鼠标移动时的位置
	CPoint ptControlPts[N + 1];
	double* knots;//节点向量
	int nMethod;//绘制B样条曲线的方法
	int nType;//B样条曲线的类型
	int step = 10;//平移距离
	CCube* cu = new CCube();
public:
	// 鼠标绘图时左键抬起处理函数
	void DrawLButtonUp(UINT nFlags, CPoint point);
	// 计算圆的半径
	int CalCircleR(CPoint point1, CPoint point2);
	afx_msg void OnSetColor();
	afx_msg void OnDrawRects();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	// 鼠标绘图时按下左键双击处理函数
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

#ifndef _DEBUG  // DrawView.cpp 中的调试版本
inline CDrawDoc* CDrawView::GetDocument() const
   { return reinterpret_cast<CDrawDoc*>(m_pDocument); }
#endif

