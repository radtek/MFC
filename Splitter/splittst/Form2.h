#if !defined(AFX_FORM2_H__FA98B71C_D0B7_11D3_BC39_00C04F602FEE__INCLUDED_)
#define AFX_FORM2_H__FA98B71C_D0B7_11D3_BC39_00C04F602FEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Form2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CForm2 form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CForm2 : public CFormView
{
protected:
	CForm2();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CForm2)

// Form Data
public:
	//{{AFX_DATA(CForm2)
	enum { IDD = IDD_FORM2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CForm2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CForm2();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CForm2)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FORM2_H__FA98B71C_D0B7_11D3_BC39_00C04F602FEE__INCLUDED_)
