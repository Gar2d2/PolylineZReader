// CErrorDlg.cpp : implementation file
//

#include "pch.h"
#include "ShapeReader.h"
#include "CErrorDlg.h"
#include "afxdialogex.h"


// CErrorDlg dialog

IMPLEMENT_DYNAMIC(CErrorDlg, CDialogEx)

CErrorDlg::CErrorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ERRORFILETYPE, pParent)
{

}

CErrorDlg::~CErrorDlg()
{
}

void CErrorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CErrorDlg, CDialogEx)
END_MESSAGE_MAP()


// CErrorDlg message handlers
