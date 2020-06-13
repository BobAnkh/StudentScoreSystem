// SysBasicInfo.cpp : ʵ���ļ�
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


// CSysBasicInfo ���

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


// CSysBasicInfo ��Ϣ�������


void CSysBasicInfo::OnBnClickedButton9()
{
	if (sil.IsEmpty())
	{
		MessageBox(TEXT("��Ϣ����û���κ�ѧ����Ϣ��"));
		return;
	}
	UpdateData(TRUE);
	if (m_searchname.IsEmpty())
	{
		MessageBox(TEXT("����Ϊ�գ�"));
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
			MessageBox(TEXT("δ��ѯ�����ѧ����"));
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
	m_combo1.AddString(TEXT("��"));
	m_combo1.AddString(TEXT("Ů"));
	m_combo1.SetCurSel(0);
}

void CSysBasicInfo::OnBnClickedButton3()
{
	UpdateData(TRUE);
	if (m_newid.IsEmpty() || m_newname.IsEmpty())
	{
		MessageBox(TEXT("������ѧ�Ų���Ϊ�գ�"));
		return;
	}
	if (m_newid.SpanIncluding(TEXT("0123456789"))!=m_newid)
	{
		MessageBox(TEXT("ѧ�������봿���֣�"));
		return;
	}
	CStringA tmp1, tmp2, tmp3;
	tmp1 = m_newname;
	tmp2 = m_newid;
	int index = m_combo1.GetCurSel();
	//���������õ���������
	CString str;
	m_combo1.GetLBText(index, str);
	tmp3 = str;
	if (sil.Search_STU(tmp2.GetBuffer(), 1) != -1)
	{

		MessageBox(TEXT("��ѧ��ѧ��������ѧ��ѧ����ͬ���޷���ӣ�"));
		return;
	}
	sil.AddToHead_STU(tmp1.GetBuffer(), tmp3.GetBuffer(), tmp2.GetBuffer());
	MessageBox(TEXT("����µ�ѧ��������Ϣ�ɹ���"));
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
