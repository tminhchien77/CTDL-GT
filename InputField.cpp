#include "InputField.h"
#include "Terms.h"
#include<graphics.h>



void showInputField(InputField inf)
{
//	cout<<inf.text;
	setcolor(BLACK);
	rectangle(inf.x, inf.y, inf.x+inf.width, inf.y+inf.height);
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(inf.x+1, inf.y+1, BLACK);
	
	string tmpTxt;
	if(textwidth(&inf.text[0])>=inf.width-10)
	{
		for(int i=inf.text.length(); i>0; i--)
		{
			tmpTxt=inf.text.substr(0,i);
			if(textwidth(&tmpTxt[0])<inf.width-10)
				break;
		}
	}
	else	tmpTxt=inf.text;
	outtextxy(inf.x+5, inf.y+(inf.height-textheight(&tmpTxt[0]))/2, &tmpTxt[0]);
//	cout<<inf.isSelected;
	if(inf.isSelected)
	{
		string tmp;
//		=inf.text+"|";
		setbkcolor(WHITE);
		if(textwidth(&inf.text[0])>=inf.width-10)
		{
			for(int i=1; i<inf.text.length(); i++)
			{
				tmp=inf.text.substr(i);
				if(textwidth(&tmp[0])<inf.width-10)
					break;
			}
			tmp+="|";
		}
		else	tmp=inf.text+"|";
		outtextxy(inf.x+5, inf.y+(inf.height-textheight(&tmp[0]))/2,  &tmp[0]);
//		cout<<textheight(&tmp[0]);
//		delete[] tmp;
	}
//	cout<<inf.text;
};

//void showSelectedInputField(InputField inf)
//{
////	cout<<inf.text;
//	setcolor(BLACK);
//	rectangle(inf.x, inf.y, inf.x+inf.width, inf.y+inf.height);
//
////		cout<<inf.isSelected;
//		outtextxy(inf.x+5, inf.y+(inf.height-textheight(inf.text))/2, inf.text);
//		outtextxy(inf.x+5+textwidth(inf.text)+2, inf.y+(inf.height-textheight(inf.text))/2, "|" );
//
//};

InputField * createInf(InputField &result, InputField &inf)
	{
//		InputField result= InputField(inf.x, inf.y, inf.width, inf.height, inf.length);
		result.x=inf.x;
		result.y=inf.y;
		result.width=inf.width;
		result.height=inf.height;
		result.length=inf.length;
//		strcpy(result.text, inf.text);
		result.text=inf.text;
		result.isSelected=true;
		
//		cout<<result.text;
//		return result;
	return &inf;
	};
	
InputField::InputField(){
};

bool InputField::isSelect(int curx, int cury)
{
	if(curx>=x && curx<x+width)
	{
		if(cury>=y && cury<y+height)
			isSelected=true;
		else
			isSelected=false;
	}
	else 
		isSelected=false;
	return isSelected;
}
