
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once
//�Զ�����Ϣ
#define NM_A (WM_USER+10)
#define NM_B (WM_USER+11)
#define NM_C (WM_USER+12)
#define NM_D (WM_USER+13)
#define NM_E (WM_USER+14)
#define NM_F (WM_USER+15)
#define NM_G (WM_USER+16)


class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)
// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CStatusBar        m_wndStatusBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

private:
	CSplitterWnd m_spw;	//��ִ��ڶ���
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	afx_msg LRESULT OnMyChange(WPARAM wparam, LPARAM lparam);
public:
	afx_msg void OnClose();
	afx_msg void On32776();
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void On32773();
	afx_msg void On32774();
	afx_msg void On32775();
};


