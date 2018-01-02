#if !defined(AFX__HSCROLL_H__D37CB2A8_CA3D_4153_8C20_87FE4F40661E__INCLUDED_)
#define AFX__HSCROLL_H__D37CB2A8_CA3D_4153_8C20_87FE4F40661E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// C_HScroll wrapper class

class C_HScroll : public CWnd
{
protected:
	DECLARE_DYNCREATE(C_HScroll)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0xb2135337, 0xd9e9, 0x4226, { 0xbb, 0x5e, 0x7, 0x10, 0x34, 0xb8, 0x33, 0x3 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:

// Operations
public:
	CString GetLargeChange();
	void SetLargeChange(LPCTSTR lpszNewValue);
	short GetValue();
	void SetValue(short nNewValue);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX__HSCROLL_H__D37CB2A8_CA3D_4153_8C20_87FE4F40661E__INCLUDED_)
