
// ShapeReaderView.h : interface of the CShapeReaderView class
//

#pragma once
#define ID_BUTTON_RESET 101

class CShapeReaderView : public CView
{
protected: // create from serialization only
	CShapeReaderView() noexcept;
	DECLARE_DYNCREATE(CShapeReaderView)

// Attributes
public:
	CShapeReaderDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CShapeReaderView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	

// variables
private:
	bool isPanning = false;
	int zoomLevel = 10;
	int zoomMultiplier = 1;
	CPoint viewOffset = (0, 0);
	CPoint initialCursorLocation;
// methods
private:
	void OnPanning(CPoint point);
	void SetPanning(CPoint point, bool newPanning);
	void ChangeZoom(short newZoom);

public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void CreateButtons();
	void RepositionButton();
	CButton resetView;
};

#ifndef _DEBUG  // debug version in ShapeReaderView.cpp
inline CShapeReaderDoc* CShapeReaderView::GetDocument() const
   { return reinterpret_cast<CShapeReaderDoc*>(m_pDocument); }
#endif

