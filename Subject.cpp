#include<iostream>
#include<fstream>
#include<string>
#include"Subject.h"
using namespace std;
// ghi file
SUBJECT::subject(){};
SUBJECT::subject(string _subjectId, string _subjectName)
{
	subjectId=_subjectId;
	subjectName=_subjectName;
}
void writeSubjectList(subjectTree &t,ofstream &f)  //ghi mon vao bien file, lien quan ham duoi
{
	if (t!=NULL)
	{ 
	
	  f<<t->sj.subjectId<<endl;
	  if(t->pleft==NULL&&t->pright==NULL)
	   {
	   	f<<t->sj.subjectName;
	   }
	  else   f<<t->sj.subjectName<<"\n";
	  writeQsFile(t->sj.qsList, t->sj.subjectId);
	  writeSubjectList(t->pleft,f);
	  writeSubjectList(t->pright,f);
	}
}
void saveFile_Tree(subjectTree &t)//luu mon vao file, dung ham nay la luu duoc r 
{
	ofstream MyFile("Subjects.txt");
	
	writeSubjectList(t, MyFile);
	MyFile.close();
}


void InsertSubject(subjectTree &t, SUBJECTNODE* p){  //chen node vao cay(them node)
	if(t== NULL){
		t=p;
	}
	if(t!=NULL) {
		if(p->sj.subjectId.compare(t->sj.subjectId)>0){
			InsertSubject(t->pright,p);
		}
		else if(p->sj.subjectId.compare(t->sj.subjectId)<0){
			InsertSubject(t->pleft, p);
		}
	}
}

SUBJECTNODE* createSubjectNode(subject t) //tao mot node monhoc
{
	SUBJECTNODE* p=new SUBJECTNODE;
	p->sj = t;
	p->pleft=p->pright=NULL;
	return p;
}
void NodeTheMang(subjectTree &X,subjectTree &Y){
	 if (Y->pleft != NULL)
    {
        NodeTheMang(X, Y->pleft);// tìm ra node trái nh?t ?
    }
    else // tìm ra du?c node trái nh?t r?i nek..
    {
        X->sj=Y->sj;
        X->sj=Y->sj;
        X = Y; // cho node X(là node mà chúng ta s? di xóa sau này) tr? d?n node th? m?ng ==> ra kh?i hàm thì ta s? xóa node X
        Y = Y->pright; // b?n ch?t ch? này chính là c?p nh?t l?i m?i liên k?t cho node cha c?a node th? m?ng(mà chúng ta s? xóa) v?i node con c?a node th? m?ng  
    }
}

int deleteNode(subjectTree &t,string idDelete){ // xem lai
	
	if (t == NULL)
    {
        return 0; // k?t thúc hàm
    }
    else
    {
        if (idDelete<t->sj.subjectId)
        {
            deleteNode(t->pleft, idDelete); // duy?t sang nhánh trái c?a cây 
 
        }
        else if (idDelete>t->sj.subjectId)
        {
            deleteNode(t->pright,idDelete ); // duy?t sang nhánh ph?i c?a cây 
        }
        else // data == t->data - dã tìm ra cái node c?n xóa
        {
//        	cout<<"SO luong cau hoi: "<<t->sj.qsList.n<<endl;
        	if(t->sj.qsList.n!=0)
        	 {
        	 	cout<<"TRuoc khi xoa"<<endl;
        	 	return 0;
        	 	cout<<"Sau khi xoa"<<endl;
			 }

            SUBJECTNODE *X = t; // node X là node th? m?ng - tí n?a chúng ta s? xóa nó
            if (t->pleft == NULL)
            {
                t = t->pright; 
            }
            else if (t->pright == NULL)
            {
                t = t->pleft;
            }
            else // node c?n xóa là node có 2 con
            {
                NodeTheMang(X, t->pright);
            }
            delete X; // xóa node c?n xóa
            X=NULL;
            return  2;
        }
    }
	
}

void readSubjectjList(SUBJECTLIST &sjList){ //ham doc load vao cay
	std::fstream file;
	file.open("Subjects.txt", std::ios::in);
	if(file==NULL) return;
    while(!file.eof())
	 { 
	    subject sj;	
	    getline(file,sj.subjectId);
	     getline(file,sj.subjectName);
	     load_item(sj.qsList, sj.subjectId);
	     cout<<"HELLLLLLOMANNNNN: "<<sj.qsList.n<<endl;
	  	SUBJECTNODE* t= createSubjectNode(sj); //khoi tao mot node
		InsertSubject(sjList.tree,t);	////    
       if(file.eof()) //neu con tro o cuoi roi thi break ra
        {  
           break;
	    }
     }
	    
	file.close();
}

 SUBJECTNODE* searchSubject(SUBJECTNODE* root, string str){ // tim mot node
	SUBJECTNODE* tree=root;	
	while (tree !=NULL){
		if(tree->sj.subjectId>str){
			tree= tree->pleft;
		}
		else if(tree->sj.subjectId<str){
			tree=tree->pright;
		}
		else if(tree->sj.subjectId==str){
			return tree;
			break;
		}
	}
	return NULL;
}

void NLR( subjectTree &t) // ham duyet cay in du lieu de test
{
	if (t != NULL)
	{
		cout << t->sj.subjectId << "  ";
		cout << t->sj.subjectName<<endl;
		NLR(t->pleft);
		NLR(t->pright);
	}
}
// ham Cuong gui
int countNodes(SUBJECTNODE* root){ // ham dem node mon hoc
   if (root == NULL)
      return 0;
   return countNodes (root->pleft) +
   countNodes (root->pright) + 1;
}

void editSubject(SUBJECTLIST &ds,string idStr, string name){ // sua mot mon
	char id[50];
	strcpy(id, idStr.c_str());
	subjectTree pos = searchSubject(ds.tree, id);
	if (pos != NULL)
	{
//		strcpy(pos->sj.subjectName, name.c_str());
		pos->sj.subjectName=name;
	}
}
int checkDuplicatedID(SUBJECTNODE* t, string a)
{
  
    SUBJECTNODE* p;
    while (t) {
        if (t->pleft == NULL) {
            if (t->sj.subjectId==a) return 1;
            t = t->pright;
        }
        else {
            p = t->pleft;
            while (p->pright && p->pright != t) {
                p = p->pright;
            }
            if (p->pright == NULL) {
                p->pright = t;
                t = t->pleft;
            }
            else {
                p->pright = NULL;
                if (t->sj.subjectId==a) return 1;

                t = t->pright;
            }
        }
    }
    return 0;
}
void sortSubject(SUBJECTNODE *ds[],int sizeOfArr){ // ham sap xep sau khi da chuyen sang mang
	int min;
	for(int i=0;i<sizeOfArr-1;i++)
	 {
	   min=i;
	 	for(int j=i+1;j<sizeOfArr;j++) //ket thuc vong nay cho  ra phan tu co gia tri min(tim vi tri  phan tu nho nhat)
	 	 {
//	 	 if(strcmp(ds[min]->sj.subjectsId,ds[j]->sj.subjectsId)>0){ neu dung du lieu la char thi so sanh nhu nay, con string thi bo dong nay di
	 	 	if(ds[min]->sj.subjectId>ds[j]->sj.subjectId){	
	 	 		min=j;
			  }
		  }
	    if(min!=i) {//vi tri phan tu nho nhat khong phai i,. doi cho
	    SUBJECTNODE *temp;
		 temp=ds[i];
	     ds[i]=ds[min];
	     ds[min]=temp;
	    }
	 }
}

void treeToArray(subjectTree t, SUBJECTNODE *ds[],int &sl){
	if(t!=NULL){
		ds[sl]=new SUBJECTNODE;		
		ds[sl]=t;
		sl++;
		treeToArray(t->pleft,ds,sl);
		treeToArray(t->pright,ds,sl);
	}	
}
	
void SUBJECTLIST::freeSubjectList(SUBJECTNODE *node)
{
	if (node != NULL) 
	{
		freeSubjectList(node->pright);
		freeSubjectList(node->pleft);
		freeSubjectList(node);
	}
}

//void giaiPhongDanhSachMonHoc(NODEMONHOC* ds_monhoc[], int sl_monhoc)
//{
//	for(int i=0;i<sl_monhoc;i++){
//		delete ds_monhoc[i];
//	}
//}
