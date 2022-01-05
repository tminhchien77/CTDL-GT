#include"Panels.h"
#include "Terms.h"
#include "Dialog.h"
#include<graphics.h>
#include<iostream>
#include"InputField.h"



void showDialog(Dialog dia)
{
	int width=wDialog, height=hDialog;
	int x=(screenWidth-width)/2;
	int y=(screenHeight-height)/2;
//	setbkcolor(WHITE);
	setcolor(BLUE);
	rectangle(x+10,y+10,x+10+width, y+10+height);
	setfillstyle(SOLID_FILL,BLUE);
	floodfill(x+10+1, y+10+1, BLUE);
	
	setcolor(BLACK);
	rectangle(x+10,y+10,x+10+width, y+10+height);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(x+10+1, y+10+1, BLACK);
	
	setcolor(RED);
	int i=0;
	for(; i<5; i++)
	{
		rectangle(x+i,y+i,x+width-i, y+height-i);
	}
	
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	floodfill(x+i, y+i, RED);
	
	
	int tmp=textwidth("-- ERROR --");
	setcolor(RED);
	setbkcolor(LIGHTGRAY);
	outtextxy(x+(width-tmp)/2, y+20, "-- Thong bao --");
	outtextxy(x+(width-textwidth(&dia.mess[0]))/2, y+50, &dia.mess[0]);
//	cout<<dia.op1.text;
//	showBtn(dia.opSave, LIGHTGRAY, 0, 0);
//	showBtn(dia.opUnSave, LIGHTGRAY, 0, 0);
//	showBtn(dia.opOK, LIGHTGRAY, 0, 0);
	if(dia.opOK.text!="")	dia.opOK.show();
	if(dia.opSave.text!="")	dia.opSave.show();
	if(dia.opUnSave.text!="")	dia.opUnSave.show();
	
	
};

Dialog::Dialog(){
};


void showLoginPnl()
{
	
	setbkcolor(LIGHTGRAY);
	cleardevice();	
	setcolor(WHITE);
	rectangle(xLoginPnl,yLoginPnl+hTopBarLoginPnl,xLoginPnl+wLoginPnl,yLoginPnl+hLoginPnl);
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(xLoginPnl+1, yLoginPnl+hTopBarLoginPnl+1, WHITE);
	
	setbkcolor(WHITE);
	setcolor(BLACK);
	outtextxy(xLoginPnl+25, yLoginPnl+50, "Ten dang nhap");
	outtextxy(xLoginPnl+25, yLoginPnl+150, "Mat khau"); 
}

void showView()
{
	
//	setbkcolor(LIGHTGRAY);
//	cleardevice();	
	setcolor(BLUE);
	rectangle(xView+10,yView+10,xView+10+wView,yView+10+hView);
	setfillstyle(SOLID_FILL,BLUE);
	floodfill(xView+10+1, yView+10+1, BLUE);
	
	setcolor(DARKGRAY);
	rectangle(xView+10,yView+10,xView+10+wView,yView+10+hView);
	setfillstyle(SOLID_FILL,DARKGRAY);
	floodfill(xView+10+1, yView+10+1, DARKGRAY);
	
	setcolor(RED);
	int i=0;
	for(; i<5; i++)
	{
		rectangle(xView+i,yView+i,xView+wView-i, yView+hView-i);
	}
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(xView+i, yView+i, RED);
//	setbkcolor(WHITE);
//	setcolor(BLACK);
//	outtextxy(xLoginPnl+25, yLoginPnl+50, "Ten dang nhap");
//	outtextxy(xLoginPnl+25, yLoginPnl+150, "Mat khau"); 
//	setcolor(BLUE);
//	rectangle(x+10,y+10,x+10+width, y+10+height);
//	setfillstyle(SOLID_FILL,BLUE);
//	floodfill(x+10+1, y+10+1, BLUE);
//	
//	setcolor(BLACK);
//	rectangle(x+10,y+10,x+10+width, y+10+height);
//	setfillstyle(SOLID_FILL,BLACK);
//	floodfill(x+10+1, y+10+1, BLACK);
}
