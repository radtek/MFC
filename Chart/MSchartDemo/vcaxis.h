#if !defined(AFX_VCAXIS_H__86BE3A99_9F5D_43E4_B135_DE1A7E0402D3__INCLUDED_)
#define AFX_VCAXIS_H__86BE3A99_9F5D_43E4_B135_DE1A7E0402D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CVcPen;
class CVcCategoryScale;
class CVcAxisGrid;
class CVcIntersection;
class CVcTick;
class CVcAxisScale;
class CVcValueScale;
class CVcAxisTitle;
class CVcLabels;

/////////////////////////////////////////////////////////////////////////////
// CVcAxis wrapper class

class CVcAxis : public COleDispatchDriver
{
public:
	CVcAxis() {}		// Calls COleDispatchDriver default constructor
	CVcAxis(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CVcAxis(const CVcAxis& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CVcPen GetPen();
	short GetLabelLevelCount();
	CVcCategoryScale GetCategoryScale();
	CVcAxisGrid GetAxisGrid();
	CVcIntersection GetIntersection();
	CVcTick GetTick();
	CVcAxisScale GetAxisScale();
	CVcValueScale GetValueScale();
	CVcAxisTitle GetAxisTitle();
	CVcLabels GetLabels();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VCAXIS_H__86BE3A99_9F5D_43E4_B135_DE1A7E0402D3__INCLUDED_)
