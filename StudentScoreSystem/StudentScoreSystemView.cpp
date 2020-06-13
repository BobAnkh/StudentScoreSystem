
// StudentScoreSystemView.cpp : CStudentScoreSystemView ���ʵ��
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CStudentScoreSystemView ����/����

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

// CStudentScoreSystemView ����

void CStudentScoreSystemView::OnDraw(CDC* /*pDC*/)
{
	CStudentScoreSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
}


// CStudentScoreSystemView ��ӡ

BOOL CStudentScoreSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CStudentScoreSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CStudentScoreSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}


// CStudentScoreSystemView ���

#ifdef _DEBUG
void CStudentScoreSystemView::AssertValid() const
{
	CView::AssertValid();
}

void CStudentScoreSystemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStudentScoreSystemDoc* CStudentScoreSystemView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStudentScoreSystemDoc)));
	return (CStudentScoreSystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CStudentScoreSystemView ��Ϣ�������
