
// StudentScoreSystemView.cpp : CStudentScoreSystemView 类的实现
//

#include "stdafx.h"
#ifndef SHARED_HANDLERS
#include "StudentScoreSystem.h"
#endif

#include "StudentScoreSystemDoc.h"
#include "StudentScoreSystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStudentScoreSystemView

IMPLEMENT_DYNCREATE(CStudentScoreSystemView, CView)

BEGIN_MESSAGE_MAP(CStudentScoreSystemView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CStudentScoreSystemView 构造/析构

CStudentScoreSystemView::CStudentScoreSystemView()
{
}

CStudentScoreSystemView::~CStudentScoreSystemView()
{
}

BOOL CStudentScoreSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

// CStudentScoreSystemView 绘制

void CStudentScoreSystemView::OnDraw(CDC* /*pDC*/)
{
	CStudentScoreSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
}


// CStudentScoreSystemView 打印

BOOL CStudentScoreSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CStudentScoreSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CStudentScoreSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}


// CStudentScoreSystemView 诊断

#ifdef _DEBUG
void CStudentScoreSystemView::AssertValid() const
{
	CView::AssertValid();
}

void CStudentScoreSystemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStudentScoreSystemDoc* CStudentScoreSystemView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStudentScoreSystemDoc)));
	return (CStudentScoreSystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CStudentScoreSystemView 消息处理程序
