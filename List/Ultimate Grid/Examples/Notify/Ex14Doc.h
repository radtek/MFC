// Ex14Doc.h : interface of the CEx14Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EX14DOC_H__1E2EF4ED_1504_11D1_A901_0080C85A0F46__INCLUDED_)
#define AFX_EX14DOC_H__1E2EF4ED_1504_11D1_A901_0080C85A0F46__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CEx14Doc : public CDocument
{
protected: // create from serialization only
	CEx14Doc();
	DECLARE_DYNCREATE(CEx14Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEx14Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEx14Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEx14Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EX14DOC_H__1E2EF4ED_1504_11D1_A901_0080C85A0F46__INCLUDED_)
