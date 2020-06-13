// SysTotal.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentScoreSystem.h"
#include "SysTotal.h"
#include "head.h"
#include "InfoFile.h"


// CSysTotal
extern StuInfoList sil;
IMPLEMENT_DYNCREATE(CSysTotal, CFormView)

CSysTotal::CSysTotal()
	: CFormView(CSysTotal::IDD)
	, m_totalshow(_T(""))
{
}

CSysTotal::~CSysTotal()
{
}

void CSysTotal::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_tlist);
	DDX_Text(pDX, IDC_EDIT1, m_totalshow);
}

BEGIN_MESSAGE_MAP(CSysTotal, CFormView)
END_MESSAGE_MAP()

// CSysTotal 诊断

#ifdef _DEBUG
void CSysTotal::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSysTotal::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

// CSysTotal 消息处理程序

void CSysTotal::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	//设置风格
	m_tlist.SetExtendedStyle(m_tlist.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//设置表头
	CString column[] = { TEXT("姓名"), TEXT("学号"), TEXT("性别"), TEXT("均绩"), TEXT("完成学分数"), TEXT("完成课程数") };
	m_tlist.InsertColumn(0, column[0], LVCFMT_CENTER, 100);
	m_tlist.InsertColumn(1, column[1], LVCFMT_CENTER, 150);
	m_tlist.InsertColumn(2, column[2], LVCFMT_CENTER, 50);
	m_tlist.InsertColumn(3, column[3], LVCFMT_CENTER, 100);
	m_tlist.InsertColumn(4, column[4], LVCFMT_CENTER, 100);
	m_tlist.InsertColumn(5, column[5], LVCFMT_CENTER, 100);
	if (sil.IsEmpty())
	{
		MessageBox(TEXT("信息库中没有任何学生信息！"));
		return;
	}
	for (int number=0; number < sil.showtotalnumber(); number++)
	{
		m_tlist.InsertItem(number, CString(sil.FindNode(number)->ShowName()));
		m_tlist.SetItemText(number, 1, CString(sil.FindNode(number)->ShowStuID()));
		m_tlist.SetItemText(number, 2, CString(sil.FindNode(number)->ShowGender()));
		CString tl3,tl4,tl5;
		if (sil.FindNode(number)->IsEmpty())
		{
			tl3.Format(TEXT("NULL"));
			m_tlist.SetItemText(number, 3, tl3);
			tl4.Format(TEXT("NULL"));
			m_tlist.SetItemText(number, 4, tl4);
			tl5.Format(TEXT("NULL"));
			m_tlist.SetItemText(number, 5, tl5);
		}
		else
		{
			if (sil.FindNode(number)->personGPA() == -1) 
			{ 
				tl3.Format(TEXT("NULL")); 
			}
			else 	
			{ 
				tl3.Format(TEXT("%.2f"), sil.FindNode(number)->personGPA()); 
			}
			m_tlist.SetItemText(number, 3, tl3);
			tl4.Format(TEXT("%d"), sil.FindNode(number)->showscorelist().PassCredit());
			m_tlist.SetItemText(number, 4, tl4);
			tl5.Format(TEXT("%d"), sil.FindNode(number)->showscorelist().PassCourse());
			m_tlist.SetItemText(number, 5, tl5);
		}

	}
	CString ts;
	if (sil.averageGPA() == -1)
	{
		ts.Format(TEXT("学生成绩管理系统中总计有%d名学生，全体学生的平均绩点为NULL"), sil.showtotalnumber());
	}
	else
	{
		ts.Format(TEXT("学生成绩管理系统中总计有%d名学生，全体学生的平均绩点为%.2f"),sil.showtotalnumber(),sil.averageGPA());
	}
	m_totalshow = ts;
	UpdateData(FALSE);
}
