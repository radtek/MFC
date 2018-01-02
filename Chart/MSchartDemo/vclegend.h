#if !defined(AFX_VCLEGEND_H__3B3EB701_56B5_4B79_9861_8D34A038FAC1__INCLUDED_)
#define AFX_VCLEGEND_H__3B3EB701_56B5_4B79_9861_8D34A038FAC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CVcLocation;
class CVcBackdrop;
class CVcFont;
class CVcTextLayout;
class COleFont;

/////////////////////////////////////////////////////////////////////////////
// CVcLegend wrapper class

class CVcLegend : public COleDispatchDriver
{
public:
	CVcLegend() {}		// Calls COleDispatchDriver default constructor
	CVcLegend(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CVcLegend(const CVcLegend& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CVcLocation GetLocation();
	CVcBackdrop GetBackdrop();
	CVcFont GetVtFont();
	CVcTextLayout GetTextLayout();
	void SetRefFont(LPDISPATCH newValue);
	COleFont GetFont();
	void Select();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VCLEGEND_H__3B3EB701_56B5_4B79_9861_8D34A038FAC1__INCLUDED_)
