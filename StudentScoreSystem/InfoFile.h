#pragma once
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#define _F_LOGIN "./login.ini"
#define _F_REC "./record.txt"
#define _F_BASIC "./basic.txt"
using namespace std;
class CInfoFile
{
public:
	CInfoFile();
	~CInfoFile();
	void ReadLogin(CString &name, CString &pwd);//��ȡ��¼��Ϣ
	void WritePwd(char* name, char* pwd);//�޸�����
	void WriteInfo();					//д�����ݵ��ļ���
	void ReadInfo();					//���ļ��ж�ȡ����
};

