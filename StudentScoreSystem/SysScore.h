#pragma once

// CSysScore ������ͼ

class CSysScore : public CFormView
{
	DECLARE_DYNCREATE(CSysScore)

protected:
	CSysScore();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CSysScore();

public:
	enum { IDD = IDD_Score };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
private:
	CString m_search1;
};


