
// StudentScoreSystemDoc.cpp : CStudentScoreSystemDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "StudentScoreSystem.h"
#endif

#include "StudentScoreSystemDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CStudentScoreSystemDoc

IMPLEMENT_DYNCREATE(CStudentScoreSystemDoc, CDocument)

BEGIN_MESSAGE_MAP(CStudentScoreSystemDoc, CDocument)
END_MESSAGE_MAP()

// CStudentScoreSystemDoc 构造/析构

CStudentScoreSystemDoc::CStudentScoreSystemDoc()
{
}

CStudentScoreSystemDoc::~CStudentScoreSystemDoc()
{
}

BOOL CStudentScoreSystemDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	//设置左侧标题
	SetTitle(TEXT("清华大学"));
	return TRUE;
}

// CStudentScoreSystemDoc 序列化

void CStudentScoreSystemDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CStudentScoreSystemDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CStudentScoreSystemDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CStudentScoreSystemDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CStudentScoreSystemDoc 诊断

#ifdef _DEBUG
void CStudentScoreSystemDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStudentScoreSystemDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CStudentScoreSystemDoc 命令
