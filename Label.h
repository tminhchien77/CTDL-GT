#ifndef LABEL_H_
#define LABEL_H_

#include<iostream>
using namespace std;


struct Label{
//	int x, y, width, height;
	string text;
//	int color;
	Label();
//	Label(string _text);
	void show(int x, int y, string text);
}; 

//void showPnl(Panel pnl);
//void showClassesPnl(Panel pnl);
//void showStudentsPnl(Panel pnl);

#endif //LABEL_H_
