#include "Buttons.h"
#include "Terms.h"
#include<graphics.h>
#include<iostream>

void Button::show(){
	
	int textX=textwidth(&text[0]);
	int textY=textheight(&text[0]);
//	int xSubjectsBtn = location*xBtnMenuBar;
	
	
	if(isSelected)
	{
		setcolor(selectedColor);
		rectangle(x,y,x+width,y+height);
		setfillstyle(SOLID_FILL,selectedColor);
	    floodfill(x+1,y+1,selectedColor);
	    setbkcolor(selectedColor);
	    setcolor(WHITE);
			
	}
	else
	{
		setcolor(unselectedColor);
		rectangle(x,y,x+width,y+height);
		setfillstyle(SOLID_FILL,unselectedColor);
	    floodfill(x+1,y+1,unselectedColor);
	    setbkcolor(unselectedColor);
		setcolor(WHITE);
	}
	outtextxy(x+(width-textX)/2,y+(height-textY)/2,&text[0]);
//	gettextsettings(&textinfo);
};

Button::Button(){
	text="";
};

Button::Button(int _x, int _y, int _width, int _height, int _unSelectedColor, int _selectedColor)
{
	x=_x;
	y=_y;
	width=_width;
	height=_height;
	selectedColor=_selectedColor;
	unselectedColor=_unSelectedColor;
	isSelected=false;
}
ButtonList::ButtonList(){
	
}

ButtonList::ButtonList(int _y, int xPnl,int widthPnl, int lengthList, int _btnWidth, int _btnHeight){
	
	btnWidth=_btnWidth;
	btnHeight=_btnHeight;
	int pages=(lengthList%10==0) ? lengthList/10 : lengthList/10+1;
	width=btnWidth*pages;
	height=btnHeight;
//	cout<<"length"<<width<<endl;
	x=xPnl+(widthPnl-width)/2;
	y=_y;
}

ButtonList::show(int lengthList, int page){
	setbkcolor(WHITE);
	setcolor(BLACK);
	rectangle(x, y, x+height, y+btnWidth);
	char tmp[2];
	setcolor(BLACK);
	int pages=(lengthList%10==0) ? lengthList/10 : lengthList/10+1;
	
	for(int i=1; i<=pages; i++){
		
		outtextxy(x+btnWidth*(i-1)+(btnWidth-textwidth(itoa(i, tmp, 10)))/2, y+(height-textheight(itoa(i, tmp, 10)))/2, itoa(i, tmp, 10));
		line(x+btnWidth*(i-1), y, x+btnWidth*(i-1), y+height);
	}
//	if(isSelected==1)
//	{
//		setcolor(btn.selectedColor);
//		rectangle(btn.x,btn.y,btn.x+btn.width,btn.y+btn.height);
//		setfillstyle(SOLID_FILL,defUnSelectedBtnColor);
//	    floodfill(btn.x+1,btn.y+1,btn.selectedColor);
//	    setbkcolor(btn.selectedColor);
//		setcolor(textColor);	
//	}
//	setcolor(defUnSelectedBtnColor);
//	rectangle(x+page*btnSize, y, x+page*btnSize+btnSize, y+btnSize);
	setfillstyle(SOLID_FILL,defUnSelectedBtnColor);
	floodfill(x+page*btnWidth+1, y+1, BLACK);
	setbkcolor(defUnSelectedBtnColor);
	setcolor(textColor);
	outtextxy(x+btnWidth*page+(btnWidth-textwidth(itoa(page+1, tmp, 10)))/2, y+(height-textheight(itoa(page+1, tmp, 10)))/2, itoa(page+1, tmp, 10));
	setbkcolor(WHITE);
}


ButtonList::ButtonList(int _x, int _y, int lengthList, int _btnWidth, int _btnHeight){
	
	x=_x;
	y=_y;
	btnWidth=_btnWidth;
	btnHeight=_btnHeight;
	
	width= (lengthList>=10) ? btnWidth*10 : btnWidth*lengthList;
	int rows= (lengthList%10==0) ? lengthList/10 : lengthList/10+1;
	height=btnHeight*rows;
}

ButtonList::showQuesBtnList(int lengthList, int curQues, Question *exam, Answers *answerList, bool isFinish){
	setcolor(BLACK);
	
	int tmpHeight= (lengthList%10!=0) ? height-btnHeight : height;
	
	rectangle(x, y, x+width, y+tmpHeight);
	
	if(lengthList%10!=0)
	{
		rectangle(x, y+tmpHeight, x+(btnWidth*(lengthList%10)), y+tmpHeight+(height-tmpHeight));
	}
	char buff[30];
	
	setbkcolor(WHITE);
	setcolor(BLACK);
	for(int i=0; i<lengthList; i++)
	{
		int tmp=i/10;
		line(x+(btnWidth*(i%10)), y+tmp*btnHeight, x+(btnWidth*(i%10)), y+tmp*btnHeight+btnHeight);
	}
	
	if(!isFinish)
	{
		for(int i=0; i<lengthList; i++)
		{
			int tmp=i/10;
			
			if(answerList[i]==nonAns)
			{
				setbkcolor(WHITE);
				outtextxy(x+btnWidth*(i%10)+(btnWidth-textwidth(itoa(i+1, buff, 10)))/2, y+tmp*btnHeight+(btnHeight-textheight(itoa(i+1, buff, 10)))/2, itoa(i+1, buff, 10));			
			}
			else
			{
				int tmpRow=1/10;
				int tmpCol=i%10;
				setfillstyle(SOLID_FILL,YELLOW);
				floodfill(x+tmpCol*btnWidth+1, y+tmpRow*btnHeight+1, BLACK);
				setbkcolor(YELLOW);
				
				string tmpStr=strcat(itoa(i+1, buff, 10), "-   ");
				tmpStr+=getAnswerChar(answerList[i]);
				outtextxy(x+btnWidth*(i%10)+(btnWidth-textwidth(&tmpStr[0]))/2, y+tmp*btnHeight+(btnHeight-textheight(&tmpStr[0]))/2, &tmpStr[0]);
			}	
		}
	}
	else
	{
		for(int i=0; i<lengthList; i++)
		{
			int tmp=i/10;
			int tmpRow=i/10;
			int tmpCol=i%10;
			string tmpstr;
			tmpstr=getAnswerChar(answerList[i]);
			if(tmpstr==exam[i].question_correctAnswer)
			{
//				setbkcolor(WHITE);
//				outtextxy(x+btnWidth*(i%10)+(btnWidth-textwidth(itoa(i+1, buff, 10)))/2, y+tmp*btnHeight+(btnHeight-textheight(itoa(i+1, buff, 10)))/2, itoa(i+1, buff, 10));		
				setfillstyle(SOLID_FILL,GREEN);
				floodfill(x+tmpCol*btnWidth+1, y+tmpRow*btnHeight+1, BLACK);
				setbkcolor(GREEN);
				
				string tmpStr=strcat(itoa(i+1, buff, 10), "-   ");
				tmpStr+=getAnswerChar(answerList[i]);
				outtextxy(x+btnWidth*(i%10)+(btnWidth-textwidth(&tmpStr[0]))/2, y+tmp*btnHeight+(btnHeight-textheight(&tmpStr[0]))/2, &tmpStr[0]);	
			}
			else
			{
//				int tmpRow=i/10;
//				int tmpCol=i%10;
				setfillstyle(SOLID_FILL,LIGHTRED);
				floodfill(x+tmpCol*btnWidth+1, y+tmpRow*btnHeight+1, BLACK);
				setbkcolor(LIGHTRED);
				
				string tmpStr=strcat(itoa(i+1, buff, 10), "-   ");
				tmpStr+=getAnswerChar(answerList[i]);
				outtextxy(x+btnWidth*(i%10)+(btnWidth-textwidth(&tmpStr[0]))/2, y+tmp*btnHeight+(btnHeight-textheight(&tmpStr[0]))/2, &tmpStr[0]);
				setbkcolor(WHITE);
			}
				
			
		}
	
	}
	
	int tmpCurRow=curQues/10;
	int tmpCurCol=curQues%10;
	
	if(answerList[curQues]==nonAns)
	{
		setfillstyle(SOLID_FILL,defUnSelectedBtnColor);
		floodfill(x+tmpCurCol*btnWidth+1, y+tmpCurRow*btnHeight+1, BLACK);
		setbkcolor(defUnSelectedBtnColor);
		setcolor(textColor);
		outtextxy(x+btnWidth*tmpCurCol+(btnWidth-textwidth(itoa(curQues+1, buff, 10)))/2, y+tmpCurRow*btnHeight+(btnHeight-textheight(itoa(curQues+1, buff, 10)))/2, itoa(curQues+1, buff, 10));
	}
	else
	{
		setfillstyle(SOLID_FILL,defUnSelectedBtnColor);
		floodfill(x+tmpCurCol*btnWidth+1, y+tmpCurRow*btnHeight+1, BLACK);
		setbkcolor(defUnSelectedBtnColor);
		setcolor(textColor);

		string tmpStr=strcat(itoa(curQues+1, buff, 10), "-   ");
		tmpStr+=getAnswerChar(answerList[curQues]);
		outtextxy(x+btnWidth*tmpCurCol+(btnWidth-textwidth(&tmpStr[0]))/2, y+tmpCurRow*btnHeight+(btnHeight-textheight(&tmpStr[0]))/2, &tmpStr[0]);
	}
	setbkcolor(WHITE);
}

void showGroupBtn(Button &btnA, Button &btnB, Button &btnC, Button &btnD, int curQues, Question *exam, Answers *answerList, bool isFinish)
{
	if(!isFinish)
	{
		switch(answerList[curQues])
		{
			case nonAns:
			{
				btnA.isSelected=false;
				btnB.isSelected=false;
				btnC.isSelected=false;
				btnD.isSelected=false;
				break;
			}
			case ansA:
			{
				btnA.isSelected=true;
				btnB.isSelected=false;
				btnC.isSelected=false;
				btnD.isSelected=false;
				break;
			}
			case ansB:
			{
				btnA.isSelected=false;
				btnB.isSelected=true;
				btnC.isSelected=false;
				btnD.isSelected=false;
				break;
			}
			case ansC:
			{
				btnA.isSelected=false;
				btnB.isSelected=false;
				btnC.isSelected=true;
				btnD.isSelected=false;
				break;
			}
			case ansD:
			{
				btnA.isSelected=false;
				btnB.isSelected=false;
				btnC.isSelected=false;
				btnD.isSelected=true;
				break;
			}
			
		}
	}
	else
	{
		btnA.isSelected=false;
		btnB.isSelected=false;
		btnC.isSelected=false;
		btnD.isSelected=false;
		switch(answerList[curQues])
		{
			case nonAns:
			{
				break;
			}
			case ansA:
			{
				btnA.unselectedColor=RED;
				btnB.unselectedColor=defUnSelectedBtnColor;
				btnC.unselectedColor=defUnSelectedBtnColor;
				btnD.unselectedColor=defUnSelectedBtnColor;
				break;
			}
			case ansB:
			{
				btnB.unselectedColor=RED;
				btnA.unselectedColor=defUnSelectedBtnColor;
				btnC.unselectedColor=defUnSelectedBtnColor;
				btnD.unselectedColor=defUnSelectedBtnColor;
				break;
			}
			case ansC:
			{
				btnC.unselectedColor=RED;
				btnB.unselectedColor=defUnSelectedBtnColor;
				btnA.unselectedColor=defUnSelectedBtnColor;
				btnD.unselectedColor=defUnSelectedBtnColor;
				break;
			}
			case ansD:
			{
				btnD.unselectedColor=RED;
				btnB.unselectedColor=defUnSelectedBtnColor;
				btnC.unselectedColor=defUnSelectedBtnColor;
				btnA.unselectedColor=defUnSelectedBtnColor;
				break;
			}
			
		}
//		string tmpstr;
//		tmpstr=getAnswerChar(answerList[curQues]);
		switch(exam[curQues].question_correctAnswer[0])
		{
			case 'A':
			{
				btnA.unselectedColor=GREEN;
				break;
			}
			case 'B':
			{
				btnB.unselectedColor=GREEN;
				break;
			}
			case 'C':
			{
				btnC.unselectedColor=GREEN;
				break;
			}
			case 'D':
			{
				btnD.unselectedColor=GREEN;
				break;
			}
		}
	}
	
	btnA.show();
	btnB.show();
	btnC.show();
	btnD.show();
}


void showGroupSexesBtn(Button &mBtn, Button &fmBtn, int sex)
{
	if(sex==1)	
	{
		mBtn.isSelected=true;
		fmBtn.isSelected=false;
	}
	else
	{
		mBtn.isSelected=false;
		fmBtn.isSelected=true;
	}
	mBtn.show();
	fmBtn.show();
}
