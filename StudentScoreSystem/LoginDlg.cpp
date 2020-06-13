// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentScoreSystem.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "InfoFile.h"

// CLoginDlg �Ի���

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


// CLoginDlg ��Ϣ�������
void CLoginDlg::OnBnClickedButton1()
{
	//��¼��ť���
	UpdateData(TRUE);
	if (m_username.IsEmpty() || m_password.IsEmpty())
	{
		MessageBox(TEXT("�û��������벻��Ϊ�գ�"));
		return;
	}
	//��ȡ��ȷ��ֵ
	CInfoFile fp;
	CString crtname, crtpwd;
	fp.ReadLogin(crtname, crtpwd);

	//�ж���֤
	if (crtname == m_username)
	{
		if (crtpwd == m_password)
		{
			//�رյ�¼�Ի���
			CDialog::OnOK();
		}
		else
		{
			MessageBox(TEXT("���벻��ȷ��"));
		}
	}
	else
	{
		MessageBox(TEXT("�û�������ȷ��"));
	}
}


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//���Ĭ�ϳ�������
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
