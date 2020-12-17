
// Roll_CallDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Roll_Call.h"
#include "Roll_CallDlg.h"
#include "afxdialogex.h"
#include <locale.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//HWND hWnd = AfxGetMainWnd()->m_hWnd;


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRoll_CallDlg 对话框




CRoll_CallDlg::CRoll_CallDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRoll_CallDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//定时器初始化，0表示无效的定时器
	m_TimerID_SJS = 0;
}

void CRoll_CallDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRoll_CallDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_DRMD, &CRoll_CallDlg::OnBnClickedBtnDrmd)
	ON_BN_CLICKED(IDC_BTN_TC, &CRoll_CallDlg::OnBnClickedBtnTc)
	ON_BN_CLICKED(IDC_BTN_KS, &CRoll_CallDlg::OnBnClickedBtnKs)
	ON_BN_CLICKED(IDC_BTN_TZ, &CRoll_CallDlg::OnBnClickedBtnTz)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CRoll_CallDlg 消息处理程序

BOOL CRoll_CallDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作

	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CWnd *hBtnKS = (CWnd *)GetDlgItem(IDC_BTN_KS);
	CWnd *hBtnTZ = (CWnd *)GetDlgItem(IDC_BTN_TZ);
	hBtnKS->EnableWindow(false);
	hBtnTZ->EnableWindow(false);

	CWnd *hEditCCRS = (CWnd *)GetDlgItem(IDC_EDIT_CCRS);
	CWnd *hEditSJS = (CWnd *)GetDlgItem(IDC_EDIT_SJS);
	hEditCCRS->SetWindowText(_T("2"));
	hEditSJS->SetWindowText(_T("显示随机数"));


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CRoll_CallDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRoll_CallDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CRoll_CallDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/*********************************导入名单***************************************/
void CRoll_CallDlg::OnBnClickedBtnDrmd()
{
	// TODO: 在此添加控件通知处理程序代码
	CWnd *hBtnKS = (CWnd *)GetDlgItem(IDC_BTN_KS);
	CWnd *hBtnTZ = (CWnd *)GetDlgItem(IDC_BTN_TZ);
	
	CFileDialog sel_DRMD(TRUE, NULL, NULL, 
		OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST,
		L"文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||", this);

	if (sel_DRMD.DoModal() == IDOK)
	{
		if (sel_DRMD.GetPathName() == "")
		{
			AfxMessageBox(_T("请选择一个文件"));

		} else {
			//AfxMessageBox(sel_DRMD.GetPathName());

			CStdioFile file_DRMD;
			BOOL is_Open = file_DRMD.Open(sel_DRMD.GetPathName(), CFile::modeRead);
			if (!is_Open)
			{
				AfxMessageBox(_T("文件打开失败"));
			} else {
				CString buff;
				CListBox * hListMD = (CListBox*)GetDlgItem(IDC_LST_MD);
				hListMD->ResetContent(); 

				char* old_Language=_strdup(setlocale(LC_CTYPE,NULL) );
				setlocale( LC_CTYPE,"chs");
				
				while (file_DRMD.ReadString(buff))
				{
					hListMD->AddString(buff);
				}

				setlocale( LC_CTYPE, old_Language ); 
				free( old_Language );
			}
			
			hBtnKS->EnableWindow(true); //导入成功以后的操作
		}
		
	}
}

/*********************************退出***************************************/
void CRoll_CallDlg::OnBnClickedBtnTc()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxGetMainWnd()->SendMessage(WM_CLOSE);

}

/*********************************开始***************************************/
void CRoll_CallDlg::OnBnClickedBtnKs()
{
	// TODO: 在此添加控件通知处理程序代码
	CWnd *hBtnKS = (CWnd *)GetDlgItem(IDC_BTN_KS);
	CWnd *hBtnTZ = (CWnd *)GetDlgItem(IDC_BTN_TZ);
	hBtnKS->EnableWindow(FALSE);
	hBtnTZ->EnableWindow(TRUE);

	if (m_TimerID_SJS == 0)
	{
		//一号定时器，500ms，null表示使用消息通知的方式
		m_TimerID_SJS = SetTimer(1, 100, NULL);
	}
	//CListBox * hListMD = (CListBox*)GetDlgItem(IDC_LST_MD);
	//int intNumMD = hListMD->GetCount();
	//int intNumCCRS = GetDlgItemInt(IDC_EDIT_CCRS);
	

}

/*********************************停止***************************************/
void CRoll_CallDlg::OnBnClickedBtnTz()
{
	// TODO: 在此添加控件通知处理程序代码
	CWnd *hBtnKS = (CWnd *)GetDlgItem(IDC_BTN_KS);
	CWnd *hBtnTZ = (CWnd *)GetDlgItem(IDC_BTN_TZ);
	hBtnKS->EnableWindow(TRUE);
	hBtnTZ->EnableWindow(FALSE);

	KillTimer(m_TimerID_SJS);
	m_TimerID_SJS = 0;

	int intNumSJS = 0;
	int intNumCCRS = 0;
	int intNumMD = 0;
	int intIndexCZ = 0;
	CListBox * hListMD = (CListBox*)GetDlgItem(IDC_LST_MD);
	CListBox * hListCZ = (CListBox*)GetDlgItem(IDC_LST_CZ);

	intNumCCRS = GetDlgItemInt(IDC_EDIT_CCRS);
	intNumMD =  hListMD->GetCount();
	hListCZ->ResetContent();

	if ( intNumMD < intNumCCRS )
	{
		for (int i=0; i < intNumMD; ++i )
		{
			CString buff;
			hListMD->GetText(0, buff);
			hListCZ->AddString(buff);
			hListMD->DeleteString(0);
		}
		AfxMessageBox(L"人数不够!");
		hBtnKS->EnableWindow(FALSE);
		hBtnTZ->EnableWindow(TRUE);

	} else {
		for (int i=0; i < intNumCCRS; ++i)
		{
			intNumSJS = rand();
			intNumMD = hListMD->GetCount();
			intIndexCZ = intNumSJS % intNumMD;
			CString buff;
			hListMD->GetText(intIndexCZ, buff);
			hListCZ->AddString(buff);
			hListMD->DeleteString(intIndexCZ);
		}
	}
}

/*******************************随机数定时器*************************************/
void CRoll_CallDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int intNumSJS = rand();
	SetDlgItemInt(IDC_EDIT_SJS, intNumSJS);

	CDialogEx::OnTimer(nIDEvent);
}
