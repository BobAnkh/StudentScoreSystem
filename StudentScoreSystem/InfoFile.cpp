#include "stdafx.h"
#include "InfoFile.h"
#include "head.h"
extern StuInfoList sil;
CInfoFile::CInfoFile()
{
}

CInfoFile::~CInfoFile()
{
}

//读取登录信息
void CInfoFile::ReadLogin( CString &name, CString &pwd )
{
	ifstream ifs;	
	ifs.open(_F_LOGIN);

	char buf[1024] ={0};

	ifs.getline(buf, sizeof(buf));	
	name = CString(buf);	

	ifs.getline(buf, sizeof(buf));	
	pwd = CString(buf);

	ifs.close();	
}

//修改密码
void CInfoFile::WritePwd( char* name, char* pwd )
{
	ofstream ofs;	
	ofs.open(_F_LOGIN); 
	
	ofs<< name <<endl;
	ofs<< pwd <<endl;	
	
	ofs.close();
}

void CInfoFile::ReadInfo()
{
	ifstream ifs1(_F_BASIC);
	char buf[1024] = { 0 };
	ifs1.getline(buf, sizeof(buf));
	while (!ifs1.eof())	//没到文件结尾
	{
		ifs1.getline(buf, sizeof(buf));
		char nn;
		char *str = strtok(buf, "|");	//以"|"分隔
		if (str != NULL)
		{
			nn = atoi(str);
		}
		else
		{
			break;
		}
		str = strtok(NULL, "|");
		char *p1 = str;
		str = strtok(NULL, "|");
		char *p2 = str;
		str = strtok(NULL, "|");
		char *p3 = str;
		sil.AddToHead_STU(p1, p2, p3);
	}
	ifs1.close();
	ifstream ifs2(_F_REC);
	char tmp[1024] = { 0 };
	ifs2.getline(tmp, sizeof(tmp));
	while (!ifs2.eof())
	{
		ifs2.getline(tmp, sizeof(tmp));
		int mm;
		char *str = strtok(tmp, "|");	//以"|"分隔
		if (str != NULL)
		{
			mm = atoi(str);
		}
		else
		{
			break;
		}
		str = strtok(NULL, "|");
		char *pp1 = str;
		str = strtok(NULL, "|");
		char *pp2 = str;
		str = strtok(NULL, "|");
		int pp3 = atoi(str);
		str = strtok(NULL, "|");
		int pp4 = atoi(str);
		str = strtok(NULL, "|");
		int pp5 = atoi(str);
		str = strtok(NULL, "|");
		int pp6 = atoi(str);
		str = strtok(NULL, "|");
		int pp7 = atoi(str);
		str = strtok(NULL, "|");
		int pp8 = atoi(str);
		sil.Search_STU(pp1)->AddScore(pp2, pp3, pp4, pp5, pp6, pp7, pp8);
	}
	ifs2.close();
}


void CInfoFile::WriteInfo()
{
	ofstream ofs1(_F_BASIC);
	if (!sil.IsEmpty())
	{
		char *bt = "序列号|姓名|性别|学号";
		ofs1 << bt << endl;
		for (int i = 0; i < sil.showtotalnumber(); i++)
		{
			ofs1 << i << "|";
			ofs1 << sil.FindNode(i)->ShowName() << "|";
			ofs1 << sil.FindNode(i)->ShowGender() << "|";
			ofs1 << sil.FindNode(i)->ShowStuID() << endl;
		}
	}
	ofs1.close();
	ofstream ofs2(_F_REC);
	if (!sil.IsEmpty())
	{
		char *st = "序列号|学号|课程名称|百分制成绩|学分|年|月|日|pf";
		ofs2 << st << endl;
		for (int i = 0; i < sil.showtotalnumber(); i++)
		{
			if (sil.FindNode(i)->IsEmpty()) continue;
			for (int j = 0; j < sil.FindNode(i)->showscorelist().coursenumber(); j++)
			{
				ofs2 << i << j << "|";
				ofs2 << sil.FindNode(i)->ShowStuID() << "|";
				ofs2 << sil.FindNode(i)->showscorelist().Search(j)->ShowSubject() << "|";
				ofs2 << sil.FindNode(i)->showscorelist().Search(j)->ShowScore() << "|";
				ofs2 << sil.FindNode(i)->showscorelist().Search(j)->ShowCredit() << "|";
				ofs2 << sil.FindNode(i)->showscorelist().Search(j)->ShowYear() << "|";
				ofs2 << sil.FindNode(i)->showscorelist().Search(j)->ShowMonth() << "|";
				ofs2 << sil.FindNode(i)->showscorelist().Search(j)->ShowDay() << "|";
				ofs2 << sil.FindNode(i)->showscorelist().Search(j)->ShowPF()<< endl;
			}
		}
	}
	ofs2.close();
}