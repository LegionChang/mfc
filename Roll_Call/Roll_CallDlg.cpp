
// Roll_CallDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CRoll_CallDlg �Ի���




CRoll_CallDlg::CRoll_CallDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRoll_CallDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//��ʱ����ʼ����0��ʾ��Ч�Ķ�ʱ��
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


// CRoll_CallDlg ��Ϣ�������

BOOL CRoll_CallDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���

	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CWnd *hBtnKS = (CWnd *)GetDlgItem(IDC_BTN_KS);
	CWnd *hBtnTZ = (CWnd *)GetDlgItem(IDC_BTN_TZ);
	hBtnKS->EnableWindow(false);
	hBtnTZ->EnableWindow(false);

	CWnd *hEditCCRS = (CWnd *)GetDlgItem(IDC_EDIT_CCRS);
	CWnd *hEditSJS = (CWnd *)GetDlgItem(IDC_EDIT_SJS);
	hEditCCRS->SetWindowText(_T("2"));
	hEditSJS->SetWindowText(_T("��ʾ�����"));


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRoll_CallDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CRoll_CallDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/*********************************��������***************************************/
void CRoll_CallDlg::OnBnClickedBtnDrmd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CWnd *hBtnKS = (CWnd *)GetDlgItem(IDC_BTN_KS);
	CWnd *hBtnTZ = (CWnd *)GetDlgItem(IDC_BTN_TZ);
	
	CFileDialog sel_DRMD(TRUE, NULL, NULL, 
		OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST,
		L"�ı��ļ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||", this);

	if (sel_DRMD.DoModal() == IDOK)
	{
		if (sel_DRMD.GetPathName() == "")
		{
			AfxMessageBox(_T("��ѡ��һ���ļ�"));

		} else {
			//AfxMessageBox(sel_DRMD.GetPathName());

			CStdioFile file_DRMD;
			BOOL is_Open = file_DRMD.Open(sel_DRMD.GetPathName(), CFile::modeRead);
			if (!is_Open)
			{
				AfxMessageBox(_T("�ļ���ʧ��"));
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
			
			hBtnKS->EnableWindow(true); //����ɹ��Ժ�Ĳ���
		}
		
	}
}

/*********************************�˳�***************************************/
void CRoll_CallDlg::OnBnClickedBtnTc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	AfxGetMainWnd()->SendMessage(WM_CLOSE);

}

/*********************************��ʼ***************************************/
void CRoll_CallDlg::OnBnClickedBtnKs()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CWnd *hBtnKS = (CWnd *)GetDlgItem(IDC_BTN_KS);
	CWnd *hBtnTZ = (CWnd *)GetDlgItem(IDC_BTN_TZ);
	hBtnKS->EnableWindow(FALSE);
	hBtnTZ->EnableWindow(TRUE);

	if (m_TimerID_SJS == 0)
	{
		//һ�Ŷ�ʱ����500ms��null��ʾʹ����Ϣ֪ͨ�ķ�ʽ
		m_TimerID_SJS = SetTimer(1, 100, NULL);
	}
	//CListBox * hListMD = (CListBox*)GetDlgItem(IDC_LST_MD);
	//int intNumMD = hListMD->GetCount();
	//int intNumCCRS = GetDlgItemInt(IDC_EDIT_CCRS);
	

}

/*********************************ֹͣ***************************************/
void CRoll_CallDlg::OnBnClickedBtnTz()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		AfxMessageBox(L"��������!");
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

/*******************************�������ʱ��*************************************/
void CRoll_CallDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int intNumSJS = rand();
	SetDlgItemInt(IDC_EDIT_SJS, intNumSJS);

	CDialogEx::OnTimer(nIDEvent);
}
