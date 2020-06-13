
// MainFrm.h : CMainFrame 类的接口
//

#pragma once
//自定义消息
#define NM_A (WM_USER+10)
#define NM_B (WM_USER+11)
#define NM_C (WM_USER+12)
#define NM_D (WM_USER+13)
#define NM_E (WM_USER+14)
#define NM_F (WM_USER+15)
#define NM_G (WM_USER+16)


class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)
// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CStatusBar        m_wndStatusBar;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

private:
	CSplitterWnd m_spw;	//拆分窗口对象
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


