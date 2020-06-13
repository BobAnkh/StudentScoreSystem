// OperatePart.cpp : 实现文件

#include "stdafx.h"
#include "StudentScoreSystem.h"
#include "OperatePart.h"


// COperatePart

IMPLEMENT_DYNCREATE(COperatePart, CFormView)

COperatePart::COperatePart()
	: CFormView(COperatePart::IDD)
{

}

COperatePart::~COperatePart()
{
}

void COperatePart::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COperatePart, CFormView)
END_MESSAGE_MAP()


// COperatePart 诊断

#ifdef _DEBUG
void COperatePart::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void COperatePart::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


