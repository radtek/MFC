// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "_vscroll.h"

/////////////////////////////////////////////////////////////////////////////
// C_VScroll

IMPLEMENT_DYNCREATE(C_VScroll, CWnd)

/////////////////////////////////////////////////////////////////////////////
// C_VScroll properties

/////////////////////////////////////////////////////////////////////////////
// C_VScroll operations

CString C_VScroll::GetLargeChange()
{
	CString result;
	InvokeHelper(0x68030001, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void C_VScroll::SetLargeChange(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x68030001, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

short C_VScroll::GetValue()
{
	short result;
	InvokeHelper(0x68030000, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
	return result;
}

void C_VScroll::SetValue(short nNewValue)
{
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x68030000, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}
