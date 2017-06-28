
// MFCOpencv.h : main header file for the MFCOpencv application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols

// CMFCOpencvApp:
// See MFCOpencv.cpp for the implementation of this class
//

class CMFCOpencvApp : public CWinApp
{
public:
	CMFCOpencvApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCOpencvApp theApp;
