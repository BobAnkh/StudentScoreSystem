#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
void score_to_grade(int a, double &b, char *s, int c);
double score_to_grade(int a);
bool daywrong(int year, int month,int day);
class AbsSystem		//抽象类，保留接口
{
public:
	virtual double averageGPA() = 0;
	virtual int AddToHead_STU(char stuname[], char stugender[], char stuid[])=0;
	virtual int Delete_STU(int i)=0;
	virtual bool IsEmpty()=0;
	virtual void SetTemp(int t) = 0;
	virtual int ShowTemp() = 0;
	virtual int showtotalnumber() = 0;
};
class Date
{
private:
	int Year, Month, Day;                 //记录该成绩录入的时间
public:
	Date(int a, int b, int c);
	~Date();
	void SetDate(int a, int b, int c);
	int ShowDay();
	int ShowMonth();
	int ShowYear();
	//here may have a friend class studentnodelist
};
class Score : public Date
{
private:
	char subject[50];   //科目名称
	int score;          //总评百分制成绩
	int credit;         //学分
	double grade1;      //绩点
	char grade2[3];     //对应等级
	int pflag;          //是否记pf的标志,0指记pf
public:
	Score(char *a,int b, int c, int d, int e, int f, int pf);
	~Score();
	void SetScore(char *a, int b, int c, int d, int e, int f, int pf);
	char *ShowSubject();
	int ShowCredit();
	double ShowGrade1();
	int ShowPF();
	int ShowScore();
	char *ShowGrade2();
};
/*公有继承日期类（即标明本成绩的录入时间），有科目名称、总评百分制成绩、学分、绩点、对应等级等私有成员，
并有相关构造、析构、设置、打印、传值等成员函数，考虑重载<>运算符； */
class ScoreList;
class ScoreNode : public Score
{
private:
	ScoreNode *next;
public:
	ScoreNode(char *a, int b, int c, int d, int e, int f, int pf, ScoreNode *next);
	~ScoreNode();
	bool operator > (ScoreNode &sn);	//运算符重载
	bool operator < (ScoreNode &sn);
	friend class ScoreList;
};
class ScoreList
{
private:
	ScoreNode *head, *current;
	int TotalCourse;              //记录总科目数
	int TotalCredit;			  //记录总学分数
public:
	ScoreList();
	~ScoreList();
	int AddToHead(char *a,int b, int c, int d, int e, int f, int pf);
	int Delete(int i);
	ScoreNode *Search(char *str);	
	int Search(char *str, int i);	//重载搜索函数
	void ScoreSort();				//排序函数
	bool IsEmpty();
	int coursenumber();
	ScoreNode *Search(int num);
	int PassCredit();				//统计通过的学分总数
	int PassCourse();				//统计通过的课程总数
};
class StuInfo
{
private:
	char Name[30];		//学生姓名
	char Gender[5];		//性别
	char StuID[20];		//学号
	int EffCredit;      //去除及格的pf课学分剩下的学分，用于计算学分绩
	double EffGrade;    //去除及格的pf课外剩余课程的绩点与学分乘积和，用于计算学分绩
	ScoreList SL;
public:
	StuInfo(char stuname[], char stugender[], char stuid[]);
	~StuInfo();
	void SetBasicInfo(char stuname[], char stugender[], char stuid[]);
	void AddScore(char *a,int b, int c, int d, int e, int f, int pf);
	ScoreNode *SearchScore(char *str);
	int SearchScore(char *str, int i);
	void DeleteScore(char *str);
	double personGPA();			//个人均绩
	double ShowEffGrade();
	int ShowEffCredit();
	char * ShowName();
	char * ShowStuID();
	char * ShowGender();
	bool IsEmpty();
	ScoreList showscorelist();
};
class StuInfoList;
class StuInfoNode :public StuInfo
{
private:
	StuInfoNode *next;
public:
	StuInfoNode(char stuname[], char stugender[], char stuid[], StuInfoNode *next);
	~StuInfoNode();
	friend class StuInfoList;
};

class StuInfoList :public AbsSystem
{
private:
	StuInfoNode *head, *current;
	int TotalNumber;	//成员总数（即学生数量）
	double totalGPA;    //记录总的学分绩点积之和，用于计算全体学生的平均绩点
	int totalCredit;    //记录总的学分之和，用于计算全体学生的平均绩点
	int temp;			//为界面设计留一个用于界面切换时缓存的重要参数的成员
public:
	StuInfoList();
	~StuInfoList();
	double averageGPA();
	int AddToHead_STU(char stuname[], char stugender[], char stuid[]);
	int Delete_STU(int i);
	StuInfoNode *Search_STU(char *str);
	int Search_STU(char *str, int i);		//重载搜索函数
	bool IsEmpty();
	void SetTemp(int t);
	StuInfoNode *FindNode(int t);			//依据位置号找到对应结点
	int ShowTemp();
	int showtotalnumber();
};
