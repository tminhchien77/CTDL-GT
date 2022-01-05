#ifndef TABLE_H_
#define TABLE_H_

#include <string>
#include"Question.h"
#include"Student.h"
#include"Class.h"
#include"Subject.h"

//using namespace std;

//#define xBtnMenuBar 80
//#define yBtnMenuBar 20
//#define classesBtn "Classes"
//#define subjectsBtn "Subjects"

struct Table{
	int x, y, width, height, hRow, yRow0;
//	char *text;
//	int selectedColor, unselectedColor;
	Table(int _x, int _y, int _width, int _height/*, char *_text, int _selectedColor, int _unSelectedColor*/){
		x=_x;
		y=_y;
		width=_width;
		height=_height;
		hRow=height/11;
		yRow0=y+hRow+height%11;
//		text=_text;
//		selectedColor=_selectedColor;
//		unselectedColor=_unSelectedColor;
	};
};

void showQuesTbl(Table tbl, QSList list, int selection, int page);
void showStudentTbl(Table tbl, StudentList list, int selection, int page);
void showClassTbl(Table tbl, CLASSLIST list, int selection, int page);
void showSubjectTbl(Table tbl, SUBJECTNODE **list, int lengthOfList, int selection, int page);
void showScoresOfClassTbl(Table tbl, StudentList list, string idSubj, int selection, int page);
void showDetailExam(Table tbl, QSList qList, Exam e, int selection, int page);
//void showClassesBtn(int isSelected, int location);
//void showSubjectsBtn(int isSelected, int location);
//void showBtn(Button btn, int bgColor, int isSelected, int location);
#endif //TABLE_H_
