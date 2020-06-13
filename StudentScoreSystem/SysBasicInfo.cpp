// SysBasicInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentScoreSystem.h"
#include "SysBasicInfo.h"
#include "MainFrm.h"
#include "head.h"

// CSysBasicInfo
extern StuInfoList sil;
IMPLEMENT_DYNCREATE(CSysBasicInfo, CFormView)

CSysBasicInfo::CSysBasicInfo()
	: CFormView(CSysBasicInfo::IDD)
	, m_newname(_T(""))
	, m_newid(_T(""))
	, m_searchname(_T(""))
{

}

CSysBasicInfo::~CSysBasicInfo()
{
}

void CSysBasicInfo::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	DDX_Text(pDX, IDC_EDIT1, m_newname);
	DDX_Text(pDX, IDC_EDIT3, m_newid);
	DDX_Text(pDX, IDC_EDIT2, m_searchname);
}

BEGIN_MESSAGE_MAP(CSysBasicInfo, CFormView)
	ON_BN_CLICKED(IDC_BUTTON9, &CSysBasicInfo::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON3, &CSysBasicInfo::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON6, &CSysBasicInfo::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON10, &CSysBasicInfo::OnBnClickedButton10)
END_MESSAGE_MAP()


// CSysBasicInfo 诊断

#ifdef _DEBUG
void CSysBasicInfo::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSysBasicInfo::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSysBasicInfo 消息处理程序


void CSysBasicInfo::OnBnClickedButton9()
{
	if (sil.IsEmpty())
	{
		MessageBox(TEXT("信息库中没有任何学生信息！"));
		return;
	}
	UpdateData(TRUE);
	if (m_searchname.IsEmpty())
	{
		MessageBox(TEXT("输入为空！"));
		return;
	}
	else
	{
		CStringA stmp1;
		stmp1 = m_searchname;
		if (sil.Search_STU(stmp1.GetBuffer(), 1) == -1)
		{
			m_searchname.Empty();
			UpdateData(FALSE);
			MessageBox(TEXT("未查询到相关学生！"));
			return;
		}
		else
		{
			sil.SetTemp(sil.Search_STU(stmp1.GetBuffer(), 1));
			::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_G, (WPARAM)NM_G, (LPARAM)0);
		}
	}
}


void CSysBasicInfo::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	m_combo1.AddString(TEXT("男"));
	m_combo1.AddString(TEXT("女"));
	m_combo1.SetCurSel(0);
}

void CSysBasicInfo::OnBnClickedButton3()
{
	UpdateData(TRUE);
	if (m_newid.IsEmpty() || m_newname.IsEmpty())
	{
		MessageBox(TEXT("姓名或学号不能为空！"));
		return;
	}
	if (m_newid.SpanIncluding(TEXT("0123456789"))!=m_newid)
	{
		MessageBox(TEXT("学号需输入纯数字！"));
		return;
	}
	CStringA tmp1, tmp2, tmp3;
	tmp1 = m_newname;
	tmp2 = m_newid;
	int index = m_combo1.GetCurSel();
	//根据索引得到具体内容
	CString str;
	m_combo1.GetLBText(index, str);
	tmp3 = str;
	if (sil.Search_STU(tmp2.GetBuffer(), 1) != -1)
	{

		MessageBox(TEXT("该学生学号与已有学生学号相同，无法添加！"));
		return;
	}
	sil.AddToHead_STU(tmp1.GetBuffer(), tmp3.GetBuffer(), tmp2.GetBuffer());
	MessageBox(TEXT("添加新的学生基本信息成功！"));
	m_newid.Empty();
	m_newname.Empty();
	m_combo1.SetCurSel(0);
	UpdateData(FALSE);
}


void CSysBasicInfo::OnBnClickedButton6()
{
	m_newid.Empty();
	m_newname.Empty();
	m_combo1.SetCurSel(0);
	UpdateData(FALSE);
}


void CSysBasicInfo::OnBnClickedButton10()
{
	m_searchname.Empty();
	UpdateData(FALSE);
}
