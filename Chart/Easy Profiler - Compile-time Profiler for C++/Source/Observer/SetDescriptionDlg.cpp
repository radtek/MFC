/********************************************************************
    File:	        SetDescriptionDlg	
    Creation Date:	2009/11/01
	
	Author: 	    Ahmed Charfeddine
					info@potatosoftware.com

	License:        Copyright [2009] [Potato software]

					Licensed under the Apache License, Version 2.0 (the "License");
					you may not use this file except in compliance with the License.
					You may obtain a copy of the License at

							http://www.apache.org/licenses/LICENSE-2.0

					Unless required by applicable law or agreed to in writing, software
					distributed under the License is distributed on an "AS IS" BASIS,
					WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
					See the License for the specific language governing permissions and
					limitations under the License.
    
	Note :	  		
*********************************************************************/
// SetDescriptionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Observer.h"
#include "SetDescriptionDlg.h"


// CSetDescriptionDlg dialog

IMPLEMENT_DYNAMIC(CSetDescriptionDlg, CDialog)

CSetDescriptionDlg::CSetDescriptionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetDescriptionDlg::IDD, pParent)
	, m_strDescription(_T(""))
{

}

CSetDescriptionDlg::~CSetDescriptionDlg()
{
}

void CSetDescriptionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strDescription);
}


BEGIN_MESSAGE_MAP(CSetDescriptionDlg, CDialog)
END_MESSAGE_MAP()


// CSetDescriptionDlg message handlers
