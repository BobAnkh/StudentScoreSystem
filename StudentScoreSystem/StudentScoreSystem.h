
// StudentScoreSystem.h : StudentScoreSystem Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������

// CStudentScoreSystemApp:
// �йش����ʵ�֣������ StudentScoreSystem.cpp
//
class CStudentScoreSystemApp : public CWinApp
{
public:
	CStudentScoreSystemApp();
// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};
extern CStudentScoreSystemApp theApp;
