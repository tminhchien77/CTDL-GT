//#include<graphics.h>
//#include<stdio.h>
//#include<windows.h>
//#include<iostream>
//#include<conio.h>
//#include"Buttons.h"
//#include"Panels.h"
//#include"Terms.h"
//#include"Student.h"
//#include"Question.h"
//#include"Table.h"
//#include"InputField.h"
//#include"Dialog.h"
//#include"Label.h"
//#include <thread>
//#include <mutex>
//#include<string>
//#include<cmath>
//
//
//using namespace std;
//#define yMenuBar 0
//#define heightMenuBar hBtnMenuBar
//#define yListPnl yMenuBar+heightMenuBar
//#define hListPnl 420
//#define yEditPnl yListPnl+hListPnl+5
//#define wBtnMenuBar 80
//#define hBtnMenuBar 20
//#define windowColor LIGHTGRAY
//
//#define padding 5
//
//bool checkQuesEntered(string ques, string answerA, string answerB, string answerC,  string answerD, string result, Dialog& dialog, bool isChanged);
//bool checkStudentEntered(string firstName, string lastName, Dialog& dialog, bool isChanged);
//void timeNormal();
//float marking(int numOfQues, Question *exam,Answers *ansListStudent);
////bool timeout();
////void* countTime(void* unused);
//int testTime=0;
//int mm;
//int ss;
//bool isFinish=false;
//bool isWriteFileInforExamOfStudent=false;
//
//
//
//
//int main ()
//{
//	
//	initwindow(screenWidth,screenHeight,"Test -- ver 1.0", 50,50);
//	char arr[100];
//    
//    QSList quesList;
//	StudentList studentList;
//	enum Roles{
//		teacher,
//		student
//	};		
//			
//	//====================================Khoi tao thanh phan======================================================================
//	Button classesBtn=Button(0,0,wBtnMenuBar,hBtnMenuBar,"Classes", unSelectedColorMenuBar, selectedColorMenuBar, false);
//	Button subjectsBtn=Button(wBtnMenuBar,0,wBtnMenuBar,hBtnMenuBar,"Subjects", unSelectedColorMenuBar, selectedColorMenuBar, false);
//	Panel l_m_Pnl=Panel(0,yListPnl,500,hListPnl, /*"Class list",*/ WHITE);
//	Panel r_m_Pnl=Panel(l_m_Pnl.x+l_m_Pnl.width+padding,yListPnl,screenWidth-l_m_Pnl.x-l_m_Pnl.width-padding,hListPnl, WHITE);
//	Panel l_b_Pnl=Panel(0, yEditPnl, 500, screenHeight-yEditPnl, WHITE);
//	Panel r_b_Pnl=Panel(l_b_Pnl.x+l_b_Pnl.width+padding, yEditPnl, screenWidth-l_b_Pnl.x-l_b_Pnl.width-padding, screenHeight-yEditPnl, WHITE);
//	Table quesTbl= Table(r_m_Pnl.x+35, r_m_Pnl.y+50, r_m_Pnl.width-35*2, r_m_Pnl.height-130);
//	Table studentTbl= Table(r_m_Pnl.x+35, r_m_Pnl.y+50, r_m_Pnl.width-35*2, r_m_Pnl.height-130);
////	Button rightNextPage=Button(quesTbl.x+quesTbl.width-75,quesTbl.y+quesTbl.height+10,75,50,"Next", selectedColorMenuBar, unSelectedColorMenuBar);
////	Button rightPrePage=Button(quesTbl.x,quesTbl.y+quesTbl.height+10,100,50,"Previous", selectedColorMenuBar, unSelectedColorMenuBar);
//	Button r_addBtn=Button(1145, 35, 100, 30,"Them moi", defUnSelectedBtnColor, defSelectedBtnColor, false);
//	Button r_SaveBtn=Button(710, 650, 100, 30, "Luu", defUnSelectedBtnColor, defSelectedBtnColor, false);
//	Button r_UnsaveBtn=Button(1000, 650, 100, 30, "Thoat", defUnSelectedBtnColor, defSelectedBtnColor, false);
//	
//	ButtonList rPageBtns;
//	
//	InputField quesInf= InputField(r_b_Pnl.x+150, r_b_Pnl.y+45, 500, 25,50);
//	InputField answerAInf= InputField(quesInf.x, quesInf.y+40, 200, 25,50);
//	InputField answerBInf= InputField(quesInf.x+300, quesInf.y+40, 200, 25,50);
//	InputField answerCInf= InputField(quesInf.x, answerAInf.y+40, 200, 25,50);
//	InputField answerDInf= InputField(quesInf.x+300, answerAInf.y+40, 200, 25,50);
//	InputField resultInf= InputField(r_b_Pnl.x+150, answerCInf.y+40, 500, 25,50);
//	InputField firstNameInf= InputField(r_b_Pnl.x+150, r_b_Pnl.y+45, 500, 25,50);
//	InputField lastNameInf= InputField(firstNameInf.x, firstNameInf.y+40, 500, 25,50);
//	Button maleBtn=Button(lastNameInf.x, lastNameInf.y+40, 200, 30, "Nam", defUnSelectedBtnColor, defSelectedBtnColor, false);
//	Button femaleBtn=Button(lastNameInf.x+300, lastNameInf.y+40, 200, 30, "Nu", defUnSelectedBtnColor, defSelectedBtnColor, false);
//	
//	Dialog dialog=Dialog("Dang nhap lieu, Luu thay doi?", "Dong y","Thoat");
//	InputField tmpInf;
//	
//	InputField userNameInf= InputField(xLoginPnl+25, yLoginPnl+75, wLoginPnl-50, 50, 50);
//	InputField passInf=InputField(xLoginPnl+25, yLoginPnl+175, wLoginPnl-50, 50, 50);
//	Button loginBtn=Button(xLoginPnl+50, yLoginPnl+260, wLoginPnl-100, 50, "Dang nhap",defUnSelectedBtnColor,defSelectedBtnColor, false);
//	
//	InputField idSubjectInf, numOfQusInf, timeInf;
////	InputField numOfQusInf;
////	InputField timeInf;
//	Button startBtn, submitBtn, exitBtn;
//	
//	Button ansA_Btn, ansB_Btn, ansC_Btn, ansD_Btn;
//	ButtonList quesBtnList;
//	
//	POINT cursorPosition;
//	int cursorX=-1, cursorY=-1;
//	int tmpcursorX=-1, tmpcursorY=-1;
//	int selecting=0;
//	int page=0;
//	int rowRightTbl=0;
//	int pageRightTbl=0;
//	bool isMouseUsing=true;
//	string * strInputting;
//	string oldStr;
//	string password;
//	bool isChanged=false;
//	bool isDialog=false;
//	bool isLoadFile=true;
//	bool tmpIsSelectedRAddBtn=false;
//	bool isAdding_r=false;
//	string idLbl;
//	bool isLogged=false;
//	bool isSeletedLoginBtn=false;
//	int role=-1;
//	bool isUpdateFile;
//	bool isInputUpper=false;
//	bool isInputPass=false;
//	bool isInputNumber=false;
//	
//	
//	int curQues=0;
//	Answers *answerList;
//	bool isLoadUI=true;
//	bool isLoadExam=false;
//	bool isTesting=false;
//	bool isLoadQS=false;
//	bool isCreateTimer=false;
//	
//	string tmpQuestion;
//	Answers * ansListStudent;
////	ScoreList scoreList;
//
//	
//	
////	startTimer();
//	
//	
//	Question *exam;
//				
//	while(1)
//	{
//		
////		cout<<"here";
//		if(isLoadFile)
//		{
//			readStudentList(studentList);
//			load_item(quesList, "TOAN");
//			rPageBtns=ButtonList(380, r_m_Pnl.x, r_m_Pnl.width, quesList.n, 25,25);
//			isLoadFile=false;
//		}
////		cout<<studentList.pHead->data.firstName;
//		if(isUpdateFile)
//		{
//			writeQsFile(quesList, "TOAN");
//			isUpdateFile=false;
//		}
//		
//		int index=rowRightTbl+pageRightTbl*10;
////		flag=false;
//		
//		setactivepage(page);
//		
//		setvisualpage(1-page);
//		
//		setbkcolor(windowColor);
//		cleardevice();
//		
//    	
//    	if(!isLogged)
//		{
////			*strInputting="";
//			showLoginPnl();
//			showInputField(userNameInf);
//			showInputField(passInf);
//			loginBtn.show();
////			showBtn(loginBtn, WHITE, isSeletedLoginBtn, 0);
//			if(!isMouseUsing)
//				{	
//					showInputField(tmpInf);
//				}
//		}
//		else
//		{
//		
//			if(role==teacher)
//			{
////				showBtn(classesBtn,windowColor,1-selecting,0);
////				showBtn(subjectsBtn,windowColor,selecting,1);
//				classesBtn.show();
//				subjectsBtn.show();
//			
//				
//				showPnl(l_m_Pnl);
//				showPnl(r_m_Pnl);
//				showPnl(l_b_Pnl);
//				showPnl(r_b_Pnl);
//				
////				cout<<studentList.pHead->data.firstName;
//				if(selecting==0)
//				{
//					showStudentTbl(studentTbl,studentList, rowRightTbl, pageRightTbl);
//					rPageBtns.show(studentList.getLength(), pageRightTbl);
//					
//					if(isMouseUsing)
//					{
//						Student tmpStudent;
//						tmpStudent=studentList.getStudent(pageRightTbl*10+rowRightTbl);
//						idLbl=tmpStudent.id;
//						firstNameInf.text=tmpStudent.firstName;
//						lastNameInf.text=tmpStudent.lastName;
////						quesInf.text= quesList.question_QSList[index].question_content;
////						answerAInf.text=quesList.question_QSList[index].question_answer_A;
////						answerBInf.text=quesList.question_QSList[index].question_answer_B;
////						answerCInf.text=quesList.question_QSList[index].question_answer_C;
////						answerDInf.text=quesList.question_QSList[index].question_answer_D;
////						resultInf.text= quesList.question_QSList[index].question_correctAnswer;
//					}
//		//			setcolor(BLACK);
//					outtextxy(r_b_Pnl.x+15, r_b_Pnl.y+15, "MSSV:");
////					if(!isAdding_r)
////						idLbl=quesList.question_QSList[index].question_code;
////					else
////					{
////						char tmp[3];
////						idLbl=itoa(quesList.n+1, tmp, 10);
////					}	
//					outtextxy(r_b_Pnl.x+150, r_b_Pnl.y+15, &idLbl[0]);
//					
//					outtextxy(r_b_Pnl.x+15, r_b_Pnl.y+45, "Ho:");
//					showInputField(firstNameInf);
//					
//					outtextxy(r_b_Pnl.x+100, r_b_Pnl.y+85, "Ten:");
//					showInputField(lastNameInf);
//					
//					maleBtn.show();
//					femaleBtn.show();
////					outtextxy(r_b_Pnl.x+400, r_b_Pnl.y+85, "B:");
////					showInputField(answerBInf);
////					
////					outtextxy(r_b_Pnl.x+100, r_b_Pnl.y+125, "C:");
////					showInputField(answerCInf);
////					
////					outtextxy(r_b_Pnl.x+400, r_b_Pnl.y+125, "D:");
////					showInputField(answerDInf);
////					
////					outtextxy(r_b_Pnl.x+15, answerCInf.y+40, "Result:");
////					showInputField(resultInf);
//		
//					if(!isMouseUsing)
//					{
//						
//						showInputField(tmpInf);
//						if(tmpInf.text!=oldStr)
//						{
//							isChanged=true;
//						}
//						else isChanged=false;
//						r_SaveBtn.show();
//						r_UnsaveBtn.show();
////						showBtn(r_SaveBtn, r_m_Pnl.color, 0,0);	
////						showBtn(r_UnsaveBtn, r_m_Pnl.color, 0,0);
//					}
//					
////					r_addBtn.text="Them moi";
//					if(tmpIsSelectedRAddBtn)
//					{
//						Sleep(200);
//						tmpIsSelectedRAddBtn=false;
//						continue;
//					}
//				}
//				else if(selecting==1)
//				{
//						
//					
//					showQuesTbl(quesTbl,quesList, rowRightTbl, pageRightTbl);
////					cout<<quesList.n;
//					rPageBtns.show(quesList.n, pageRightTbl);
//					
//					
//					
//					if(isMouseUsing)
//					{
//						idLbl=quesList.question_QSList[index].question_code;
//						quesInf.text= quesList.question_QSList[index].question_content;
//						answerAInf.text=quesList.question_QSList[index].question_answer_A;
//						answerBInf.text=quesList.question_QSList[index].question_answer_B;
//						answerCInf.text=quesList.question_QSList[index].question_answer_C;
//						answerDInf.text=quesList.question_QSList[index].question_answer_D;
//						resultInf.text= quesList.question_QSList[index].question_correctAnswer;
//					}
//		//			setcolor(BLACK);
//					outtextxy(r_b_Pnl.x+15, r_b_Pnl.y+15, "ID Question:");
//					if(!isAdding_r)
//						idLbl=quesList.question_QSList[index].question_code;
//					else
//					{
//						char tmp[3];
//						idLbl=itoa(quesList.n+1, tmp, 10);
//					}	
//					outtextxy(r_b_Pnl.x+150, r_b_Pnl.y+15, &idLbl[0]);
//					
//					outtextxy(r_b_Pnl.x+15, r_b_Pnl.y+45, "Question:");
//					showInputField(quesInf);
//					
//					outtextxy(r_b_Pnl.x+100, r_b_Pnl.y+85, "A:");
//					showInputField(answerAInf);
//					
//					outtextxy(r_b_Pnl.x+400, r_b_Pnl.y+85, "B:");
//					showInputField(answerBInf);
//					
//					outtextxy(r_b_Pnl.x+100, r_b_Pnl.y+125, "C:");
//					showInputField(answerCInf);
//					
//					outtextxy(r_b_Pnl.x+400, r_b_Pnl.y+125, "D:");
//					showInputField(answerDInf);
//					
//					outtextxy(r_b_Pnl.x+15, answerCInf.y+40, "Result:");
//					showInputField(resultInf);
//		
//					if(!isMouseUsing)
//					{
//						
//						showInputField(tmpInf);
//						if(tmpInf.text!=oldStr)
//						{
//							isChanged=true;
//						}
//						else isChanged=false;
//						r_SaveBtn.show();
//						r_UnsaveBtn.show();
////						showBtn(r_SaveBtn, r_m_Pnl.color, 0,0);	
////						showBtn(r_UnsaveBtn, r_m_Pnl.color, 0,0);
//					}
//					
////					r_addBtn.text="Them moi";
//					if(tmpIsSelectedRAddBtn)
//					{
//						Sleep(200);
//						tmpIsSelectedRAddBtn=false;
//						continue;
//					}
////					else showBtn(r_addBtn,WHITE, tmpIsSelectedRAddBtn,0);
//					
//				}
//			}
//			else //student
//			{
//				
//				if(isLoadUI)
//				{
//					l_m_Pnl=Panel(25,5,300,screenHeight-5, WHITE);
//					r_m_Pnl=Panel(l_m_Pnl.x+l_m_Pnl.width+padding,5,screenWidth-l_m_Pnl.x-l_m_Pnl.width-padding-25,420, WHITE);
//					r_b_Pnl=Panel(l_m_Pnl.x+l_m_Pnl.width+padding, r_m_Pnl.y+r_m_Pnl.height+padding, r_m_Pnl.width, screenHeight-r_m_Pnl.height-padding-5, WHITE);
//					idSubjectInf=InputField(l_m_Pnl.x+30, 150, l_m_Pnl.width-60, 50, 50);
//					numOfQusInf=InputField(idSubjectInf.x, idSubjectInf.y+125, idSubjectInf.width, idSubjectInf.height, 50);
//					timeInf=InputField(idSubjectInf.x, numOfQusInf.y+100, idSubjectInf.width, idSubjectInf.height, 50);
//					startBtn=Button(idSubjectInf.x, timeInf.y+75, idSubjectInf.width, 50, "Bat dau", defUnSelectedBtnColor, defSelectedBtnColor, false);
//					submitBtn=Button(idSubjectInf.x, timeInf.y+75, idSubjectInf.width, 50, "Nop bai", defUnSelectedBtnColor, defSelectedBtnColor, false);
//					exitBtn=Button(idSubjectInf.x, startBtn.y+60, idSubjectInf.width, 50, "Thoat", defUnSelectedBtnColor, defSelectedBtnColor, false);
//					ansA_Btn=Button(r_m_Pnl.x+75, r_m_Pnl.y+130, 300, 50, defUnSelectedBtnColor, defSelectedBtnColor);
//					ansB_Btn=Button(ansA_Btn.x+400, ansA_Btn.y, ansA_Btn.width, ansA_Btn.height, defUnSelectedBtnColor, defSelectedBtnColor);
//					ansC_Btn=Button(ansA_Btn.x, ansA_Btn.y+100, ansA_Btn.width, ansA_Btn.height, defUnSelectedBtnColor, defSelectedBtnColor);
//					ansD_Btn=Button(ansB_Btn.x, ansB_Btn.y+100, ansA_Btn.width, ansA_Btn.height, defUnSelectedBtnColor, defSelectedBtnColor);
//					isLoadUI=false;
////					readScoreList(userNameInf.text, scoreList);
//					
//				}
//				
//				
//				if(isLoadExam)
//				{
////					random cau hoi xong cho vao list exam phia duoi
////					QSList exam=QSList()
//					QSList tmpQSList;
//					load_item(tmpQSList, idSubjectInf.text);
////					exam=new Question[atoi(&numOfQusInf.text[0])];
//					exam=loadExam(tmpQSList,atoi(&numOfQusInf.text[0]));
//					isLoadExam=false;
//					cout<<"here";
//					isTesting=true;
//					quesBtnList=ButtonList(492, 475, atoi(&numOfQusInf.text[0]), 60, 30);
//					ansListStudent=new Answers[atoi(&numOfQusInf.text[0])];
//					for(int i=0; i<atoi(&numOfQusInf.text[0]); i++)
//					{
//						ansListStudent[i]=nonAns;
//					}
//					
//				}
//				showPnl(l_m_Pnl);
//				showPnl(r_m_Pnl);
//				showPnl(r_b_Pnl);
//				setcolor(textColor);
//				outtextxy(idSubjectInf.x, idSubjectInf.y-25, "Ma mon hoc:");
//				showInputField(idSubjectInf);
//				
//				outtextxy(idSubjectInf.x, numOfQusInf.y-25, "So luong cau hoi:");
//				showInputField(numOfQusInf);
//				
//				outtextxy(idSubjectInf.x, timeInf.y-25, "Thoi gian thi:");
//				showInputField(timeInf);
//				
//				
//
//				
//				
//				
//				if(!isTesting && !isFinish)
//					startBtn.show();
//				if(isFinish)
//				{
//					char buff[10];
//					setcolor(RED);
//					setbkcolor(WHITE);
//					outtextxy(800, 50, "Diem:");
//					float score=marking(atoi(&numOfQusInf.text[0]), exam, ansListStudent);
//					if(isWriteFileInforExamOfStudent)
//					{
//						isWriteFileInforExamOfStudent=false;
//						writeFileInforExamOfStudent(userNameInf.text, idSubjectInf.text, score, atoi(&numOfQusInf.text[0]),  exam, ansListStudent);		
//						writeFileScoreOfClass(userNameInf.text, idSubjectInf.text, score);				
//					}
//
//					outtextxy(850, 50, itoa(score, buff, 10));
//					//ghi file chi tiet bai thi SV
//					
//				}
//				if(isTesting || isFinish)
//				{
//					
//					
//					if(isLoadQS)
//					{
//						ansA_Btn.text=exam[curQues].question_answer_A;
//						ansB_Btn.text=exam[curQues].question_answer_B;
//						ansC_Btn.text=exam[curQues].question_answer_C;
//						ansD_Btn.text=exam[curQues].question_answer_D;
//						tmpQuestion=exam[curQues].question_content;
//						
//						isLoadQS=false;
//					}
//					setbkcolor(WHITE);
//					setcolor(textColor);
//					outtextxy(r_m_Pnl.x+50, r_m_Pnl.y+85, &tmpQuestion[0]);
//					outtextxy(r_m_Pnl.x+50, r_m_Pnl.y+50, "Cau hoi so 1:");
//
//					outtextxy(ansA_Btn.x-25, ansA_Btn.y+(ansA_Btn.height-textheight("A"))/2, "A");
//					outtextxy(ansB_Btn.x-25, ansB_Btn.y+(ansB_Btn.height-textheight("B"))/2, "B");
//					outtextxy(ansC_Btn.x-25, ansC_Btn.y+(ansC_Btn.height-textheight("C"))/2, "C");
//					outtextxy(ansD_Btn.x-25, ansD_Btn.y+(ansD_Btn.height-textheight("D"))/2, "D");
//
//					showGroupBtn(ansA_Btn, ansB_Btn, ansC_Btn, ansD_Btn, ansListStudent[curQues]);
//					quesBtnList.showQuesBtnList(atoi(&numOfQusInf.text[0]), curQues, exam,ansListStudent, isFinish);
//				}
//				if(isTesting)
//				{
//					submitBtn.show();
//					
//					setbkcolor(WHITE);
//					setcolor(textColor);
//					string s=to_string(mm)+":"+to_string(ss);
//					outtextxy(1050, 30, &s[0]);	
//				}	
//				else
//					exitBtn.show();
////				cout<<r_m_Pnl.x+(r_m_Pnl.width-500)/2;
////				quesBtnList=ButtonList()
////				if(isMouseUsing)
////				{
////					quesInf.text= quesList.question_QSList[index].question_content;
////					answerAInf.text=quesList.question_QSList[index].question_answer_A;
////					answerBInf.text=quesList.question_QSList[index].question_answer_B;
////					answerCInf.text=quesList.question_QSList[index].question_answer_C;
////					answerDInf.text=quesList.question_QSList[index].question_answer_D;
////					resultInf.text= quesList.question_QSList[index].question_correctAnswer;
////				}
//				if(!isMouseUsing)
//				{	
//					setbkcolor(WHITE);
//					showInputField(tmpInf);
//				}
//			}
//		}
//
//		
//		
////		showDialog();
//		// Xu ly chuot
//		if(GetAsyncKeyState(VK_LBUTTON))
//		{
//			GetCursorPos(&cursorPosition);
//			ScreenToClient(GetForegroundWindow(), &cursorPosition);
//			cursorX=cursorPosition.x;
//			cursorY=cursorPosition.y;
//			if(tmpcursorX!=cursorX && tmpcursorY!=cursorY)
//			{
//				if(!isLogged)
//				{
//					if(cursorX>=userNameInf.x && cursorX<userNameInf.x+userNameInf.width)
//					{
//						if(cursorY>=userNameInf.y && cursorY<userNameInf.y+userNameInf.height)
//						{
//							isMouseUsing=false;
//							createInf(tmpInf,userNameInf);
//							showInputField(tmpInf);
//							strInputting=&userNameInf.text;
//							isInputUpper=true;
//							isInputPass=false;
//						}
//						else if(cursorY>=passInf.y && cursorY<passInf.y+passInf.height)
//						{
//							isMouseUsing=false;
//							createInf(tmpInf,passInf);
//							showInputField(tmpInf);
//							strInputting=&passInf.text;
//							isInputUpper=false;
//							isInputPass=true;
//						}
//						else if(cursorY>=loginBtn.y && cursorY<loginBtn.y+loginBtn.height)
//						{
//							cout<<userNameInf.text<<"   "<<password<<endl;
//							if(userNameInf.text=="GV"&&password=="GV")
//							{
//								
//								isMouseUsing=true;
//								isLogged=true;
//								role=teacher;
//							}
//							else if(userNameInf.text=="N18DCCN023"&&password=="SV")
//							{
//								isMouseUsing=true;
//								isLogged=true;
//								role=student;
//							}
//							else
//							{
//								//Sai username password
//							}
//							isInputPass=false;
//						}
//					}
//					
//								
//				}
//				else
//				{
//					if(isDialog)
//					{
//						if(cursorY>=dialog.opUnSave.y && cursorY<dialog.opUnSave.y+dialog.opUnSave.height)
//						{
//							if(cursorX>=dialog.opSave.x && cursorX<dialog.opSave.x+dialog.opSave.width) //Luu thay doi nhap lieu
//							{
//								if(isTesting)
//								{
//										isTesting=false;
//										isFinish=true;
//										isWriteFileInforExamOfStudent=true;
//								}
//								else
//								{
//									quesList.question_QSList[index].question_content=quesInf.text;
//									quesList.question_QSList[index].question_answer_A=answerAInf.text;
//									quesList.question_QSList[index].question_answer_B=answerBInf.text;
//									quesList.question_QSList[index].question_answer_C=answerCInf.text;
//									quesList.question_QSList[index].question_answer_D=answerDInf.text;
//									quesList.question_QSList[index].question_correctAnswer=resultInf.text;
//									
//								}
//								isDialog=false;
//								isMouseUsing=true;
//							}
//							else if(cursorX>=dialog.opUnSave.x && cursorX<dialog.opUnSave.x+dialog.opUnSave.width) //Huy bo thay doi nhap lieu
//							{
//								if(isTesting)
//									isDialog=false;
//								else
//								{
//									quesInf.text= quesList.question_QSList[index].question_content;
//									answerAInf.text=quesList.question_QSList[index].question_answer_A;
//									answerBInf.text=quesList.question_QSList[index].question_answer_B;
//									answerCInf.text=quesList.question_QSList[index].question_answer_C;
//									answerDInf.text=quesList.question_QSList[index].question_answer_D;
//									resultInf.text= quesList.question_QSList[index].question_correctAnswer;
//								}
//								
//								
//								isDialog=false;
//								isMouseUsing=true;
//							}
//							else if(cursorX>=dialog.opOK.x && cursorX<dialog.opOK.x+dialog.opOK.width) //OKKKK
//							{
//								isMouseUsing=true;
//								isDialog=false;
//							}	
//						}
//						
//						else if(cursorY>=dialog.opOK.y && cursorY<dialog.opOK.y+dialog.opOK.height)
//						{
//	//						cout<<"here";
//							if(cursorX>=dialog.opOK.x && cursorX<dialog.opOK.x+dialog.opOK.width) //OKKKK
//							{
//								cout<<"quay lai nhap lieu";
//								isMouseUsing=true;
//								isDialog=false;
//								isAdding_r=false;
//							}	
//						}
//					}	
//					else
//					{
//						if(role==teacher)
//						{
//							// Con tro chuot dang o thanh menu bar
//							if(cursorY>=yMenuBar && cursorY<yListPnl)	
//							{
//								if(cursorX>=classesBtn.x && cursorX<classesBtn.x+classesBtn.width && selecting!=0)
//								{
//									if(!isMouseUsing)
//									{
//		//								if(quesInf.text=="" || answerAInf.text=="" || answerBInf.text=="" || answerCInf.text=="" || answerDInf.text=="" || resultInf.text=="" && tmpInf.isSelected)
//		//								
//		//								{
//		//									isDialog=true;
//		//									dialog=Dialog("Cac truong khong duoc de trong!", "","","OK");
//		//								}
//		//								else if(isChanged)
//		//								{
//		//									isDialog=true;
//		//									dialog=Dialog("Dang nhap lieu, luu thay doi?", "Luu","Khong luu");
//		//		//							cout<<dialog.op1.text;
//		//								}
//										if(checkQuesEntered(quesInf.text, answerAInf.text, answerBInf.text, answerCInf.text, answerDInf.text, resultInf.text, dialog, isChanged))
//											isDialog=true;
//										else
//										{
//											selecting=0;
//											isMouseUsing=true;
//											isUpdateFile=true;
//										} 
//									}
//									else
//									{
//										selecting=0;
//										isMouseUsing=true;
//										isLoadFile=true;
//									} 
//									
//								}
//								else if(cursorX>=subjectsBtn.x && cursorX<subjectsBtn.x+subjectsBtn.width && selecting!=1)
//								{
//									
//									if(!isMouseUsing)
//									{
//					//					cout<<isChanged;
//										
//										if(isChanged)
//										{	
//					
//											isDialog=true;
//											dialog=Dialog("Dang nhap lieu, Luu thay doi?", "Luu","Khong luu");
//			//								cout<<dialog.op1.text;
//										}
//										
//									}
//									else
//									{
//										selecting=1;
//										isMouseUsing=true;
//										isLoadFile=true;
//									} 
//								}
//								
//							}
//							//Con tro dang o phan giua
//							else if(cursorY>=yListPnl && cursorY<yListPnl+l_m_Pnl.height)
//							{
//								if(selecting==1)
//								{
//									if(cursorY>=quesTbl.yRow0 && cursorY<quesTbl.y+quesTbl.height)
//									{
//										if(cursorX>=quesTbl.x && cursorX<quesTbl.x+quesTbl.width)
//										{
//											if(!isMouseUsing)
//											{
//												if(quesInf.text=="" || answerAInf.text=="" || answerBInf.text=="" || answerCInf.text=="" || answerDInf.text=="" || resultInf.text=="" && tmpInf.isSelected)
//												{
//													isDialog=true;
//													dialog=Dialog("Cac truong khong duoc de trong!", "","","OK");
//												}
//												else if(isChanged)
//												{
//													isDialog=true;
//													dialog=Dialog("Dang nhap lieu, Luu thay doi?","Luu", "Khong luu");
//			
//												}
//												else
//												{
//													rowRightTbl=(cursorY-quesTbl.yRow0)/quesTbl.hRow;
//													isMouseUsing=true;
//												}
//											}
//											else
//											{
//												rowRightTbl=(cursorY-quesTbl.yRow0)/quesTbl.hRow;
//												isMouseUsing=true;
//											} 
//											
//										}
//			//							isMouseUsing=true;
//			//							cout<<"that";
//									}
//									else if(cursorY>=rPageBtns.y && cursorY<rPageBtns.y+sizePageBtn)	// click doi trang 
//									{
//										if(cursorX>=rPageBtns.x && cursorX<rPageBtns.x+rPageBtns.width)
//										{
//											page=(cursorX-rPageBtns.x)/sizePageBtn;
//											isMouseUsing=true;
//										}
//									}
//									else if(cursorY>=r_addBtn.y && cursorY<r_addBtn.y+r_addBtn.height)
//									{
//										if(cursorX>=r_addBtn.x && cursorX<r_addBtn.x+r_addBtn.width)
//										{
//											tmpIsSelectedRAddBtn=true;
//											isAdding_r=true;
//	//										showBtn(r_addBtn,WHITE, tmpIsSelectedRAddBtn,0);
//											r_addBtn.show();
//			//								isMouseUsing=true;
//											
//											quesInf.text= "";
//											answerAInf.text="";
//											answerBInf.text="";
//											answerCInf.text="";
//											answerDInf.text="";
//											resultInf.text= "";
//											
//											isMouseUsing=false;
//											createInf(tmpInf,quesInf);
//											showInputField(tmpInf);
//											oldStr=quesInf.text;
//											strInputting=&quesInf.text;
//										}
//									}
//								}
//								else if(selecting==0)
//								{
//									if(cursorY>=studentTbl.yRow0 && cursorY<studentTbl.y+studentTbl.height)
//									{
//										if(cursorX>=studentTbl.x && cursorX<studentTbl.x+studentTbl.width)
//										{
//											if(!isMouseUsing)
//											{
//	//											if(quesInf.text=="" || answerAInf.text=="" || answerBInf.text=="" || answerCInf.text=="" || answerDInf.text=="" || resultInf.text=="" && tmpInf.isSelected)
//	//											{
//	//												isDialog=true;
//	//												dialog=Dialog("Cac truong khong duoc de trong!", "","","OK");
//	//											}
//	//											else if(isChanged)
//	//											{
//	//												isDialog=true;
//	//												dialog=Dialog("Dang nhap lieu, Luu thay doi?","Luu", "Khong luu");
//	//		
//	//											}
//	//											else
//	//											{
//	//												rowRightTbl=(cursorY-studentTbl.yRow0)/studentTbl.hRow;
//	//												isMouseUsing=true;
//	//											}
//											}
//											else
//											{
//												rowRightTbl=(cursorY-studentTbl.yRow0)/studentTbl.hRow;
//												isMouseUsing=true;
//											} 
//											
//										}
//			//							isMouseUsing=true;
//			//							cout<<"that";
//									}
//									else if(cursorY>=rPageBtns.y && cursorY<rPageBtns.y+sizePageBtn)	// click doi trang 
//									{
//										if(cursorX>=rPageBtns.x && cursorX<rPageBtns.x+rPageBtns.width)
//										{
//											page=(cursorX-rPageBtns.x)/sizePageBtn;
//											isMouseUsing=true;
//										}
//									}
//	//								else if(cursorY>=r_addBtn.y && cursorY<r_addBtn.y+r_addBtn.height)
//	//								{
//	//									if(cursorX>=r_addBtn.x && cursorX<r_addBtn.x+r_addBtn.width)
//	//									{
//	//										tmpIsSelectedRAddBtn=true;
//	//										isAdding_r=true;
//	////										showBtn(r_addBtn,WHITE, tmpIsSelectedRAddBtn,0);
//	//										r_addBtn.show();
//	//		//								isMouseUsing=true;
//	//										
//	//										quesInf.text= "";
//	//										answerAInf.text="";
//	//										answerBInf.text="";
//	//										answerCInf.text="";
//	//										answerDInf.text="";
//	//										resultInf.text= "";
//	//										
//	//										isMouseUsing=false;
//	//										createInf(tmpInf,quesInf);
//	//										showInputField(tmpInf);
//	//										oldStr=quesInf.text;
//	//										strInputting=&quesInf.text;
//	//									}
//	//								}
//								}
//								
//							}
//							//Con tro dang o phan cuoi
//							else if(cursorY>=r_b_Pnl.y && cursorY<r_b_Pnl.y+r_b_Pnl.height)
//							{
//		//						if(role==teacher)
//		//						{
//									if(selecting==0)
//									{
//										
//										if(cursorX>=firstNameInf.x && cursorX<firstNameInf.x+firstNameInf.width)
//										{
//											if(cursorY>=firstNameInf.y && cursorY<firstNameInf.y+firstNameInf.height)
//											{
//												isMouseUsing=false;
//												createInf(tmpInf,firstNameInf);
//												showInputField(tmpInf);
//												oldStr=firstNameInf.text;
//												strInputting=&firstNameInf.text;
//												
//											}
//											else if(cursorY>=lastNameInf.y && cursorY<lastNameInf.y+lastNameInf.height)
//											{
//												isMouseUsing=false;
//												createInf(tmpInf,lastNameInf);
//												showInputField(tmpInf);
//												oldStr=lastNameInf.text;
//												strInputting=&lastNameInf.text;
//											}
//											else if(cursorY>=maleBtn.y && cursorY<maleBtn.y+maleBtn.height)
//											{
//			//									Chon gioi tinh
//			
//												if(cursorX>=maleBtn.x && cursorX<maleBtn.x+maleBtn.width)
//												{
//													
//	//												if(!isMouseUsing)
//	//												{
//	//													if(checkStudentEntered(firstNameInf.text, lastNameInf.text, dialog, false))
//	//														isDialog=true;
//	//													else
//	//													{
//	//														
//	//														Question tmpQues= Question(quesInf.text, answerAInf.text, answerBInf.text, answerCInf.text, answerDInf.text, resultInf.text);
//	//														Student tmpStu=Student(firstNameInf.text, lastNameInf.text, "Nam");
//	//														if(studentList.addStudent(initializeStudentNode(tmpStu)))
//	//														{
//	//															
//	//															dialog=Dialog("Thanh cong!", "", "", "OK");
//	//															isDialog=true;
//	//		//													isLoadFile=true;
//	////															show_item(quesList);
//	////															cout<<quesList.n;
//	//														}
//	//													} 
//	//												}
//													maleBtn.isSelected=true;
//													femaleBtn.isSelected=false;
//													isMouseUsing=true;
//												}
//												else if(cursorX>=femaleBtn.x && cursorX<femaleBtn.x+femaleBtn.width)
//												{
//													
//	//												
//													maleBtn.isSelected=false;
//													femaleBtn.isSelected=true;
//													isMouseUsing=true;
//												}
//											}
//					
//										}
//										
//	//									if(cursorX>=answerAInf.x && cursorX<answerAInf.x+answerAInf.width)
//	//									{
//	//				
//	//										if(cursorY>=answerAInf.y && cursorY<answerAInf.y+answerAInf.height)
//	//										{
//	//											
//	//											isMouseUsing=false;
//	//											createInf(tmpInf,answerAInf);
//	//											showInputField(tmpInf);
//	//											oldStr=answerAInf.text;
//	//											strInputting=&answerAInf.text;
//	//										}
//	//										else if(cursorY>=answerCInf.y && cursorY<answerCInf.y+answerCInf.height)
//	//										{
//	//											
//	//											isMouseUsing=false;
//	//											createInf(tmpInf,answerCInf);
//	//											showInputField(tmpInf);
//	//											oldStr=answerCInf.text;
//	//											strInputting=&answerCInf.text;
//	//										}
//	//									}
//	//									else if(cursorX>=answerBInf.x && cursorX<answerBInf.x+answerBInf.width)
//	//									{
//	//										if(cursorY>=answerBInf.y && cursorY<answerBInf.y+answerBInf.height)
//	//										{
//	//											isMouseUsing=false;
//	//											createInf(tmpInf,answerBInf);
//	//											showInputField(tmpInf);
//	//											oldStr=answerBInf.text;
//	//											strInputting=&answerBInf.text;
//	//										}
//	//										else if(cursorY>=answerDInf.y && cursorY<answerDInf.y+answerDInf.height)
//	//										{
//	//											isMouseUsing=false;
//	//											createInf(tmpInf,answerDInf);
//	//											showInputField(tmpInf);
//	//											oldStr=answerDInf.text;
//	//											strInputting=&answerDInf.text;
//	//										}
//	//									}
//									}
//									else if(selecting==1)
//									{
//										
//										if(cursorX>=quesInf.x && cursorX<quesInf.x+quesInf.width)
//										{
//											if(cursorY>=quesInf.y && cursorY<quesInf.y+quesInf.height)
//											{
//												isMouseUsing=false;
//												createInf(tmpInf,quesInf);
//												showInputField(tmpInf);
//												oldStr=quesInf.text;
//												strInputting=&quesInf.text;
//												
//											}
//											else if(cursorY>=resultInf.y && cursorY<resultInf.y+resultInf.height)
//											{
//												isMouseUsing=false;
//												createInf(tmpInf,resultInf);
//												showInputField(tmpInf);
//												oldStr=resultInf.text;
//												strInputting=&resultInf.text;
//											}
//											else if(cursorY>=r_SaveBtn.y && cursorY<r_SaveBtn.y+r_SaveBtn.height)
//											{
//			//									cout<<"Luu";
//												if(cursorX>=r_SaveBtn.x && cursorX<r_SaveBtn.x+r_SaveBtn.width)
//												{
//													
//													if(!isMouseUsing)
//													{
//														if(checkQuesEntered(quesInf.text, answerAInf.text, answerBInf.text, answerCInf.text, answerDInf.text, resultInf.text, dialog, false))
//															isDialog=true;
//														else
//														{
//															
//															Question tmpQues= Question(quesInf.text, answerAInf.text, answerBInf.text, answerCInf.text, answerDInf.text, resultInf.text);
//															if(add_QSList(quesList, tmpQues))
//															{
//																
//																dialog=Dialog("Thanh cong!", "", "", "OK");
//																isDialog=true;
//			//													isLoadFile=true;
//																show_item(quesList);
//	//															cout<<quesList.n;
//															}
//															else
//															{
//																dialog=Dialog("Vuot qua so luong cau hoi (200)!", "", "", "OK");
//																isDialog=true;
//																isMouseUsing=true;
//															}
//														} 
//													}
//												}
//											}
//					
//										}
//										
//										if(cursorX>=answerAInf.x && cursorX<answerAInf.x+answerAInf.width)
//										{
//					
//											if(cursorY>=answerAInf.y && cursorY<answerAInf.y+answerAInf.height)
//											{
//												
//												isMouseUsing=false;
//												createInf(tmpInf,answerAInf);
//												showInputField(tmpInf);
//												oldStr=answerAInf.text;
//												strInputting=&answerAInf.text;
//											}
//											else if(cursorY>=answerCInf.y && cursorY<answerCInf.y+answerCInf.height)
//											{
//												
//												isMouseUsing=false;
//												createInf(tmpInf,answerCInf);
//												showInputField(tmpInf);
//												oldStr=answerCInf.text;
//												strInputting=&answerCInf.text;
//											}
//										}
//										else if(cursorX>=answerBInf.x && cursorX<answerBInf.x+answerBInf.width)
//										{
//											if(cursorY>=answerBInf.y && cursorY<answerBInf.y+answerBInf.height)
//											{
//												isMouseUsing=false;
//												createInf(tmpInf,answerBInf);
//												showInputField(tmpInf);
//												oldStr=answerBInf.text;
//												strInputting=&answerBInf.text;
//											}
//											else if(cursorY>=answerDInf.y && cursorY<answerDInf.y+answerDInf.height)
//											{
//												isMouseUsing=false;
//												createInf(tmpInf,answerDInf);
//												showInputField(tmpInf);
//												oldStr=answerDInf.text;
//												strInputting=&answerDInf.text;
//											}
//										}
//									}
//									
//								
//							}
//							
//						}
//						else if(role==student)
//						{
//	
//							// Chuot dang o ben trai
//							if(cursorX>=l_m_Pnl.x && cursorX<l_m_Pnl.x+l_m_Pnl.width)
//							{
//								if(!isTesting && !isFinish)
//								{
//									if(cursorX>=idSubjectInf.x && cursorX<idSubjectInf.x+idSubjectInf.width)
//									{
//										
//										if(cursorY>=idSubjectInf.y && cursorY<idSubjectInf.y+idSubjectInf.height)
//										{
//											isMouseUsing=false;
//											createInf(tmpInf,idSubjectInf);
//											showInputField(tmpInf);
//		//									oldStr=quesInf.text;
//											strInputting=&idSubjectInf.text;
//											isInputUpper=true;
//											isInputNumber=false;
//										}
//										else if(cursorY>=numOfQusInf.y && cursorY<numOfQusInf.y+numOfQusInf.height)
//										{
//											isMouseUsing=false;
//											createInf(tmpInf,numOfQusInf);
//											showInputField(tmpInf);
//											strInputting=&numOfQusInf.text;
//											isInputNumber=true;
//										}
//										else if(cursorY>=timeInf.y && cursorY<timeInf.y+timeInf.height)
//										{
//											isMouseUsing=false;
//											createInf(tmpInf,timeInf);
//											showInputField(tmpInf);
//											strInputting=&timeInf.text;
//											isInputNumber=true;
//										}
//										else if(cursorY>=startBtn.y && cursorY<startBtn.y+startBtn.height )
//										{
//											if(cursorX>=startBtn.x && cursorX<startBtn.x+startBtn.width)
//											{
//												if(idSubjectInf.text=="" || numOfQusInf.text=="" || timeInf.text=="")
//												{
//													dialog=Dialog("Cac truong khong duoc de trong!", "","","OK");
//													isDialog=true;
//													
//												}
//												else
//												{
//													isLoadExam=true;
//													isMouseUsing=true;
//													isLoadQS=true;
//													isCreateTimer=true;
//													testTime=atoi(&timeInf.text[0])*60;
//													
//												}
//											}
//										}
//									}
//								
//								}
//								
//								else if(isTesting)
//								{
//									if(cursorX>=submitBtn.x && cursorX<submitBtn.x+submitBtn.width && cursorY>=submitBtn.y && cursorY<submitBtn.y+submitBtn.height &&!isFinish)
//									{
////										isTesting=false;
////										isFinish=true;
////										isWriteFileInforExamOfStudent=true;
//										isDialog=true;
//										dialog=Dialog("Dang trong gio thi, ban muon nop bai ngay?","Nop bai", "Quay lai");
//									}
//								}
//									
//							}
//						
//							else // Chuot dang o ben phai
//							{
//								if(isTesting || isFinish)
//								{
//									//con tro o ben phai va phia duoi
//									if(cursorX>=quesBtnList.x && cursorX<quesBtnList.x+quesBtnList.width)
//									{
//										if(cursorY>=quesBtnList.y && cursorY<quesBtnList.y+quesBtnList.height)
//										{
//											int tmpRow=(cursorY-quesBtnList.y)/quesBtnList.btnHeight;
//											int tmpCol=(cursorX-quesBtnList.x)/quesBtnList.btnWidth;
//											curQues=tmpRow*10+tmpCol;
//											isLoadQS=true;
//		//									isLoadQS=true;
//											
//		//									quesBtnList.showQuesBtnList(5, curQues, answerList);
//										}
//									}
//								}
//								
//								if(isTesting)
//								{
//									
//									if(cursorY>=ansA_Btn.y && cursorY<ansA_Btn.y+ansA_Btn.height)
//									{
//										if(cursorX>=ansA_Btn.x && cursorX<ansA_Btn.x+ansA_Btn.width)
//										{
//											ansListStudent[curQues]=ansA;
//											
//										}
//										else if(cursorX>=ansB_Btn.x && cursorX<ansB_Btn.x+ansB_Btn.width)
//										{
//		//									ansA_Btn.isSelected=true;
//											ansListStudent[curQues]=ansB;	
//										}
//									}
//									else if(cursorY>=ansC_Btn.y && cursorY<ansC_Btn.y+ansC_Btn.height)
//									{
//										if(cursorX>=ansC_Btn.x && cursorX<ansC_Btn.x+ansC_Btn.width)
//										{
//		//									ansC_Btn.isSelected=true;
//		////									ansA_Btn.show();
//											ansListStudent[curQues]=ansC;
//											
//										}
//										else if(cursorX>=ansD_Btn.x && cursorX<ansD_Btn.x+ansD_Btn.width)
//										{
//		//									ansA_Btn.isSelected=true;
//											ansListStudent[curQues]=ansD;	
//										}
//									}
//									
//									
//								}
//							}
//							
//						}
//					}
//			
//				}
//				tmpcursorX=cursorX;
//				tmpcursorY=cursorY;
//			}
//		}
//		
//		if(kbhit())
//		{
//			
//			if(!isMouseUsing)
//			{
//				char key=getch();
////				cout<<key;
//				if(key>=32)
//				{
//					if(isInputUpper && key>=97 && key<=122)
//						key-=32;
//					if(!isLogged && isInputPass)
//					{
//						password+=key;
//						key='*';
//					}
//					
//					
//					if(textwidth(&tmpInf.text[0])<tmpInf.width-15)
//					{
//						if(!(isInputNumber && !(key>=48 && key<=57)))	
//							tmpInf.text+=key;
//					}
//						
//				}
//				else if(key==8)
//				{
//					
//					if(tmpInf.text.length()>0)
//					{
//						if(!isLogged && isInputPass)
//						{
//							password.erase(password.size()-1);
//							
//						}
//						tmpInf.text.erase(tmpInf.text.size()-1);
//					}
//							
//				}
////				if(isInputPass)
////				{
////					*strInputting=passInf.text;
////				}
//					*strInputting=tmpInf.text;
//			}
//				
//		}
//
//		if(isDialog)
//		{
//			showDialog(dialog);
//		}
//		if(isCreateTimer)
//		{
//			thread t1(timeNormal);
//			t1.detach();
//			isCreateTimer=false;
//		}
////		cout<<endl;
//			
//		page=1-page;
//		
//		
//	};
//	
//	
//	
//	getch();
//	closegraph();
//} 
//
//bool checkQuesEntered(string ques, string answerA, string answerB, string answerC,  string answerD, string result, Dialog& dialog, bool isChanged)
//{
//	bool isDialog=false;
//	if(ques=="" || answerA=="" || answerB=="" || answerC=="" || answerD=="" || result=="" /*&& tmpInf.isSelected*/)							
//	{
//		isDialog=true;
//		dialog=Dialog("Cac truong khong duoc de trong!", "","","OK");
//	}
//	else if(isChanged)
//	{
//		isDialog=true;
//		dialog=Dialog("Dang nhap lieu, luu thay doi?", "Luu","Khong luu");
//	}
//	return isDialog;
//}
//
//bool checkStudentEntered(string firstName, string lastName, Dialog& dialog, bool isChanged)
//{
//	bool isDialog=false;
//	if(firstName=="" || lastName=="")							
//	{
//		isDialog=true;
//		dialog=Dialog("Cac truong khong duoc de trong!", "","","OK");
//	}
//	else if(isChanged)
//	{
//		isDialog=true;
//		dialog=Dialog("Dang nhap lieu, luu thay doi?", "Luu","Khong luu");
//	}
//	return isDialog;
//}
//
//
//void timeNormal()
//{
//	for(int i=testTime; i>=0; i--)
//	{
//		mm=(i-i%60)/60;
//		ss=i%60;
//		Sleep(990);		
//	}
//	isFinish=true;
//	isWriteFileInforExamOfStudent=true;
//}
//
//float marking(int numOfQues, Question *exam,Answers *ansListStudent)
//{
//	float count=0;
////	float numOfQues=sizeof(ansListStudent)/sizeof(ansListStudent[0]);
////	cout<<"Do lon mang: "<<sizeof(ansListStudent)<<endl;
////	cout<<"Do lon thanh phan: "<<sizeof(ansListStudent[0])<<endl;
////	cout<<"So cau hoi: "<<numOfQues<<endl;
//	for(int i=0; i<numOfQues; i++)
//	{
//		string tmpstr;
//		tmpstr+=getAnswerChar(ansListStudent[i]);
//		if(tmpstr==exam[i].question_correctAnswer)
//		count++;
//	}
//	cout<<"So cau dung: "<<count<<endl;
//	return count/(float)numOfQues*10.0;
//}
