// CShapeErrorDlg.cpp : implementation file
//

#include "pch.h"
#include "ShapeReader.h"
#include "CShapeErrorDlg.h"
#include "afxdialogex.h"


// CShapeErrorDlg dialog

IMPLEMENT_DYNAMIC(CShapeErrorDlg, CDialogEx)

CShapeErrorDlg::CShapeErrorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ERRORSHAPETYPE, pParent)
{

}

CShapeErrorDlg::~CShapeErrorDlg()
{
}

void CShapeErrorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CShapeErrorDlg, CDialogEx)
END_MESSAGE_MAP()


// CShapeErrorDlg message handlers
