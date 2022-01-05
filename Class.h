#ifndef CLASS_H_
#define CLASS_H_

#define MAXCLASS 100
#include<iostream>
#include"Student.h"
using namespace std;


struct Class{
	string classID;
	string className;
	int sl=0 ;
	StudentList studentList;	
};
typedef struct Class CLASS;
struct classList{
CLASS* ds[MAXCLASS];
	int sl=0;
	void freeClassList();
};
typedef struct classList CLASSLIST;

void addClass(CLASSLIST &dsl,string a,string b); //ham them mot lop
void showClass(CLASSLIST dsl); //ham test show lop ra
bool loadClassList(CLASSLIST &dsl); //ham doc file len mang
void writeClassList(CLASSLIST dsl); //ham ghi lop xuong file
void deleteClassList(CLASSLIST &dsl);
bool checkEditableQues(CLASSLIST list,string idSubj, string idQues);
#endif //CLASS_H_
