
// StudentScoreSystemView.h : CStudentScoreSystemView ��Ľӿ�
//

#pragma once
class CStudentScoreSystemView : public CView
{
protected: // �������л�����
	CStudentScoreSystemView();
	DECLARE_DYNCREATE(CStudentScoreSystemView)

// ����
public:
	CStudentScoreSystemDoc* GetDocument() const;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CStudentScoreSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // StudentScoreSystemView.cpp �еĵ��԰汾
inline CStudentScoreSystemDoc* CStudentScoreSystemView::GetDocument() const
   { return reinterpret_cast<CStudentScoreSystemDoc*>(m_pDocument); }
#endif

