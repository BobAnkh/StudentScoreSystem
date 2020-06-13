#pragma once
#include "afxwin.h"
// CSysBasicManager 窗体视图

class CSysBasicManager : public CFormView
{
	DECLARE_DYNCREATE(CSysBasicManager)

protected:
	CSysBasicManager();           // 动态创建所使用的受保护的构造函数
	virtual ~CSysBasicManager();

public:
	enum { IDD = IDD_BasicInfoManager };
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
	afx_msg void OnBnClickedButton6();
private:
	CComboBox m_combo2;
public:
	virtual void OnInitialUpdate();
private:
	CString m_showname;
	CString m_showid;
	CString m_showgender;
	CString m_changename;
	CString m_changeid;
public:
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
};


