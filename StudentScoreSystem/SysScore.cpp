// SysScore.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentScoreSystem.h"
#include "SysScore.h"
#include "MainFrm.h"
#include "head.h"

// CSysScore
extern StuInfoList sil;
IMPLEMENT_DYNCREATE(CSysScore, CFormView)

CSysScore::CSysScore()
	: CFormView(CSysScore::IDD)
	, m_search1(_T(""))
{
}

CSysScore::~CSysScore()
{
}

void CSysScore::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_search1);
}

BEGIN_MESSAGE_MAP(CSysScore, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CSysScore::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSysScore 诊断

#ifdef _DEBUG
void CSysScore::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSysScore::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

// CSysScore 消息处理程序

void CSysScore::OnBnClickedButton1()
{
	if (sil.IsEmpty())
	{
		MessageBox(TEXT("信息库中没有任何学生信息！"));
		return;
	}
	UpdateData(TRUE);
	if (m_search1.IsEmpty())
	{
		MessageBox(TEXT("输入为空！"));
		return;
	}
	else
	{
		CStringA stmp1;
		stmp1 = m_search1;
		if (sil.Search_STU(stmp1.GetBuffer(), 1) == -1)
		{
			m_search1.Empty();
			UpdateData(FALSE);
			MessageBox(TEXT("未查询到相关学生！"));
			return;
		}
		else
		{
			sil.SetTemp(sil.Search_STU(stmp1.GetBuffer(), 1));
			::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_F, (WPARAM)NM_F, (LPARAM)0);
		}
	}
}
