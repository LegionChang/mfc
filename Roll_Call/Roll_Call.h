
// Roll_Call.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CRoll_CallApp:
// �йش����ʵ�֣������ Roll_Call.cpp
//

class CRoll_CallApp : public CWinApp
{
public:
	CRoll_CallApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CRoll_CallApp theApp;