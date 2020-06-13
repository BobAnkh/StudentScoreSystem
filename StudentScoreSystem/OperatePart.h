#pragma once
// COperatePart 窗体视图

class COperatePart : public CFormView
{
	DECLARE_DYNCREATE(COperatePart)

protected:
	COperatePart();           // 动态创建所使用的受保护的构造函数
	virtual ~COperatePart();

public:
	enum { IDD = IDD_OPERATEPART };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};