
// ShapeReader.h : main header file for the ShapeReader application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CShapeReaderApp:
// See ShapeReader.cpp for the implementation of this class
//

class CShapeReaderApp : public CWinApp
{
public:
	CShapeReaderApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CShapeReaderApp theApp;
