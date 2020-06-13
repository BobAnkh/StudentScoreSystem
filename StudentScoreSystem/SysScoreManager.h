#pragma once
#include "afxwin.h"
// CSysScoreManager 窗体视图

class CSysScoreManager : public CFormView
{
	DECLARE_DYNCREATE(CSysScoreManager)

protected:
	CSysScoreManager();           // 动态创建所使用的受保护的构造函数
	virtual ~CSysScoreManager();

public:
	enum { IDD = IDD_ScoreManager };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	virtual void OnInitialUpdate();
private:
	CString m_showname1;
	CString m_showid1;
	CString m_showgender1;
	CComboBox m_combo3;
	CString m_newcoursename;
	int m_newcredit;
	int m_newcoursescore;
	int m_newyear;
	int m_newmonth;
	int m_newday;
public:
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton5();
private:
	CString m_searchcourse;
	CString m_showcoursename;
	int m_showcredit;
	int m_showcoursescore;
	CString m_showpf;
	int m_showyear;
	int m_showmonth;
	int m_showday;
	CString m_changecoursename;
	int m_changecredit;
	int m_changecoursescore;
	CComboBox m_combo4;
	int m_changeyear;
	int m_changemonth;
	int m_changeday;
public:
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
};


