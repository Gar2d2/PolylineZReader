#pragma once


// CShapeErrorDlg dialog

class CShapeErrorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CShapeErrorDlg)

public:
	CShapeErrorDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CShapeErrorDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ERRORSHAPETYPE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
