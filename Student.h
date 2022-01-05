#ifndef STUDENT_H_
#define STUDENT_H_
#include "Score.h"
#include <string>
#include <fstream>
#include"Terms.h"
#include"Question.h"
using namespace std;
struct Student{
	string id;
	string firstName;
	string lastName;
	int sex;
	string password;
	ScoreList scoreList;
	Student();
	Student(string _id, string _firstName, string _lastName, int _sex);
	void createPassWord();
	
};

struct StudentNode{
	Student data;
	StudentNode *pNext;
};

struct StudentList{
	StudentNode *pHead;
//	int n;
	StudentList();
	bool addStudent(StudentNode *p);
	int getLength();
	Student getStudent(int index);
	int searchByID(string id);
	void freeStudentList();
};

void initializeStudentList(StudentList &list);

StudentNode * initializeStudentNode(Student student);

string getNextID(StudentList list, string idClass);
void editStudent(StudentList &list, int index, string fName, string lName, int _sex);
void readStudent(Student &sv);
bool readStudentList(string idLop, StudentList &list);
//bool writeFileScoreOfClass(string id, string idSubj, float score);
bool writeFileInforExamOfStudent(string id, string idSubj, int score, int numOfQues, Question *exam);
bool writeFileStudentsOfClass(string classID, StudentList list);

#endif // STUDENT_H_
