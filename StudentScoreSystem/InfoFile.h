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
	void ReadLogin(CString &name, CString &pwd);//读取登录信息
	void WritePwd(char* name, char* pwd);//修改密码
	void WriteInfo();					//写入数据到文件中
	void ReadInfo();					//从文件中读取数据
};

