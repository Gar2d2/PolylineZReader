
// ShapeReaderDoc.h : interface of the CShapeReaderDoc class
//


#pragma once


class CShapeReaderDoc : public CDocument
{
protected: // create from serialization only
	CShapeReaderDoc() noexcept;
	DECLARE_DYNCREATE(CShapeReaderDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CShapeReaderDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
	void OnErrorReadingFile();
	void OnErrorShapeType();
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

	// Variables
public:
	class ShapeDrawer* shapeDrawer = nullptr;
private:
	CWnd* userWin = nullptr;
	// Methods
public:


#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
