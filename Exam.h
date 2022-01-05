#ifndef EXAM_H_
#define EXAM_H_

#include <fstream>
#include "Terms.h"
//#include <string>

using namespace std;


struct Exam{
	string * idQuesArray;
	int length;
	void freeExam();
};
//typedef Answer* EXAM;

char getAnswerChar(Answers ans);
void readExam(ifstream &fileIn, Exam &e);
//bool writeFileInforExamOfStudent(ofstream &fileOut, int numOfQues, Exam e);
#endif //EXAM_H_
