#include"Label.h"
#include<graphics.h>

Label::Label(){
};

//Label::Label(string _text)
//{
//	text=_text;
//}
void Label::show(int x, int y, string text){
	outtextxy(x, y, &text[0]);
}


