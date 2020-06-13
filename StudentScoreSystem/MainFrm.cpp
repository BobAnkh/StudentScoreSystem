
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "StudentScoreSystem.h"
#include "SelectPart.h"
#include "MainFrm.h"
#include "OperatePart.h"
#include "UserDlg.h"
#include "SysScoreManager.h"
#include "SysScore.h"
#include "SysScoreList.h"
#include "SysBasicInfo.h"
#include "SysTotal.h"
#include "SysBasicManager.h"
#include "head.h"
#include "InfoFile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
extern StuInfoList sil;
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	//ON_MESSAGE响应自定义消息
	ON_MESSAGE(NM_A,OnMyChange)
	ON_MESSAGE(NM_B, OnMyChange)
	ON_MESSAGE(NM_C, OnMyChange)
	ON_MESSAGE(NM_D, OnMyChange)
	ON_MESSAGE(NM_E, OnMyChange)
	ON_MESSAGE(NM_F, OnMyChange)
	ON_MESSAGE(NM_G, OnMyChange)

	ON_WM_CLOSE()
	ON_COMMAND(ID_32776, &CMainFrame::On32776)
	ON_COMMAND(ID_32771, &CMainFrame::On32771)
	ON_COMMAND(ID_32772, &CMainFrame::On32772)
	ON_COMMAND(ID_32773, &CMainFrame::On32773)
	ON_COMMAND(ID_32774, &CMainFrame::On32774)
	ON_COMMAND(ID_32775, &CMainFrame::On32775)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));
	//设置窗口
	MoveWindow(0, 0, 1000, 750);
	//屏幕居中
	CenterWindow();
	//修改图标
	SetClassLong(m_hWnd, GCL_HICON, (LONG)AfxGetApp()->LoadIconW(IDI_ICON4));
	//设置标题  右侧部分
	SetTitle(TEXT("学生成绩管理系统"));
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	//return CFrameWnd::OnCreateClient(lpcs, pContext);
	//拆成1行2列
	m_spw.CreateStatic(this, 1, 2);
	//左侧和右侧具体的显示内容
	m_spw.CreateView(0, 0, RUNTIME_CLASS(CSelectPart), CSize(220, 500), pContext);
	m_spw.CreateView(0, 1, RUNTIME_CLASS(COperatePart), CSize(750, 500), pContext);


	return TRUE;//代表自己拆分
}

LRESULT CMainFrame::OnMyChange(WPARAM wparam, LPARAM lparam)
{
	CCreateContext context;
	if (wparam == NM_A)
	{
		//挂载界面
		context.m_pNewViewClass = RUNTIME_CLASS(CUserDlg);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView *)m_spw.GetPane(0, 1);
		m_spw.DeleteView(0, 1);
		m_spw.CreateView(0, 1, RUNTIME_CLASS(CUserDlg), CSize(750, 500), &context);
		CUserDlg *pNewView = (CUserDlg *)m_spw.GetPane(0, 1);
		m_spw.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spw.SetActivePane(0, 1);
	}
	else if (wparam == NM_B)
	{
		context.m_pNewViewClass = RUNTIME_CLASS(CSysBasicInfo);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView *)m_spw.GetPane(0, 1);
		m_spw.DeleteView(0, 1);
		m_spw.CreateView(0, 1, RUNTIME_CLASS(CSysBasicInfo), CSize(750, 500), &context);
		CSysBasicInfo *pNewView = (CSysBasicInfo *)m_spw.GetPane(0, 1);
		m_spw.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spw.SetActivePane(0, 1);
	}
	else if (wparam == NM_C)
	{
		context.m_pNewViewClass = RUNTIME_CLASS(CSysScore);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView *)m_spw.GetPane(0, 1);
		m_spw.DeleteView(0, 1);
		m_spw.CreateView(0, 1, RUNTIME_CLASS(CSysScore), CSize(750, 500), &context);
		CSysScore *pNewView = (CSysScore *)m_spw.GetPane(0, 1);
		m_spw.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spw.SetActivePane(0, 1);
	}
	else if (wparam == NM_D)
	{
		context.m_pNewViewClass = RUNTIME_CLASS(CSysScoreList);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView *)m_spw.GetPane(0, 1);
		m_spw.DeleteView(0, 1);
		m_spw.CreateView(0, 1, RUNTIME_CLASS(CSysScoreList), CSize(750, 500), &context);
		CSysScoreList *pNewView = (CSysScoreList *)m_spw.GetPane(0, 1);
		m_spw.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spw.SetActivePane(0, 1);
	}
	else if (wparam == NM_E)
	{
		context.m_pNewViewClass = RUNTIME_CLASS(CSysTotal);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView *)m_spw.GetPane(0, 1);
		m_spw.DeleteView(0, 1);
		m_spw.CreateView(0, 1, RUNTIME_CLASS(CSysTotal), CSize(750, 500), &context);
		CSysTotal *pNewView = (CSysTotal *)m_spw.GetPane(0, 1);
		m_spw.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spw.SetActivePane(0, 1);
	}
	else if (wparam == NM_F)
	{
		context.m_pNewViewClass = RUNTIME_CLASS(CSysScoreManager);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView *)m_spw.GetPane(0, 1);
		m_spw.DeleteView(0, 1);
		m_spw.CreateView(0, 1, RUNTIME_CLASS(CSysScoreManager), CSize(750, 500), &context);
		CSysScoreManager *pNewView = (CSysScoreManager *)m_spw.GetPane(0, 1);
		m_spw.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spw.SetActivePane(0, 1);
	}
	else if (wparam == NM_G)
	{
		context.m_pNewViewClass = RUNTIME_CLASS(CSysBasicManager);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView *)m_spw.GetPane(0, 1);
		m_spw.DeleteView(0, 1);
		m_spw.CreateView(0, 1, RUNTIME_CLASS(CSysBasicManager), CSize(750, 500), &context);
		CSysBasicManager *pNewView = (CSysBasicManager *)m_spw.GetPane(0, 1);
		m_spw.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spw.SetActivePane(0, 1);
	}

	return 0;
}


void CMainFrame::OnClose()
{
	CInfoFile fps;
	fps.WriteInfo();
	CFrameWnd::OnClose();
}

//以下都是与菜单栏的各项功能相关的函数
//退出
void CMainFrame::On32776()
{
	CInfoFile fps;
	fps.WriteInfo();
	exit(0);
}

//切换界面
void CMainFrame::On32771()
{
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);
}


void CMainFrame::On32772()
{
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
}


void CMainFrame::On32773()
{
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
}


void CMainFrame::On32774()
{
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
}


void CMainFrame::On32775()
{
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E, (WPARAM)NM_E, (LPARAM)0);
}
