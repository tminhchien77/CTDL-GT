#include<graphics.h>
#include<stdio.h>
#include<windows.h>
#include<iostream>
#include<conio.h>
#include"Buttons.h"
#include"Panels.h"
#include"Terms.h"
#include"Student.h"
#include"Question.h"
#include"Table.h"
#include"InputField.h"
#include"Dialog.h"
#include"Label.h"
#include <thread>
#include <mutex>
#include<string>
#include<cmath>
#include"Class.h"


using namespace std;
#define yMenuBar 0
#define heightMenuBar hBtnMenuBar
#define yListPnl yMenuBar+heightMenuBar
#define hListPnl 420
#define yEditPnl yListPnl+hListPnl+5
#define wBtnMenuBar 80
#define hBtnMenuBar 20
#define windowColor LIGHTGRAY

#define padding 5

int isInputBlank(Dialog& dialog, int numText, string str1="", string str2="", string str3="", string str4="",  string str5="", string str6="");
bool isDupInput(string str1, string str2, string str3, string str4);
bool checkStudentEntered(string firstName, string lastName, Dialog& dialog, bool isChanged);
bool checkInputInforQues(Dialog& dialog, string str1="", string str2="", string str3="", string str4="",  string str5="", string str6="");
Roles * checkLogin(string id, string pwd);
void timeNormal();
float marking(int numOfQues, Question *exam,Answers *ansListStudent);
string formatStr(string str);
//bool timeout();
//void* countTime(void* unused);
int testTime=0;
int mm;
int ss;
bool isTimeout=false;





int main ()
{
	
//	return 0;
	initwindow(screenWidth,screenHeight,"Test -- ver 1.0", 50,50);
	char arr[100];
    
	CLASSLIST classList;
	SUBJECTLIST subjList;
	SUBJECTNODE **subjArray;
			
			
	//====================================Khoi tao thanh phan======================================================================
	Button classesBtn=Button(0,0,wBtnMenuBar,hBtnMenuBar,"Lop", DARKGRAY, selectedColorMenuBar, false);
	Button subjectsBtn=Button(wBtnMenuBar,0,wBtnMenuBar,hBtnMenuBar,"Mon", DARKGRAY, selectedColorMenuBar, false);
	Button exitBtn=Button(screenWidth-80, 0, 80, 20, "Thoat", LIGHTRED,defSelectedBtnColor, false);
	Panel l_m_Pnl=Panel(0,yListPnl,500,hListPnl, /*"Class list",*/ WHITE);
	Panel r_m_Pnl=Panel(l_m_Pnl.x+l_m_Pnl.width+padding,yListPnl,screenWidth-l_m_Pnl.x-l_m_Pnl.width-padding,hListPnl, WHITE);
	Panel l_b_Pnl=Panel(0, yEditPnl, 500, screenHeight-yEditPnl, WHITE);
	Panel r_b_Pnl=Panel(l_b_Pnl.x+l_b_Pnl.width+padding, yEditPnl, screenWidth-l_b_Pnl.x-l_b_Pnl.width-padding, screenHeight-yEditPnl, WHITE);
	Table quesTbl= Table(r_m_Pnl.x+35, r_m_Pnl.y+50, r_m_Pnl.width-35*2, r_m_Pnl.height-130);
	Table studentTbl= Table(r_m_Pnl.x+35, r_m_Pnl.y+50, r_m_Pnl.width-35*2, r_m_Pnl.height-130);
	Table classTbl=Table(l_m_Pnl.x+15, l_m_Pnl.y+50, l_m_Pnl.width-15*2, l_m_Pnl.height-130);
	Table subjTbl=Table(l_m_Pnl.x+15, l_m_Pnl.y+50, l_m_Pnl.width-15*2, l_m_Pnl.height-130);
//	Button rightNextPage=Button(quesTbl.x+quesTbl.width-75,quesTbl.y+quesTbl.height+10,75,50,"Next", selectedColorMenuBar, unSelectedColorMenuBar);
//	Button rightPrePage=Button(quesTbl.x,quesTbl.y+quesTbl.height+10,100,50,"Previous", selectedColorMenuBar, unSelectedColorMenuBar);
	Button r_addBtn=Button(1145, 35, 100, 30,"Them moi", defUnSelectedBtnColor, LIGHTRED, false);
	Button r_SaveBtn=Button(710, 650, 100, 30, "Luu", defUnSelectedBtnColor, defSelectedBtnColor, false);
	Button r_LeaveBtn=Button(1000, 650, 100, 30, "Thoat", defUnSelectedBtnColor, defSelectedBtnColor, false);
	Button viewListClassBtn=Button(235, 40, 250, 25,"Xem danh sach diem thi", defUnSelectedBtnColor, LIGHTRED, false);
	Button viewListSubjectBtn=Button(200, 525, 250, 25,"Xem danh sach mon hoc", defUnSelectedBtnColor, LIGHTRED, false);
	Button exitViewBtn=Button(xView+wView-115, yView+30, 100, 30, "Thoat", LIGHTRED, defSelectedBtnColor, false);
	Button showScoreBtn=Button(xView+wView-145-exitViewBtn.width, yView+30, 125, 30, "Danh sach diem", defUnSelectedBtnColor, defSelectedBtnColor, false);
	
	Button deleteBtn=Button(335, 40, 60, 25,"Xoa", LIGHTRED, defUnSelectedBtnColor, false);
	Button l_addBtn=Button(405, 40, 80, 25,"Them moi", defUnSelectedBtnColor, LIGHTRED, false);
	Button l_SaveBtn=Button(100, 600, 100, 30, "Luu", defUnSelectedBtnColor, defSelectedBtnColor, false);
	Button l_LeaveBtn=Button(350, 600, 100, 30, "Thoat", defUnSelectedBtnColor, defSelectedBtnColor, false);
	
	ButtonList rPageBtns, lPageBtns, vPageBtns;
	
	InputField quesInf= InputField(r_b_Pnl.x+150, r_b_Pnl.y+45, 500, 25,255);
	InputField answerAInf= InputField(quesInf.x, quesInf.y+40, 200, 25,255);
	InputField answerBInf= InputField(quesInf.x+300, quesInf.y+40, 200, 25,255);
	InputField answerCInf= InputField(quesInf.x, answerAInf.y+40, 200, 25,255);
	InputField answerDInf= InputField(quesInf.x+300, answerAInf.y+40, 200, 25,255);
	InputField resultInf= InputField(r_b_Pnl.x+150, answerCInf.y+40, 500, 25,1);
	InputField firstNameInf= InputField(r_b_Pnl.x+150, r_b_Pnl.y+45, 500, 25,50);
	InputField lastNameInf= InputField(firstNameInf.x, firstNameInf.y+40, 500, 25,50);
	Button maleBtn=Button(lastNameInf.x, lastNameInf.y+40, 200, 30, "Nam", defUnSelectedBtnColor, defSelectedBtnColor, false);
	Button femaleBtn=Button(lastNameInf.x+300, lastNameInf.y+40, 200, 30, "Nu", defUnSelectedBtnColor, defSelectedBtnColor, false);
	
	Dialog dialog=Dialog("Dang nhap lieu, Luu thay doi?", "Dong y","Thoat");
	InputField tmpInf;
	InputField *infPointer;
	
	InputField userNameInf= InputField(xLoginPnl+25, yLoginPnl+75, wLoginPnl-50, 50, 50);
	InputField passInf=InputField(xLoginPnl+25, yLoginPnl+175, wLoginPnl-50, 50, 50);
	Button loginBtn=Button(xLoginPnl+50, yLoginPnl+260, wLoginPnl-100, 50, "Dang nhap",defUnSelectedBtnColor,defSelectedBtnColor, false);
	
	InputField idSubjectInf, numOfQusInf, timeInf;
	
	
	
	InputField nameSubjInf= InputField(100, quesInf.y+40, 350, quesInf.height,255);
	InputField idSubjInf= InputField(nameSubjInf.x, quesInf.y, nameSubjInf.width, nameSubjInf.height,15);
	string idSubjLbl;
//	InputField numOfQusInf;
//	InputField timeInf;
	Button startBtn, submitBtn;
	
	
	Button ansA_Btn, ansB_Btn, ansC_Btn, ansD_Btn;
	ButtonList quesBtnList;
	
	POINT cursorPosition;
	int cursorX=-1, cursorY=-1;
	int tmpcursorX=-1, tmpcursorY=-1;
	int tab=1;
	int page=0;
	int rowRightTbl=0;
	int pageRightTbl=0;
	int rowLeftTbl=0;
	int pageLeftTbl=0;
	bool isMouseUsing=true;
	string * strInputting;
	string oldStr;
	string password;
	bool isChanged=false;
	bool isDialog=false;
//	bool isLoadLeftList=true;
	bool tmpIsSelectedRAddBtn=false;
	bool isAddingRight=false;
	bool isAddingLeft=false;
	string idLbl;
	bool isLogged=false;
	bool isSeletedLoginBtn=false;
	int role=-1;
	bool isUpdateFile=false;
	bool isInputUpper=false;
	bool isInputPass=false;
	bool isInputNumber=false;
	bool isErrorLbl=false;
	int lengthOfRightList;
	int lengthOfLeftList;
	bool isStartAdd=false;
	bool isFlagTest=false;
	bool isAddDone=false;
	bool isView=false;
	
	
	int curQues=0;
	Answers *answerList;
	bool isLoadUI=true;
	bool isLoadExam=false;
	bool isTesting=false;
	bool isLoadQS=false;
	bool isCreateTimer=false;
	bool isFinish=false;
	bool isWriteFileInforExamOfStudent=false;
	bool isWroteTestFile=false;
	int sex=1;
	bool isSexSelecting=false;
//	bool isLoadRightList=true;
	bool isLoadFile=true;
	bool isInputtingLeft=false;
	bool isInputtingRight=false;
	int lengthOfViewList;
	int pageViewTbl=0, rowViewTbl=0;
	bool isViewScoreOfClass=false;
	bool isWriteFile=false;
	bool isWriteFileClasses=false;
	bool isWriteFileSubjects=false;
	bool isViewDetailExam=false;
	int indexStudent;
	bool isShowing=false;
	int indexSubj=-1;
	bool isFreeMemory=false;
	
	string tmpQuestion;
	Answers * ansListStudent;
	ScoreList scoreList;
	string idLeftSelecting;
	string idSelecting;
	char tmpKey;
//	string idSubjLbl;
	
	
	
//	startTimer();
	
	
	Question *exam;
	
		
			
	while(1)
	{
		
		if(isLoadFile && role==teacher)
		{
			
			loadClassList(classList);
//			cout<<"Diem thi SV 1: "<<classList.ds[1]->studentList.pHead->data.scoreList.pHead->data.score;
			idLeftSelecting=classList.ds[0]->classID;
			
			readSubjectjList(subjList);
			lengthOfLeftList=countNodes(subjList.tree);
			subjArray=new SUBJECTNODE*[lengthOfLeftList];
			int index=0;
			treeToArray(subjList.tree, subjArray,index);
			sortSubject(subjArray,lengthOfLeftList);
			isLoadFile=false;
//			cout<<"Diem "<<classList.ds[0]->studentList.getStudent(1).scoreList.searchIDSub("BAS1227")->data.idSubject;
		}
		if(isWriteFile)
		{
			if(isWriteFileClasses)
				writeClassList(classList);
			if(isWriteFileSubjects)
			{
				cout<<"HEREEEEEEE";
				saveFile_Tree(subjList.tree);
			}
			isWriteFileClasses=false;
			isWriteFileSubjects=false;
			isWriteFile=false;	
		}
		
		if(isFreeMemory)
		{
			cout<<"FREE MEMORY";
			if(role==teacher)
			{
				for(int i=0; i<countNodes(subjList.tree); i++)
				{
					delete subjArray[i];
				}
				delete[] subjArray;
				
				classList.freeClassList();
				subjList.freeSubjectList(subjList.tree);
			}
			else
			{
				delete[] ansListStudent;
				delete exam;
			}
			delete strInputting;
			delete infPointer;
			isFreeMemory=false;
		}
		int indexRight=rowRightTbl+pageRightTbl*10;
		int indexLeft=rowLeftTbl+pageLeftTbl*10;
		
		setactivepage(page);
		
		setvisualpage(1-page);
		
		setbkcolor(windowColor);
		
		cleardevice();
		
    	
    	if(!isLogged)
		{
//			*strInputting="";
			showLoginPnl();
			showInputField(userNameInf);
			showInputField(passInf);
			loginBtn.show();
//			showBtn(loginBtn, WHITE, isSeletedLoginBtn, 0);
			if(!isMouseUsing)
				{	
					showInputField(tmpInf);
				}
			if(isErrorLbl)
			{
				setbkcolor(WHITE);
				setcolor(RED);
				outtextxy(520, 410, "** Sai ten dang nhap hoac mat khau** ");
			}
		}
		else
		{
			if(isErrorLbl)	isErrorLbl=false;
			if(role==teacher)
			{
				if(tab==1)
				{
					classesBtn.isSelected=false;
					subjectsBtn.isSelected=true;
				}
				else
				{
					classesBtn.isSelected=true;
					subjectsBtn.isSelected=false;
				}
				classesBtn.show();
				subjectsBtn.show();
				exitBtn.show();
			
				
				showPnl(l_m_Pnl);
				showPnl(r_m_Pnl);
				showPnl(l_b_Pnl);
				showPnl(r_b_Pnl);
				r_addBtn.show();
				
				
				setbkcolor(WHITE);
				if(tab==0)
				{
					lengthOfLeftList=classList.sl;
					lPageBtns=ButtonList(380, l_m_Pnl.x, l_m_Pnl.width, lengthOfLeftList, 25,25);
					
					lengthOfRightList=classList.ds[pageLeftTbl*10 + rowLeftTbl]->studentList.getLength();
					rPageBtns=ButtonList(380, r_m_Pnl.x, r_m_Pnl.width, lengthOfRightList, 25,25);
					
					if(isAddDone)	lengthOfRightList=classList.ds[indexLeft]->studentList.getLength();
//					cout<<"so hang cua bang "<<lengthOfRightList<<endl;
					if(!isAddingRight)
					{
						r_addBtn.isSelected=false;
						Student tmpStudent;
						tmpStudent=classList.ds[indexLeft]->studentList.getStudent(indexRight);
						idLbl=tmpStudent.id;
						if(isMouseUsing)
						{
							
							firstNameInf.text=tmpStudent.firstName;
							lastNameInf.text=tmpStudent.lastName;
						}
							
					}
						
					else
					{
						r_addBtn.isSelected=true;
						if(isStartAdd)
						{
							firstNameInf.text="";
							lastNameInf.text="";
							
							isMouseUsing=false;
							infPointer=infPointer=createInf(tmpInf,firstNameInf);
							
							showInputField(tmpInf);
							oldStr=firstNameInf.text;
							strInputting=&firstNameInf.text;
							idLbl=getNextID(classList.ds[indexLeft]->studentList, classList.ds[indexLeft]->classID);
							
							isStartAdd=false;
						}
					}	
					setcolor(BLACK);
					outtextxy(r_b_Pnl.x+150, r_b_Pnl.y+15, &idLbl[0]);
					
					showStudentTbl(studentTbl,classList.ds[indexLeft]->studentList, rowRightTbl, pageRightTbl);
					rPageBtns.show(classList.ds[indexLeft]->studentList.getLength(), pageRightTbl);
					
					if(isMouseUsing)
					{
						Student tmpStudent;
						tmpStudent=classList.ds[indexLeft]->studentList.getStudent(indexRight);
						idLbl=tmpStudent.id;
						firstNameInf.text=tmpStudent.firstName;
						lastNameInf.text=tmpStudent.lastName;
						if(!isSexSelecting)	sex=tmpStudent.sex;
					}
					
					outtextxy(r_b_Pnl.x+15, r_b_Pnl.y+15, "MSSV:");	
					outtextxy(r_b_Pnl.x+150, r_b_Pnl.y+15, &idLbl[0]);
					
					outtextxy(r_b_Pnl.x+15, r_b_Pnl.y+45, "Ho:");
					showInputField(firstNameInf);
					
					outtextxy(r_b_Pnl.x+15, r_b_Pnl.y+85, "Ten:");
					showInputField(lastNameInf);
					
					showGroupSexesBtn(maleBtn, femaleBtn, sex);





					viewListClassBtn.show();
					showClassTbl(classTbl, classList, rowLeftTbl, pageLeftTbl);
					lPageBtns.show(classList.sl, pageLeftTbl);
					
					
					
				}
				else if(tab==1)
				{
					lPageBtns=ButtonList(380, l_m_Pnl.x, l_m_Pnl.width, lengthOfLeftList, 25,25);
					lengthOfRightList=subjArray[indexLeft]->sj.qsList.n;
					rPageBtns=ButtonList(380, r_m_Pnl.x, r_m_Pnl.width, lengthOfRightList, 25,25);
					
					l_addBtn.show();
					
					setbkcolor(WHITE);
					r_addBtn.isSelected=false;
					l_addBtn.isSelected=false;
					
					if(isAddDone)
					{
						if(isAddingRight)
						{
							lengthOfRightList=subjArray[indexLeft]->sj.qsList.n;
							rowRightTbl=(lengthOfRightList-1)%10;
							pageRightTbl=(lengthOfRightList-1)/10;
							isAddDone=false;
						}
						else if(isAddingLeft)
						{
							lengthOfLeftList=countNodes(subjList.tree);
							rowLeftTbl=(lengthOfLeftList-1)%10;
							pageLeftTbl=(lengthOfLeftList-1)/10;
							isAddDone=false;
						}
					}
						
					if(!isAddingRight)
					{
//						cout<<"HEYYYYYY2222";
						if(lengthOfRightList==0)
						{
							idLbl="";
							quesInf.text= "";
							answerAInf.text="";
							answerBInf.text="";
							answerCInf.text="";
							answerDInf.text="";
							resultInf.text= "";
						}
						else
						{
							idLbl=subjArray[indexLeft]->sj.qsList.question_QSList[indexRight].question_code;
							if(isMouseUsing)
							{
	//							idLbl=quesList.question_QSList[indexRight].question_code;
								quesInf.text= subjArray[indexLeft]->sj.qsList.question_QSList[indexRight].question_content;
								answerAInf.text=subjArray[indexLeft]->sj.qsList.question_QSList[indexRight].question_answer_A;
								answerBInf.text=subjArray[indexLeft]->sj.qsList.question_QSList[indexRight].question_answer_B;
								answerCInf.text=subjArray[indexLeft]->sj.qsList.question_QSList[indexRight].question_answer_C;
								answerDInf.text=subjArray[indexLeft]->sj.qsList.question_QSList[indexRight].question_answer_D;
								resultInf.text= subjArray[indexLeft]->sj.qsList.question_QSList[indexRight].question_correctAnswer;
							}
						}
						
						
//						load_item(quesList, "TOAN");
						
					}
						
					else
					{
						r_addBtn.isSelected=true;
						if(isStartAdd)
						{
							quesInf.text= "";
							answerAInf.text="";
							answerBInf.text="";
							answerCInf.text="";
							answerDInf.text="";
							resultInf.text= "";
							isMouseUsing=false;
							infPointer=createInf(tmpInf,quesInf);
							
							showInputField(tmpInf);
							oldStr=quesInf.text;
							strInputting=&quesInf.text;
							char tmp[3];
							
							if(lengthOfRightList==0)	idLbl="1";
							else idLbl=itoa(subjArray[indexLeft]->sj.qsList.n+1, tmp, 10);
							isStartAdd=false;
						}	
					}
					
					if(!isAddingLeft)
					{
//						cout<<"HEYYYYYY444";
						idSubjLbl=subjArray[indexLeft]->sj.subjectId;
//						cout<<"THERE";
						setcolor(BLACK);
						outtextxy(105, 492, &idSubjLbl[0]);
						if(isMouseUsing)
						{

							nameSubjInf.text=subjArray[indexLeft]->sj.subjectName;
//							cout<<"THERE111";
						}
						
					}
						
					else
					{
						l_addBtn.isSelected=true;
						if(isStartAdd)
						{
							idSubjInf.text="";
							nameSubjInf.text="";
							isMouseUsing=false;
							infPointer=createInf(tmpInf,idSubjInf);
							
							showInputField(tmpInf);
							oldStr=idSubjInf.text;
							strInputting=&idSubjInf.text;
							char tmp[6];
//							idLbl=itoa(subjArray[indexLeft]->sj.qsList.n+1, tmp, 10);
							isStartAdd=false;
						}	
						showInputField(idSubjInf);
					}	
					setcolor(BLACK);
					outtextxy(r_b_Pnl.x+150, r_b_Pnl.y+15, &idLbl[0]);	
					
					showQuesTbl(quesTbl,subjArray[indexLeft]->sj.qsList, rowRightTbl, pageRightTbl);
					
					rPageBtns.show(lengthOfRightList, pageRightTbl);
					
										
					
		//			setcolor(BLACK);
					if(lengthOfRightList>0 || isAddingRight)
					{
						outtextxy(r_b_Pnl.x+15, r_b_Pnl.y+15, "Ma cau hoi:");
					
					
						outtextxy(r_b_Pnl.x+15, r_b_Pnl.y+45, "Noi dung:");
						showInputField(quesInf);
						
						outtextxy(r_b_Pnl.x+100, r_b_Pnl.y+85, "A:");
						showInputField(answerAInf);
						
						outtextxy(r_b_Pnl.x+400, r_b_Pnl.y+85, "B:");
						showInputField(answerBInf);
						
						outtextxy(r_b_Pnl.x+100, r_b_Pnl.y+125, "C:");
						showInputField(answerCInf);
						
						outtextxy(r_b_Pnl.x+400, r_b_Pnl.y+125, "D:");
						showInputField(answerDInf);
						
						outtextxy(r_b_Pnl.x+15, answerCInf.y+40, "Dap an:");
						showInputField(resultInf);
					}
		
					outtextxy(20, 492, "Ma Mon:");
					outtextxy(20, 532, "Ten Mon:");
//					cout<<"Ma mon dau tien: "<<lengthOfLeftList;
					
					showSubjectTbl(classTbl, subjArray, lengthOfLeftList, rowLeftTbl, pageLeftTbl);
					lPageBtns.show(lengthOfLeftList, pageRightTbl);
					
					showInputField(nameSubjInf);
					
						
				}
				if(!isMouseUsing)
				{
//					cout<<isInputtingLeft;
					showInputField(tmpInf);
					if(tmpInf.text!=oldStr)
					{
						isChanged=true;
					}
					else isChanged=false;
					
					if(isInputtingRight || tab==0)
					{
						r_SaveBtn.show();
						r_LeaveBtn.show();
					}
					else if(isInputtingLeft)
					{
						l_SaveBtn.show();
						l_LeaveBtn.show();
					}
				}
				else
				{
					if(tab==1 && lengthOfRightList==0)
						deleteBtn.show();
					 
				}
				 
				if(isSexSelecting)
				{
					r_SaveBtn.show();
					r_LeaveBtn.show();
				}
				if(isViewScoreOfClass || isView || isViewDetailExam)
				{
					viewListClassBtn.isSelected=true;
					subjTbl=Table(xView+15, yView+65, wView-15*2, hView-130);
					vPageBtns=ButtonList(yView+hView-40, xView, wView, lengthOfViewList, 25,25);
					showView();
//					setbkcolor()
					if(isViewDetailExam)
					{
						showDetailExam(subjTbl, subjArray[indexSubj]->sj.qsList, classList.ds[indexLeft]->studentList.getStudent(indexStudent).scoreList.searchIDSub(idSelecting)->exam, rowViewTbl,pageViewTbl);
						showScoreBtn.text="Chi tiet";
						showScoreBtn.show();
					}
					else if(isViewScoreOfClass)
					{
						showScoresOfClassTbl(subjTbl, classList.ds[indexLeft]->studentList, idSelecting, rowViewTbl, pageViewTbl);
						showScoreBtn.text="Chi tiet";
						showScoreBtn.show();
						indexStudent=rowViewTbl+pageViewTbl*10;
					}
					else if(isView)
					{
						showSubjectTbl(subjTbl, subjArray, lengthOfViewList, rowViewTbl, pageViewTbl);
						indexSubj=pageViewTbl*10+rowViewTbl;
						idSelecting=subjArray[indexSubj]->sj.subjectId;
						showScoreBtn.show();
					}
					
					
					vPageBtns.show(lengthOfViewList, pageViewTbl);
					exitViewBtn.show();
					
				}
			}
			else //student
			{
				
				if(isLoadUI)
				{
					l_m_Pnl=Panel(25,5,300,screenHeight-5, WHITE);
					r_m_Pnl=Panel(l_m_Pnl.x+l_m_Pnl.width+padding,5,screenWidth-l_m_Pnl.x-l_m_Pnl.width-padding-25,420, WHITE);
					r_b_Pnl=Panel(l_m_Pnl.x+l_m_Pnl.width+padding, r_m_Pnl.y+r_m_Pnl.height+padding, r_m_Pnl.width, screenHeight-r_m_Pnl.height-padding-5, WHITE);
					idSubjectInf=InputField(l_m_Pnl.x+30, 150, l_m_Pnl.width-60, 50, 50);
					numOfQusInf=InputField(idSubjectInf.x, idSubjectInf.y+125, idSubjectInf.width, idSubjectInf.height, 50);
					timeInf=InputField(idSubjectInf.x, numOfQusInf.y+100, idSubjectInf.width, idSubjectInf.height, 50);
					startBtn=Button(idSubjectInf.x, timeInf.y+75, idSubjectInf.width, 50, "Bat dau", defUnSelectedBtnColor, defSelectedBtnColor, false);
					submitBtn=Button(idSubjectInf.x, timeInf.y+75, idSubjectInf.width, 50, "Nop bai", defUnSelectedBtnColor, defSelectedBtnColor, false);
					exitBtn=Button(idSubjectInf.x, startBtn.y+60, idSubjectInf.width, 50, "Thoat", LIGHTRED, defSelectedBtnColor, false);
					ansA_Btn=Button(r_m_Pnl.x+75, r_m_Pnl.y+130, 300, 50, defUnSelectedBtnColor, defSelectedBtnColor);
					ansB_Btn=Button(ansA_Btn.x+400, ansA_Btn.y, ansA_Btn.width, ansA_Btn.height, defUnSelectedBtnColor, defSelectedBtnColor);
					ansC_Btn=Button(ansA_Btn.x, ansA_Btn.y+100, ansA_Btn.width, ansA_Btn.height, defUnSelectedBtnColor, defSelectedBtnColor);
					ansD_Btn=Button(ansB_Btn.x, ansB_Btn.y+100, ansA_Btn.width, ansA_Btn.height, defUnSelectedBtnColor, defSelectedBtnColor);
					isLoadUI=false;
					readScoreList(userNameInf.text, scoreList);
				}
				
				
				if(isLoadExam)
				{
					QSList tmpQSList;
					load_item(tmpQSList, idSubjectInf.text);
//					exam=new Question[atoi(&numOfQusInf.text[0])];
					exam=loadExam(tmpQSList,atoi(&numOfQusInf.text[0]));
					isLoadExam=false;
					isTesting=true;
					quesBtnList=ButtonList(492, 475, atoi(&numOfQusInf.text[0]), 60, 30);
					ansListStudent=new Answers[atoi(&numOfQusInf.text[0])];
					for(int i=0; i<atoi(&numOfQusInf.text[0]); i++)
					{
						ansListStudent[i]=nonAns;
					}
					
				}
				showPnl(l_m_Pnl);
				showPnl(r_m_Pnl);
				showPnl(r_b_Pnl);
				setcolor(textColor);
				outtextxy(idSubjectInf.x, idSubjectInf.y-25, "Ma mon hoc:");
				showInputField(idSubjectInf);
				
				outtextxy(idSubjectInf.x, numOfQusInf.y-25, "So luong cau hoi:");
				showInputField(numOfQusInf);
				
				outtextxy(idSubjectInf.x, timeInf.y-25, "Thoi gian thi:");
				showInputField(timeInf);
				
				

				
				
				
				if(!isTesting && !isFinish)
					startBtn.show();
				if(isFinish)
				{
					char buff[10];
					setcolor(RED);
					setbkcolor(WHITE);
					outtextxy(800, 50, "Diem:");
					float score=marking(atoi(&numOfQusInf.text[0]), exam, ansListStudent);
					if((isWriteFileInforExamOfStudent && !isWroteTestFile)||(isTimeout && !isWroteTestFile))
					{
						isWriteFileInforExamOfStudent=false;
						isWroteTestFile=true;
						writeFileInforExamOfStudent(userNameInf.text, idSubjectInf.text, score, atoi(&numOfQusInf.text[0]),  exam);		
//						writeFileScoreOfClass(userNameInf.text, idSubjectInf.text, score);				
					}

					outtextxy(850, 50, itoa(score, buff, 10));
					//ghi file chi tiet bai thi SV
					
				}
				if(isTesting || isFinish)
				{
					
					
					if(isLoadQS)
					{
						ansA_Btn.text=exam[curQues].question_answer_A;
						ansB_Btn.text=exam[curQues].question_answer_B;
						ansC_Btn.text=exam[curQues].question_answer_C;
						ansD_Btn.text=exam[curQues].question_answer_D;
						tmpQuestion=exam[curQues].question_content;
						
						isLoadQS=false;
					}
					setbkcolor(WHITE);
					setcolor(textColor);
					outtextxy(r_m_Pnl.x+50, r_m_Pnl.y+85, &tmpQuestion[0]);
					outtextxy(r_m_Pnl.x+50, r_m_Pnl.y+50, "Cau hoi so 1:");

					outtextxy(ansA_Btn.x-25, ansA_Btn.y+(ansA_Btn.height-textheight("A"))/2, "A");
					outtextxy(ansB_Btn.x-25, ansB_Btn.y+(ansB_Btn.height-textheight("B"))/2, "B");
					outtextxy(ansC_Btn.x-25, ansC_Btn.y+(ansC_Btn.height-textheight("C"))/2, "C");
					outtextxy(ansD_Btn.x-25, ansD_Btn.y+(ansD_Btn.height-textheight("D"))/2, "D");

					showGroupBtn(ansA_Btn, ansB_Btn, ansC_Btn, ansD_Btn,curQues, exam,ansListStudent, isFinish);
					quesBtnList.showQuesBtnList(atoi(&numOfQusInf.text[0]), curQues, exam,ansListStudent, isFinish);
				}
				if(isTesting)
				{
					submitBtn.show();
					
					setbkcolor(WHITE);
					setcolor(textColor);
					string minute, second;
					if(mm<10)
						minute="0"+to_string(mm);
					if(ss<10)
						second="0"+	to_string(ss);
					else	second=to_string(ss);
					string s=minute+":"+second;
					if(mm==0)	setcolor(RED);			
					outtextxy(1050, 30, &s[0]);	
					setcolor(BLACK);	
				}	
				else
					exitBtn.show();
				if(!isMouseUsing)
				{	
					setbkcolor(WHITE);
					showInputField(tmpInf);
				}
			}
		}
		
		
		
		
//		showDialog();
		// Xu ly chuot
		if(GetAsyncKeyState(VK_LBUTTON))
		{
			GetCursorPos(&cursorPosition);
			ScreenToClient(GetForegroundWindow(), &cursorPosition);
			cursorX=cursorPosition.x;
			cursorY=cursorPosition.y;
			if(tmpcursorX!=cursorX && tmpcursorY!=cursorY)
			{
				if(!isLogged)
				{
					if(cursorX>=userNameInf.x && cursorX<userNameInf.x+userNameInf.width)
					{
						if(cursorY>=userNameInf.y && cursorY<userNameInf.y+userNameInf.height)
						{
							isMouseUsing=false;
							infPointer=createInf(tmpInf,userNameInf);
							showInputField(tmpInf);
							strInputting=&userNameInf.text;
							isInputUpper=true;
							isInputPass=false;
						}
						else if(cursorY>=passInf.y && cursorY<passInf.y+passInf.height)
						{
							isMouseUsing=false;
							infPointer=createInf(tmpInf,passInf);
							showInputField(tmpInf);
							strInputting=&passInf.text;
							isInputUpper=false;
							isInputPass=true;
						}
						else if(cursorY>=loginBtn.y && cursorY<loginBtn.y+loginBtn.height)
						{
							Roles *tmp=checkLogin(userNameInf.text, password);
//							cout<<*tmp;
							if(tmp!=NULL)
							{
								if(*tmp==student)
								{
									isMouseUsing=true;
									isLogged=true;
									role=student;
								}	
								else if(*tmp==teacher)
								{
									isMouseUsing=true;
									isLogged=true;
									role=teacher;
								}
							}
							else
							{
								isErrorLbl=true;
								
							}
							isInputPass=false;
							isMouseUsing=true;
						}
					}
					
								
				}
				else
				{
					if(isDialog)
					{
						
						if(cursorY>=dialog.opUnSave.y && cursorY<dialog.opUnSave.y+dialog.opUnSave.height)
						{
							
							if(cursorX>=dialog.opSave.x && cursorX<dialog.opSave.x+dialog.opSave.width) //Luu thay doi nhap lieu
							{
								
								if(isTesting)
								{
										isTesting=false;
										isFinish=true;
										isWriteFileInforExamOfStudent=true;
//										terminate();
								}
								else
								{
//									if(!isAddDone)
//										editQuestion(subjArray[indexLeft]->sj.qsList,indexRight, quesInf.text, answerAInf.text, answerBInf.text, answerCInf.text, answerDInf.text, resultInf.text);	
									if(tab==1)
									{
										if(isInputtingRight || isInputtingLeft)
										{
											isInputtingRight=false;
											isInputtingLeft=false;
											isChanged=false;
											isMouseUsing=true;
										}
										if(isAddingLeft)	isAddingLeft=false;
										else if(isAddingRight)	isAddingRight=false;
									}
									else if(tab==0)
									{
										isChanged=false;
										isMouseUsing=true;
									}
								}
								
								isDialog=false;
//								isMouseUsing=true;
								
//								isLoadRightList=true;
//								if(isAddingRight || isAddingLeft)	isStartAdd=true;
//								else isStartAdd=false;
//								else if()	isStartAdd=true;	
							}
							else if(cursorX>=dialog.opUnSave.x && cursorX<dialog.opUnSave.x+dialog.opUnSave.width) //Huy bo thay doi nhap lieu
							{
								if(isTesting)
									isDialog=false;
								else
								{
//									quesInf.text= subjArray[indexLeft]->sj.qsList.question_QSList[indexRight].question_content;
//									answerAInf.text=subjArray[indexLeft]->sj.qsList.question_QSList[indexRight].question_answer_A;
//									answerBInf.text=subjArray[indexLeft]->sj.qsList.question_QSList[indexRight].question_answer_B;
//									answerCInf.text=subjArray[indexLeft]->sj.qsList.question_QSList[indexRight].question_answer_C;
//									answerDInf.text=subjArray[indexLeft]->sj.qsList.question_QSList[indexRight].question_answer_D;
//									resultInf.text= subjArray[indexLeft]->sj.qsList.question_QSList[indexRight].question_correctAnswer;
									if(tab==1)
									{
										if(isInputtingRight|| isInputtingLeft)
										{
											isMouseUsing=false;
//											showInputField(tmpInf);
										}
									}
									else if(tab==0)
									{
										isMouseUsing=false;
									}
								}
								
								
								isDialog=false;
//								isMouseUsing=true;
//								isChanged=false;
							}
							else if(cursorX>=dialog.opOK.x && cursorX<dialog.opOK.x+dialog.opOK.width) //OKKKK
							{
//								cout<<"Hereeee!";
								
//								isMouseUsing=false; //false
//								isDialog=false;
//								isChanged=false;
								if(!isMouseUsing)
								{
									isMouseUsing=false;
//											showInputField(tmpInf);
								}
//								if(isAddDone)	isMouseUsing=true;
								isDialog=false;
//                                if(isAddingRight || isAddingLeft)	isStartAdd=true;
//                                else isStartAdd=false;
							}	
						}
						
						else if(cursorY>=dialog.opOK.y && cursorY<dialog.opOK.y+dialog.opOK.height)
						{
							
							if(cursorX>=dialog.opOK.x && cursorX<dialog.opOK.x+dialog.opOK.width) //OKKKK
							{
//								isMouseUsing=false;
//								isDialog=false;
//								isChanged=false;
//								if(isAddingRight || isAddingLeft)	isStartAdd=true;
//								else isStartAdd=false;
//								cout<<"thereeeeeeeee";
								if(!isMouseUsing)
								{
									isMouseUsing=false;
//											showInputField(tmpInf);
								}
//								if(isAddDone)	isMouseUsing=true;
								isDialog=false;
							}	
						}
					}	
					else if(isView || isViewScoreOfClass || isViewDetailExam)
					{
						if((cursorY>=yView && cursorY<yView+hView) && (cursorX>=xView && cursorX<xView+wView))
						{
							if(cursorY>=exitViewBtn.y && cursorY<exitViewBtn.y+exitViewBtn.height)
							{
								if(cursorX>=exitViewBtn.x && cursorX<exitViewBtn.x+exitViewBtn.width)
								{
									isView=false;
									viewListClassBtn.isSelected=false;
									if(isViewScoreOfClass)
									{
										isViewScoreOfClass=false;
										isView=true;
										rowViewTbl=0;
										pageViewTbl=0;
										lengthOfViewList=countNodes(subjList.tree);
									}
									else if(isViewDetailExam)
									{
										isViewDetailExam=false;
										isViewScoreOfClass=true;
										rowViewTbl=0;
										pageViewTbl=0;
										lengthOfViewList=classList.ds[indexLeft]->sl;
									}
								}
								else if (cursorX>=showScoreBtn.x && cursorX<showScoreBtn.x+showScoreBtn.width)
								{
									if(isView)
									{
										isViewScoreOfClass=true;
										lengthOfViewList=classList.ds[indexLeft]->studentList.getLength();
										pageViewTbl=0;
										rowViewTbl=0;
										isView=false;
									}
									else if(isViewScoreOfClass)
									{
//										cout<<"HEREEEE";
//										cout<<"do dai"<<classList.ds[indexLeft]->studentList.getStudent(indexStudent).scoreList.searchScore(idSelecting)
										
										if(classList.ds[indexLeft]->studentList.getStudent(indexStudent).scoreList.searchScore(idSelecting)>=0)
										{
											isViewScoreOfClass=false;
											isViewDetailExam=true;
											lengthOfViewList=classList.ds[indexLeft]->studentList.getStudent(indexStudent).scoreList.searchIDSub(idSelecting)->exam.length;
											pageViewTbl=0;
											rowViewTbl=0;
										}
										else
										{
											dialog=Dialog("Du lieu rong!", "","","OK");
											isDialog=true;
										}
										
									}
									
								}
							}
							else if(cursorY>=subjTbl.yRow0 && cursorY<subjTbl.y+subjTbl.height)
							{	
								if(cursorX>=subjTbl.x && cursorX<subjTbl.x+subjTbl.width)
								{
									int tmp=(cursorY-subjTbl.yRow0)/subjTbl.hRow;
									if((tmp+pageViewTbl*10)<lengthOfViewList)
										rowViewTbl=tmp;
									isMouseUsing=true;
									
									
									
								}
							}
							else if(cursorY>=vPageBtns.y && cursorY<vPageBtns.y+sizePageBtn)	// click doi trang 
							{
								if(cursorX>=vPageBtns.x && cursorX<vPageBtns.x+vPageBtns.width)
								{
									pageViewTbl=(cursorX-vPageBtns.x)/sizePageBtn;
									isMouseUsing=true;
								}
							}
						}
						else
						{
							isView=false;
							isViewDetailExam=false;
							isViewScoreOfClass=false;
							viewListClassBtn.isSelected=false;
						}
					}
					else
					{
						
						if(role==teacher)
						{
							// Con tro chuot dang o thanh menu bar
							if(cursorY>=yMenuBar && cursorY<yListPnl)	
							{
								
								
								if(cursorX>=classesBtn.x && cursorX<classesBtn.x+classesBtn.width && tab!=0)
								{
//									cout<<"HEREEEE";
//									if(isUpdateFile)
//									{
//										writeQsFile(subjArray[indexLeft]->sj.qsList, subjArray[indexLeft]->sj.subjectId);
//										isUpdateFile=false;
//									}
									if(isInputBlank(dialog,6, quesInf.text, answerAInf.text, answerBInf.text, answerCInf.text, answerDInf.text, resultInf.text)&& idLbl!="")
									{
										if(isAddingRight)
										{
											dialog=Dialog("Dang them moi!", "","","OK");
											isDialog=true;
										}	
//										else	
//										isDialog=true;
									}
									else if(isChanged)
									{
										isDialog=true;
										dialog=Dialog("Dang nhap lieu, luu thay doi?", "Luu","Khong luu");
									}
									else
									{
//										cout<<"HEREEEE111";
										tab=0;
										isSexSelecting=false;
										isAddingRight=false;
										isMouseUsing=true;
										pageLeftTbl=0;
										rowLeftTbl=0;
										pageRightTbl=0;
										rowRightTbl=0;
									} 
									
								}
								else if(cursorX>=subjectsBtn.x && cursorX<subjectsBtn.x+subjectsBtn.width && tab!=1)
								{
//									if(isUpdateFile)
//									{
//										cout<<"There";
//										if(!writeFileStudentsOfClass(classList.ds[indexLeft]->classID, classList.ds[indexLeft]->studentList))
//										{ 
//											isDialog=true;
//											dialog=Dialog("File khong ton tai!","","","OK");
//										}
//										isUpdateFile=false;
//									}
									if(isInputBlank(dialog,2, firstNameInf.text, lastNameInf.text))
									{
										if(isAddingRight)
										{
											dialog=Dialog("Dang them moi!", "","","OK");
											isDialog=true;
										}	
										else	
										isDialog=true;
									}
									else if(isChanged)
									{
										isDialog=true;
										dialog=Dialog("Dang nhap lieu, luu thay doi?", "Luu","Khong luu");
									}
									else
									{
										tab=1;
										isAddingRight=false;
										isMouseUsing=true;
										pageLeftTbl=0;
										rowLeftTbl=0;
										pageRightTbl=0;
										rowRightTbl=0;
										lengthOfLeftList=countNodes(subjList.tree);
										subjTbl=Table(l_m_Pnl.x+15, l_m_Pnl.y+50, l_m_Pnl.width-15*2, l_m_Pnl.height-130);
//										cout<<"lengthOfLeftList "<<lengthOfLeftList;
									}
									
								}
								else if(cursorX>=exitBtn.x && cursorX<exitBtn.x+exitBtn.width)
								{
									isLogged=false;
									isWriteFile=true;
									isFreeMemory=true;
								}
							}
							//Con tro dang o phan giua
							else if(cursorY>=l_m_Pnl.y && cursorY<l_m_Pnl.y+l_m_Pnl.height)
							{
								
								isSexSelecting=false;
								if(cursorX>=l_m_Pnl.x && cursorX<l_m_Pnl.x+l_m_Pnl.width)
								{
//									
									if(tab==0)
									{
										
//										if(isAddingRight)
//										{
//											dialog=Dialog("Dang them moi!", "","","OK");
//											isDialog=true;
//										}	
//										else if(isInputBlank(dialog,6, quesInf.text, answerAInf.text, answerBInf.text, answerCInf.text, answerDInf.text, resultInf.text))
//										{
//											isDialog=true;
//										}
//										else if(isChanged)
//										{
//											isDialog=true;
//											dialog=Dialog("Dang nhap lieu, luu thay doi?", "Luu","Khong luu");
//										}
										/*else */if(cursorY>=classTbl.yRow0 && cursorY<classTbl.y+classTbl.height)
										{
											
											if(cursorX>=classTbl.x && cursorX<classTbl.x+classTbl.width)
											{
//												cout<<"So hang bang trai: "<<lengthOfLeftList;
												int tmpRow=rowLeftTbl;
												int tmp=(cursorY-classTbl.yRow0)/classTbl.hRow;
												if((tmp+pageLeftTbl*10)<lengthOfLeftList)
													rowLeftTbl=tmp;
												
												if(tmpRow!=rowLeftTbl)	
												{
//													idLeftSelecting=classList.ds[indexLeft]->classID;
													rowRightTbl=0;
													pageRightTbl=0;
//													isLoadFile=true;
//													isLoadRightList=true;
												}
//												idLeftSelecting=
												isMouseUsing=true;
											}
										}
										else if(cursorY>=lPageBtns.y && cursorY<lPageBtns.y+sizePageBtn)	// click doi trang 
										{
											if(cursorX>=lPageBtns.x && cursorX<lPageBtns.x+lPageBtns.width)
											{
												pageLeftTbl=(cursorX-lPageBtns.x)/sizePageBtn;
												isMouseUsing=true;
											}
										}
										else if(cursorY>=viewListClassBtn.y && cursorY<viewListClassBtn.y+viewListClassBtn.height)
										{
											if(cursorX>=viewListClassBtn.x && cursorX<viewListClassBtn.x+viewListClassBtn.width)
											{
												isView=true;
												lengthOfViewList=countNodes(subjList.tree);
											}
										}
									}
									else if(tab==1)
									{
										
//										cout<<"Thay doi: "<<isChanged;
										if(isAddingRight)
										{
//											cout<<"HEREEE1";
											dialog=Dialog("Dang them moi!", "","","OK");
											isDialog=true;
										}	
//										else if(isInputBlank(dialog,2, idSubjectInf.text, nameSubjInf.text))
//										{
////											cout<<"HEREEE2";
//											isDialog=true;
//										}
										else if(isChanged)
										{
											isDialog=true;
											dialog=Dialog("Dang nhap lieu, luu thay doi?", "Luu","Khong luu");
										}
										else if(cursorY>=classTbl.yRow0 && cursorY<classTbl.y+classTbl.height)	//subjecttbl dung tam bien classTbl
										{
											if(cursorX>=classTbl.x && cursorX<classTbl.x+classTbl.width)
											{
//												cout<<"SO HANG TRAI: "<<lengthOfLeftList;
												int tmpRow=rowLeftTbl;
												int tmp=(cursorY-classTbl.yRow0)/subjTbl.hRow;
												if((tmp+pageLeftTbl*10)<lengthOfLeftList)
													rowLeftTbl=tmp;
												
												if(tmpRow!=rowLeftTbl)
												{
													rowRightTbl=0;
													pageRightTbl=0;
												}
												cout<<" Hang dang chon: "<< rowLeftTbl;
												isMouseUsing=true;
											}
										}
										else if(cursorY>=lPageBtns.y && cursorY<lPageBtns.y+sizePageBtn)	// click doi trang 
										{
											if(cursorX>=lPageBtns.x && cursorX<lPageBtns.x+lPageBtns.width)
											{
												
												pageLeftTbl=(cursorX-lPageBtns.x)/sizePageBtn;
												isMouseUsing=true;
											}
										}
										else if(cursorY>=l_addBtn.y && cursorY<l_addBtn.y+l_addBtn.height)
										{
											if(cursorX>=l_addBtn.x && cursorX<l_addBtn.x+l_addBtn.width)
											{
//												cout<<"O day";
												isAddingLeft=true;
												isInputtingLeft=true;
//												cout<<isAddingLeft;
//												isAddingRight=false;
												isStartAdd=true;
												isMouseUsing=false;
											}
											else if(cursorX>=deleteBtn.x && cursorX<deleteBtn.x+deleteBtn.width && lengthOfRightList==0)
											{
												deleteNode(subjList.tree,subjArray[indexLeft]->sj.subjectId);
												int index=0;
												treeToArray(subjList.tree, subjArray, index);
												sortSubject(subjArray, countNodes(subjList.tree));
												isWriteFileSubjects=true;
												isDialog=true; 
												dialog=Dialog("Thanh cong!", "", "", "OK");
												rowLeftTbl=0;
												pageLeftTbl=0;
												lengthOfLeftList=countNodes(subjList.tree);
//												showSubjectTbl(classTbl, subjArray, lengthOfLeftList, rowLeftTbl, pageLeftTbl);	
											}
										}
									}
								}
								else if(cursorX>=r_m_Pnl.x && cursorX<r_m_Pnl.x+r_m_Pnl.width) //Con tro chuot dang o ben phai
								{
//									cout<<"CHANGEDDDD: "<<isChanged<<endl;
									if(tab==1)
									{
										if(isAddingLeft)
										{
											dialog=Dialog("Dang them moi!", "","","OK");
											isDialog=true;
										}	
//										else if(isInputBlank(dialog,6, quesInf.text, answerAInf.text, answerBInf.text, answerCInf.text, answerDInf.text, resultInf.text))
//										{
//											cout<<"HEREEEE"<<endl;
//											isDialog=true;
//										}
										else if(isChanged)
										{
											isDialog=true;
											dialog=Dialog("Dang nhap lieu, luu thay doi?", "Luu","Khong luu");
										}
										else if(cursorY>=quesTbl.yRow0 && cursorY<quesTbl.y+quesTbl.height)
										{
											if(cursorX>=quesTbl.x && cursorX<quesTbl.x+quesTbl.width)
											{
												int tmp=(cursorY-quesTbl.yRow0)/quesTbl.hRow;
												if((tmp+pageRightTbl*10)<lengthOfRightList)
													rowRightTbl=tmp;
												isMouseUsing=true;
											}
										}
										else if(cursorY>=rPageBtns.y && cursorY<rPageBtns.y+sizePageBtn)	// click doi trang 
										{
											if(cursorX>=rPageBtns.x && cursorX<rPageBtns.x+rPageBtns.width)
											{
												pageRightTbl=(cursorX-rPageBtns.x)/sizePageBtn;
												isMouseUsing=true;
											}
										}
										else if(cursorY>=r_addBtn.y && cursorY<r_addBtn.y+r_addBtn.height)
										{
											if(cursorX>=r_addBtn.x && cursorX<r_addBtn.x+r_addBtn.width)
											{
												isAddingRight=true;
												isStartAdd=true;
												isInputtingRight=true;
												isMouseUsing=false;
											}
										}
									}
									else if(tab==0)
									{
	
										if(isAddingRight)
										{
											dialog=Dialog("Dang them moi!", "","","OK");
											isDialog=true;
										}	
										else if(isInputBlank(dialog,2, firstNameInf.text, lastNameInf.text))
										{
											isDialog=true;
										}
										else if(isChanged)
										{
											isDialog=true;
											dialog=Dialog("Dang nhap lieu, luu thay doi?", "Luu","Khong luu");
										}
										
										else if(cursorY>=studentTbl.yRow0 && cursorY<studentTbl.y+studentTbl.height)
										{
											if(cursorX>=studentTbl.x && cursorX<studentTbl.x+studentTbl.width)
											{
												cout<<"So hang bang phai: "<< lengthOfRightList;
												int tmp=(cursorY-studentTbl.yRow0)/studentTbl.hRow;
												if((tmp+pageRightTbl*10)<lengthOfRightList)
													rowRightTbl=tmp;
//												cout<<"Diem: "<<classList.ds[indexLeft]->studentList.getStudent(rowRightTbl+pageRightTbl*10).scoreList.pHead->exam[0].studentAnswer<<endl;
												isMouseUsing=true;		
											}
										}
										else if(cursorY>=rPageBtns.y && cursorY<rPageBtns.y+sizePageBtn)	// click doi trang 
										{
											if(cursorX>=rPageBtns.x && cursorX<rPageBtns.x+rPageBtns.width)
											{
												page=(cursorX-rPageBtns.x)/sizePageBtn;
												isMouseUsing=true;
											}
										}
										
										else if(cursorY>=r_addBtn.y && cursorY<r_addBtn.y+r_addBtn.height)
										{
											if(cursorX>=r_addBtn.x && cursorX<r_addBtn.x+r_addBtn.width)
											{
												isAddingRight=true;
												isStartAdd=true;
	//											isSexSelecting=true;
											}
										}
									}
								
								}
							}
							//Con tro dang o phan cuoi
							else if(cursorY>=r_b_Pnl.y && cursorY<r_b_Pnl.y+r_b_Pnl.height)
							{
								if(tab==0)
								{
									if(cursorX>=r_b_Pnl.x && cursorX<r_b_Pnl.x+r_b_Pnl.width)
									{
										if(cursorX>=firstNameInf.x && cursorX<firstNameInf.x+firstNameInf.width)
										{
											if(cursorY>=firstNameInf.y && cursorY<firstNameInf.y+firstNameInf.height)
											{
												isMouseUsing=false;
	//											isIn
												infPointer=createInf(tmpInf,firstNameInf);
												showInputField(tmpInf);
												oldStr=firstNameInf.text;
												strInputting=&firstNameInf.text;
												
											}
											else if(cursorY>=lastNameInf.y && cursorY<lastNameInf.y+lastNameInf.height)
											{
												isMouseUsing=false;
												infPointer=createInf(tmpInf,lastNameInf);
												showInputField(tmpInf);
												oldStr=lastNameInf.text;
												strInputting=&lastNameInf.text;
											}
											else if(cursorY>=maleBtn.y && cursorY<maleBtn.y+maleBtn.height)
											{
			//									Chon gioi tinh
			
												if(cursorX>=maleBtn.x && cursorX<maleBtn.x+maleBtn.width)
												{
													
	//												if(!isMouseUsing)
	//												{
	//													if(checkStudentEntered(firstNameInf.text, lastNameInf.text, dialog, false))
	//														isDialog=true;
	//													else
	//													{
	//														
	//														Question tmpQues= Question(quesInf.text, answerAInf.text, answerBInf.text, answerCInf.text, answerDInf.text, resultInf.text);
	//														Student tmpStu=Student(firstNameInf.text, lastNameInf.text, "Nam");
	//														if(studentList.addStudent(initializeStudentNode(tmpStu)))
	//														{
	//															
	//															dialog=Dialog("Thanh cong!", "", "", "OK");
	//															isDialog=true;
	//		//													isLoadFile=true;
	////															show_item(quesList);
	////															cout<<quesList.n;
	//														}
	//													} 
	//												}
													sex=1;
													isSexSelecting=true;
	//												isMouseUsing=false;
												}
												else if(cursorX>=femaleBtn.x && cursorX<femaleBtn.x+femaleBtn.width)
												{
													
	//												
													sex=0;
	//												isMouseUsing=false;
													isSexSelecting=true;
												}
											}
											else if(cursorY>=r_SaveBtn.y && cursorY<r_SaveBtn.y+r_SaveBtn.height)
											{
												
												if(cursorX>=r_SaveBtn.x && cursorX<r_SaveBtn.x+r_SaveBtn.width)
												{
													
													if(!isMouseUsing || isSexSelecting)
													{
			
														if(isInputBlank(dialog,2, firstNameInf.text, lastNameInf.text))
														{
															dialog=Dialog("Cac truong khong duoc de trong!", "","","OK");
															isDialog=true;
														}
														else
														{
															if(r_addBtn.isSelected)
															{
	//															
																Student tempStudent=Student(idLbl,formatStr(firstNameInf.text) ,formatStr(lastNameInf.text) , sex);
//																cout<<idLbl<<firstNameInf.text<<lastNameInf.text<<sex<<endl;
//																cout<<tempStudent.id<<tempStudent.firstName<<tempStudent.lastName<<tempStudent.sex<<tempStudent.password<<endl;
																if(classList.ds[indexLeft]->studentList.addStudent(initializeStudentNode(tempStudent)))
																{
	//																cout<<"Helllo"<<studentList.getStudent(4).id<<endl;
																	dialog=Dialog("Thanh cong!", "", "", "OK");
																	isDialog=true;
																	isAddDone=true;
																	isUpdateFile=true;
																}
															}
															else
															{
	//															editQuestion(quesList,indexRight, quesInf.text, answerAInf.text, answerBInf.text, answerCInf.text, answerDInf.text, resultInf.text);
																editStudent(classList.ds[indexLeft]->studentList, indexRight, firstNameInf.text, lastNameInf.text, sex);
																isMouseUsing=true;
																isUpdateFile=true;
																isChanged=false;
															}
															isWriteFileClasses=true;
	
														} 
													}
												
												}
												else if(cursorX>=r_LeaveBtn.x && cursorX<r_LeaveBtn.x+r_LeaveBtn.width)
												{
													int tmpFlag=isInputBlank(dialog,2, firstNameInf.text, lastNameInf.text);
													if(tmpFlag==1)
													{
														isDialog=true;		
													}
													else if(isChanged)
													{
														isDialog=true;
	//													isClickedExit=true;
														dialog=Dialog("Chua luu lai nhap lieu, quay lai nhap lieu?", "Thoat","Quay lai");
													}
													else if(isAddingRight)
													{
														if(tmpFlag==-1)
														{
															
															isAddingRight=false;
															isMouseUsing=true;
														}
													}
													
												}
											}
										}
									}
//									else if(cursorX>=l_b_Pnl.x && cursorX<l_b_Pnl.x+l_b_Pnl.width)
//									{
//										if(cursorY>=viewListSubjectBtn.y && cursorY<viewListSubjectBtn.y+viewListSubjectBtn.height)
//										{
//											if(cursorX>=viewListSubjectBtn.x && cursorX<viewListSubjectBtn.x+viewListSubjectBtn.width)
//											{
//												isView=true;
//												lengthOfViewList=countNodes(subjList.tree);
//												isMouseUsing=false;
//											}
//										}
//									}
									
//									if(cursorX>=answerAInf.x && cursorX<answerAInf.x+answerAInf.width)
//									{
//				
//										if(cursorY>=answerAInf.y && cursorY<answerAInf.y+answerAInf.height)
//										{
//											
//											isMouseUsing=false;
//											infPointer=createInf(tmpInf,answerAInf);
//											showInputField(tmpInf);
//											oldStr=answerAInf.text;
//											strInputting=&answerAInf.text;
//										}
//										else if(cursorY>=answerCInf.y && cursorY<answerCInf.y+answerCInf.height)
//										{
//											
//											isMouseUsing=false;
//											infPointer=createInf(tmpInf,answerCInf);
//											showInputField(tmpInf);
//											oldStr=answerCInf.text;
//											strInputting=&answerCInf.text;
//										}
//									}
//									else if(cursorX>=answerBInf.x && cursorX<answerBInf.x+answerBInf.width)
//									{
//										if(cursorY>=answerBInf.y && cursorY<answerBInf.y+answerBInf.height)
//										{
//											isMouseUsing=false;
//											infPointer=createInf(tmpInf,answerBInf);
//											showInputField(tmpInf);
//											oldStr=answerBInf.text;
//											strInputting=&answerBInf.text;
//										}
//										else if(cursorY>=answerDInf.y && cursorY<answerDInf.y+answerDInf.height)
//										{
//											isMouseUsing=false;
//											infPointer=createInf(tmpInf,answerDInf);
//											showInputField(tmpInf);
//											oldStr=answerDInf.text;
//											strInputting=&answerDInf.text;
//										}
//									}
								}
								else if(tab==1)
								{
									if(cursorX>=r_b_Pnl.x && cursorX<r_b_Pnl.x+r_b_Pnl.width)
									{
										if(isAddingLeft)
										{
											dialog=Dialog("Dang them moi!", "","","OK");
											isDialog=true;
										}
										else if(cursorX>=quesInf.x && cursorX<quesInf.x+quesInf.width)
										{
											if(cursorY>=quesInf.y && cursorY<quesInf.y+quesInf.height)
											{
												isMouseUsing=false;
												isInputtingRight=true;
												infPointer=createInf(tmpInf,quesInf);
												showInputField(tmpInf);
												oldStr=quesInf.text;
												strInputting=&quesInf.text;
												
											}
											else if(cursorY>=resultInf.y && cursorY<resultInf.y+resultInf.height)
											{
												isMouseUsing=false;
												isInputtingRight=true;
												infPointer=createInf(tmpInf,resultInf);
	//											testInf=&resultInf;
												showInputField(tmpInf);
												oldStr=resultInf.text;
												strInputting=&resultInf.text;
	//											isInputUpper=true
											}
											else if(cursorY>=r_SaveBtn.y && cursorY<r_SaveBtn.y+r_SaveBtn.height)
											{
			//									cout<<"Luu";
												if(cursorX>=r_SaveBtn.x && cursorX<r_SaveBtn.x+r_SaveBtn.width)
												{
													
													if(!isMouseUsing)
													{
			
														if(isInputBlank(dialog,6, quesInf.text, answerAInf.text, answerBInf.text, answerCInf.text, answerDInf.text, resultInf.text))
														{
															dialog=Dialog("Cac truong khong duoc de trong!", "","","OK");
															isDialog=true;
														}
														else if(isDupInput(answerAInf.text, answerBInf.text, answerCInf.text, answerDInf.text))
														{
															dialog=Dialog("Dap dan khong duoc trung lap!", "","","OK");
															isDialog=true;
														}
														else
														{
															if(r_addBtn.isSelected)
															{
																Question tmpQues= Question(quesInf.text, answerAInf.text, answerBInf.text, answerCInf.text, answerDInf.text, resultInf.text[0]);
																if(add_QSList(subjArray[indexLeft]->sj.qsList, tmpQues))
																{
																	dialog=Dialog("Thanh cong!", "", "", "OK");
																	isDialog=true;
																	isAddDone=true;
//																	isUpdateFile=true;
																	isStartAdd=true;
																	isMouseUsing=true;
																	isWriteFileSubjects=true;
																}
																else
																{
																	dialog=Dialog("Vuot qua so luong cau hoi (200)!", "", "", "OK");
																	isDialog=true;
																	isMouseUsing=true;
																}
															}
															else
															{
																if(checkEditableQues(classList, subjArray[indexLeft]->sj.subjectId, idLbl))
																{
																	editQuestion(subjArray[indexLeft]->sj.qsList,indexRight, quesInf.text, answerAInf.text, answerBInf.text, answerCInf.text, answerDInf.text, resultInf.text[0]);
																	isMouseUsing=true;
																	isUpdateFile=true;
																	isChanged=false;
																	isWriteFileSubjects=true;
																}
																else
																{
																	dialog=Dialog("Khong the chinh sua cau hoi nay", "", "", "OK");
																	isDialog=true;
																	isMouseUsing=true;
																	isChanged=false;
																}
															}
	
														} 
													}
												
												}
												else if(cursorX>=r_LeaveBtn.x && cursorX<r_LeaveBtn.x+r_LeaveBtn.width)
												{
													int tmpFlag=isInputBlank(dialog,6, quesInf.text, answerAInf.text, answerBInf.text, answerCInf.text, answerDInf.text, resultInf.text);
													if(tmpFlag==1)
													{
														dialog=Dialog("Cac truong khong duoc de trong!", "","","OK");
														isDialog=true;		
													}
													else if(isChanged)
													{
														isDialog=true;
	//													isClickedExit=true;
														dialog=Dialog("Dang nhap lieu, ban muon thoat?", "Thoat","Tro lai");
													}
													else if(isAddingRight)
													{
	//													cout<<"fsdhgjkfauhjfd";
														if(tmpFlag==-1)
														{
															isInputtingRight=false;
															isAddingRight=false;
															isMouseUsing=true;
														}
													}
													
												}
											}
					
										}
										
										if(cursorX>=answerAInf.x && cursorX<answerAInf.x+answerAInf.width)
										{
					
											if(cursorY>=answerAInf.y && cursorY<answerAInf.y+answerAInf.height)
											{
												
												isMouseUsing=false;
												isInputtingRight=true;
												infPointer=createInf(tmpInf,answerAInf);
												showInputField(tmpInf);
												oldStr=answerAInf.text;
												strInputting=&answerAInf.text;
											}
											else if(cursorY>=answerCInf.y && cursorY<answerCInf.y+answerCInf.height)
											{
												
												isMouseUsing=false;
												isInputtingRight=true;
												infPointer=createInf(tmpInf,answerCInf);
												showInputField(tmpInf);
												oldStr=answerCInf.text;
												strInputting=&answerCInf.text;
											}
										}
										else if(cursorX>=answerBInf.x && cursorX<answerBInf.x+answerBInf.width)
										{
											if(cursorY>=answerBInf.y && cursorY<answerBInf.y+answerBInf.height)
											{
												isMouseUsing=false;
												isInputtingRight=true;
												infPointer=createInf(tmpInf,answerBInf);
												showInputField(tmpInf);
												oldStr=answerBInf.text;
												strInputting=&answerBInf.text;
											}
											else if(cursorY>=answerDInf.y && cursorY<answerDInf.y+answerDInf.height)
											{
												isMouseUsing=false;
												isInputtingRight=true;
												infPointer=createInf(tmpInf,answerDInf);
												showInputField(tmpInf);
												oldStr=answerDInf.text;
												strInputting=&answerDInf.text;
											}
										}
									}
									else if(cursorX>=l_b_Pnl.x && cursorX<l_b_Pnl.x+l_b_Pnl.width)
									{
										if(isAddingRight)
										{
											dialog=Dialog("Dang them moi!", "","","OK");
											isDialog=true;
										}
										else if(cursorX>=idSubjInf.x && cursorX<idSubjInf.x+idSubjInf.width)
										{
											if(cursorY>=idSubjInf.y && cursorY<idSubjInf.y+idSubjInf.height && isAddingLeft)
											{
												isMouseUsing=false;
												infPointer=createInf(tmpInf,idSubjInf);
												showInputField(tmpInf);
												oldStr=idSubjInf.text;
												strInputting=&idSubjInf.text;
												isInputtingLeft=true;
											}
											else if(cursorY>=nameSubjInf.y && cursorY<nameSubjInf.y+nameSubjInf.height)
											{
												isMouseUsing=false;
												infPointer=createInf(tmpInf,nameSubjInf);
	//											testInf=&resultInf;
												showInputField(tmpInf);
												oldStr=nameSubjInf.text;
												strInputting=&nameSubjInf.text;
	//											isInputUpper=true
												isInputtingLeft=true;
											}
											else if(cursorY>=l_SaveBtn.y && cursorY<l_SaveBtn.y+l_SaveBtn.height)
											{
												cout<<"Luu";
												if(cursorX>=l_SaveBtn.x && cursorX<l_SaveBtn.x+l_SaveBtn.width)
												{
													
													if(!isMouseUsing)
													{
														if(!isAddingLeft)
														{
															if(nameSubjInf.text=="")
															{
																dialog=Dialog("Ten mon khong duoc de trong!", "","","OK");
																isDialog=true;
															}
															else
															{
																editSubject(subjList, idSubjLbl, nameSubjInf.text);
																isMouseUsing=true;
//																isUpdateFile=true;
																isChanged=false;
															}
														}
														else
														{
															if(isInputBlank(dialog,2, idSubjInf.text, nameSubjInf.text))
															{
																dialog=Dialog("Cac truong khong duoc de trong!", "","","OK");
																isDialog=true;
															}
															else if(idSubjInf.text.length()<6)
															{
																dialog=Dialog("Ma mon hoc phai co dung 6 ky tu!", "","","OK");
																isDialog=true;
															}
															else
															{
																	
																	if(checkDuplicatedID(subjList.tree, idSubjInf.text))
																	{
																		dialog=Dialog("Ma mon da ton tai", "", "", "OK");
																		isDialog=true;
																	}
																	else
																	{
	//																	cout<<"HERREEEE";
																		SUBJECT tmpSubj=subject(idSubjInf.text, nameSubjInf.text);
																		InsertSubject(subjList.tree, createSubjectNode(tmpSubj));
																		subjArray[lengthOfLeftList]=createSubjectNode(tmpSubj);
																		
																		dialog=Dialog("Thanh cong!", "", "", "OK");
																		isDialog=true;
																		isAddDone=true;
																		isMouseUsing=true;
																		isStartAdd=true;
																		isWriteFileSubjects=true;
																		lengthOfLeftList=countNodes(subjList.tree);
																		sortSubject(subjArray, lengthOfLeftList);
//																		isAddingLeft=true;
																	}
	//																Question tmpQues= Question(quesInf.text, answerAInf.text, answerBInf.text, answerCInf.text, answerDInf.text, resultInf.text);
	//																if(add_QSList(subjArray[indexLeft]->sj.qsList, tmpQues))
	//																{
	//																	dialog=Dialog("Thanh cong!", "", "", "OK");
	//																	isDialog=true;
	//																	isAddDone=true;
	//																	isUpdateFile=true;
	//	//																show_item(quesList);
	//																	
	//	//																showQuesTbl(quesTbl, quesList, quesList.n%10, quesList.n/10);
	//																}
	//																else
	//																{
	//																	dialog=Dialog("Vuot qua so luong cau hoi (200)!", "", "", "OK");
	//																	isDialog=true;
	//																	isMouseUsing=true;
	//																}
															
	//															else
	//															{
	//																
	//																editSubject(subjList, idSubjInf.text, nameSubjInf.text);
	//																cout<<subjArray[0]->sj.subjectName;
	////																editSubjectID(subjList.tree, idSubjectInf.text, )
	////																editQuestion(subjArray[indexLeft]->sj.qsList,indexRight, quesInf.text, answerAInf.text, answerBInf.text, answerCInf.text, answerDInf.text, resultInf.text);
	//																isMouseUsing=true;
	////																isUpdateFile=true;
	//																isChanged=false;
	//															}
		
															} 
														}
														
													}
												
												}
												else if(cursorX>=l_LeaveBtn.x && cursorX<l_LeaveBtn.x+l_LeaveBtn.width)
												{
													cout<<"HERE";
													if(isChanged)
													{
														cout<<"HERE11";
														isDialog=true;
														dialog=Dialog("Chua luu lai nhap lieu, quay lai nhap lieu?", "Thoat","Quay lai");
													}
													if(!isAddingLeft)
													{
														if(nameSubjInf.text=="")
														{
															dialog=Dialog("Ten mon khong duoc de trong!", "","","OK");
															isDialog=true;
														}
														else
														{
															isInputtingLeft=false;
//															isAddingLeft=false;
															isMouseUsing=true;
														}
													}
													else
													{
														cout<<"HERE22";
														int tmpFlag=isInputBlank(dialog,2, idSubjInf.text, nameSubjInf.text);
														if(tmpFlag==1)
														{
															dialog=Dialog("Cac truong khong duoc de trong!", "","","OK");
															isDialog=true;		
														}
														else if(tmpFlag==-1)
														{
															isInputtingLeft=false;
															isAddingLeft=false;
															isMouseUsing=true;
														}
													}
													
													
												}
											}
					
										}

										
									}
									
								
								}
								
							
							}
							
						}
						else if(role==student)
						{
	
							// Chuot dang o ben trai
							if(cursorX>=l_m_Pnl.x && cursorX<l_m_Pnl.x+l_m_Pnl.width)
							{
								if(!isTesting && !isFinish)
								{
									if(cursorX>=idSubjectInf.x && cursorX<idSubjectInf.x+idSubjectInf.width)
									{
										
										if(cursorY>=idSubjectInf.y && cursorY<idSubjectInf.y+idSubjectInf.height)
										{
											isMouseUsing=false;
											infPointer=createInf(tmpInf,idSubjectInf);
											showInputField(tmpInf);
											strInputting=&idSubjectInf.text;
											isInputUpper=true;
											isInputNumber=false;
										}
										else if(cursorY>=numOfQusInf.y && cursorY<numOfQusInf.y+numOfQusInf.height)
										{
											isMouseUsing=false;
											infPointer=createInf(tmpInf,numOfQusInf);
											showInputField(tmpInf);
											strInputting=&numOfQusInf.text;
											isInputNumber=true;
										}
										else if(cursorY>=timeInf.y && cursorY<timeInf.y+timeInf.height)
										{
											isMouseUsing=false;
											infPointer=createInf(tmpInf,timeInf);
											showInputField(tmpInf);
											strInputting=&timeInf.text;
											isInputNumber=true;
										}
										else if(cursorY>=startBtn.y && cursorY<startBtn.y+startBtn.height )
										{
											if(cursorX>=startBtn.x && cursorX<startBtn.x+startBtn.width)
											{
												
												if(idSubjectInf.text=="" || numOfQusInf.text=="" || timeInf.text=="")
												{
													dialog=Dialog("Cac truong khong duoc de trong!", "","","OK");
													isDialog=true;
													
												}
												else if(checkTested(scoreList, idSubjectInf.text))
												{
													dialog=Dialog("Ban da hoan thanh bai thi mon nay!", "","","OK");
													isDialog=true;
												}
												else if(numOfQusInf.text=="0")
												{
													dialog=Dialog("So luong cau hoi phai lon hon 0!", "","","OK");
													isDialog=true;
												}
												else if(timeInf.text=="0")
												{
													dialog=Dialog("Thoi gian thi phai lon hon 0!", "","","OK");
													isDialog=true;
												}
												else
												{
													QSList tmpQSList;
													if(load_item(tmpQSList, idSubjectInf.text))
													{
														if(tmpQSList.n<atoi(&numOfQusInf.text[0]))
														{
															dialog=Dialog("Vuot qua so luong co trong bo cau hoi!", "","","OK");
															isDialog=true;
														}
														else
														{
															isLoadExam=true;
															isMouseUsing=true;
															isLoadQS=true;
															isCreateTimer=true;
															testTime=atoi(&timeInf.text[0])*60;
															exam=loadExam(tmpQSList,atoi(&numOfQusInf.text[0]));
															isTesting=true;
															quesBtnList=ButtonList(492, 475, atoi(&numOfQusInf.text[0]), 60, 30);
															ansListStudent=new Answers[atoi(&numOfQusInf.text[0])];
															for(int i=0; i<atoi(&numOfQusInf.text[0]); i++)
															{
																ansListStudent[i]=nonAns;
															}	
														}
														
													}
													else
													{
														dialog=Dialog("Mon hoc khong ton tai!", "","","OK");
														isDialog=true;
													}
												}
											}
										}
										else if(cursorY>=exitBtn.y && cursorY<exitBtn.y+exitBtn.height && cursorX>=exitBtn.x && cursorX<exitBtn.x+exitBtn.width)
										{
											isLogged=false;
											isFreeMemory=true;
										}
									}
								
								}
								
								else if(isTesting)
								{
									if(cursorX>=submitBtn.x && cursorX<submitBtn.x+submitBtn.width && cursorY>=submitBtn.y && cursorY<submitBtn.y+submitBtn.height &&!isFinish)
									{
										isDialog=true;
										dialog=Dialog("Dang trong gio thi, ban muon nop bai ngay?","Nop bai", "Quay lai");
									}
								}
									
							}
						
							else // Chuot dang o ben phai
							{
								if(isTesting || isFinish)
								{
									//con tro o ben phai va phia duoi
									if(cursorX>=quesBtnList.x && cursorX<quesBtnList.x+quesBtnList.width)
									{
										if(cursorY>=quesBtnList.y && cursorY<quesBtnList.y+quesBtnList.height)
										{
											int tmpRow=(cursorY-quesBtnList.y)/quesBtnList.btnHeight;
											int tmpCol=(cursorX-quesBtnList.x)/quesBtnList.btnWidth;
											curQues=tmpRow*10+tmpCol;
											isLoadQS=true;
		//									isLoadQS=true;
											
		//									quesBtnList.showQuesBtnList(5, curQues, answerList);
										}
									}
								}
								
								if(isTesting)
								{
									
									if(cursorY>=ansA_Btn.y && cursorY<ansA_Btn.y+ansA_Btn.height)
									{
										if(cursorX>=ansA_Btn.x && cursorX<ansA_Btn.x+ansA_Btn.width)
										{
											ansListStudent[curQues]=ansA;
											
										}
										else if(cursorX>=ansB_Btn.x && cursorX<ansB_Btn.x+ansB_Btn.width)
										{
		//									ansA_Btn.isSelected=true;
											ansListStudent[curQues]=ansB;	
										}
									}
									else if(cursorY>=ansC_Btn.y && cursorY<ansC_Btn.y+ansC_Btn.height)
									{
										if(cursorX>=ansC_Btn.x && cursorX<ansC_Btn.x+ansC_Btn.width)
										{
		//									ansC_Btn.isSelected=true;
		////									ansA_Btn.show();
											ansListStudent[curQues]=ansC;
											
										}
										else if(cursorX>=ansD_Btn.x && cursorX<ansD_Btn.x+ansD_Btn.width)
										{
		//									ansA_Btn.isSelected=true;
											ansListStudent[curQues]=ansD;	
										}
									}
									
									
								}
							}
							
						}
						
					}
			
				}
				tmpcursorX=cursorX;
				tmpcursorY=cursorY;
			}
		}
//		cout<<tmpInf.text.length();
		if(kbhit())
		{
			if(!isDialog)
			{
				if(!isMouseUsing)
				{
					char key=getch();
					if(key!=32 || tmpKey!=32)
					{
						if(key>=32)
						{
							if(infPointer==&lastNameInf && (key>=97 && key<=122) && tmpKey==32)
							{
								key-=32;
							}
							else if(infPointer==&resultInf)
							{
								if(key>=97&&key<=100)	key-=32;
							}
							if((isInputUpper ||  infPointer==&idSubjInf) && key>=97 && key<=122)
								key-=32;
							if(!isLogged && isInputPass)
							{
								password+=key;
								key='*';
							}	
							if(textwidth(&tmpInf.text[0])<tmpInf.width-15 || tmpInf.text.length()<tmpInf.length)
							{
								if(infPointer==&resultInf)
								{
									if(key==65 || key==66 || key==67 || key==68)
									tmpInf.text+=key;
								}
								else if(!(isInputNumber && !(key>=48 && key<=57)))	
									tmpInf.text+=key;
							}
								
						}
						else if(key==8)
						{
							
							if(tmpInf.text.length()>0)
							{
								if(!isLogged && isInputPass)
								{
									password.erase(password.size()-1);
									
								}
								tmpInf.text.erase(tmpInf.text.size()-1);
							}
									
						}
						 *strInputting=tmpInf.text;
							tmpKey=key;
					}	
				}
			}
			
				
		}

		if(isDialog)
		{
			showDialog(dialog);
		}
		if(isCreateTimer)
		{
			isCreateTimer=false;
			thread t1(timeNormal);
			t1.detach();
			
		}

		if(isTimeout)
		{
			isFinish=true;
			isTesting=false;
		}
//		cout<<endl;
//		cout<<isDupInput(answerAInf.text, answerBInf.text, answerCInf.text, answerDInf.text);	
		page=1-page;
		
		
	};
	
	
	
	getch();
	closegraph();

} 


int isInputBlank(Dialog & dialog, int numText, string str1, string str2, string str3, string str4,  string str5, string str6)
{
	string arr[6]={str1, str2, str3, str4, str5, str6};
	
	int countBlank=0;
	
	for(int i=0; i<numText; i++)
	{
		if(arr[i]=="" || arr[i]==" ")	countBlank++;
	}
	
	if(countBlank==numText)	return -1;
	else if(countBlank>0&&countBlank<numText) return 1;
	else if(countBlank==0) return 0;
//	if(str1=="" && str2=="" && str3=="" && str4=="" && str5=="" && str6=="")	return -1;
//	int result=0;
//	string tmp=","+str1+","+str2+","+str3+","+str4+","+str5+","+str6+",";
//	if(tmp.find(",,")!=string::npos)							
//	{
//		
//		result=1;
//		dialog=Dialog("Cac truong khong duoc de trong!", "","","OK");
//	}
//	return result;
}

bool isDupInput(string str1, string str2, string str3, string str4)
{
	string arr[4]={str1, str2, str3, str4};
	for(int i=0; i<2; i++)
	{
		for(int j=i+1; j<=3; j++)
		{
			if(arr[i]==arr[j])	return true;
		}
	}
	
	return false;
}
bool checkInputInforQues(Dialog & dialog, string str1, string str2, string str3, string str4,  string str5, string str6)
{
	bool result=false;
	cout<<"Trung";
	if(isDupInput(str2, str3, str4, str5))
	{
		cout<<"Trung";
		dialog=Dialog("Cac dap an khong duoc trung nhau!", "","","OK");
		result=true;
	}
	if(isInputBlank(dialog,6, str1, str2, str3, str4,  str5, str6))	result= true;	// ton tai truong trong	
	return result;
}
bool checkStudentEntered(string firstName, string lastName, Dialog& dialog, bool isChanged)
{
	bool isDialog=false;
	if(firstName=="" || lastName=="")							
	{
		isDialog=true;
		dialog=Dialog("Cac truong khong duoc de trong!", "","","OK");
	}
	else if(isChanged)
	{
		isDialog=true;
		dialog=Dialog("Dang nhap lieu, luu thay doi?", "Luu","Khong luu");
	}
	return isDialog;
}


void timeNormal()
{
//	cout<<"timer";
	for(int i=testTime; i>=0; i--)
	{
		mm=(i-i%60)/60;
		ss=i%60;
		Sleep(990);
//		terminate();	
	}
	isTimeout=true;
	
}

float marking(int numOfQues, Question *exam,Answers *ansListStudent)
{
	float count=0;
//	float numOfQues=sizeof(ansListStudent)/sizeof(ansListStudent[0]);
//	cout<<"Do lon mang: "<<sizeof(ansListStudent)<<endl;
//	cout<<"Do lon thanh phan: "<<sizeof(ansListStudent[0])<<endl;
//	cout<<"So cau hoi: "<<numOfQues<<endl;
	for(int i=0; i<numOfQues; i++)
	{
		string tmpstr;
		tmpstr+=getAnswerChar(ansListStudent[i]);
		if(tmpstr==exam[i].question_correctAnswer)
		count++;
	}
	cout<<"So cau dung: "<<count<<endl;
	return count/(float)numOfQues*10.0;
}

Roles * checkLogin(string id, string pwd){
//	cout<<"HEREEEEE";
	Roles role;
	if(id=="GV" && pwd=="GV")
	{
		role=teacher;
		return &role;
	}
	else if(id=="GV" && pwd!="GV")
	{
//		cout<<"HEREEEEE";
		return NULL;
	} 
	string className="D18CQ"+id.substr(0,4);
	StudentList studentList;
	if(!readStudentList(className, studentList))
	{
		
		return NULL;
	}

	int index=studentList.searchByID(id);	

	if(index!=-1)
	{
		Student tmp=studentList.getStudent(index);
		if(tmp.password==pwd)
		{
			
			role=student;
			return &role;
		}
		else	return NULL;
	}
	return NULL;
}

string formatStr(string str)   /// ham nay ne ong oi
 {
 	while(str[0]==32) // xoa dau chuoi
     {
     	 str.erase(0,1);
	 }
	if(str[str.length()-1]==32) //xoa khoang trang cuoi chuoi
	 {
	 	 str.erase(str.length()-1,1);
	 }	 
	return str;
 }
