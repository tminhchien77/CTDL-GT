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
//
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
//
//
//int main ()
//{
//	
//	int a=initwindow(screenWidth,screenHeight,"Test -- ver 1.0", 50,50);
//	
//	char arr[100];
//    
//    QSList quesList;
//	
//			
//			
//	//====================================Khoi tao thanh phan======================================================================
////	Button classesBtn=Button(0,0,wBtnMenuBar,hBtnMenuBar,"Classes", selectedColorMenuBar, unSelectedColorMenuBar);
////	Button subjectsBtn=Button(wBtnMenuBar,0,wBtnMenuBar,hBtnMenuBar,"Subjects", selectedColorMenuBar, unSelectedColorMenuBar);
//	Panel l_Pnl=Panel(3,3,500,screenHeight, WHITE);
//	Panel r_t_Pnl=Panel(l_Pnl.x+l_Pnl.width+padding,3,screenWidth-l_Pnl.x-l_Pnl.width-padding-3,420, WHITE);
////	Panel l_b_Pnl=Panel(0, yEditPnl, 500, screenHeight-yEditPnl, WHITE);
//	Panel r_b_Pnl=Panel(l_Pnl.x+l_Pnl.width+padding, r_t_Pnl.y+r_t_Pnl.height+padding, r_t_Pnl.width, screenHeight-r_t_Pnl.height-padding, WHITE);
////	Table quesTbl= Table(r_m_Pnl.x+35, r_m_Pnl.y+50, r_m_Pnl.width-35*2, r_m_Pnl.height-130);
//////	Button rightNextPage=Button(quesTbl.x+quesTbl.width-75,quesTbl.y+quesTbl.height+10,75,50,"Next", selectedColorMenuBar, unSelectedColorMenuBar);
//////	Button rightPrePage=Button(quesTbl.x,quesTbl.y+quesTbl.height+10,100,50,"Previous", selectedColorMenuBar, unSelectedColorMenuBar);
////	Button r_addBtn=Button(1145, 35, 100, 30, defUnSelectedBtnColor, WHITE);
////	Button r_SaveBtn=Button(710, 650, 100, 30, "Luu", defUnSelectedBtnColor, WHITE);
////	Button r_UnsaveBtn=Button(1000, 650, 100, 30, "Thoat", defUnSelectedBtnColor, WHITE);
////	ButtonList rPageBtns;
////	
////	InputField quesInf= InputField(r_b_Pnl.x+150, r_b_Pnl.y+45, 500, 25,50);
////	InputField answerAInf= InputField(quesInf.x, quesInf.y+40, 200, 25,50);
////	InputField answerBInf= InputField(quesInf.x+300, quesInf.y+40, 200, 25,50);
////	InputField answerCInf= InputField(quesInf.x, answerAInf.y+40, 200, 25,50);
////	InputField answerDInf= InputField(quesInf.x+300, answerAInf.y+40, 200, 25,50);
////	InputField resultInf= InputField(r_b_Pnl.x+150, answerCInf.y+40, 500, 25,50);
////	Dialog dialog=Dialog("Dang nhap lieu, Luu thay doi?", "Dong y","Thoat");
////	InputField tmpInf;
////	Label idQSLbl;
////	
////	POINT cursorPosition;
////	int cursorX, cursorY;
////	int selecting=0;
//	int page=0;
////	int rowRightTbl=0;
////	int pageRightTbl=0;
////	bool isMouseUsing=true;
////	string * strInputting;
////	string oldStr;
////	bool isChanged=false;
////	bool isDialog=false;
////	bool isLoadFile=false;
////	bool tmpIsSelectedRAddBtn=false;
////	bool isAdding_r=false;
////	string txtIdQS;
//	
//	while(1){
//		setactivepage(page);
//		
//		setvisualpage(1-page);
//		setbkcolor(LIGHTGRAY);
//		cleardevice();
//		showPnl(l_Pnl);
//		showPnl(r_t_Pnl);
//		showPnl(r_b_Pnl);
////		if(GetAsyncKeyState(VK_LBUTTON))
////		{
////			
////			if(isDialog)
////			{
////				
////				if(cursorY>=dialog.opUnSave.y && cursorY<dialog.opUnSave.y+dialog.opUnSave.height)
////				{
////					
////					if(cursorX>=dialog.opSave.x && cursorX<dialog.opSave.x+dialog.opSave.width) //Luu thay doi nhap lieu
////					{
//////						
////						quesList.question_QSList[index].question_content=quesInf.text;
////						quesList.question_QSList[index].question_answer_A=answerAInf.text;
////						quesList.question_QSList[index].question_answer_B=answerBInf.text;
////						quesList.question_QSList[index].question_answer_C=answerCInf.text;
////						quesList.question_QSList[index].question_answer_D=answerDInf.text;
////						quesList.question_QSList[index].question_correctAnswer=resultInf.text;
////						isDialog=false;
////						isMouseUsing=true;
////					}
////					else if(cursorX>=dialog.opUnSave.x && cursorX<dialog.opUnSave.x+dialog.opUnSave.width) //Huy bo thay doi nhap lieu
////					{
////						
////						quesInf.text= quesList.question_QSList[index].question_content;
////						answerAInf.text=quesList.question_QSList[index].question_answer_A;
////						answerBInf.text=quesList.question_QSList[index].question_answer_B;
////						answerCInf.text=quesList.question_QSList[index].question_answer_C;
////						answerDInf.text=quesList.question_QSList[index].question_answer_D;
////						resultInf.text= quesList.question_QSList[index].question_correctAnswer;
////						
////						isDialog=false;
////						isMouseUsing=true;
////					}
////				}
////				else if(cursorY>=dialog.opOK.y && cursorY<dialog.opOK.y+dialog.opOK.height)
////				{
////					if(cursorX>=dialog.opOK.x && cursorX<dialog.opOK.x+dialog.opOK.width) //Quay lai nhap lieu
////					{
////						cout<<"quay lai nhap lieu";
////						isMouseUsing=false;
//////						tmpInf.isSelected=true;
//////						cout<<"nhap";
//////						cout<<tmpInf.text;
//////						cout<<"hihi";
////						isDialog=false;
//////						goto label;
////						showInputField(tmpInf);
////					}	
////				}
////			}	
////			else
////			{
////				// Con tro chuot dang o thanh menu bar
////				if(cursorY>=yMenuBar && cursorY<yListPnl)	
////				{
////					if(cursorX>=classesBtn.x && cursorX<classesBtn.x+classesBtn.width && selecting!=0)
////					{
////						cout<<"ngoai";
////						if(!isMouseUsing)
////						{
////							cout<<"trong";
////							if(quesInf.text=="" || answerAInf.text=="" || answerBInf.text=="" || answerCInf.text=="" || answerDInf.text=="" || resultInf.text=="" && tmpInf.isSelected)
////							
////							{
////								cout<<"dialog text trong";
////								isDialog=true;
////								dialog=Dialog("Cac truong khong duoc de trong!", "","","OK");
////							}
////							else if(isChanged)
////							{
////								isDialog=true;
////								dialog=Dialog("Dang nhap lieu, luu thay doi?", "Luu","Khong luu");
////	//							cout<<dialog.op1.text;
////							}
////							else
////							{
////								selecting=0;
////								isMouseUsing=true;
////							} 
////						}
////						else
////						{
////							selecting=0;
////							isMouseUsing=true;
////						} 
////						
////					}
////					else if(cursorX>=subjectsBtn.x && cursorX<subjectsBtn.x+subjectsBtn.width && selecting!=1)
////					{
////						
////						if(!isMouseUsing)
////						{
////		//					cout<<isChanged;
////							
////							if(isChanged)
////							{	
////		
////								isDialog=true;
////								dialog=Dialog("Dang nhap lieu, Luu thay doi?", "Luu","Khong luu");
//////								cout<<dialog.op1.text;
////							}
////							
////						}
////						else
////						{
////							selecting=1;
////							isMouseUsing=true;
////							isLoadFile=true;
////						} 
////					}
////					
////				}
////				//Con tro dang o phan giua
////				else if(cursorY>=yListPnl && cursorY<yListPnl+l_m_Pnl.height)
////				{
////					if(selecting==1)
////					{
////						if(cursorY>=quesTbl.yRow0 && cursorY<quesTbl.y+quesTbl.height)
////						{
////							if(cursorX>=quesTbl.x && cursorX<quesTbl.x+quesTbl.width)
////							{
////								if(!isMouseUsing)
////								{
////									if(quesInf.text=="" || answerAInf.text=="" || answerBInf.text=="" || answerCInf.text=="" || answerDInf.text=="" || resultInf.text=="" && tmpInf.isSelected)
////									{
////										isDialog=true;
////										dialog=Dialog("Cac truong khong duoc de trong!", "","","OK");
////									}
////									else if(isChanged)
////									{
////										isDialog=true;
////										dialog=Dialog("Dang nhap lieu, Luu thay doi?","Luu", "Khong luu");
////
////									}
////									else
////									{
////										rowRightTbl=(cursorY-quesTbl.yRow0)/quesTbl.hRow;
////										isMouseUsing=true;
////									}
////								}
////								else
////								{
////									rowRightTbl=(cursorY-quesTbl.yRow0)/quesTbl.hRow;
////									isMouseUsing=true;
////								} 
////								
////							}
//////							isMouseUsing=true;
//////							cout<<"that";
////						}
////						else if(cursorY>=rPageBtns.y && cursorY<rPageBtns.y+sizePageBtn)
////						{
////							if(cursorX>=rPageBtns.x && cursorX<rPageBtns.x+rPageBtns.width)
////							{
////								page=(cursorX-rPageBtns.x)/sizePageBtn;
////								isMouseUsing=true;
////							}
////						}
////						else if(cursorY>=r_addBtn.y && cursorY<r_addBtn.y+r_addBtn.height)
////						{
////							if(cursorX>=r_addBtn.x && cursorX<r_addBtn.x+r_addBtn.width)
////							{
////								tmpIsSelectedRAddBtn=true;
////								isAdding_r=true;
////								showBtn(r_addBtn,WHITE, tmpIsSelectedRAddBtn,0);
//////								isMouseUsing=true;
////								
////								quesInf.text= "";
////								answerAInf.text="";
////								answerBInf.text="";
////								answerCInf.text="";
////								answerDInf.text="";
////								resultInf.text= "";
////								
////								isMouseUsing=false;
////								createInf(tmpInf,quesInf);
////								showInputField(tmpInf);
////								oldStr=quesInf.text;
////								strInputting=&quesInf.text;
////							}
////						}
////					}
////					else
////					{
////						
////					}
////					
////				}
////				//Con tro dang o phan cuoi
////				else if(cursorY>=yEditPnl && cursorY<yEditPnl+l_b_Pnl.height)
////				{
////					
////					
////					if(selecting==1)
////					{
////						
////						if(cursorX>=quesInf.x && cursorX<quesInf.x+quesInf.width)
////						{
////							if(cursorY>=quesInf.y && cursorY<quesInf.y+quesInf.height)
////							{
////								isMouseUsing=false;
////								createInf(tmpInf,quesInf);
////								showInputField(tmpInf);
////								oldStr=quesInf.text;
////								strInputting=&quesInf.text;
////								
////							}
////							else if(cursorY>=resultInf.y && cursorY<resultInf.y+resultInf.height)
////							{
////								isMouseUsing=false;
////								createInf(tmpInf,resultInf);
////								showInputField(tmpInf);
////								oldStr=resultInf.text;
////								strInputting=&resultInf.text;
////							}
////	
////						}
////						
////						if(cursorX>=answerAInf.x && cursorX<answerAInf.x+answerAInf.width)
////						{
////	
////							if(cursorY>=answerAInf.y && cursorY<answerAInf.y+answerAInf.height)
////							{
////								
////								isMouseUsing=false;
////								createInf(tmpInf,answerAInf);
////								showInputField(tmpInf);
////								oldStr=answerAInf.text;
////								strInputting=&answerAInf.text;
////							}
////							else if(cursorY>=answerCInf.y && cursorY<answerCInf.y+answerCInf.height)
////							{
////								
////								isMouseUsing=false;
////								createInf(tmpInf,answerCInf);
////								showInputField(tmpInf);
////								oldStr=answerCInf.text;
////								strInputting=&answerCInf.text;
////							}
////						}
////						else if(cursorX>=answerBInf.x && cursorX<answerBInf.x+answerBInf.width)
////						{
////							if(cursorY>=answerBInf.y && cursorY<answerBInf.y+answerBInf.height)
////							{
////								isMouseUsing=false;
////								createInf(tmpInf,answerBInf);
////								showInputField(tmpInf);
////								oldStr=answerBInf.text;
////								strInputting=&answerBInf.text;
////							}
////							else if(cursorY>=answerDInf.y && cursorY<answerDInf.y+answerDInf.height)
////							{
////								isMouseUsing=false;
////								createInf(tmpInf,answerDInf);
////								showInputField(tmpInf);
////								oldStr=answerDInf.text;
////								strInputting=&answerDInf.text;
////							}
////						}
////					}	
////				}
////			}
////		}
////		
////		if(kbhit())
////		{
////			
////			if(!isMouseUsing)
////			{
//////				showInputField(tmpInf);
//////				cout<<"KKKK";
////				char key=getch();
////				
//////				cout<<key;
////				if(key>=32)
////				{
////					tmpInf.text+=key;
//////						cout<<tmpInf.text;
////					
////				}
////				else if(key==8)
////				{
////							tmpInf.text.erase(tmpInf.text.size()-1);
////				}
////	//			else if(key==0){
////	//				switch(getch())
////	//				{
////	//					case KEY_LEFT:
////	//						
////	//				}
////	//			}
//////				showSelectedInputField(tmpInf)	;
////				*strInputting=tmpInf.text;
////			}
////				
////		}
//////		label:
////		if(isDialog)
////		{
//////			cout<<dialog.op1.text;
////			showDialog(dialog);
//////			justShowedDialog=true;
////		}
//		page=1-page;
////		delay(50);
//	};
//	
//	
//	
//	getch();
//	closegraph();
//} 
//

