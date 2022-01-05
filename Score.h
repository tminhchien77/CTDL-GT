#ifndef SCORE_H_
#define SCORE_H_

#include <fstream>
#include"Exam.h"
//#include <string>

using namespace std;

struct Score{
	string idSubject;
	float score;
	
};

struct ScoreNode{
	Score data;
	Exam exam;
	ScoreNode *pNext;
};

struct ScoreList{
	ScoreNode *pHead;
	ScoreList();
	bool addScore(ScoreNode *p);
	int searchScore(string idSubj);
	ScoreNode *searchIDSub(string idSubj);
	void freeScoreList();
};

void initializeScoreList(ScoreList &list);

ScoreNode * initializeScoreNode(Score s, Exam exam);
bool readScoreList(string id, ScoreList &list);
bool checkTested(ScoreList list, string id);

#endif //SCORE_H_
