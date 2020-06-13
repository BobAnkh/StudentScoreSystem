
// StudentScoreSystemView.h : CStudentScoreSystemView 类的接口
//

#pragma once
class CStudentScoreSystemView : public CView
{
protected: // 仅从序列化创建
	CStudentScoreSystemView();
	DECLARE_DYNCREATE(CStudentScoreSystemView)

// 特性
public:
	CStudentScoreSystemDoc* GetDocument() const;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CStudentScoreSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // StudentScoreSystemView.cpp 中的调试版本
inline CStudentScoreSystemDoc* CStudentScoreSystemView::GetDocument() const
   { return reinterpret_cast<CStudentScoreSystemDoc*>(m_pDocument); }
#endif

