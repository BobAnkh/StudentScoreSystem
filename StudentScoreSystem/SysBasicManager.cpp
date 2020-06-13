// SysBasicManager.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentScoreSystem.h"
#include "SysBasicManager.h"
#include "MainFrm.h"
#include "head.h"

// CSysBasicManager
extern StuInfoList sil;
IMPLEMENT_DYNCREATE(CSysBasicManager, CFormView)

CSysBasicManager::CSysBasicManager()
	: CFormView(CSysBasicManager::IDD)
	, m_showname(_T(""))
	, m_showid(_T(""))
	, m_showgender(_T(""))
	, m_changename(_T(""))
	, m_changeid(_T(""))
{
}

CSysBasicManager::~CSysBasicManager()
{
}

void CSysBasicManager::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO2, m_combo2);
	DDX_Text(pDX, IDC_EDIT1, m_showname);
	DDX_Text(pDX, IDC_EDIT3, m_showid);
	DDX_Text(pDX, IDC_EDIT5, m_showgender);
	DDX_Text(pDX, IDC_EDIT6, m_changename);
	DDX_Text(pDX, IDC_EDIT4, m_changeid);
}

BEGIN_MESSAGE_MAP(CSysBasicManager, CFormView)
	ON_BN_CLICKED(IDC_BUTTON6, &CSysBasicManager::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON5, &CSysBasicManager::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &CSysBasicManager::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CSysBasicManager::OnBnClickedButton3)
END_MESSAGE_MAP()


// CSysBasicManager ���

#ifdef _DEBUG
void CSysBasicManager::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSysBasicManager::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

// CSysBasicManager ��Ϣ�������

void CSysBasicManager::OnBnClickedButton6()
{
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
}


void CSysBasicManager::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	m_showname = CString(sil.FindNode(sil.ShowTemp())->ShowName());
	m_showid = CString(sil.FindNode(sil.ShowTemp())->ShowStuID());
	m_showgender = CString(sil.FindNode(sil.ShowTemp())->ShowGender());
	m_combo2.AddString(TEXT("��"));
	m_combo2.AddString(TEXT("Ů"));
	m_combo2.SetCurSel(0);
	UpdateData(FALSE);
	
}


void CSysBasicManager::OnBnClickedButton5()
{
	sil.Delete_STU(sil.ShowTemp());
	m_showname.Empty();
	m_showid.Empty();
	m_showgender.Empty();
	m_changename.Empty();
	m_changeid.Empty();
	m_combo2.SetCurSel(0);
	UpdateData(FALSE);
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
	MessageBox(TEXT("��ɾ����ѧ��ȫ����Ϣ��"));
}


void CSysBasicManager::OnBnClickedButton4()
{
	m_changename.Empty();
	m_changeid.Empty();
	m_combo2.SetCurSel(0);
	UpdateData(FALSE);
}


void CSysBasicManager::OnBnClickedButton3()
{
	UpdateData(TRUE);
	if (m_changeid.IsEmpty() || m_changename.IsEmpty())
	{
		MessageBox(TEXT("������ѧ�Ų���Ϊ�գ�"));
		return;
	}
	if (m_changeid.SpanIncluding(TEXT("0123456789")) != m_changeid)
	{
		MessageBox(TEXT("ѧ�������봿���֣�"));
		return;
	}
	CStringA tmp1, tmp2, tmp3;
	tmp1 = m_changename;
	tmp2 = m_changeid;
	if ((sil.Search_STU(tmp2.GetBuffer(), 1) != -1) && (sil.Search_STU(tmp2.GetBuffer(), 1) != sil.ShowTemp()))
	{

		MessageBox(TEXT("��ѧ��ѧ������������ѧ��ѧ����ͬ���޷��޸ģ�"));
		return;
	}
	int index = m_combo2.GetCurSel();
	CString str;
	m_combo2.GetLBText(index, str);
	tmp3 = str;
	sil.FindNode(sil.ShowTemp())->SetBasicInfo(tmp1.GetBuffer(), tmp3.GetBuffer(), tmp2.GetBuffer());
	m_showname = CString(sil.FindNode(sil.ShowTemp())->ShowName());
	m_showid = CString(sil.FindNode(sil.ShowTemp())->ShowStuID());
	m_showgender = CString(sil.FindNode(sil.ShowTemp())->ShowGender());
	m_changeid.Empty();
	m_changename.Empty();
	m_combo2.SetCurSel(0);
	UpdateData(FALSE);
	MessageBox(TEXT("�޸�ѧ��������Ϣ�ɹ���"));
}
