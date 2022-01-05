#ifndef BUTTONS_H_
#define BUTTONS_H_

#include <string>
#include "Terms.h"
#include "Question.h"
#include "Exam.h"
using namespace std;

#define xBtnMenuBar 80
#define yBtnMenuBar 20
//#define classesBtn "Classes"
//#define subjectsBtn "Subjects"

struct Button{
	int x, y, width, height;
	string text;
	int selectedColor, unselectedColor;
	bool isSelected;
	Button();
	Button(int _x, int _y, int _width, int _height, int _unSelectedColor, int _selectedColor);
	Button(int _x, int _y, int _width, int _height, string _text, int _unSelectedColor, int _selectedColor, bool _isSelected){
		x=_x;
		y=_y;
		width=_width;
		height=_height;
		text=_text;
		selectedColor=_selectedColor;
		unselectedColor=_unSelectedColor;
		isSelected=_isSelected;
	};
	void show();
	
} ;
struct ButtonList{
	int x, y, width, height, btnWidth, btnHeight;
	ButtonList();
	ButtonList(int _x, int _y, int lengthList, int _btnWidth, int _btnHeight);
	ButtonList(int _y, int xPnl,int widthPnl, int lengthList, int _btnWidth, int _btnHeight);
	show(int lengthList, int page);
	showQuesBtnList(int lengthList, int curQues, Question *exam, Answers *answerList, bool isFinish);
};
void showGroupBtn(Button &btnA, Button &btnB, Button &btnC, Button &btnD, int curQues, Question *exam, Answers *answerList, bool isFinish);
void showGroupSexesBtn(Button &mBtn, Button &fmBtm, int sex);
#endif //BUTTONS_H_
