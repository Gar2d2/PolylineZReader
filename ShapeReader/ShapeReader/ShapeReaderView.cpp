
// ShapeReaderView.cpp : implementation of the CShapeReaderView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ShapeReader.h"
#endif

#include "shapefil.h"
#include "MemDC.h"
#include "ShapeDrawer.h"
#include "ShapeReaderDoc.h"
#include "ShapeReaderView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CShapeReaderView

IMPLEMENT_DYNCREATE(CShapeReaderView, CView)

BEGIN_MESSAGE_MAP(CShapeReaderView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONUP()
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CShapeReaderView construction/destruction

CShapeReaderView::CShapeReaderView() noexcept
{

}

CShapeReaderView::~CShapeReaderView()
{
	
}

BOOL CShapeReaderView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	
	
	return CView::PreCreateWindow(cs);
}


int CShapeReaderView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	CreateButtons();

	return 0;
}
// CShapeReaderView drawing

void CShapeReaderView::OnDraw(CDC* pDC)
{
	CShapeReaderDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	RepositionButton();
	MemDC dc(pDC);
	
	if (pDoc->shapeDrawer)
	{
		pDoc->shapeDrawer->DrawShape(&dc, viewOffset, zoomLevel);
	}

}




// CShapeReaderView diagnostics

#ifdef _DEBUG
void CShapeReaderView::AssertValid() const
{
	CView::AssertValid();
	
}

void CShapeReaderView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CShapeReaderDoc* CShapeReaderView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShapeReaderDoc)));
	return (CShapeReaderDoc*)m_pDocument;
}
#endif //_DEBUG


// CShapeReaderView message handlers


void CShapeReaderView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	SetPanning(point, true);
	CView::OnLButtonDown(nFlags, point);
}

void CShapeReaderView::OnLButtonUp(UINT nFlags, CPoint point)
{
	SetPanning(point, false);

	CView::OnLButtonUp(nFlags, point);
}

void CShapeReaderView::OnMouseMove(UINT nFlags, CPoint point)
{
	OnPanning(point);

	CView::OnMouseMove(nFlags, point);
}


BOOL CShapeReaderView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	ChangeZoom(zDelta);

	return CView::OnMouseWheel(nFlags, zDelta, pt);
}

void CShapeReaderView::OnPanning(CPoint point)
{
	if (isPanning)
	{
		viewOffset += point - initialCursorLocation;
		CRect client;
		GetClientRect(client);
		
		Invalidate();
		UpdateWindow();

		initialCursorLocation = point;
	}
}

void CShapeReaderView::SetPanning(CPoint point, bool newPanning)
{
	isPanning = newPanning;
	initialCursorLocation = point;
}

void CShapeReaderView::ChangeZoom(short newZoom)
{
	newZoom < 0 && zoomLevel > 0 ? zoomLevel -= zoomMultiplier : zoomLevel += zoomMultiplier;
	Invalidate();
	UpdateWindow();
}




BOOL CShapeReaderView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	

	return FALSE;
}

void CShapeReaderView::CreateButtons()
{
	resetView.Create(_T("Reset View"), BS_PUSHBUTTON | WS_VISIBLE, CRect(300, 100, 400, 150), this, ID_BUTTON_RESET);
	//resetView.ShowWindow(SW_SHOW);
		
	
}

void CShapeReaderView::RepositionButton()
{
	CWnd* t = this;
	CRect clientRect;
	CRect buttonRect;
	resetView.GetWindowRect(buttonRect);
	t->GetClientRect(clientRect);
	resetView.MoveWindow((clientRect.right - buttonRect.Width())/2 , clientRect.bottom - buttonRect.Height(), 80, 20);
}

