#include"Panels.h"
#include "Terms.h"
#include "Buttons.h"
#include<graphics.h>

#define classesPnlTitle "Class QSList"
#define widthClassesPnl 400
#define heightClassesPnl 400
#define xStudentsPnl widthClassesPnl+5
#define heightStudentsPnl 400

void showPnl(Panel pnl){
	setcolor(pnl.color);
	rectangle(pnl.x,pnl.y,pnl.x+pnl.width, pnl.y+pnl.height);
	setfillstyle(SOLID_FILL,pnl.color);
	floodfill(pnl.x+1, pnl.y+1, pnl.color);
	setbkcolor(pnl.color);
}

//void showPnl(Panel pnl){
////	setcolor(pnlColor);
////	rectangle(0,yBtnMenuBar,widthClassesPnl,yBtnMenuBar+heightClassesPnl);
////	setfillstyle(SOLID_FILL,pnlColor);
////	floodfill(widthClassesPnl-1,yBtnMenuBar+heightClassesPnl-1,pnlColor);
//	showPnl(pnl);
//	setbkcolor(pnl.color);
////	setcolor(textColor);
////	outtextxy(pnl.x+15, pnl.y+10,pnl.text);
//}

//void showStudentsPnl(Panel pnl){
////	setcolor(pnlColor);
////	rectangle(xStudentsPnl,yBtnMenuBar,screenWidth,yBtnMenuBar+heightStudentsPnl);
////	setfillstyle(SOLID_FILL,pnlColor);
////	floodfill(screenWidth-1,yBtnMenuBar+heightStudentsPnl-1,pnlColor);
//	showPnl(pnl);
//	setbkcolor(pnl.color);
//	setcolor(textColor);
//	outtextxy(pnl.x+15, pnl.y+10,pnl.text);
//}
