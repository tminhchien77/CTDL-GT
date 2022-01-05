#ifndef PANELS_H_
#define PANELS_H_

struct Panel{
	int x, y, width, height;
//	char *text;
	int color;
	Panel(int _x, int _y, int _width, int _height/*, char *_text*/, int _color){
		x=_x;
		y=_y;
		width=_width;
		height=_height;
//		text=_text;
		color=_color;
	};
}; 

void showPnl(Panel pnl);
//void showClassesPnl(Panel pnl);
//void showStudentsPnl(Panel pnl);

#endif //PANELS_H_
