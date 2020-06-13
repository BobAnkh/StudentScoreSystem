#pragma once
#include "afxwin.h"

// CSysBasicInfo 窗体视图

class CSysBasicInfo : public CFormView
{
	DECLARE_DYNCREATE(CSysBasicInfo)

protected:
	CSysBasicInfo();           // 动态创建所使用的受保护的构造函数
	virtual ~CSysBasicInfo();

public:
	enum { IDD = IDD_BasicInfo };
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
	afx_msg void OnBnClickedButton9();
private:
	CComboBox m_combo1;
	CString m_newname;
	CString m_newid;
public:
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton6();
	
private:
	CString m_searchname;
public:
	afx_msg void OnBnClickedButton10();
};


