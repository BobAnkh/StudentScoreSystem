#pragma once
// CSelectPart 视图

class CSelectPart : public CTreeView
{
	DECLARE_DYNCREATE(CSelectPart)

protected:
	CSelectPart();           // 动态创建所使用的受保护的构造函数
	virtual ~CSelectPart();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
private:
	CTreeCtrl *m_tcl;	//树控件
	CImageList m_iml;	//图标列表
public:
	virtual void OnInitialUpdate();
	afx_msg void OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult);
};


