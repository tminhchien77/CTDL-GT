#ifndef TERMS_H_
#define TERMS_H_

#include<graphics.h>

//#define xButtonMenuBar 25
//#define yButtonMenuBar 12
#define screenWidth 1280
#define screenHeight 700
#define textColor BLACK
#define defUnSelectedBtnColor CYAN
#define defSelectedBtnColor MAGENTA
//#define bgColor LIGHTGRAY
#define pnlColor WHITE
#define selectionColor CYAN

#define quesInfIndex 0
#define wDialog 400
#define hDialog 200
#define xDialog (screenWidth-wDialog)/2
#define yDialog (screenHeight-hDialog)/2

#define selectedColorMenuBar CYAN
#define unSelectedColorMenuBar CYAN
#define extensionFile ".txt"

enum Answers{
	ansA,
	ansB, 
	ansC, 
	ansD,
	nonAns
};

enum Sexes{
	Nu,
	Nam
};

enum Roles{
		teacher,
		student
	};

#define sizePageBtn 25
#endif //TERMS_H_
