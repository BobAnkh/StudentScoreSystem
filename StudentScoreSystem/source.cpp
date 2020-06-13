#include "stdafx.h"
#include "head.h"

using namespace std;
void score_to_grade(int a, double &b, char *s, int c)		//原始百分制成绩到绩点和对应等级的转换函数
{
	if (c == 1) {
		if (a < 60) { b = 0.0; strcpy(s, "F"); }
		else if (a < 63) { b = 1.0; strcpy(s, "D"); }
		else if (a < 67) { b = 1.3; strcpy(s, "D+"); }
		else if (a < 70) { b = 1.7; strcpy(s, "C-"); }
		else if (a < 73) { b = 2.0; strcpy(s, "C"); }
		else if (a < 77) { b = 2.3; strcpy(s, "C+"); }
		else if (a < 80) { b = 2.7; strcpy(s, "B-"); }
		else if (a < 85) { b = 3.0; strcpy(s, "B"); }
		else if (a < 90) { b = 3.3; strcpy(s, "B+"); }
		else if (a < 95) { b = 3.7; strcpy(s, "A-"); }
		else if (a < 100) { b = 4.0; strcpy(s, "A"); }
		else { b = 4.0; strcpy(s, "A"); }
	}
	else {
		if (a < 60) { b = 0.0; strcpy(s, "F"); }
		else { b = -1; strcpy(s, "P"); }
	}
}
double score_to_grade(int a)
{
	if (a < 60) return 0.0;
	else if (a < 63)   return 1.0;
	else if (a < 67)   return 1.3;
	else if (a < 70)   return 1.7;
	else if (a < 73)   return 2.0;
	else if (a < 77)   return 2.3;
	else if (a < 80)   return 2.7;
	else if (a < 85)   return 3.0;
	else if (a < 90)   return 3.3;
	else if (a < 95)   return 3.7;
	else    return 4.0;
}
bool daywrong(int year, int month,int day)			//判断日期是否正确的函数
{
	int d;
	switch (month)
	{
	case 1:;
	case 3:;
	case 5:;
	case 7:;
	case 8:;
	case 10:;
	case 12: d = 31; break;
	case 4:;
	case 6:;
	case 9:;
	case 11:d = 30; break;
	case 2:{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) d = 29;
		else d = 28;
	}break;
	}
	if (day<1 || day>d)	return TRUE;
	else return FALSE;
}

Date::Date(int a, int b, int c)       //把数据合理性检查放在输入该数据的地方了
{
	Year = a;
	Month = b;
	Day = c;
}
Date::~Date() {};
void Date::SetDate(int a, int b, int c)
{
	Year = a;
	Month = b;
	Day = c;
}
int Date::ShowDay()
{
	return Day;
}
int Date::ShowMonth()
{
	return Month;
}
int Date::ShowYear()
{
	return Year;
}

Score::Score(char *a,int b, int c, int d, int e, int f, int pf) :Date(d, e, f)        //把数据合理性检查放在输入该数据的地方了
{
	strcpy(subject, a);
	score = b;
	credit = c;
	pflag = pf;
	score_to_grade(b, grade1, grade2, pf);
}
Score::~Score() {};
void Score::SetScore(char *a, int b, int c, int d, int e, int f, int pf)
{
	Date::SetDate(d, e, f);
	strcpy(subject, a);
	score = b;
	credit = c;
	pflag = pf;
	score_to_grade(b, grade1, grade2, pf);
}
char *Score::ShowSubject()
{
	return subject;
}
int Score::ShowCredit()
{
	return credit;
}
double Score::ShowGrade1()
{
	return grade1;
}
int Score::ShowPF()
{
	return pflag;
}
int Score::ShowScore()
{
	return score;
}
char *Score::ShowGrade2()
{
	return grade2;
}

ScoreNode::ScoreNode(char *a,int b, int c, int d, int e, int f, int pf, ScoreNode *next) :Score(a, b, c, d, e, f, pf)
{
	this->next = next;
}
ScoreNode::~ScoreNode() {};
bool ScoreNode::operator > (ScoreNode &sn)
{
	if (this->ShowYear() != sn.ShowYear())
		return(this->ShowYear() > sn.ShowYear());
	else
	{
		if (this->ShowMonth() != sn.ShowMonth())
			return(this->ShowMonth() > sn.ShowMonth());
		else
		{
			if (this->ShowDay() != sn.ShowDay())
				return(this->ShowDay() > sn.ShowDay());
			else
			{
				if (strcmp(this->ShowSubject(), sn.ShowSubject()) >= 0) return true;
				else return false;
			}
		}
	}
}
bool ScoreNode::operator < (ScoreNode &sn)
{
	if (this->ShowYear() != sn.ShowYear())
		return(this->ShowYear() < sn.ShowYear());
	else
	{
		if (this->ShowMonth() != sn.ShowMonth())
			return(this->ShowMonth() < sn.ShowMonth());
		else
		{
			if (this->ShowDay() != sn.ShowDay())
				return(this->ShowDay() < sn.ShowDay());
			else
			{
				if (strcmp(this->ShowSubject(), sn.ShowSubject()) < 0) return true;
				else return false;
			}
		}
	}
}


ScoreList::ScoreList()
{
	head = current = NULL;
	this->TotalCourse = 0;
	this->TotalCredit = 0;
}
ScoreList::~ScoreList(){};
int ScoreList::AddToHead(char *a,  int b, int c, int d, int e, int f, int pf)
{
	ScoreNode *p = current;
	current = head;
	ScoreNode *newSN = new ScoreNode(a, b, c, d, e, f, pf, NULL);
	newSN->next = head;
	head = current = newSN;
	this->TotalCourse += 1;
	this->TotalCredit += c;
	return 1;
}
int ScoreList::Delete(int i)
{
	ScoreNode *p, *q;
	if (i == 0) {
		q = head;
		current = head = head->next;
	}
	else {
		p = current;
		current = head;
		for (int m = 0; m < i - 1; m++)
		{
			if (current == NULL)break;
			else current = current->next;
		}
		if (current == NULL || current->next == NULL)
		{
			current = p;
			return 0;
		}
		else
		{
			q = current->next;
			current = current->next = q->next;
		}
	}
	this->TotalCourse -= 1;
	this->TotalCredit -= q->ShowCredit();
	delete q;
	return 1;
}
ScoreNode *ScoreList::Search(char *str)
{
	ScoreNode *p = head;
	if (p == NULL)
	{
		return NULL;
	}
	else
	{
		while (p!= NULL)
		{
			if (strcmp(str, p->ShowSubject()) == 0) return p;
			p = p->next;
		}
		return NULL;
	}
}
int ScoreList::Search(char *str, int i)     //多加一个参数便于重载，也便于编写代码和调用
{
	ScoreNode *p = head;
	int j = 0;
	if (p == NULL)
	{
		return -1;
	}
	else
	{
		while (p!= NULL)
		{
			if (strcmp(str, p->ShowSubject()) == 0) return j; 
			j++;
			p = p->next;
		}
		return -1;
	}
}
void ScoreList::ScoreSort()    
{
	int n = this->TotalCourse;
	for (int i = 0; i < n ; i++)
	{
		ScoreNode *p = head;
		for (int k = 0; k < n-i ; k++)
		{
			if (p->next == NULL)   continue;
			if (*p > *(p->next))
			{
				char *a1 = new char[50];
				char *a2 = new char[50];
				strcpy(a1, p->next->ShowSubject());
				strcpy(a2, p->ShowSubject());
				int b1 = p->next->ShowScore();
				int c1 = p->next->ShowCredit();
				int d1 = p->next->ShowYear();
				int e1 = p->next->ShowMonth();
				int f1 = p->next->ShowDay();
				int pf1 = p->next->ShowPF();
				int b2 = p->ShowScore();
				int c2 = p->ShowCredit();
				int d2 = p->ShowYear();
				int e2 = p->ShowMonth();
				int f2 = p->ShowDay();
				int pf2 = p->ShowPF();
				p->SetScore(a1, b1, c1, d1, e1, f1, pf1);
				(p->next)->SetScore(a2, b2, c2, d2, e2, f2, pf2);
				delete[]a1;
				delete[]a2;
			}
			p = p->next;
		}
	}
}
bool ScoreList::IsEmpty()	
{
	if (head == NULL) return TRUE;
	else return FALSE;
}
int ScoreList::coursenumber()
{
	return this->TotalCourse;
}
ScoreNode *ScoreList::Search(int num)
{
	ScoreNode *p = head;
	for (int i = 0; i < num; i++)
		p = p->next;
	return p;
}
int ScoreList::PassCredit()
{
	ScoreNode *p = head;
	int pc=0;
	for (int i = 0; i < TotalCourse; i++)
	{ 
		if (p->ShowScore() >= 60)	pc += p->ShowCredit();
		p = p->next;
	}
	return pc;
}
int ScoreList::PassCourse()
{
	ScoreNode *p = head;
	int pc = 0;
	for (int i = 0; i < TotalCourse; i++)
	{
		if (p->ShowScore() >= 60)	pc += 1;
		p = p->next;
	}
	return pc;
}

StuInfo::StuInfo(char stuname[], char stugender[], char stuid[])
{
	strcpy(Name, stuname);
	strcpy(Gender, stugender);
	strcpy(StuID, stuid);
	EffCredit = 0;
	EffGrade = 0;
}
StuInfo::~StuInfo() {};
void StuInfo::SetBasicInfo(char stuname[], char stugender[], char stuid[])
{
	strcpy(Name, stuname);
	strcpy(Gender, stugender);
	strcpy(StuID, stuid);
}
void StuInfo::AddScore(char *a, int b, int c, int d, int e, int f, int pf)
{
	SL.AddToHead(a, b, c, d, e, f, pf);
	if (pf == 0)
	{
		if (b < 60)
		{
			EffCredit += c;
			EffGrade += c * score_to_grade(b);
		}
	}
	else
	{
		EffCredit += c;
		EffGrade += c * score_to_grade(b);
	}
}
ScoreNode *StuInfo::SearchScore(char *str)
{
	return SL.Search(str);
}
int StuInfo::SearchScore(char *str, int i)
{
	return SL.Search(str,1);
}
void StuInfo::DeleteScore(char *str)
{
	int i = SL.Search(str, 0);
	ScoreNode *tmp = SL.Search(str);
	int c = tmp->ShowCredit();
	int b = tmp->ShowScore();
	int pf = tmp->ShowPF();
	if (pf == 0)
	{
		if (b < 60)
		{
			EffCredit -= c;
			EffGrade -= c * score_to_grade(b);
		}
	}
	else
	{
		EffCredit -= c;
		EffGrade -= c * score_to_grade(b);
	}
	SL.Delete(i);
}
double StuInfo::personGPA()
{
	if (this->EffCredit == 0) return -1;
	else return this->EffGrade / this->EffCredit;
}
double StuInfo::ShowEffGrade()
{
	return this->EffGrade;
}
int StuInfo::ShowEffCredit()
{
	return this->EffCredit;
}
char * StuInfo::ShowName()
{
	return this->Name;
}
char * StuInfo::ShowStuID()
{
	return this->StuID;
}
char * StuInfo::ShowGender()
{
	return this->Gender;
}
bool StuInfo::IsEmpty()
{
	return SL.IsEmpty();
}
ScoreList StuInfo::showscorelist()
{
	return this->SL;
}

StuInfoNode::StuInfoNode(char stuname[], char stugender[], char stuid[], StuInfoNode *next) :StuInfo(stuname, stugender, stuid)
{
	this->next = next;
}
StuInfoNode::~StuInfoNode() {};

StuInfoList::StuInfoList()
{
	head = current = NULL;
	TotalNumber = 0;
	totalGPA = 0;
	totalCredit = 0;
}
StuInfoList::~StuInfoList() {};
double StuInfoList::averageGPA()  
{
	StuInfoNode *p = head;
	if (p == NULL) return 0;
	else
	{
		totalCredit = 0;
		totalGPA = 0;
		while (p != NULL)
		{
			if (p->ShowEffCredit() == 0);
			else
			{
				totalGPA += p->ShowEffGrade();
				totalCredit += p->ShowEffCredit();
			}
			p = p->next;
		}
		if (totalCredit == 0)	return -1;
		else 	return  totalGPA / totalCredit;
	}
}
int StuInfoList::AddToHead_STU(char stuname[], char stugender[], char stuid[])
{
	StuInfoNode *p = current;
	current = head;
	StuInfoNode *newSN = new StuInfoNode(stuname, stugender, stuid, NULL);
	newSN->next = head;
	head = current = newSN;
	this->TotalNumber += 1;
	return 1;
}
int StuInfoList::Delete_STU(int i)
{
	StuInfoNode *p, *q;
	if (i == 0) {
		q = head;
		current = head = head->next;
	}
	else {
		p = current;
		current = head;
		for (int m = 0; m < i - 1; m++)
		{
			if (current == NULL)break;
			else current = current->next;
		}
		if (current == NULL || current->next == NULL)
		{
			current = p;
			return 0;
		}
		else
		{
			q = current->next;
			current = current->next = q->next;
		}
	}
	this->TotalNumber -= 1;
	delete q;
	return 1;
}
StuInfoNode *StuInfoList::Search_STU(char *str)      //这里输入学号或者姓名查询均可
{
	StuInfoNode *p = head;
	if (p == NULL)
	{
		return NULL;
	}
	else
	{
		while (p!= NULL)
		{
			if ((strcmp(str, p->ShowName()) == 0) || (strcmp(str, p->ShowStuID()) == 0)) return p;
			p = p->next;
		}
		return NULL;
	}
}
int StuInfoList::Search_STU(char *str, int i)
{
	StuInfoNode *p = head;
	int k = 0;
	if (p == NULL)
	{
		return -1;
	}
	else
	{
		while (p!= NULL)
		{
			if ((strcmp(str, p->ShowName()) == 0) || (strcmp(str, p->ShowStuID()) == 0)) return k;   
			k++;
			p = p->next;
		}
		return -1;
	}
}
bool StuInfoList::IsEmpty()		
{
	if (head == NULL) return TRUE;
	else return FALSE;
}
void StuInfoList::SetTemp(int t)
{
	temp = t;
}
StuInfoNode *StuInfoList::FindNode(int t)
{
	StuInfoNode *q = head;
	for (int k = 0; k < t; k++)
	{
		q = q->next;
	}
	return q;
}
int StuInfoList::ShowTemp()
{
	return temp;
}
int StuInfoList::showtotalnumber()
{
	return this->TotalNumber;
}
StuInfoList sil;		//创建外部对象