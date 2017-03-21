
// DrawView.cpp : CDrawView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Draw.h"
#endif

#include "DrawDoc.h"
#include "DrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

BEGIN_MESSAGE_MAP(CDrawView, CView)               //������ط�ʵ������ԴID���䴦������ʵ������
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32773, &CDrawView::OnDrawCircle)
	ON_COMMAND(ID_32772, &CDrawView::OnDrawRect)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_32774, &CDrawView::OnSetColor)
	ON_COMMAND(ID_32776, &CDrawView::OnDrawRects)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_32783, &CDrawView::OnDrawBezier)
	ON_COMMAND(ID_32784, &CDrawView::OnDrawB)
	ON_COMMAND(ID_32785, &CDrawView::OnDrawCube)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_32786, &CDrawView::OnRetateX)
	ON_COMMAND(ID_32787, &CDrawView::OnRetateY)
	ON_COMMAND(ID_32788, &CDrawView::OnRetateZ)
	ON_COMMAND(ID_32791, &CDrawView::OnCircleZ)
	ON_COMMAND(ID_32789, &CDrawView::OnCircleX)
	ON_COMMAND(ID_32790, &CDrawView::OnCircleY)
	ON_COMMAND(ID_32777, &CDrawView::OnSetColorFill)
	ON_COMMAND(ID_32792, &CDrawView::OnSetStep)
	ON_BN_CLICKED(IDOK, &CDrawView::OnBnClickedOk)
END_MESSAGE_MAP()

// CDrawView ����/����

CDrawView::CDrawView()
	: m_StartPoint(0)
	, m_EndPoint(0)
	, m_LButtonDown(FALSE)
	, m_DrawType(0) //Ĭ�ϲ����ڻ���Բ״̬
	, m_isDraw(TRUE) //Ĭ�ϴ��ڻ�ͼ״̬
{
	// TODO: �ڴ˴���ӹ������

}

CDrawView::~CDrawView()
{
}

BOOL CDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDrawView ����

void CDrawView::OnDraw(CDC* /*pDC*/)
{
	CDrawDoc* pDoc = GetDocument();
	CDC* pDC = this->GetDC();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i < pDoc->m_MapList.GetSize(); i++) {
		CMapElement* pMap = (CMapElement*)pDoc->m_MapList.GetAt(i);
		pMap->draw(pDC);
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CDrawView ��ӡ

BOOL CDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CDrawView ���

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawDoc* CDrawView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawDoc)));
	return (CDrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawView ��Ϣ�������


void CDrawView::OnDrawCircle()
{
	//���������Ϊ��׼��ʮ�ֹ��
	m_Cursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
	CClientDC dc(this);
	m_DrawType = 1;
	m_isDraw = true;
	// TODO: �ڴ���������������
}


void CDrawView::OnDrawRect()
{
	//���������Ϊ��׼��ʮ�ֹ��
	m_Cursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
	CClientDC dc(this);
	m_DrawType = 2;
	m_isDraw = true;
	// TODO: �ڴ���������������
}


void CDrawView::OnLButtonDown(UINT nFlags, CPoint point)  //ϵͳ�������Ϣ������
{

	//SetCursor(m_Cursor);
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_isDraw) {
		this->DrawLButtonDown(nFlags, point);
	}
	CView::OnLButtonDown(nFlags, point); // ���д����ǵ��ö�Ӧ�ĸ���������Ϣ���������е�һЩĬ�ϴ�������ɾ�����������
}


void CDrawView::OnMouseMove(UINT nFlags, CPoint point)  //ϵͳ�������Ϣ������
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//SetCursor(m_Cursor);
	if (m_isDraw) {
		this->DrawMouseMove(nFlags,point);
	}
	CView::OnMouseMove(nFlags, point);
}


void CDrawView::OnLButtonUp(UINT nFlags, CPoint point)  //ϵͳ�������Ϣ������
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//SetCursor(m_Cursor);
	if (m_isDraw) {
		this->DrawLButtonUp(nFlags,point);
	}
	CView::OnLButtonUp(nFlags, point);
}
void CDrawView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_isDraw) {
		this->DrawLButtonDblClk(nFlags, point);
	}
	CView::OnRButtonDown(nFlags, point);
}

void CDrawView::OnLButtonDblClk(UINT nFlags, CPoint point) //ϵͳ�����Ϣ������˫��
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_isDraw) {
		this->DrawLButtonDblClk(nFlags, point);
	}
	CView::OnLButtonDblClk(nFlags, point);
}


// ����ͼʱ�������˫��������
void CDrawView::DrawLButtonDblClk(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	CDC* pDC = this->GetDC();
	CDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	//this->SetCapture();
	if (m_isDrawRects && (m_DrawType == 3)) {
		m_isDrawRects = false;
		m_isDraw = false;
		tempcfr->AddLine(m_EndPoint, tempcfr->GetStartPoint());
		tempcfr->draw(pDC);
		tempcfr->Setfillcolor(m_LineColor);
		tempcfr->SetEndPoint(m_EndPoint);
		tempcfr->EdgeMarkFill(pDC, m_LineColor);
		//pDoc->m_MapList.Add(tempcfr);
	}
	this->ReleaseDC(pDC);
}
//����ͼʱ���������´�����
void CDrawView::DrawLButtonDown(UINT nFlags, CPoint point)
{
	SetCursor(m_Cursor);
	this->SetCapture();//��׽���
	if ((m_DrawType == 3) && (m_isDrawRects)) {
		//start
		m_StartPoint = m_EndPoint;
		
	}
	else if (m_DrawType == 4) {
		ptControlPts[m_nCount] = point;
		m_Newpoint = point;
		m_nCount = (++m_nCount) % (N + 1);
	}
	else if (m_DrawType == 5) {
		ptControlPts[m_nCount] = point;
		m_Newpoint = point;
		m_nCount = (++m_nCount) % (N + 1);

	}else{

		m_StartPoint = point;
		m_EndPoint = point;
		m_LButtonDown = true;
	}

	
	

}


// ����ͼʱ����ƶ�������
void CDrawView::DrawMouseMove(UINT nFlags, CPoint point)
{
	CClientDC dc(this);//�����豸��������
	CDC* pDC = this->GetDC();
	pDC->SetROP2(R2_NOT);
	//�ж�����ƶ���ͬʱ���������£�����Ҫ���Ƶ���ֱ�߶�
	if (m_LButtonDown&&(m_DrawType == 1)) {   //����Բ��
		dc.SetROP2(R2_NOT);//���û�ͼģʽΪR2_NOT
		//���»���ǰһ������ƶ���Ϣ���������Ƶ�ֱ�߶�
		//��Ϊ��ͼģʽ��ԭ�򣬽�������˸��߶�
		int temp = CalCircleR(m_StartPoint,m_EndPoint);
		tempc->SetM_LineColor(m_LineColor);
		tempc->SetStartPoint(m_StartPoint);
		tempc->SetEndPoint(m_EndPoint);
		tempc->SetCr(temp);
		tempc->draw(pDC);
		//dc.Arc(m_StartPoint.x - temp, m_StartPoint.y - temp, m_StartPoint.x + temp, m_StartPoint.y + temp, m_StartPoint.x - temp, m_StartPoint.y - temp, m_StartPoint.x - temp, m_StartPoint.y - temp);
		//�����µ��߶�
		temp = CalCircleR(m_StartPoint,point);
		//dc.Arc(m_StartPoint.x - temp, m_StartPoint.y - temp, m_StartPoint.x + temp, m_StartPoint.y + temp, m_StartPoint.x - temp, m_StartPoint.y - temp, m_StartPoint.x - temp, m_StartPoint.y - temp);
		//9k,tempc->SetM_LineColor(m_LineColor);
		tempc->SetEndPoint(point);
		tempc->SetCr(temp);
		tempc->draw(pDC);
		//�����µ��߶��յ�
		m_R = temp;
		m_EndPoint = point;

	}else if(m_LButtonDown&&(m_DrawType == 2)) {   //���ƾ���
		dc.SetROP2(R2_NOT);//���û�ͼģʽΪR2_NOT
						   //���»���ǰһ������ƶ���Ϣ���������Ƶ�ֱ�߶�
						   //��Ϊ��ͼģʽ��ԭ�򣬽�������˸��߶�
		dc.MoveTo(m_StartPoint);
		dc.LineTo(m_StartPoint.x, m_EndPoint.y);
		dc.LineTo(m_EndPoint);
		dc.LineTo(m_EndPoint.x, m_StartPoint.y);
		dc.LineTo(m_StartPoint);
		//�ٻ���һ��
		dc.MoveTo(m_StartPoint);
		dc.LineTo(m_StartPoint.x, point.y);
		dc.LineTo(point);
		dc.LineTo(point.x, m_StartPoint.y);
		dc.LineTo(m_StartPoint);
		//�����µ��յ�
		m_EndPoint = point;

	}
	/*else if (m_LButtonDown && (m_DrawType == 3)) {//���ƶ����
		
	}*/
	else if ((m_isDrawRects) && (m_DrawType == 3)) {
		dc.SetROP2(R2_NOT);//���û�ͼģʽΪR2_NOT
						   //���»���ǰһ������ƶ���Ϣ���������Ƶ�ֱ�߶�
						   //��Ϊ��ͼģʽ��ԭ�򣬽�������˸��߶�
		templine->SetStartPoint(m_StartPoint);
		templine->SetEndPoint(m_EndPoint);
		templine->draw(pDC);
		templine->SetEndPoint(point);
		templine->draw(pDC);
		/*tempcfr->AddLine(m_StartPoint, m_EndPoint);
		tempcfr->draw(pDC);*/
		m_EndPoint = point;
	}
	else if ((m_nCount>0)&&(m_nCount<=N)){
		dc.SetROP2(R2_NOT);
		dc.MoveTo((CPoint)ptControlPts[m_nCount - 1]);//����ǰ��ջ��Ƶ�һ��ֱ��
		dc.LineTo(m_Newpoint);
		dc.MoveTo((CPoint)ptControlPts[m_nCount - 1]);
		dc.LineTo(point);
		m_Newpoint = point;

	}
}


// ����ͼʱ���̧������
void CDrawView::DrawLButtonUp(UINT nFlags, CPoint point)
{
	SetCursor(m_Cursor);
	ReleaseCapture();
	CClientDC dc(this);
	CDC* pDC = this->GetDC();
	CDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	m_LButtonDown = false;
	if (m_DrawType == 1) {
		Circle* c = new Circle();
		c->SetM_LineColor(m_LineColor);
		c->SetStartPoint(m_StartPoint);
		c->SetEndPoint(m_EndPoint);
		c->SetCr(m_R);
		c->draw(pDC);
		pDoc->m_MapList.Add(c);
		
	}
	if (m_DrawType == 2) {
		CRectangle* r = new CRectangle();
		r->SetM_LineColor(m_LineColor);
		r->SetStartPoint(m_StartPoint);
		r->SetEndPoint(m_EndPoint);
		r->draw(pDC);
		pDoc->m_MapList.Add(r);
	}
	if ((m_DrawType == 3)&&m_isDrawRects) {
		//CFillRect* cf = new CFillRect();
		m_EndPoint = point;
		tempcfr->AddLine(m_StartPoint,m_EndPoint);
		tempcfr->draw(pDC);
		//pDoc->m_MapList.Add(tempcfr);
	}
	if ((m_DrawType == 3) && (m_isDrawRects == false)) {
		//start
		tempcfr = new CFillRect();
		m_isDrawRects = true;
		tempcfr->SetStartPoint(point);
	}
	if (m_DrawType == 4) {
		if (m_nCount == 0) {
			DrawBezier(pDC, ptControlPts);
		}
	}
	if ((m_DrawType == 5) && (m_nCount == 0)) {
		GenerateKnots(0);//Ĭ�ϲ���1���� �Ǿ���
		bspline_to_points(ptControlPts, N, k, knots, ptPts, npoints);
		dc.MoveTo((CPoint)ptPts[0]);
		for (int i = 1; i <= npoints; i++) {
			dc.LineTo((CPoint)ptPts[i]);
		}
	}
	this->ReleaseDC(pDC);
}

	


// ����Բ�İ뾶
int CDrawView::CalCircleR(CPoint point1, CPoint point2)
{
	int temp1 = (point2.x - point1.x);
	int temp2 = (point2.y - point1.y);
	int temp = (int)sqrt(((temp1*temp1) + (temp2*temp2)));
	return temp;
}


void CDrawView::OnSetColor()
{
	// TODO: �ڴ���������������
	CColorDialog dlg;//ϵͳ������ṩ��ɫ���õĶԻ���
	if (dlg.DoModal() == IDOK) {
		//�û�ѡ��ȷ����ť���رնԻ��������û�ѡ�����ɫ
		m_LineColor = dlg.GetColor();
		
	}
}


void CDrawView::OnDrawRects()
{
	//���������Ϊ��׼��ʮ�ֹ��
	m_Cursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
	CClientDC dc(this);
	
	m_DrawType = 3;
	m_isDraw = true;
	// TODO: �ڴ���������������s
}
void CDrawView::OnDrawCube()
{
	// TODO: �ڴ���������������

	CDrawDoc* pDoc = GetDocument();
	CClientDC dc(this);
	CDC* pDC = this->GetDC();
	m_DrawType = 5;
	m_isDraw = true;
	cu->draw(pDC);
	pDoc->m_MapList.Add(cu);

}
void CDrawView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CDC* pDC = this->GetDC();
	CClientDC dc(this);
	
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_DrawType == 6) {
		if (nChar == 'W') {
			cu->RotateX(step);
			this->Invalidate();
		}
		if (nChar == 'S') {
			cu->RotateX(step);
			this->Invalidate();
		}
		if (nChar == 'A') {

		}
		if (nChar == 'D') {

		}
	}
	if (m_DrawType == 7) {
		if (nChar == 'W') {
			cu->RotateY(step);
			this->Invalidate();
		}
		if (nChar == 'S') {
			cu->RotateY(-step);
			this->Invalidate();
		}
		if (nChar == 'A') {

		}
		if (nChar == 'D') {

		}
	}
	if (m_DrawType == 8) {
		if (nChar == 'W') {
			cu->RotateZ(step);
			this->Invalidate();
		}
		if (nChar == 'S') {
			cu->RotateZ(step);
			this->Invalidate();
		}
		if (nChar == 'A') {

		}
		if (nChar == 'D') {

		}
	}
	if (m_DrawType == 9) {
		if (nChar == 'W') {
			
		}
		if (nChar == 'S') {

		}
		if (nChar == 'A') {
			cu->CircleZ((3.1415926/36));
			this->Invalidate();
		}
		if (nChar == 'D') {
			cu->CircleZ(-(3.1415926 / 36));
			this->Invalidate();
		}
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CDrawView::OnRetateX()
{
	CClientDC dc(this);
	CDC* pDC = this->GetDC();
	m_DrawType = 6;
	m_isDraw = true;
	// TODO: �ڴ���������������
}
void CDrawView::OnRetateY()
{
	CClientDC dc(this);
	CDC* pDC = this->GetDC();
	m_DrawType = 7;
	m_isDraw = true;
	// TODO: �ڴ���������������
}

void CDrawView::OnRetateZ()
{
	CClientDC dc(this);
	CDC* pDC = this->GetDC();
	m_DrawType = 8;
	m_isDraw = true;
	// TODO: �ڴ���������������
}
void CDrawView::OnCircleZ()
{
	CClientDC dc(this);
	CDC* pDC = this->GetDC();
	m_DrawType = 9;
	m_isDraw = true;
	// TODO: �ڴ���������������
}

void CDrawView::OnDrawB()
{
	// TODO: �ڴ���������������
	m_Cursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
	CClientDC dc(this);
	m_nCount = 0;//���������µĴ�����ʼ��Ϊ0
				 //nMethod = 0;
	m_DrawType = 5;
	m_isDraw = true;
}
void CDrawView::OnDrawBezier()
{
	m_Cursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
	CClientDC dc(this);
	m_nCount = 0;
	m_DrawType = 4;
	m_isDraw = true;
	// TODO: �ڴ���������������
}
void CDrawView::DrawBezier(CDC* pDC, CPoint P[])
{
	CPoint R[N + 1], Q[N + 1];
	int i, j;
	CPoint temp;
	const double epsilon = 1;
	if (maxdistance(P) < epsilon) {
		pDC->MoveTo((CPoint)P[0]);
		pDC->LineTo((CPoint)P[N]);
	}
	else {
		for (i = 0; i <= N; i++) {
			R[i] = P[i];
			
		}
		for (i = 0; i <= N-1; i++) {
			Q[i] = R[0];
			for (j = 0; j <= N - 1-i; j++) {
					temp = (R[j] + R[j + 1]);// 2.0
					R[j].x = temp.x / 2.0;
					R[j].y = temp.y / 2.0;
			}	
		}
		Q[N] = R[0];
		DrawBezier(pDC, Q);
		DrawBezier(pDC, R);
	}

}
double CDrawView::maxdistance(CPoint  p[])
{
	double s, h, hmax = 0;
	for (int i = 0; i < N - 1; i++) {
		s = ((p[0].x - p[i + 1].x)*(p[0].y + p[i + 1].y) + (p[i + 1].x - p[N].x)*(p[i + 1].y + p[N].y) + (p[N].x - p[0].x)*(p[N].y + p[0].y));
		double distance = sqrt((p[0].x - p[N].x)*(p[0].x-p[N].x)+(p[0].y-p[N].y)*(p[0].y-p[N].y));
		h = fabs(s / distance);
		if (hmax < h)
			hmax = h;
	}
	return hmax;
}



void CDrawView::GenerateKnots(int type)
{
	int i, len = N + k + 1;
	knots = new double[len];
	switch (type) {
	case 0:
		for (i = 0; i < len; i++)
			knots[i] = i;
		break;
	case 1:
		for (i = 0; i < len; i++) {
			if (i <= k - 1) {
				knots[i] = 0;
			}
			else if(i>=N+1) {
				knots[i] = N - k + 2;
			}
			else {
				knots[i] = i - k + 1;
			}
		}
		break;
	}
}


void CDrawView::bspline_to_points(CPoint  P[], int n, int k, double  knot[], CPoint  pts[], int npoints)
{
	double u, delt;
	int i, j;
	delt = (knot[n + 1] - knot[n - 1]) / (double)npoints;
	j = k - 1;
	u = knot[k - 1];
	switch (1) {
	case 0:
			break;
	case 1:
		for (i = 0; i <= npoints; i++,u+=delt) {
			while ((j < n) && (u > knot[j + 1]))j++;
			pts[i] = deboor(P, j, k, knot, u);
		}
		break;
	}
}


CPoint CDrawView::deboor(CPoint  CP[], int j, int k, double  knot[], double u)
{
	double denom, alpha;
	CPoint *P = new CPoint[k];
	const double epsilon = 0.0005;
	for (int i = 0; i < k; i++) {
		P[i] = CP[j - k + 1 + i];
	}
	for (int r = 1; r < k; r++) {
		for (int i = k - 1; i >= r; i--) {
			denom = knot[i - r + j + 1] - knot[i + j - k + 1];
			if (fabs(denom) < epsilon)
				alpha = 0;
			else
				alpha = (u - knot[i + j - k + 1]) / denom;
			P[i].x = P[i - 1].x * (1 - alpha)+P[i].x*alpha;
			P[i].y = P[i - 1].y * (1 - alpha) + P[i].y*alpha;
		}
	}
	return P[k-1];
}












void CDrawView::OnCircleX()
{
	// TODO: �ڴ���������������
}


void CDrawView::OnCircleY()
{
	// TODO: �ڴ���������������
}


void CDrawView::OnSetColorFill()
{
	CColorDialog dlg;//ϵͳ������ṩ��ɫ���õĶԻ���
	if (dlg.DoModal() == IDOK) {
		//�û�ѡ��ȷ����ť���رնԻ��������û�ѡ�����ɫ
		m_LineColor = dlg.GetColor();

	}
	// TODO: �ڴ���������������
}

void CDrawView::OnSetStep()
{
	
	//dlg.setid
	//IDD_DIALOG1
	// TODO: �ڴ���������������
}


void CDrawView::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
