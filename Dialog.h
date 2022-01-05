#ifndef DIALOG_H_
#define DIALOG_H_

#include <string>
#include "Buttons.h"
#include"Terms.h"
#include<iostream>

#define wLoginPnl 300
#define hLoginPnl 350
#define xLoginPnl (screenWidth-wLoginPnl)/2
#define yLoginPnl (screenHeight-hLoginPnl)/2
#define hTopBarLoginPnl 0


#define wView 700
#define hView 600
#define xView (screenWidth-wView)/2
#define yView (screenHeight-hView)/2

struct Dialog{
//	int x, y/*, width, height*/;
	string mess;
	Button opUnSave;
	Button opSave;
	Button opOK;
	
	Dialog();
	Dialog(/*int _x, int _y, int _width, int _height, */string _mess, string _txtOpSave = "", string _txtOpUnSave="", string _txtOpOK="")
	{
		
		mess=_mess;
		if(_txtOpSave!="" && _txtOpUnSave!="" && _txtOpOK=="")
		{
			
			opSave=Button(xDialog+45, yDialog+130, 70, 50, &_txtOpSave[0], defUnSelectedBtnColor, defSelectedBtnColor, false);
			opSave.text=&_txtOpSave[0];
//			cout<<opUnSave.text;
//			Button()
			opUnSave=Button(xDialog+280, yDialog+130, 70, 50, &_txtOpUnSave[0], defUnSelectedBtnColor, defSelectedBtnColor, false);
			opUnSave.text=&_txtOpUnSave[0];
		}
		else if(_txtOpSave=="" && _txtOpUnSave=="" && _txtOpOK!="")
		{
			opOK=Button(xDialog+(wDialog-70)/2, yDialog+130, 70, 50, &_txtOpOK[0], defUnSelectedBtnColor, defSelectedBtnColor, false);
			opOK.text=&_txtOpOK[0];
		}
	};
	
	
};
void showDialog(Dialog dia);
void showLoginPnl();
void showView();
//void showDialog();
//void showClassesBtn(int isSelected, int location);
//void showSubjectsBtn(int isSelected, int location);
//void showBtn(Button btn, int bgColor, int isSelected, int location);
#endif //DIALOG_H_
