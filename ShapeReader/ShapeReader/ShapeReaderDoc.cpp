
// ShapeReaderDoc.cpp : implementation of the CShapeReaderDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ShapeReader.h"
#endif

#include "shapefil.h"
#include "PolylineZ.h"
#include "ShapeDrawer.h"
#include "CErrorDlg.h"
#include "CShapeErrorDlg.h"
#include "PolylineZDrawer.h"
#include "ShapeReaderDoc.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CShapeReaderDoc

IMPLEMENT_DYNCREATE(CShapeReaderDoc, CDocument)

BEGIN_MESSAGE_MAP(CShapeReaderDoc, CDocument)
	ON_COMMAND(IDD_ERRORFILETYPE, &CShapeReaderDoc::OnErrorReadingFile)
END_MESSAGE_MAP()


// CShapeReaderDoc construction/destruction

CShapeReaderDoc::CShapeReaderDoc() noexcept
{
	// TODO: add one-time construction code here

}

CShapeReaderDoc::~CShapeReaderDoc()
{
}

BOOL CShapeReaderDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CShapeReaderDoc serialization

void CShapeReaderDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		TRACE(ar.GetFile()->GetFilePath());
		CStringA s(ar.GetFile()->GetFilePath());
		const char* filepath = s;
		SHPHandle handle = SHPOpen(filepath, "");
		if (!handle)
		{
			OnErrorReadingFile();
			return;
		}
		switch (handle->nShapeType)
		{
		case 3: //polylineZ and polyline 
		case 13:
			shapeDrawer = new PolylineZDrawer(new PolylineZ(handle), this);
			break;

		default:
			OnErrorShapeType();
			break;
		};
		
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CShapeReaderDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CShapeReaderDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CShapeReaderDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CShapeReaderDoc diagnostics

#ifdef _DEBUG
void CShapeReaderDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CShapeReaderDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

void CShapeReaderDoc::OnErrorReadingFile()
{
	CErrorDlg dlg;
	dlg.DoModal();
}

void CShapeReaderDoc::OnErrorShapeType()
{
	CShapeErrorDlg dlg;
	dlg.DoModal();
}

// CShapeReaderDoc commands
