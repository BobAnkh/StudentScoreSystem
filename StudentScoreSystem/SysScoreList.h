#pragma once
#include "afxcmn.h"
// CSysScoreList 窗体视图

class CSysScoreList : public CFormView
{
	DECLARE_DYNCREATE(CSysScoreList)

protected:
	CSysScoreList();           // 动态创建所使用的受保护的构造函数
	virtual ~CSysScoreList();

public:
	enum { IDD = IDD_ScoreList };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_list1;
public:
	virtual void OnInitialUpdate();
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
private:
	CString m_listsearch;
public:
	afx_msg void OnBnClickedButton1();
private:
	CString m_showperson;
};


