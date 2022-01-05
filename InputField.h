#ifndef INPUT_FIELD_H_
#define INPUT_FIELD_H_

#include <string>
#include"Question.h"
//using namespace std;

//#define xBtnMenuBar 80
//#define yBtnMenuBar 20
//#define classesBtn "Classes"
//#define subjectsBtn "Subjects"

struct InputField{
	int x, y, width, height;
	string text;
	int length;
	bool isSelected; 
//	int selectedColor, unselectedColor;
	InputField();
	InputField(int _x, int _y, int _width, int _height, int _length/*int _selectedColor, int _unSelectedColor*/)
	{
		x=_x;
		y=_y;
		width=_width;
		height=_height;
		text="";
		length=_length;
		isSelected=false;
	};
	bool isSelect(int curx, int cury);
};


void showInputField(InputField inf);
InputField * createInf(InputField &result, InputField &inf);
//void showSelectedInputField(InputField inf);

#endif //INPUT_FIELD_H_
