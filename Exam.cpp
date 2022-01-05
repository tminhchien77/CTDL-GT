#include "Exam.h"
#include <iostream>

char getAnswerChar(Answers ans)
{
	char result;
	switch(ans)
	{
		case ansA:
		{
			result='A';
			break;
		}
		case ansB:
		{
			result='B';
			break;
		}
		case ansC:
		{
			result='C';
			break;
		}
		case ansD:
		{
			result='D';
			break;
		}
		
	};
	return result;
}

void readExam(ifstream &fileIn, Exam &e)
{
	cout<<"Hlllllooooo"<<endl;
//	int n;
	fileIn>>e.length;
	string tmp;
	getline(fileIn, tmp);
	e.idQuesArray=new string[e.length];
	for(int i=0; i<e.length; i++)
	{
		getline(fileIn, e.idQuesArray[i], ',');
	}
}

void Exam::freeExam()
{
	delete[] idQuesArray;
}
//bool writeFileInforExamOfStudent(ofstream &fileOut, Exam e)
//{
//	fileOut<<e.length<<endl;
//	for(int i=0; i< e.length; i++)
//	{
//		fileOut<<e.idQuesArray[i]<<",";
//	}
//	return true;
//	
//	
//}

