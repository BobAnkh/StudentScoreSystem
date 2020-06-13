#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
void score_to_grade(int a, double &b, char *s, int c);
double score_to_grade(int a);
bool daywrong(int year, int month,int day);
class AbsSystem		//�����࣬�����ӿ�
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
	int Year, Month, Day;                 //��¼�óɼ�¼���ʱ��
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
	char subject[50];   //��Ŀ����
	int score;          //�����ٷ��Ƴɼ�
	int credit;         //ѧ��
	double grade1;      //����
	char grade2[3];     //��Ӧ�ȼ�
	int pflag;          //�Ƿ��pf�ı�־,0ָ��pf
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
/*���м̳������ࣨ���������ɼ���¼��ʱ�䣩���п�Ŀ���ơ������ٷ��Ƴɼ���ѧ�֡����㡢��Ӧ�ȼ���˽�г�Ա��
������ع��졢���������á���ӡ����ֵ�ȳ�Ա��������������<>������� */
class ScoreList;
class ScoreNode : public Score
{
private:
	ScoreNode *next;
public:
	ScoreNode(char *a, int b, int c, int d, int e, int f, int pf, ScoreNode *next);
	~ScoreNode();
	bool operator > (ScoreNode &sn);	//���������
	bool operator < (ScoreNode &sn);
	friend class ScoreList;
};
class ScoreList
{
private:
	ScoreNode *head, *current;
	int TotalCourse;              //��¼�ܿ�Ŀ��
	int TotalCredit;			  //��¼��ѧ����
public:
	ScoreList();
	~ScoreList();
	int AddToHead(char *a,int b, int c, int d, int e, int f, int pf);
	int Delete(int i);
	ScoreNode *Search(char *str);	
	int Search(char *str, int i);	//������������
	void ScoreSort();				//������
	bool IsEmpty();
	int coursenumber();
	ScoreNode *Search(int num);
	int PassCredit();				//ͳ��ͨ����ѧ������
	int PassCourse();				//ͳ��ͨ���Ŀγ�����
};
class StuInfo
{
private:
	char Name[30];		//ѧ������
	char Gender[5];		//�Ա�
	char StuID[20];		//ѧ��
	int EffCredit;      //ȥ�������pf��ѧ��ʣ�µ�ѧ�֣����ڼ���ѧ�ּ�
	double EffGrade;    //ȥ�������pf����ʣ��γ̵ļ�����ѧ�ֳ˻��ͣ����ڼ���ѧ�ּ�
	ScoreList SL;
public:
	StuInfo(char stuname[], char stugender[], char stuid[]);
	~StuInfo();
	void SetBasicInfo(char stuname[], char stugender[], char stuid[]);
	void AddScore(char *a,int b, int c, int d, int e, int f, int pf);
	ScoreNode *SearchScore(char *str);
	int SearchScore(char *str, int i);
	void DeleteScore(char *str);
	double personGPA();			//���˾���
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
	int TotalNumber;	//��Ա��������ѧ��������
	double totalGPA;    //��¼�ܵ�ѧ�ּ����֮�ͣ����ڼ���ȫ��ѧ����ƽ������
	int totalCredit;    //��¼�ܵ�ѧ��֮�ͣ����ڼ���ȫ��ѧ����ƽ������
	int temp;			//Ϊ���������һ�����ڽ����л�ʱ�������Ҫ�����ĳ�Ա
public:
	StuInfoList();
	~StuInfoList();
	double averageGPA();
	int AddToHead_STU(char stuname[], char stugender[], char stuid[]);
	int Delete_STU(int i);
	StuInfoNode *Search_STU(char *str);
	int Search_STU(char *str, int i);		//������������
	bool IsEmpty();
	void SetTemp(int t);
	StuInfoNode *FindNode(int t);			//����λ�ú��ҵ���Ӧ���
	int ShowTemp();
	int showtotalnumber();
};
