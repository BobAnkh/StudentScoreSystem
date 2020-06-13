// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentScoreSystem.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "InfoFile.h"

// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginDlg::IDD, pParent)
	, m_username(_T(""))
	, m_password(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_username);
	DDX_Text(pDX, IDC_EDIT2, m_password);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLoginDlg::OnBnClickedButton2)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序
void CLoginDlg::OnBnClickedButton1()
{
	//登录按钮点击
	UpdateData(TRUE);
	if (m_username.IsEmpty() || m_password.IsEmpty())
	{
		MessageBox(TEXT("用户名或密码不能为空！"));
		return;
	}
	//获取正确的值
	CInfoFile fp;
	CString crtname, crtpwd;
	fp.ReadLogin(crtname, crtpwd);

	//判断验证
	if (crtname == m_username)
	{
		if (crtpwd == m_password)
		{
			//关闭登录对话框
			CDialog::OnOK();
		}
		else
		{
			MessageBox(TEXT("密码不正确！"));
		}
	}
	else
	{
		MessageBox(TEXT("用户名不正确！"));
	}
}


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//添加默认出现内容
	CInfoFile fp;
	CString crtname, crtpwd;
	fp.ReadLogin(crtname, crtpwd);
	m_username = crtname;
	m_password = crtpwd;
	UpdateData(FALSE);

	return TRUE;  
}

void CLoginDlg::OnBnClickedButton2()
{
	exit(0);
}

void CLoginDlg::OnOK()
{
	//CDialogEx::OnOK();
}

void CLoginDlg::OnClose()
{
	//CDialogEx::OnClose();
	exit(0);
}
