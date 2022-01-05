#ifndef Question_H
#define Question_H

#include <iostream>
#include"Terms.h"
#include <string>
//#include"Class.h"
#define MAX 200
using namespace std;

struct Question
{
	string question_code;
	string question_content;
	string question_answer_A;
	string question_answer_B;
	string question_answer_C;
	string question_answer_D;
	string question_correctAnswer;
	
	Question();
	Question(string ques, string answerA, string answerB, string answerC,  string answerD, char result);
};
struct QSList{
	int n; //so cau hoi
	Question question_QSList[MAX];  // lam sao
	
	QSList();
	int biSearchQS(string id);
};

int Full(QSList list);//ham kiem tra danh sach da day hay chua
string subjectItem();
void create_list(QSList &plist);
bool load_item(QSList &plist, string idSub);
void show_list(QSList &plist);
void show_questionList(QSList &quesList);
int add_item(QSList &plist,string t);
int show_item(QSList &plist);
int delete_item(QSList &plist);
void clear_list(QSList &plist);
bool add_QSList(QSList &pQSList, Question qst);
void writeQsFile(QSList &pQSList, string idSj);
Question * loadExam(QSList &pQSList, int numOfQues);
void Swap(int* number_1, int* number_2);
void ShuffleArray(int* arr, int n);
void editQuestion(QSList &list, int index, string content, string ansA, string ansB, string ansC, string ansD, char result);

#endif
