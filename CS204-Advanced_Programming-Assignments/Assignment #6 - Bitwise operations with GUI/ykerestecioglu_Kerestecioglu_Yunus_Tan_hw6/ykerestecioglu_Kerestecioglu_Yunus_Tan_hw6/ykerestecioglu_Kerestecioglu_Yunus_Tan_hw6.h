
// ykerestecioglu_Kerestecioglu_Yunus_Tan_hw6.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6App:
// See ykerestecioglu_Kerestecioglu_Yunus_Tan_hw6.cpp for the implementation of this class
//

class Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6App : public CWinApp
{
public:
	Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Cykerestecioglu_Kerestecioglu_Yunus_Tan_hw6App theApp;