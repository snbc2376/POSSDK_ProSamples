
// POSSDK_PRO_Demo.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CPOSSDK_PRO_DemoApp:
// See POSSDK_PRO_Demo.cpp for the implementation of this class
//

class CPOSSDK_PRO_DemoApp : public CWinApp
{
public:
	CPOSSDK_PRO_DemoApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CPOSSDK_PRO_DemoApp theApp;

