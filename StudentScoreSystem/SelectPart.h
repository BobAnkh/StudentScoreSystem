#pragma once
// CSelectPart ��ͼ

class CSelectPart : public CTreeView
{
	DECLARE_DYNCREATE(CSelectPart)

protected:
	CSelectPart();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	CTreeCtrl *m_tcl;	//���ؼ�
	CImageList m_iml;	//ͼ���б�
public:
	virtual void OnInitialUpdate();
	afx_msg void OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult);
};


