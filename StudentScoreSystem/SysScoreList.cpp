// SysScoreList.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentScoreSystem.h"
#include "SysScoreList.h"
#include "head.h"

// CSysScoreList
extern StuInfoList sil;
IMPLEMENT_DYNCREATE(CSysScoreList, CFormView)

CSysScoreList::CSysScoreList()
	: CFormView(CSysScoreList::IDD)
	, m_listsearch(_T(""))
	, m_showperson(_T(""))
{
}

CSysScoreList::~CSysScoreList()
{
}

void CSysScoreList::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list1);
	DDX_Text(pDX, IDC_EDIT1, m_listsearch);
	DDX_Text(pDX, IDC_EDIT3, m_showperson);
}

BEGIN_MESSAGE_MAP(CSysScoreList, CFormView)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CSysScoreList::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BUTTON1, &CSysScoreList::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSysScoreList ���

#ifdef _DEBUG
void CSysScoreList::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSysScoreList::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSysScoreList ��Ϣ�������


void CSysScoreList::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	//���÷��
	m_list1.SetExtendedStyle(m_list1.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//���ñ�ͷ
	CString column[] = { TEXT("�γ�����"), TEXT("ѧ��"), TEXT("�ٷ��Ƴɼ�"), TEXT("����"), TEXT("��Ӧ�ȼ�"),TEXT("¼��ʱ��") };
	m_list1.InsertColumn(0, column[0], LVCFMT_CENTER, 150);
	m_list1.InsertColumn(1, column[1], LVCFMT_CENTER, 80);
	m_list1.InsertColumn(2, column[2], LVCFMT_CENTER, 100);
	m_list1.InsertColumn(3, column[3], LVCFMT_CENTER, 80);
	m_list1.InsertColumn(4, column[4], LVCFMT_CENTER, 80);
	m_list1.InsertColumn(5, column[5], LVCFMT_CENTER, 100);
}


void CSysScoreList::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	*pResult = 0;
}


void CSysScoreList::OnBnClickedButton1()
{
	UpdateData(TRUE);
	if (sil.IsEmpty())
	{
		MessageBox(TEXT("��Ϣ����û���κ�ѧ����Ϣ��"));
		return;
	}
	if (m_listsearch.IsEmpty())
	{
		MessageBox(TEXT("����Ϊ�գ�"));
		return;
	}
	CStringA ltmp1;
	ltmp1 = m_listsearch;
	if (sil.Search_STU(ltmp1.GetBuffer(), 1) == -1)
	{
		m_listsearch.Empty();
		UpdateData(FALSE);
		MessageBox(TEXT("δ��ѯ�����ѧ����"));
		return;
	}
	if (sil.Search_STU(ltmp1.GetBuffer()) ->IsEmpty())
	{
			m_listsearch.Empty();
			UpdateData(FALSE);
			MessageBox(TEXT("δ��ѯ����ѧ���κγɼ���"));
			return;
	}
	//��ӡ�ɼ�
	sil.Search_STU(ltmp1.GetBuffer())->showscorelist().ScoreSort();//������
	m_list1.DeleteAllItems();
	for (int num = 0; num < sil.Search_STU(ltmp1.GetBuffer())->showscorelist().coursenumber(); num++)
	{
		m_list1.InsertItem(num, CString(sil.Search_STU(ltmp1.GetBuffer())->showscorelist().Search(num)->ShowSubject()));
		CString cl1,cl2,cl3,cl5;
		cl1.Format(TEXT("%d"), sil.Search_STU(ltmp1.GetBuffer())->showscorelist().Search(num)->ShowCredit());
		cl2.Format(TEXT("%d"), sil.Search_STU(ltmp1.GetBuffer())->showscorelist().Search(num)->ShowScore());
		if (sil.Search_STU(ltmp1.GetBuffer())->showscorelist().Search(num)->ShowGrade1() == -1)
		{
			cl3.Format(TEXT("��pf"));
		}
		else
		{
			cl3.Format(TEXT("%.1f"), sil.Search_STU(ltmp1.GetBuffer())->showscorelist().Search(num)->ShowGrade1());
		}
		cl5.Format(TEXT("%d-%d-%d"), sil.Search_STU(ltmp1.GetBuffer())->showscorelist().Search(num)->ShowYear(), sil.Search_STU(ltmp1.GetBuffer())->showscorelist().Search(num)->ShowMonth(), sil.Search_STU(ltmp1.GetBuffer())->showscorelist().Search(num)->ShowDay());
		m_list1.SetItemText(num, 1, cl1);
		m_list1.SetItemText(num, 2, cl2);
		m_list1.SetItemText(num, 3, cl3);
		m_list1.SetItemText(num, 4, CString(sil.Search_STU(ltmp1.GetBuffer())->showscorelist().Search(num)->ShowGrade2()));
		m_list1.SetItemText(num, 5, cl5);
	}
	CString slt;
	if (sil.Search_STU(ltmp1.GetBuffer())->personGPA() == -1)
	{
		slt.Format(TEXT("��ѧ������%d�ſγ̣�����ͨ���γ�%d�Ź�%dѧ�֣�ƽ������ΪNULL"), sil.Search_STU(ltmp1.GetBuffer())->showscorelist().coursenumber(), sil.Search_STU(ltmp1.GetBuffer())->showscorelist().PassCourse(), sil.Search_STU(ltmp1.GetBuffer())->showscorelist().PassCredit());
	}
	else
	{
		slt.Format(TEXT("��ѧ������%d�ſγ̣�����ͨ���γ�%d�Ź�%dѧ�֣�ƽ������Ϊ%.2f"), sil.Search_STU(ltmp1.GetBuffer())->showscorelist().coursenumber(), sil.Search_STU(ltmp1.GetBuffer())->showscorelist().PassCourse(), sil.Search_STU(ltmp1.GetBuffer())->showscorelist().PassCredit(),sil.Search_STU(ltmp1.GetBuffer())->personGPA());
	}
	m_showperson = slt;
	UpdateData(FALSE);
}
