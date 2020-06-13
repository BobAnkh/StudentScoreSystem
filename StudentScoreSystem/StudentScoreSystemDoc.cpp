
// StudentScoreSystemDoc.cpp : CStudentScoreSystemDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CStudentScoreSystemDoc ����/����

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
	//����������
	SetTitle(TEXT("�廪��ѧ"));
	return TRUE;
}

// CStudentScoreSystemDoc ���л�

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

// ����ͼ��֧��
void CStudentScoreSystemDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
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

// ������������֧��
void CStudentScoreSystemDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
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

// CStudentScoreSystemDoc ���

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


// CStudentScoreSystemDoc ����
