#include "Score.h"
#include <iostream>

//using namespace std;

void initializeScoreList(ScoreList &list)
{
	list.pHead=NULL;
}

ScoreNode * initializeScoreNode(Score score, Exam exam)
{
	ScoreNode *pNode =new ScoreNode;
	if(pNode!=NULL)
	{
		pNode->data=score;
		pNode->exam=exam;
		pNode->pNext=NULL;
	}
	else
	{
		cout<<"Cap phat bo nho that bai";
	}
	return pNode;
}

ScoreList::ScoreList(){};

bool ScoreList::addScore(ScoreNode *p)
{
	if(pHead==NULL)
	{
		pHead=p;
		return false;
	} 
	else
	{
		ScoreNode *pTmp=pHead;
		while(pTmp->pNext!=NULL)
		{
			pTmp=pTmp->pNext;
		}
		pTmp->pNext=p;
		return true;
	}
}

bool readScoreList(string id, ScoreList &list)
{
	ifstream fileIn;
	string fileName=id+".txt";
	cout<<"Ten file: "<<fileName<<endl;
	fileIn.open(fileName, ios_base::in);
	list.pHead=NULL;
	int count=0;
	if(fileIn.fail())	return false;
	int c=fileIn.peek();
	while(c!=EOF)
	{
		Score s;
		getline(fileIn, s.idSubject,',');
		cout<<"ID monnn: "<<s.idSubject<<endl;
		fileIn>>s.score;
//		cout<<"Diem "<<s.score<<endl;
		Exam e;
		readExam(fileIn, e);
		ScoreNode *p=initializeScoreNode(s, e);
		list.addScore(p);
		string tmp;
		getline(fileIn, tmp);
		count++;
		c=fileIn.peek();
	}
	cout<<"So lan lap: "<<count<<endl;
	fileIn.close();
}

bool checkTested(ScoreList list, string id)
{
	ScoreNode *p=list.pHead;
	if(p==NULL)	return false;
	while(p!=NULL)
	{
		if(p->data.idSubject==id)	return true;
		p=p->pNext;
	}
	return false;
}

int ScoreList::searchScore(string idSubj)
{
	ScoreNode *p=pHead;
	if(p==NULL)	return -1;
	
	while(p!=NULL)
	{
//		cout<<"ID monNN: "<< p->data.idSubject;
		if(p->data.idSubject==idSubj)	return p->data.score;
		p=p->pNext;
	}
	return -1;
}

ScoreNode * ScoreList::searchIDSub(string idSubj)
{
	ScoreNode *p=pHead;
	if(p==NULL)	return NULL;
	
	while(p!=NULL)
	{

		if(p->data.idSubject==idSubj)	return p;
		p=p->pNext;
	}
	return NULL;
}

void ScoreList::freeScoreList()
{
	ScoreNode *p;
	while(pHead!=NULL)
	{
		p=pHead;
		pHead=pHead->pNext;
		p->exam.freeExam();
		free(p);
	}
}


