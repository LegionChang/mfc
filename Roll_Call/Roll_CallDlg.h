
// Roll_CallDlg.h : 头文件
//

#pragma once


// CRoll_CallDlg 对话框
class CRoll_CallDlg : public CDialogEx
{
// 构造
public:
	CRoll_CallDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_ROLL_CALL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	UINT m_TimerID_SJS;

	// 生成的消息映射函数
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
