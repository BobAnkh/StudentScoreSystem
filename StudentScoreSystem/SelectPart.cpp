// SelectPart.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentScoreSystem.h"
#include "SelectPart.h"
#include "MainFrm.h"

// CSelectPart

IMPLEMENT_DYNCREATE(CSelectPart, CTreeView)

CSelectPart::CSelectPart()
{
}

CSelectPart::~CSelectPart()
{
}

BEGIN_MESSAGE_MAP(CSelectPart, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CSelectPart::OnTvnSelchanged)
END_MESSAGE_MAP()

// CSelectPart 诊断

#ifdef _DEBUG
void CSelectPart::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectPart::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSelectPart 消息处理程序

void CSelectPart::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	//初始化树视图
	//获取树控件
	m_tcl = &GetTreeCtrl();
	//准备图片集合并添加结点
	HICON icon = AfxGetApp()->LoadIconW(IDI_ICON2);
	m_iml.Create(50, 50, ILC_COLOR32, 1, 1);
	m_iml.Add(icon);
	m_tcl->SetImageList(&m_iml, TVSIL_NORMAL);
	m_tcl->InsertItem(TEXT("用户中心"), 0, 0, NULL);
	m_tcl->InsertItem(TEXT("学生基本信息管理"), 0, 0, NULL);
	m_tcl->InsertItem(TEXT("学生成绩管理"), 0, 0, NULL);
	m_tcl->InsertItem(TEXT("学生成绩单打印"), 0, 0, NULL);
	m_tcl->InsertItem(TEXT("总体信息统计情况"), 0, 0, NULL);
}


void CSelectPart::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	*pResult = 0;
	//获取当前选中项
	HTREEITEM htitem = m_tcl->GetSelectedItem();
	CString temp = m_tcl->GetItemText(htitem);
	//发送消息
	if (temp == TEXT("用户中心"))
	{
		//返回窗口的句柄，发送自定义消息，指定附加消息信息，0
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);
	}
	else if (temp == TEXT("学生基本信息管理"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
	}
	else if (temp == TEXT("学生成绩管理"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
	}
	else if (temp == TEXT("学生成绩单打印"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
	}
	else if (temp == TEXT("总体信息统计情况"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E, (WPARAM)NM_E, (LPARAM)0);
	}
}
