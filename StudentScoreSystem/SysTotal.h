#pragma once
#include "afxcmn.h"
// CSysTotal 窗体视图

class CSysTotal : public CFormView
{
	DECLARE_DYNCREATE(CSysTotal)

protected:
	CSysTotal();           // 动态创建所使用的受保护的构造函数
	virtual ~CSysTotal();
public:
	enum { IDD = IDD_Total };
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
	CListCtrl m_tlist;
public:
	virtual void OnInitialUpdate();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
private:
	CString m_totalshow;
};


