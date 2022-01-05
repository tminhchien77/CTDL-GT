#include "Table.h"
#include "Terms.h"
#include "Student.h"
#include "Class.h"
#include "Subject.h"
#include<graphics.h>
//#include<string>
//#include <sstream>


void showQuesTbl(Table tbl, QSList list, int selection, int page)
{
//	cout<<"So hang: "<<list.n;
	setcolor(textColor);
	outtextxy(tbl.x+10, tbl.y+(tbl.hRow+tbl.height%11-textheight("MA CAU HOI"))/2, "MA CAU HOI");
	outtextxy(tbl.x+110, tbl.y+(tbl.hRow+tbl.height%11-textheight("NOI DUNG"))/2, "NOI DUNG");
	
	if(page*10+selection<list.n)
	{
		
		for(int i=page*10, tmp=0; i<(page+1)*10; i++, tmp++)
		{
			outtextxy(tbl.x+10,tbl.yRow0+tbl.hRow*tmp+(tbl.hRow-textheight(&list.question_QSList[i].question_code[0]))/2, &list.question_QSList[i].question_code[0]);
			string tmpStr=list.question_QSList[i].question_content;
			tmpStr=tmpStr.substr(0,70);
			outtextxy(tbl.x+110,tbl.yRow0+tbl.hRow*tmp+(tbl.hRow-textheight(&tmpStr[0]))/2, &tmpStr[0]);
		}
		// highlight hang duoc chon
		setcolor(selectionColor);
		rectangle(tbl.x, tbl.yRow0+tbl.hRow*selection, tbl.x+tbl.width, tbl.yRow0+tbl.hRow*selection+tbl.hRow);
		setfillstyle(SOLID_FILL,selectionColor);
	    floodfill(tbl.x+1,tbl.yRow0+tbl.hRow*selection+1,selectionColor);
	    setbkcolor(selectionColor);
		setcolor(textColor);
		outtextxy(tbl.x+10, tbl.yRow0+tbl.hRow*selection+(tbl.hRow-textheight(&list.question_QSList[page*10+selection].question_code[0]))/2, &list.question_QSList[page*10+selection].question_code[0]);
		string tmpStr=list.question_QSList[page*10+selection].question_content;
		tmpStr=tmpStr.substr(0,90);
		outtextxy(tbl.x+110, tbl.yRow0+tbl.hRow*selection+(tbl.hRow-textheight(&tmpStr[0]))/2, &tmpStr[0]);
//		cout<<"Cau to mau:        "<<list.question_QSList[page*10+selection].question_content;
		// Ve bang
		
	}
	rectangle(tbl.x, tbl.y, tbl.x+tbl.width, tbl.y+tbl.height);
	line(tbl.x+100, tbl.y, tbl.x+100, tbl.y+tbl.height);
	line(tbl.x, tbl.yRow0, tbl.x+tbl.width, tbl.yRow0);
}

void showStudentTbl(Table tbl, StudentList list, int selection, int page)
{
	
	int lengthOfList=list.getLength();
	
	setcolor(textColor);
	outtextxy(tbl.x+50, tbl.y+(tbl.hRow+tbl.height%11-textheight("MSSV"))/2, "MSSV");
	outtextxy(tbl.x+210, tbl.y+(tbl.hRow+tbl.height%11-textheight("Ho"))/2, "Ho");
	outtextxy(tbl.x+420, tbl.y+(tbl.hRow+tbl.height%11-textheight("Ten"))/2, "Ten");
	outtextxy(tbl.x+625, tbl.y+(tbl.hRow+tbl.height%11-textheight("Gioi tinh"))/2, "Gioi tinh");
		
	if(page*10+selection<lengthOfList)
	{
		
		
		StudentNode *p;
		StudentNode *tmpP=list.pHead;
//		cout<<list.pHead->data.lastName;
		if(p==NULL) return;
		else
		{
//			
			int tmp=0;
			
			while(tmpP!=NULL && tmp<=page*10)
			{
				p=tmpP;
				tmpP=tmpP->pNext;	
				tmp++;	
			}
			
		}
//		cout<<p->data.firstName;
//		for(int i=page*10, tmp=0; i<(page+1)*10; i++, tmp++)
//		{
//			outtextxy(tbl.x+10,tbl.yRow0+tbl.hRow*tmp+(tbl.hRow-textheight(&list.question_QSList[i].question_code[0]))/2, &list.question_QSList[i].question_code[0]);
//			outtextxy(tbl.x+110,tbl.yRow0+tbl.hRow*tmp+(tbl.hRow-textheight(&list.question_QSList[i].question_content[0]))/2, &list.question_QSList[i].question_content[0]);
//		}
		for(int i=0; i<10 && p!=NULL; i++)
		{
//			cout<<"here";
//			cout<<p->data.id;
			outtextxy(tbl.x+15,tbl.yRow0+tbl.hRow*i+(tbl.hRow-textheight(&p->data.id[0]))/2, &p->data.id[0]);
			outtextxy(tbl.x+165,tbl.yRow0+tbl.hRow*i+(tbl.hRow-textheight(&p->data.firstName[0]))/2, &p->data.firstName[0]);
			outtextxy(tbl.x+315,tbl.yRow0+tbl.hRow*i+(tbl.hRow-textheight(&p->data.lastName[0]))/2, &p->data.lastName[0]);
			string tmp;
			if(p->data.sex==0)	tmp="Nu";
			else tmp="Nam";
			outtextxy(tbl.x+615,tbl.yRow0+tbl.hRow*i+(tbl.hRow-textheight(&tmp[0]))/2, &tmp[0]);
			if(i==page*10+selection) tmpP=p;
			p=p->pNext;
		}
//		 highlight hang duoc chon
		setcolor(selectionColor);
		rectangle(tbl.x, tbl.yRow0+tbl.hRow*selection, tbl.x+tbl.width, tbl.yRow0+tbl.hRow*selection+tbl.hRow);
		setfillstyle(SOLID_FILL,selectionColor);
	    floodfill(tbl.x+1,tbl.yRow0+tbl.hRow*selection+1,selectionColor);
	    setbkcolor(selectionColor);
		setcolor(textColor);
//		outtextxy(tbl.x+10, tbl.yRow0+tbl.hRow*selection+(tbl.hRow-textheight(&tmpP->data.id[0]))/2, &list.question_QSList[page*10+selection].question_code[0]);
//		outtextxy(tbl.x+110, tbl.yRow0+tbl.hRow*selection+(tbl.hRow-textheight(&list.question_QSList[page*10+selection].question_content[0]))/2, &list.question_QSList[page*10+selection].question_content[0]);
		outtextxy(tbl.x+15,tbl.yRow0+tbl.hRow*selection+(tbl.hRow-textheight(&tmpP->data.id[0]))/2, &tmpP->data.id[0]);
		outtextxy(tbl.x+165,tbl.yRow0+tbl.hRow*selection+(tbl.hRow-textheight(&tmpP->data.firstName[0]))/2, &tmpP->data.firstName[0]);
		outtextxy(tbl.x+315,tbl.yRow0+tbl.hRow*selection+(tbl.hRow-textheight(&tmpP->data.lastName[0]))/2, &tmpP->data.lastName[0]);
		string tmp;
		if(tmpP->data.sex==0)	tmp="Nu";
		else tmp="Nam";
		outtextxy(tbl.x+615,tbl.yRow0+tbl.hRow*selection+(tbl.hRow-textheight(&tmp[0]))/2, &tmp[0]);
		
	}
	
	// Ve bang
	rectangle(tbl.x, tbl.y, tbl.x+tbl.width, tbl.y+tbl.height);
	line(tbl.x+150, tbl.y, tbl.x+150, tbl.y+tbl.height);
	line(tbl.x+300, tbl.y, tbl.x+300, tbl.y+tbl.height);
	line(tbl.x+600, tbl.y, tbl.x+600, tbl.y+tbl.height);
	line(tbl.x, tbl.yRow0, tbl.x+tbl.width, tbl.yRow0);
}

void showClassTbl(Table tbl, CLASSLIST list, int selection, int page)
{
	if(page*10+selection>=list.sl)
	{
		return;
	}
		
	else
	{
		setbkcolor(WHITE);
		setcolor(textColor);
		outtextxy(tbl.x+10, tbl.y+(tbl.hRow+tbl.height%11-textheight("Ma Lop"))/2, "Ma Lop");
		outtextxy(tbl.x+110, tbl.y+(tbl.hRow+tbl.height%11-textheight("Ten Lop"))/2, "Ten Lop");
		for(int i=page*10, tmp=0; i<(page+1)*10 && i<list.sl; i++, tmp++)
		{
			outtextxy(tbl.x+10,tbl.yRow0+tbl.hRow*tmp+(tbl.hRow-textheight(&list.ds[i]->classID[0]))/2, &list.ds[i]->classID[0]);
			outtextxy(tbl.x+110,tbl.yRow0+tbl.hRow*tmp+(tbl.hRow-textheight(&list.ds[i]->className[0]))/2, &list.ds[i]->className[0]);
		}
		// highlight hang duoc chon
		
		setcolor(selectionColor);
		rectangle(tbl.x, tbl.yRow0+tbl.hRow*selection, tbl.x+tbl.width, tbl.yRow0+tbl.hRow*selection+tbl.hRow);
		setfillstyle(SOLID_FILL,selectionColor);
	    floodfill(tbl.x+1,tbl.yRow0+tbl.hRow*selection+1,selectionColor);
	    setbkcolor(selectionColor);
		setcolor(textColor);
		outtextxy(tbl.x+10, tbl.yRow0+tbl.hRow*selection+(tbl.hRow-textheight(&list.ds[page*10+selection]->classID[0]))/2, &list.ds[page*10+selection]->classID[0]);
		outtextxy(tbl.x+110, tbl.yRow0+tbl.hRow*selection+(tbl.hRow-textheight(&list.ds[page*10+selection]->className[0]))/2, &list.ds[page*10+selection]->className[0]);
//		cout<<"Cau to mau:        "<<list.question_QSList[page*10+selection].question_content;
		// Ve bang
		rectangle(tbl.x, tbl.y, tbl.x+tbl.width, tbl.y+tbl.height);
		line(tbl.x+100, tbl.y, tbl.x+100, tbl.y+tbl.height);
		line(tbl.x, tbl.yRow0, tbl.x+tbl.width, tbl.yRow0);
	}
}

void showSubjectTbl(Table tbl, SUBJECTNODE **list, int lengthOfList, int selection, int page)
{
	
	if(page*10+selection<lengthOfList)
	{
		setbkcolor(WHITE);
		setcolor(textColor);
		outtextxy(tbl.x+10, tbl.y+(tbl.hRow+tbl.height%11-textheight("Ma Mon"))/2, "Ma Mon");
		outtextxy(tbl.x+110, tbl.y+(tbl.hRow+tbl.height%11-textheight("Ten Mon"))/2, "Ten Mon");
//		cout<<"HERE"<<endl;
		for(int i=page*10, tmp=0; i<(page+1)*10 && i<lengthOfList; i++, tmp++)
		{
//			cout<<"Ma mon: "<<list[i]->sj.subjectId<<endl;
			outtextxy(tbl.x+10,tbl.yRow0+tbl.hRow*tmp+(tbl.hRow-textheight(&list[i]->sj.subjectId[0]))/2, &list[i]->sj.subjectId[0]);
			outtextxy(tbl.x+110,tbl.yRow0+tbl.hRow*tmp+(tbl.hRow-textheight(&list[i]->sj.subjectName[0]))/2, &list[i]->sj.subjectName[0]);
			
		}
		// highlight hang duoc chon
//		cout<<"Chang le o day";
		setcolor(selectionColor);
		rectangle(tbl.x, tbl.yRow0+tbl.hRow*selection, tbl.x+tbl.width, tbl.yRow0+tbl.hRow*selection+tbl.hRow);
		setfillstyle(SOLID_FILL,selectionColor);
	    floodfill(tbl.x+1,tbl.yRow0+tbl.hRow*selection+1,selectionColor);
	    setbkcolor(selectionColor);
		setcolor(textColor);
		outtextxy(tbl.x+10, tbl.yRow0+tbl.hRow*selection+(tbl.hRow-textheight(&list[page*10+selection]->sj.subjectId[0]))/2, &list[page*10+selection]->sj.subjectId[0]);
		outtextxy(tbl.x+110, tbl.yRow0+tbl.hRow*selection+(tbl.hRow-textheight(&list[page*10+selection]->sj.subjectName[0]))/2, &list[page*10+selection]->sj.subjectName[0]);
//		cout<<"Cau to mau:        "<<list.question_QSList[page*10+selection].question_content;
		// Ve bang
		rectangle(tbl.x, tbl.y, tbl.x+tbl.width, tbl.y+tbl.height);
		line(tbl.x+100, tbl.y, tbl.x+100, tbl.y+tbl.height);
		line(tbl.x, tbl.yRow0, tbl.x+tbl.width, tbl.yRow0);
	}
}

void showScoresOfClassTbl(Table tbl, StudentList list, string idSubj, int selection, int page)
{
//	stringstream ss; 
	int lengthOfList=list.getLength();
	
	setcolor(textColor);
	outtextxy(tbl.x+50, tbl.y+(tbl.hRow+tbl.height%11-textheight("MSSV"))/2, "MSSV");
	outtextxy(tbl.x+210, tbl.y+(tbl.hRow+tbl.height%11-textheight("Ho"))/2, "Ho");
	outtextxy(tbl.x+420, tbl.y+(tbl.hRow+tbl.height%11-textheight("Ten"))/2, "Ten");
	outtextxy(tbl.x+625, tbl.y+(tbl.hRow+tbl.height%11-textheight("Diem"))/2, "Diem");
		
	if(page*10+selection<lengthOfList)
	{
		
		
		StudentNode *p;
		StudentNode *tmpP=list.pHead;
		if(p==NULL) return;
		else
		{
//			
			int tmp=0;
			
			while(tmpP!=NULL && tmp<=page*10)
			{
				p=tmpP;
				tmpP=tmpP->pNext;	
				tmp++;	
			}
			
		}
		for(int i=0; i<10 && p!=NULL; i++)
		{
			
			outtextxy(tbl.x+15,tbl.yRow0+tbl.hRow*i+(tbl.hRow-textheight(&p->data.id[0]))/2, &p->data.id[0]);
			outtextxy(tbl.x+165,tbl.yRow0+tbl.hRow*i+(tbl.hRow-textheight(&p->data.firstName[0]))/2, &p->data.firstName[0]);
			outtextxy(tbl.x+315,tbl.yRow0+tbl.hRow*i+(tbl.hRow-textheight(&p->data.lastName[0]))/2, &p->data.lastName[0]);
			float tmpScore=p->data.scoreList.searchScore(idSubj);
			char buff[2];
//			cout<<tmpScore;
			string displayScore;
			if(tmpScore==-1) displayScore="Chua thi";
			else displayScore=itoa(tmpScore, buff, 10);
//			itoa(p->data.scoreList.)
			outtextxy(tbl.x+615,tbl.yRow0+tbl.hRow*i+(tbl.hRow-textheight(&displayScore[0]))/2, &displayScore[0]);
			if(i==page*10+selection) tmpP=p;
			p=p->pNext;
		}
//		 highlight hang duoc chon
		setcolor(selectionColor);
		rectangle(tbl.x, tbl.yRow0+tbl.hRow*selection, tbl.x+tbl.width, tbl.yRow0+tbl.hRow*selection+tbl.hRow);
		setfillstyle(SOLID_FILL,selectionColor);
	    floodfill(tbl.x+1,tbl.yRow0+tbl.hRow*selection+1,selectionColor);
	    setbkcolor(selectionColor);
		setcolor(textColor);
//		outtextxy(tbl.x+10, tbl.yRow0+tbl.hRow*selection+(tbl.hRow-textheight(&tmpP->data.id[0]))/2, &list.question_QSList[page*10+selection].question_code[0]);
//		outtextxy(tbl.x+110, tbl.yRow0+tbl.hRow*selection+(tbl.hRow-textheight(&list.question_QSList[page*10+selection].question_content[0]))/2, &list.question_QSList[page*10+selection].question_content[0]);
		outtextxy(tbl.x+15,tbl.yRow0+tbl.hRow*selection+(tbl.hRow-textheight(&tmpP->data.id[0]))/2, &tmpP->data.id[0]);
		outtextxy(tbl.x+165,tbl.yRow0+tbl.hRow*selection+(tbl.hRow-textheight(&tmpP->data.firstName[0]))/2, &tmpP->data.firstName[0]);
		outtextxy(tbl.x+315,tbl.yRow0+tbl.hRow*selection+(tbl.hRow-textheight(&tmpP->data.lastName[0]))/2, &tmpP->data.lastName[0]);
//		string tmp;
//		if(tmpP->data.sex==0)	tmp="Nu";
//		else tmp="Nam";
		
		int tmpScore=tmpP->data.scoreList.searchScore(idSubj);
		char buff[2];
		string displayScore;
		if(tmpScore==-1) displayScore="Chua thi";
		else displayScore=itoa(tmpScore, buff, 10);
		outtextxy(tbl.x+615,tbl.yRow0+tbl.hRow*selection+(tbl.hRow-textheight(&displayScore[0]))/2, &displayScore[0]);
		
	}
	
	// Ve bang
	rectangle(tbl.x, tbl.y, tbl.x+tbl.width, tbl.y+tbl.height);
	line(tbl.x+150, tbl.y, tbl.x+150, tbl.y+tbl.height);
	line(tbl.x+300, tbl.y, tbl.x+300, tbl.y+tbl.height);
	line(tbl.x+600, tbl.y, tbl.x+600, tbl.y+tbl.height);
	line(tbl.x, tbl.yRow0, tbl.x+tbl.width, tbl.yRow0);
}

void showDetailExam(Table tbl, QSList qList, Exam e, int selection, int page)
{
	if(page*10+selection>=e.length)
	{
		return;
	}
//	list[0].	
	else
	{
		setbkcolor(WHITE);
		setcolor(textColor);
		outtextxy(tbl.x+10, tbl.y+(tbl.hRow+tbl.height%11-textheight("Ma Cau Hoi"))/2, "Ma Cau Hoi");
		outtextxy(tbl.x+110, tbl.y+(tbl.hRow+tbl.height%11-textheight("Cau Hoi"))/2, "Cau Hoi");
		Question *tmpQues;
		for(int i=page*10, tmp=0; i<(page+1)*10 && i<e.length; i++, tmp++)
		{
			tmpQues=&qList.question_QSList[qList.biSearchQS(e.idQuesArray[i])];
			outtextxy(tbl.x+10,tbl.yRow0+tbl.hRow*tmp+(tbl.hRow-textheight(&tmpQues->question_code[0]))/2, &tmpQues->question_code[0]);
			string tmpStr=tmpQues->question_content;
			tmpStr=tmpStr.substr(0,80);
			outtextxy(tbl.x+110,tbl.yRow0+tbl.hRow*tmp+(tbl.hRow-textheight(&tmpStr[0]))/2, &tmpStr[0]);
			
		}
		// highlight hang duoc chon
//		cout<<"Chang le o day";
		setcolor(selectionColor);
		rectangle(tbl.x, tbl.yRow0+tbl.hRow*selection, tbl.x+tbl.width, tbl.yRow0+tbl.hRow*selection+tbl.hRow);
		setfillstyle(SOLID_FILL,selectionColor);
	    floodfill(tbl.x+1,tbl.yRow0+tbl.hRow*selection+1,selectionColor);
	    setbkcolor(selectionColor);
		setcolor(textColor);
		tmpQues=&qList.question_QSList[qList.biSearchQS(e.idQuesArray[page*10+selection])];
		string tmpStr=tmpQues->question_content;
		tmpStr=tmpStr.substr(0,80);
		outtextxy(tbl.x+10, tbl.yRow0+tbl.hRow*selection+(tbl.hRow-textheight(&tmpQues->question_code[0]))/2, &tmpQues->question_code[0]);
		outtextxy(tbl.x+110, tbl.yRow0+tbl.hRow*selection+(tbl.hRow-textheight(&tmpStr[0]))/2, &tmpStr[0]);
//		cout<<"Cau to mau:        "<<list.question_QSList[page*10+selection].question_content;
		// Ve bang
		rectangle(tbl.x, tbl.y, tbl.x+tbl.width, tbl.y+tbl.height);
		line(tbl.x+100, tbl.y, tbl.x+100, tbl.y+tbl.height);
		line(tbl.x, tbl.yRow0, tbl.x+tbl.width, tbl.yRow0);
	}
}

