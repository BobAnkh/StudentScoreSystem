// UserDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentScoreSystem.h"
#include "UserDlg.h"
#include "InfoFile.h"
#include "head.h"

// CUserDlg
extern StuInfoList sil;
IMPLEMENT_DYNCREATE(CUserDlg, CFormView)

CUserDlg::CUserDlg()
	: CFormView(CUserDlg::IDD)
	, m_uname(_T(""))
	, m_newpwd(_T(""))
	, m_confpwd(_T(""))
{
}

CUserDlg::~CUserDlg()
{
}

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_uname);
	DDX_Text(pDX, IDC_EDIT3, m_newpwd);
	DDX_Text(pDX, IDC_EDIT4, m_confpwd);
}

BEGIN_MESSAGE_MAP(CUserDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CUserDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CUserDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

// CUserDlg ���

#ifdef _DEBUG
void CUserDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

// CUserDlg ��Ϣ�������

void CUserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	CInfoFile fp;
	CString f_name,f_pwd;
	fp.ReadLogin(f_name, f_pwd);
	m_uname = f_name;
	UpdateData(FALSE);
}


void CUserDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	CInfoFile fp;
	CString f_name, f_pwd;
	fp.ReadLogin(f_name, f_pwd);
	m_uname = f_name;
	if (m_newpwd.IsEmpty() || m_confpwd.IsEmpty())
	{
		MessageBox(TEXT("�µ������ȷ�����벻��Ϊ��!"));
		return;
	}
	else if (m_newpwd != m_confpwd)
	{
		MessageBox(TEXT("�µ�������ȷ�����벻һ��!"));
		return;
	}
	else if (m_newpwd == f_pwd)
	{
		MessageBox(TEXT("�µ�������������벻һ��!"));
		return;
	}
	//д�������룬��Ҫת��
	CStringA temp1,temp2;
	temp1 = f_name;
	temp2 = m_confpwd;
	fp.WritePwd(temp1.GetBuffer(), temp2.GetBuffer());
	MessageBox(TEXT("�����޸ĳɹ���"));
	//�������
	m_newpwd.Empty();
	m_confpwd.Empty();
	UpdateData(FALSE);

}


void CUserDlg::OnBnClickedButton2()
{
	m_newpwd.Empty();
	m_confpwd.Empty();
	UpdateData(FALSE);
}

