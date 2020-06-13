// SysScoreManager.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentScoreSystem.h"
#include "SysScoreManager.h"
#include "MainFrm.h"
#include "head.h"

extern StuInfoList sil;
// CSysScoreManager

IMPLEMENT_DYNCREATE(CSysScoreManager, CFormView)

CSysScoreManager::CSysScoreManager()
	: CFormView(CSysScoreManager::IDD)
	, m_showname1(_T(""))
	, m_showid1(_T(""))
	, m_showgender1(_T(""))
	, m_newcoursename(_T(""))
	, m_newcredit(0)
	, m_newcoursescore(0)
	, m_newyear(0)
	, m_newmonth(0)
	, m_newday(0)
	, m_searchcourse(_T(""))
	, m_showcoursename(_T(""))
	, m_showcredit(0)
	, m_showcoursescore(0)
	, m_showpf(_T(""))
	, m_showyear(0)
	, m_showmonth(0)
	, m_showday(0)
	, m_changecoursename(_T(""))
	, m_changecredit(0)
	, m_changecoursescore(0)
	, m_changeyear(0)
	, m_changemonth(0)
	, m_changeday(0)
{

}

CSysScoreManager::~CSysScoreManager()
{
}

void CSysScoreManager::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_showname1);
	DDX_Text(pDX, IDC_EDIT3, m_showid1);
	DDX_Text(pDX, IDC_EDIT6, m_showgender1);
	DDX_Control(pDX, IDC_COMBO2, m_combo3);
	DDX_Text(pDX, IDC_EDIT11, m_newcoursename);
	DDX_Text(pDX, IDC_EDIT9, m_newcredit);
	DDX_Text(pDX, IDC_EDIT10, m_newcoursescore);
	DDX_Text(pDX, IDC_EDIT2, m_newyear);
	DDX_Text(pDX, IDC_EDIT7, m_newmonth);
	DDX_Text(pDX, IDC_EDIT8, m_newday);
	DDX_Text(pDX, IDC_EDIT19, m_searchcourse);
	DDX_Text(pDX, IDC_EDIT17, m_showcoursename);
	DDX_Text(pDX, IDC_EDIT15, m_showcredit);
	DDX_Text(pDX, IDC_EDIT16, m_showcoursescore);
	DDX_Text(pDX, IDC_EDIT18, m_showpf);
	DDX_Text(pDX, IDC_EDIT12, m_showyear);
	DDX_Text(pDX, IDC_EDIT13, m_showmonth);
	DDX_Text(pDX, IDC_EDIT14, m_showday);
	DDX_Text(pDX, IDC_EDIT25, m_changecoursename);
	DDX_Text(pDX, IDC_EDIT23, m_changecredit);
	DDX_Text(pDX, IDC_EDIT24, m_changecoursescore);
	DDX_Control(pDX, IDC_COMBO3, m_combo4);
	DDX_Text(pDX, IDC_EDIT20, m_changeyear);
	DDX_Text(pDX, IDC_EDIT21, m_changemonth);
	DDX_Text(pDX, IDC_EDIT22, m_changeday);
}

BEGIN_MESSAGE_MAP(CSysScoreManager, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CSysScoreManager::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON6, &CSysScoreManager::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON5, &CSysScoreManager::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON12, &CSysScoreManager::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CSysScoreManager::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON11, &CSysScoreManager::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON7, &CSysScoreManager::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CSysScoreManager::OnBnClickedButton8)
END_MESSAGE_MAP()


// CSysScoreManager ���

#ifdef _DEBUG
void CSysScoreManager::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSysScoreManager::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

// CSysScoreManager ��Ϣ�������

void CSysScoreManager::OnBnClickedButton1()
{
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
}


void CSysScoreManager::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	m_showname1 = CString(sil.FindNode(sil.ShowTemp())->ShowName());
	m_showid1 = CString(sil.FindNode(sil.ShowTemp())->ShowStuID());
	m_showgender1 = CString(sil.FindNode(sil.ShowTemp())->ShowGender());
	m_showcoursename.Empty();
	m_combo3.AddString(TEXT("��"));
	m_combo3.AddString(TEXT("��"));
	m_combo3.SetCurSel(0);
	m_newday = 1;
	m_newmonth = 1;
	m_newyear = 2019;
	m_combo4.AddString(TEXT("��"));
	m_combo4.AddString(TEXT("��"));
	m_combo4.SetCurSel(0);
	m_changeday = 1;
	m_changemonth = 1;
	m_changeyear = 2019;
	m_showday = 1;
	m_showmonth = 1;
	m_showyear = 2019;
	UpdateData(FALSE);
}


void CSysScoreManager::OnBnClickedButton6()
{
	m_newcoursename.Empty();
	m_newcoursescore = 0;
	m_newcredit = 0;
	m_newday = 1;
	m_newmonth = 1;
	m_newyear = 2019;
	m_combo3.SetCurSel(0);
	UpdateData(FALSE);
}


void CSysScoreManager::OnBnClickedButton5()
{
	UpdateData(TRUE);
	if (m_newcoursename.IsEmpty())
	{
		MessageBox(TEXT("�γ���Ϊ�գ�"));
		return;
	}
	if (m_newcredit < 1)
	{
		MessageBox(TEXT("ѧ������Ϊ���ڵ���1��������"));
		return;
	}
	if (m_newcoursescore < 0||m_newcoursescore>100)
	{
		MessageBox(TEXT("�ɼ���Ϊ0��100���������"));
		return;
	}
	if (m_newyear < 1)
	{
		MessageBox(TEXT("����������"));
		return;
	}
	if (m_newmonth < 1||m_newmonth>12)
	{
		MessageBox(TEXT("�·��������"));
		return;
	}
	if (daywrong(m_newyear, m_newmonth, m_newday))
	{
		MessageBox(TEXT("�����������"));
		return;
	}
	CStringA ntmp;
	ntmp = m_newcoursename;
	int index = m_combo3.GetCurSel();
	CString str;
	m_combo3.GetLBText(index, str);
	if (sil.FindNode(sil.ShowTemp())->SearchScore(ntmp.GetBuffer(),1)!=-1)
	{
		MessageBox(TEXT("�ÿγ��������пγ�����ͬ���޷���ӣ�"));
		return;
	}
	if (str == TEXT("��"))
	{
		sil.FindNode(sil.ShowTemp())->AddScore(ntmp.GetBuffer(), m_newcoursescore, m_newcredit, m_newyear, m_newmonth, m_newday, 0);
	}
	else
	{
		sil.FindNode(sil.ShowTemp())->AddScore(ntmp.GetBuffer(), m_newcoursescore, m_newcredit, m_newyear, m_newmonth, m_newday, 1);
	}
	m_newcoursename.Empty();
	m_newcoursescore = 0;
	m_newcredit = 0;
	m_newday = 1;
	m_newmonth = 1;
	m_newyear = 2019;
	m_combo3.SetCurSel(0);
	UpdateData(FALSE);
	MessageBox(TEXT("�³ɼ���ӳɹ���"));
}


void CSysScoreManager::OnBnClickedButton12()
{
	m_searchcourse.Empty();
	m_showcoursename.Empty();
	m_showcredit = 0;
	m_showcoursescore = 0;
	m_showpf.Empty();
	m_changecoursename.Empty();
	m_changecoursescore = 0;
	m_changecredit = 0;
	m_combo4.SetCurSel(0);
	m_changeday = 1;
	m_changemonth = 1;
	m_changeyear = 2019;
	m_showday = 1;
	m_showmonth = 1;
	m_showyear = 2019;
	UpdateData(FALSE);
}


void CSysScoreManager::OnBnClickedButton13()
{
	m_changecoursename.Empty();
	m_changecoursescore = 0;
	m_changecredit = 0;
	m_combo4.SetCurSel(0);
	m_changeday = 1;
	m_changemonth = 1;
	m_changeyear = 2019;
	UpdateData(FALSE);
}


void CSysScoreManager::OnBnClickedButton11()
{
	UpdateData(TRUE);
	if (sil.FindNode(sil.ShowTemp())->IsEmpty())
	{
		MessageBox(TEXT("��ѧ���ɼ�����Ϊ�գ��޷����в�ѯ��"));
		return;
	}
	if (m_searchcourse.IsEmpty())
	{
		MessageBox(TEXT("��ѯ�γ���Ϊ�գ�"));
		return;
	}
	CStringA ntmp2;
	ntmp2 = m_searchcourse;
	if (sil.FindNode(sil.ShowTemp())->SearchScore(ntmp2.GetBuffer(), 1) == -1)
	{
		MessageBox(TEXT("δ��ѯ���ÿγ̣�"));
		return;
	}
	m_showcoursename = CString(sil.FindNode(sil.ShowTemp())->SearchScore(ntmp2.GetBuffer())->ShowSubject());
	m_showcredit = sil.FindNode(sil.ShowTemp())->SearchScore(ntmp2.GetBuffer())->ShowCredit();
	m_showcoursescore = sil.FindNode(sil.ShowTemp())->SearchScore(ntmp2.GetBuffer())->ShowScore();
	m_showyear = sil.FindNode(sil.ShowTemp())->SearchScore(ntmp2.GetBuffer())->ShowYear();
	m_showmonth = sil.FindNode(sil.ShowTemp())->SearchScore(ntmp2.GetBuffer())->ShowMonth();
	m_showday = sil.FindNode(sil.ShowTemp())->SearchScore(ntmp2.GetBuffer())->ShowDay();
	if (sil.FindNode(sil.ShowTemp())->SearchScore(ntmp2.GetBuffer())->ShowPF() == 1)
	{
		m_showpf = CString("��");
	}
	else
	{
		m_showpf = CString("��");
	}
	m_searchcourse.Empty();
	UpdateData(FALSE);
}


void CSysScoreManager::OnBnClickedButton7()
{
	if (m_showcoursename.IsEmpty())
	{
		MessageBox(TEXT("���Ƚ��в�ѯ��"));
		return;
	}
	CStringA ntmp3;
	ntmp3 = m_showcoursename;
	sil.FindNode(sil.ShowTemp())->DeleteScore(ntmp3.GetBuffer());
	m_searchcourse.Empty();
	m_showcoursename.Empty();
	m_showcredit = 0;
	m_showcoursescore = 0;
	m_showpf.Empty();
	m_changecoursename.Empty();
	m_changecoursescore = 0;
	m_changecredit = 0;
	m_combo4.SetCurSel(0);
	m_changeday = 1;
	m_changemonth = 1;
	m_changeyear = 2019;
	m_showday = 1;
	m_showmonth = 1;
	m_showyear = 2019;
	UpdateData(FALSE);
	MessageBox(TEXT("ɾ���ɹ���"));
}


void CSysScoreManager::OnBnClickedButton8()
{
	UpdateData(TRUE);
	if (m_showcoursename.IsEmpty())
	{
		MessageBox(TEXT("���Ƚ��в�ѯ��"));
		return;
	}
	CStringA ntmp4;
	ntmp4 = m_showcoursename;
	
	if (m_changecoursename.IsEmpty())
	{
		MessageBox(TEXT("�γ���Ϊ�գ�"));
		return;
	}
	if (m_changecredit < 1)
	{
		MessageBox(TEXT("ѧ������Ϊ���ڵ���1��������"));
		return;
	}
	if (m_changecoursescore < 0 || m_changecoursescore>100)
	{
		MessageBox(TEXT("�ɼ���Ϊ0��100���������"));
		return;
	}
	if (m_changeyear < 1)
	{
		MessageBox(TEXT("����������"));
		return;
	}
	if (m_changemonth < 1 || m_changemonth>12)
	{
		MessageBox(TEXT("�·��������"));
		return;
	}
	if (daywrong(m_changeyear, m_changemonth, m_changeday))
	{
		MessageBox(TEXT("�����������"));
		return;
	}
	CStringA ntmp5;
	ntmp5 = m_changecoursename;
	int index = m_combo3.GetCurSel();
	CString str;
	m_combo4.GetLBText(index, str);
	if (str == TEXT("��"))
	{
		sil.FindNode(sil.ShowTemp())->SearchScore(ntmp4.GetBuffer())->SetScore(ntmp5.GetBuffer(), m_changecoursescore, m_changecredit, m_changeyear, m_changemonth, m_changeday, 0);
	}
	else
	{
		sil.FindNode(sil.ShowTemp())->SearchScore(ntmp4.GetBuffer())->SetScore(ntmp5.GetBuffer(), m_changecoursescore, m_changecredit, m_changeyear, m_changemonth, m_changeday, 1);
	}
	m_changecoursename.Empty();
	m_changecoursescore = 0;
	m_changecredit = 0;
	m_changeday = 1;
	m_changemonth = 1;
	m_changeyear = 2019;
	m_combo4.SetCurSel(0);
	m_showcoursename = CString(sil.FindNode(sil.ShowTemp())->SearchScore(ntmp5.GetBuffer())->ShowSubject());
	m_showcredit = sil.FindNode(sil.ShowTemp())->SearchScore(ntmp5.GetBuffer())->ShowCredit();
	m_showcoursescore = sil.FindNode(sil.ShowTemp())->SearchScore(ntmp5.GetBuffer())->ShowScore();
	m_showyear = sil.FindNode(sil.ShowTemp())->SearchScore(ntmp5.GetBuffer())->ShowYear();
	m_showmonth = sil.FindNode(sil.ShowTemp())->SearchScore(ntmp5.GetBuffer())->ShowMonth();
	m_showday = sil.FindNode(sil.ShowTemp())->SearchScore(ntmp5.GetBuffer())->ShowDay();
	if (sil.FindNode(sil.ShowTemp())->SearchScore(ntmp5.GetBuffer())->ShowPF() == 1)
	{
		m_showpf = CString("��");
	}
	else
	{
		m_showpf = CString("��");
	}
	m_searchcourse.Empty();
	UpdateData(FALSE);
	MessageBox(TEXT("�ɼ��޸ĳɹ���"));
}
