
// Hardware Store.h : main header file for the Hardware Store application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CHardwareStoreApp:
// See Hardware Store.cpp for the implementation of this class
//

class CHardwareStoreApp : public CWinAppEx
{
public:
	CHardwareStoreApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CHardwareStoreApp theApp;
