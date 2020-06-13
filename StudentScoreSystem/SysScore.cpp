// SysScore.cpp : ʵ���ļ�
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


// CSysScore ���

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

// CSysScore ��Ϣ�������

void CSysScore::OnBnClickedButton1()
{
	if (sil.IsEmpty())
	{
		MessageBox(TEXT("��Ϣ����û���κ�ѧ����Ϣ��"));
		return;
	}
	UpdateData(TRUE);
	if (m_search1.IsEmpty())
	{
		MessageBox(TEXT("����Ϊ�գ�"));
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
			MessageBox(TEXT("δ��ѯ�����ѧ����"));
			return;
		}
		else
		{
			sil.SetTemp(sil.Search_STU(stmp1.GetBuffer(), 1));
			::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_F, (WPARAM)NM_F, (LPARAM)0);
		}
	}
}
