
// Roll_CallDlg.h : ͷ�ļ�
//

#pragma once


// CRoll_CallDlg �Ի���
class CRoll_CallDlg : public CDialogEx
{
// ����
public:
	CRoll_CallDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ROLL_CALL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	UINT m_TimerID_SJS;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnDrmd();
	afx_msg void OnBnClickedBtnTc();
	afx_msg void OnBnClickedBtnKs();
	afx_msg void OnBnClickedBtnTz();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
