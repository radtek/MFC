// EdgeObj.cpp: implementation of the CEdgeObj class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EdgeObj.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEdgeObj::CEdgeObj()
{
	m_operaType = UNDOREDO_TYPE_NULL;
}

CEdgeObj::~CEdgeObj()
{

}
