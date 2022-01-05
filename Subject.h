#ifndef SUBJECT_H_
#define SUBJECT_H_

#include"Question.h"

using namespace std;

struct subject{
	string subjectId;
	string subjectName;
	QSList qsList;
	
	subject();
	subject(string _subjectId, string subjectName);
};
typedef struct subject SUBJECT;
struct subjectNode{
	subject sj;
	subjectNode *pleft;
	subjectNode *pright;
};
typedef struct subjectNode SUBJECTNODE;
typedef subjectNode* subjectTree;
struct subjectList{
	SUBJECTNODE* tree=NULL;
	int sl;
	void freeSubjectList(SUBJECTNODE *node);
};
typedef struct subjectList  SUBJECTLIST ;

void treeToArray(subjectTree tree, subjectTree ds[],int &index);
void editSubject(SUBJECTLIST &ds,string idStr, string name);
int checkDuplicatedID(SUBJECTNODE* t, string a);
//void editSubjectID(SUBJECTNODE* &root, string id, string preid);
int countNodes(SUBJECTNODE* root);
void NLR( subjectTree &t);
 SUBJECTNODE* searchSubject(SUBJECTNODE* root, string str);
 void readSubjectjList(SUBJECTLIST &sjList);
 int deleteNode(subjectTree &t,string idDelete);
 void NodeTheMang(subjectTree &X,subjectTree &Y);
 SUBJECTNODE* createSubjectNode(subject t);
 void InsertSubject(subjectTree &t, SUBJECTNODE* p);
 void saveFile_Tree(subjectTree &t);
 void writeSubjectList(subjectTree &t,ofstream &f) ;
 void sortSubject(SUBJECTNODE *ds[],int sizeOfArr);
 
#endif //SUBJECT_H_















//#pragma one
//#include<string>
//#include<iostream>
//#define MAXSUBJECT 100
//#define MAXCLASS 100
//
//using namespace std;
////********************************LIST SUBJECT**********************
//struct subject
//{
//	//data
//	string ID_subject;
//	string name_subject;
//	//*list_question
//	LIST_QUESTION list_question;
//	//pointer
//	subject *pleft;
//	subject *pright;
//};
//typedef struct subject* tree;
//
//struct list_subject
//{
//	tree list = null
//	int number = 0;
//};
//typedef struct DanhSachMonHoc DSMH;
//// ********************************LIST CLASS**************************
//
//struct class{
//	string ID_class;
//	string name_class;
//	LIST_STUDENT list_s; // dua vao ten cua Dai dat nha
//};
//typedef struct class CLASS;
//
//struct list_class{
//	int number_class = 0;
//	CLASS *LISTLOP[MAXCLASS]={NULL};
//};
//typedef struct list_class LIST_CLASS;

