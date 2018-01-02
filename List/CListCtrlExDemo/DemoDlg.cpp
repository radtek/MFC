// DemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CListCtrlExDemo.h"
#include "DemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CDemoDlg dialog




CDemoDlg::CDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_DEMO, m_lstDemo);
	DDX_Control(pDX, IDC_DATE, m_wndDT);
	DDX_Control(pDX, IDC_COMBO, m_wndCB);
	DDX_Control(pDX, IDC_EDIT, m_wndEdit);
}

BEGIN_MESSAGE_MAP(CDemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CDemoDlg message handlers

void CDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	m_imgList.Create(1, 20, ILC_COLOR, 0, 1);
	m_lstDemo.SetImageList(&m_imgList, LVSIL_SMALL);
	FillListBox();
	m_lstDemo.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDemoDlg::AddColumns(void)
{
	m_lstDemo.InsertColumn(0, "Default Editor", LVCFMT_LEFT, 100);
	m_lstDemo.InsertColumn(1, "Date Time Editor", LVCFMT_LEFT, 100);
	m_lstDemo.InsertColumn(2, "Combobox Editor", LVCFMT_LEFT, 100);
	m_lstDemo.InsertColumn(3, "Color Select", LVCFMT_LEFT, 150);
	m_lstDemo.InsertColumn(4, "Read Only Column", LVCFMT_LEFT, 100);
	m_lstDemo.InsertColumn(5, "Just a Column", LVCFMT_LEFT, 100);

	m_lstDemo.SetColumnEditor(1, &CDemoDlg::InitEditor, &CDemoDlg::EndEditor, &m_wndDT);
	m_lstDemo.SetColumnEditor(2, &CDemoDlg::InitEditor, &CDemoDlg::EndEditor, &m_wndCB);
	m_lstDemo.SetColumnEditor(3, &CDemoDlg::InitEditor, &CDemoDlg::EndEditor, &m_dlgColor);
	m_lstDemo.SetColumnReadOnly(4);
	m_lstDemo.SetDefaultEditor(NULL, NULL, &m_wndEdit);
	m_lstDemo.SetColumnColors(4, RGB(200, 200, 200), RGB(128, 128, 128));
	m_lstDemo.SetColumnSorting(0, CListCtrlEx::Auto, CListCtrlEx::StringNoCase);
	m_lstDemo.SetColumnSorting(1, CListCtrlEx::Auto, CListCtrlEx::Date);
	m_lstDemo.SetColumnSorting(2, CListCtrlEx::Auto, CListCtrlEx::String);
	m_lstDemo.SetColumnSorting(3, CListCtrlEx::Auto, CListCtrlEx::StringNoCase);
	m_lstDemo.SetColumnSorting(4, CListCtrlEx::Auto, CListCtrlEx::StringNoCase);
}

void CDemoDlg::FillListBox(void)
{
	m_lstDemo.Reset();
	AddColumns();
	CString strDate = COleDateTime(CTime::GetCurrentTime().GetTime()).Format();
	for(int i = 0; i < 20; i++)
	{
		CString str;
		str.Format("Some %d Text %d", rand(), rand());
		m_lstDemo.InsertItem(i, str);
		m_lstDemo.SetItemText(i, 1, strDate);
		m_lstDemo.SetItemText(i, 2, "text1");
		m_lstDemo.SetItemText(i, 3, "Some Text");
		m_lstDemo.SetItemText(i, 4, "Read Only");
		m_lstDemo.SetItemText(i, 5, "Some Text");
		if(i%9 == 3)
		{
			m_lstDemo.SetRowColors(i, -1, RGB(255, 0, 0));
			m_lstDemo.SetRowEditor(i, NULL, NULL, &m_wndEdit);
		}
		if(i % 7 == 0)
		{
			m_lstDemo.SetCellColors(i, 5, RGB(0, 255, 0), RGB(255, 255, 255));
			m_lstDemo.SetCellEditor(i, 5, &CDemoDlg::InitEditor, &CDemoDlg::EndEditor, &m_wndDT);
		}
		if(i % 8 == 0) m_lstDemo.SetCellColors(i, 5, RGB(0, 255, 0), -1);
	}
	
}
BOOL CDemoDlg::InitEditor(CWnd** pWnd, int nRow, int nColumn, CString& strSubItemText, DWORD_PTR dwItemData, void* pThis, BOOL bUpdate)
{
	ASSERT(*pWnd);
	switch(nColumn)
	{
	case 1:
	case 5:
		{
			CDateTimeCtrl *pDTC = dynamic_cast<CDateTimeCtrl *>(*pWnd);
			COleDateTime dt;
			if(dt.ParseDateTime(strSubItemText)) pDTC->SetTime(dt);
		}
		break;
	case 2:
		{
			CComboBox *pCmb = dynamic_cast<CComboBox *>(*pWnd);
			pCmb->SelectString(0, strSubItemText);
		}
		break;
	case 3:
		{
			CDlgColor *pDlg = dynamic_cast<CDlgColor *>(*pWnd);		
			pDlg->m_nColor = strSubItemText.CompareNoCase("green")?(strSubItemText.CompareNoCase("blue")?0:2):1;
			pDlg->Create(CDlgColor::IDD, (CWnd*)pThis);			
			pDlg->UpdateData(FALSE);
		}
		break;
	}
	return TRUE;
}
BOOL CDemoDlg::EndEditor(CWnd** pWnd, int nRow, int nColumn, CString& strSubItemText, DWORD_PTR dwItemData, void* pThis, BOOL bUpdate)
{
	ASSERT(pWnd);
	switch(nColumn)
	{
	case 1:
	case 5:
		{
			CDateTimeCtrl *pDTC = dynamic_cast<CDateTimeCtrl *>(*pWnd);
			COleDateTime dt;
			pDTC->GetTime(dt);
			strSubItemText = dt.Format();
		}
		break;
	case 2:
		{
			CComboBox *pCmb = dynamic_cast<CComboBox *>(*pWnd);
			int index = pCmb->GetCurSel();
			if(index >= 0) pCmb->GetLBText(index, strSubItemText);
		}
		break;
	case 3:
		{
			CDlgColor *pDlg = dynamic_cast<CDlgColor *>(*pWnd);
			CListCtrlEx *pList = reinterpret_cast<CListCtrlEx *>(pThis);
			pDlg->UpdateData(TRUE);
			switch(pDlg->m_nColor)
			{
			case 1:
				strSubItemText = "Green";
				pList->SetCellColors(nRow, nColumn, RGB(0, 255, 0), -1);
				break;
			case 2:
				strSubItemText = "Blue";
				pList->SetCellColors(nRow, nColumn, RGB(0, 0,255 ), -1);
				break;
			default:
				strSubItemText = "Red";
				pList->SetCellColors(nRow, nColumn, RGB(255, 0, 0), -1);
				break;
			}				
			pDlg->DestroyWindow();
		}
		break;
	}
	return TRUE;
}
