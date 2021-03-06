// CGradientCtrlDemo.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "CGradientCtrlDemo.h"
#include "CGradientCtrlDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGradientCtrlDemoApp

BEGIN_MESSAGE_MAP(CGradientCtrlDemoApp, CWinApp)
	//{{AFX_MSG_MAP(CGradientCtrlDemoApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGradientCtrlDemoApp construction

CGradientCtrlDemoApp::CGradientCtrlDemoApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CGradientCtrlDemoApp object

CGradientCtrlDemoApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CGradientCtrlDemoApp initialization

BOOL CGradientCtrlDemoApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CGradientCtrlDemoDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

