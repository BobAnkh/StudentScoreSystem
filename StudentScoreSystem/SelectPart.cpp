// SelectPart.cpp : ʵ���ļ�
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

// CSelectPart ���

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


// CSelectPart ��Ϣ�������

void CSelectPart::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	//��ʼ������ͼ
	//��ȡ���ؼ�
	m_tcl = &GetTreeCtrl();
	//׼��ͼƬ���ϲ���ӽ��
	HICON icon = AfxGetApp()->LoadIconW(IDI_ICON2);
	m_iml.Create(50, 50, ILC_COLOR32, 1, 1);
	m_iml.Add(icon);
	m_tcl->SetImageList(&m_iml, TVSIL_NORMAL);
	m_tcl->InsertItem(TEXT("�û�����"), 0, 0, NULL);
	m_tcl->InsertItem(TEXT("ѧ��������Ϣ����"), 0, 0, NULL);
	m_tcl->InsertItem(TEXT("ѧ���ɼ�����"), 0, 0, NULL);
	m_tcl->InsertItem(TEXT("ѧ���ɼ�����ӡ"), 0, 0, NULL);
	m_tcl->InsertItem(TEXT("������Ϣͳ�����"), 0, 0, NULL);
}


void CSelectPart::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	*pResult = 0;
	//��ȡ��ǰѡ����
	HTREEITEM htitem = m_tcl->GetSelectedItem();
	CString temp = m_tcl->GetItemText(htitem);
	//������Ϣ
	if (temp == TEXT("�û�����"))
	{
		//���ش��ڵľ���������Զ�����Ϣ��ָ��������Ϣ��Ϣ��0
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);
	}
	else if (temp == TEXT("ѧ��������Ϣ����"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
	}
	else if (temp == TEXT("ѧ���ɼ�����"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
	}
	else if (temp == TEXT("ѧ���ɼ�����ӡ"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
	}
	else if (temp == TEXT("������Ϣͳ�����"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E, (WPARAM)NM_E, (LPARAM)0);
	}
}
