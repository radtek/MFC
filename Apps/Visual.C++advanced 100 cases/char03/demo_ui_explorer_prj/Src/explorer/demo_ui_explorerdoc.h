// demo_ui_explorerDoc.h : interface of the CDemo_ui_explorerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMO_UI_EXPLORERDOC_H__7BB52B83_0704_11D2_AB9F_441100C10000__INCLUDED_)
#define AFX_DEMO_UI_EXPLORERDOC_H__7BB52B83_0704_11D2_AB9F_441100C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CDemo_ui_explorerDoc : public CDocument
{
protected: // create from serialization only
	CDemo_ui_explorerDoc();
	DECLARE_DYNCREATE(CDemo_ui_explorerDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemo_ui_explorerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDemo_ui_explorerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDemo_ui_explorerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMO_UI_EXPLORERDOC_H__7BB52B83_0704_11D2_AB9F_441100C10000__INCLUDED_)
