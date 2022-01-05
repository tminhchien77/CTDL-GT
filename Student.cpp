#include "Student.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
Student::Student(){};
string removeSpaces(char *str)
{
    int count = 0;
    for (int i = 0; str[i]; i++)
    {
    	if (str[i] != ' ')
            str[count++] = str[i];
	} 
    str[count] = '\0';
    return str;
}
void Student::createPassWord(){
	string tmpFirst=firstName;
	string tmpLast=lastName;
	password=removeSpaces(&tmpFirst[0])+removeSpaces(&tmpLast[0]);
};
Student::Student(string _id, string _firstName, string _lastName, int _sex){
	id=_id;
	firstName=_firstName;
	lastName=_lastName;
	sex=_sex;
	createPassWord();
};
StudentList::StudentList(){};
int StudentList::getLength()
{
	StudentNode *p=pHead;
	if(p==NULL)return 0;
	int count=0;
	while(p!=NULL)
	{
		p=p->pNext;
		count++;
	}
	return count;
}
void initializeStudentList(StudentList &list)
{
	list.pHead=NULL;
//	list.n=0;
}

bool StudentList::addStudent(StudentNode *p)
{
	if(pHead==NULL)
	{
		pHead=p;
		return false;
	} 
	else
	{
		StudentNode *pTmp=pHead;
		while(pTmp->pNext!=NULL)
		{
			pTmp=pTmp->pNext;
		}
		pTmp->pNext=p;
		return true;
	}
	
//	n++;
}

Student StudentList::getStudent(int index)
{
	StudentNode *p=pHead;
	for(int i=0; i<index; i++)
	{
		p=p->pNext;
	}
	return p->data;
};

void editStudent(StudentList &list, int index, string fName, string lName, int _sex)
{
	StudentNode *p=list.pHead;
	for(int i=0; i!=index; i++)
	{
		p=p->pNext;
	}
	
	p->data.firstName=fName;
	p->data.lastName=lName;
	p->data.sex=_sex;
}

StudentNode * initializeStudentNode(Student student)
{
	StudentNode *pNode =new StudentNode;
	if(pNode!=NULL)
	{
		pNode->data=student;
		pNode->pNext=NULL;
	}
	else
	{
		cout<<"Cap phat bo nho that bai";
	}
	return pNode;
}

void readStudent(ifstream &fileIn, Student &sv){
	getline(fileIn, sv.id,',');	
//	cout<<"ID SV: "<<"?"<<sv.id<<endl;
	getline(fileIn, sv.firstName,',');
	getline(fileIn, sv.lastName,',');
	fileIn>>sv.sex;
	
	string tmp;
	getline(fileIn, tmp);
	sv.password=tmp.substr(1, tmp.length()-1);
}

bool readStudentList(string idLop, StudentList &list)
{
	
	ifstream fileIn;
	string fileName=idLop+extensionFile;
//	cout<<" "<< fileName<<endl;
	fileIn.open(fileName, ios_base::in);
	if(fileIn.fail()) return false;
	list.pHead=NULL;
	int n=0;
	fileIn>>n;
	string tmp;
	getline(fileIn, tmp);
	for(int i=0; i<n; i++)
	{
		Student s;
		readStudent(fileIn, s);
		
		readScoreList(s.id, s.scoreList);
		StudentNode *p=initializeStudentNode(s);
		list.addStudent(p);
	}
//	cout<<"Chieudai"<<list.getLength();
	fileIn.close();
//	cout<<"Doc file"<<list.pHead->data.password;
	return true;
}



bool writeFileScoreOfClass(string id, string idSubj, float score)
{
	string classID="D18CQ"+id.substr(0,4);
	ofstream fileOut;
	string fileName="score_"+idSubj+"_"+classID+".txt";
	fileOut.open(fileName, ios::out|ios::app);
	if(fileOut.fail())
		return false;
	fileOut<<id<<","<<score<<endl;
	fileOut.close();
	return true;
	
	
}

//Student* StudentList::searchByID(string id)
//{
//	int left=0; 
//	int right=getLength()-1;
//	int mid=0;
////	cout<<"User pass "<<id;
////	cout<<"passss"<<pHead->data.password<<endl;
//	do
//	{
//		mid=(left+right)/2;
////		cout<<"mid="<<mid<<endl;
//		Student tmp=getStudent(mid);
////		cout<<"pass"<<tmp.password;
//		if(tmp.id==id)
//		{
//			cout<<"Da tra ve "<<tmp.id<<" "<<tmp.password<<endl;
//			return &tmp;
//		}	
//		else if(tmp.id.compare(id)>0) // id cua student > id user
//		{
//			right=mid-1; // Vi id lon hon id giua nen id can tim nam o ben trai, nen right lui ve giua-1
//
//		}
//		 
//		else
//			left=mid+1; // Vi id nho hon id giua nen id can tim nam o ben phai, nen left tien toi giua+1	
//	}while(left<=right);
//	return NULL;
//	
//}

int StudentList::searchByID(string id)
{
	int left=0; 
	int right=getLength()-1;
	int mid=0;
//	cout<<"User pass "<<id;
//	cout<<"passss"<<pHead->data.password<<endl;
	do
	{
		mid=(left+right)/2;
//		cout<<"mid="<<mid<<endl;
		Student tmp=getStudent(mid);
//		cout<<"pass"<<tmp.password;
		if(tmp.id==id)
		{
//			cout<<"Da tra ve "<<tmp.id<<" "<<tmp.password<<endl;
			return mid;
		}	
		else if(tmp.id.compare(id)>0) // id cua student > id user
		{
			right=mid-1; // Vi id lon hon id giua nen id can tim nam o ben trai, nen right lui ve giua-1

		}
		 
		else
			left=mid+1; // Vi id nho hon id giua nen id can tim nam o ben phai, nen left tien toi giua+1	
	}while(left<=right);
	return -1;
	
}
//bool writeAStudentIntoClass(ofstream fileOut, string id, Student s)
//{
//	fileOut<<s.id<<","<<s.firstName<<","<<s.lastName<<","<<s.sex<<","<<s.password;
//}

bool writeFileStudentsOfClass(string classID, StudentList list)
{
	
	ofstream fileOut;
	string fileName=classID+extensionFile;
	fileOut.open(fileName, ios::out);
	if(fileOut.fail())
		return false;
	StudentNode *p=list.pHead;
	fileOut<<list.getLength()<<endl;
	while(p!=NULL)
	{
		fileOut<<p->data.id<<","<<p->data.firstName<<","<<p->data.lastName<<","<<p->data.sex<<","<<p->data.password<<endl;
		p=p->pNext;
	}
	fileOut.close();
	return true;
}

string getNextID(StudentList list, string idClass)
{
	char tmp[5];
//	cout<<"Loi"<<idClass;
	int maxIDStudent=atoi(&list.getStudent(list.getLength()-1).id.substr(5,4)[0])+1;
	string tmpstr(itoa(maxIDStudent, tmp,10));
	if(maxIDStudent<10) tmpstr= "000"+tmpstr;
	else if(maxIDStudent<100) tmpstr= "00"+tmpstr;
	else if(maxIDStudent<1000) tmpstr= "0"+tmpstr;
	return 	idClass.substr(5,4)+"_"+tmpstr;
}

bool writeFileInforExamOfStudent(string idStudent, string idSubj, int score, int numOfQues, Question *exam)
{
	ofstream fileOut;
	string fileName=idStudent+extensionFile;
	fileOut.open(fileName, ios::out|ios::app);
	if(fileOut.fail())
		return false;
	fileOut<<idSubj<<","<<score<<endl;
	fileOut<<numOfQues<<endl;
	for(int i=0; i<numOfQues; i++)
	{
		fileOut<<exam[i].question_code<<",";
	}
	fileOut<<endl;
	fileOut.close();
}

void StudentList::freeStudentList()
{
	StudentNode *p;
	while(pHead!=NULL)
	{
		p=pHead;
		pHead=pHead->pNext;
		p->data.scoreList.freeScoreList();
		free(p);
	}
}

//void ScoreList::freeScoreList()
//{
//	ScoreNode *p;
//	while(pHead!=NULL)
//	{
//		p=pHead;
//		pHead=pHead->pNext;
//		p->exam.freeExam();
//		free(p);
//	}
//}
