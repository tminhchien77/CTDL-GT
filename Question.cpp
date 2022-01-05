#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>
#include "Question.h"
//#include "list_question_Function.h"
#include <sstream>
#include <time.h>
#include<graphics.h>
#include "graphics.h"
using namespace std;

Question::Question(){};
Question::Question(string ques, string answerA, string answerB, string answerC,  string answerD, char result)
{
	question_content=ques;
	question_answer_A=answerA;
	question_answer_B=answerB;
	question_answer_C=answerC;
	question_answer_D=answerD;
	question_correctAnswer=result;
}

QSList::QSList(){};
string subjectItem()
 {
 	string ds[30];
 	fstream myFile;
    myFile.open("subjectsFile"); 
    int j=0;
 	while(!myFile.eof())
 	 {
 	 	getline(myFile,ds[j]);
 	 	if(myFile.eof())
 	 	 {
 	 	 	break;
		   }
 	 	j=j+1;
	  }
	for(int i=0;i<=j;i++)
	{
			cout<<i+1<<"."<<ds[i]<<endl;
	}
	int index;
	cout<<"nhap chi so ung voi mon: ";
	cin>>index;
	myFile.close();
	return ds[index-1];
 }

//void create_list(QSList &plist)
//{     
//   string subject_codeText=subjectItem();
//	ofstream myFile;
//    myFile.open(subject_codeText.c_str()); 
//    plist.n=0;
//     int question_plus=0; // auto tu ma bang khong , khi co n la not  
//    string str;
//    do{
//    	cout<<"nhap so cau hoi: ";
//       cin>>plist.n;
//       if(plist.n>MAX)
//        {
//        	cout<<"so cau hoi khong hop le\n";
//		}
//		else break;			
//	}while(1);
//     cin.ignore();
//     for(int i=0;i<plist.n;i++)
//      {
//        question_plus=question_plus+1;
//        stringstream ss;
//        ss<<question_plus;
//        str = ss.str();
//        plist.question_QSList[i].question_code=ss.str();
//      	cout<<"nhap noi dung cau hoi : ";
//      	getline(cin,plist.question_QSList[i].question_content);
//        cout<<"nhap dap an A : ";
//        getline(cin,plist.question_QSList[i].question_answer_A);
//        cout<<"nhap dap an B : ";
//        getline(cin,plist.question_QSList[i].question_answer_B);
//        cout<<"nhap dap an C : ";
//        getline(cin,plist.question_QSList[i].question_answer_C);
//        cout<<"nhap dap an D : ";
//        getline(cin,plist.question_QSList[i].question_answer_D);
//        cout<<"nhap dap an cau hoi: ";
//        getline(cin,plist.question_QSList[i].question_correctAnswer);
//		myFile<<plist.question_QSList[i].question_code<<"\n"<<plist.question_QSList[i].question_content<<"\n";
//      	myFile<<plist.question_QSList[i].question_answer_A<<endl;
//      	myFile<<plist.question_QSList[i].question_answer_B<<endl;
//      	myFile<<plist.question_QSList[i].question_answer_C<<endl;
//      	myFile<<plist.question_QSList[i].question_answer_D<<endl;
//		if(i==plist.n-1)
//		{
//			myFile<<plist.question_QSList[i].question_correctAnswer;
//		}
//		else{
//			myFile<<plist.question_QSList[i].question_correctAnswer<<endl;
//			cout<<endl;
//		}
//     }
//   cout<<"..............."<<plist.n<<endl;
//	myFile.close();
//}

bool load_item(QSList &plist, string idSub){  // tai len cau hoi cua mot mon
//  string subject_codeText=subjectItem();
  fstream myFile;
  string fileName=idSub+extensionFile;
  myFile.open(fileName); 
  if(myFile.peek()==-1)
	{
		plist.n=0;
		return false;
	}
//	cout<<"HELLLLOOOOo";
   plist.n=0;
   int i=0;
   string strText;
    while(!myFile.eof())
	 { 
	       getline(myFile,strText);
	       plist.question_QSList[i].question_code=strText;
	       getline(myFile,strText);
           plist.question_QSList[i].question_content=strText;
           getline(myFile,strText);
           plist.question_QSList[i].question_answer_A=strText;
           getline(myFile,strText);
           plist.question_QSList[i].question_answer_B=strText;
           getline(myFile,strText);
           plist.question_QSList[i].question_answer_C=strText;
           getline(myFile,strText);
           plist.question_QSList[i].question_answer_D=strText;
           
           getline(myFile,strText);
//			myFile.get(plist.question_QSList[i].question_correctAnswer);
//			cout<<"HEREEEE333";
           plist.question_QSList[i].question_correctAnswer=strText;
           i=i+1;
	       plist.n=plist.n+1;
     }
   myFile.close();
   return true;
}

int QSList:: biSearchQS(string id)
{
	int left=0; 
	int right=n-1;
	int mid=0;
	
	do
	{
		mid=(left+right)/2;
		Question *tmp=&question_QSList[mid];
		if(tmp->question_code.compare(id)==0)
		{
//			cout<<"Toi day";
			return mid;
		}	
		else if(tmp->question_code.compare(id)>0) // id cua student > id user
		{
			right=mid-1; // Vi id lon hon id giua nen id can tim nam o ben trai, nen right lui ve giua-1

		}
		 
		else
			left=mid+1; // Vi id nho hon id giua nen id can tim nam o ben phai, nen left tien toi giua+1	
	}while(left<=right);
	return -1;
	
}
//int add_item(QSList &plist, string t){   // cho thang load tra ve string
//    ofstream myFile;
//    myFile.open(t.c_str(),ios::out | ios::app);
//    myFile<<"\n";
//	int add_count;
//	do{
//		cout<<"nhap so cau hoi can them : ";
//		cin>>add_count;
//		if(plist.n+add_count>MAX)
//	   {
//	 	 cout<<"so cau hoi them khong vuot qua "<<MAX-plist.n<<"\n";
//	   }else break;
//	}while(1);	
//    stringstream str2num(plist.question_QSList[plist.n-1].question_code);  // chuyen chi so cua cau hoi cuoi cung ve int
//    int last_code; // =chi so cua cau hoi cuoi cung truoc khi them
//    str2num>>last_code; //chuyen chi so cuoi vao day
//    plist.n=plist.n+add_count;
//	cout<<"so cau hoi sau khi them : "<<plist.n<<endl;
//    last_code=last_code+1; // ma cau hoi tiep theo =ma cuoi cung luc chua them+1
//    cin.ignore(); 
//		for(int i=(plist.n-add_count);i<(plist.n);i++)
//		 {  
//		    stringstream ss;
//            ss<<last_code;
//             //2 dong tren truyen vao ss last_code dang string;
//            plist.question_QSList[i].question_code=ss.str(); 
//            last_code=last_code+1; // tang len de tu dong cong ma cau hoi
//		 	cout<<"nhap cau hoi can them: ";
//	        getline(cin,plist.question_QSList[i].question_content);
//	        cout<<"nhap dap an A : ";
//	        getline(cin,plist.question_QSList[i].question_answer_A);
//            cout<<"nhap dap an B : ";
//            getline(cin,plist.question_QSList[i].question_answer_B);
//            cout<<"nhap dap an C : ";
//            getline(cin,plist.question_QSList[i].question_answer_C);
//            cout<<"nhap dap an D : ";
//            getline(cin,plist.question_QSList[i].question_answer_D);
//            cout<<"nhap dap an dung: ";
//            getline(cin,plist.question_QSList[i].question_correctAnswer);
//		 }
//		  
//	    for(int i=(plist.n-add_count);i<(plist.n);i++)
//		 { 
//		    myFile<<plist.question_QSList[i].question_code<<"\n"<<plist.question_QSList[i].question_content<<"\n";
//      	    myFile<<plist.question_QSList[i].question_answer_A<<endl;
//      	    myFile<<plist.question_QSList[i].question_answer_B<<endl;
//      	    myFile<<plist.question_QSList[i].question_answer_C<<endl;
//      	    myFile<<plist.question_QSList[i].question_answer_D<<endl;
//        	if(i==plist.n-1)
//		     {
//			   myFile<<plist.question_QSList[i].question_correctAnswer;
//		     }
//		    else{
//			  myFile<<plist.question_QSList[i].question_correctAnswer<<endl;
//			   cout<<endl;
//		     }
//		 }
//		cout<<"them cau hoi thanh cong"<<endl;
//	   myFile.close();
//	    return  1;
//}  

int show_item(QSList &plist){
	
	for(int i=0;i<plist.n;i++)
	 { 
	        cout<<"Ma cau hoi : "<<plist.question_QSList[i].question_code<<endl;
	        cout<<"Cau hoi: "<<plist.question_QSList[i].question_content<<endl;
	        cout<<"A."<<plist.question_QSList[i].question_answer_A<<endl;
	        cout<<"B."<<plist.question_QSList[i].question_answer_B<<endl;
	        cout<<"C."<<plist.question_QSList[i].question_answer_C<<endl;
	        cout<<"D."<<plist.question_QSList[i].question_answer_D<<endl;
	        cout<<"Dap an: "<<plist.question_QSList[i].question_correctAnswer<<endl;
	 }
  return 1;
}
//int delete_item(QSList &plist)
//{   
// string flag=load_item(plist);
//    if(flag=="")
//	   {
//	  	cout<<"danh sach cau hoi trong\n";
//	  	return 0;
//	   }
// else{
//    cout<<"nhap ma cau hoi can xoa: ";
//    int num;
//	cin>>num;
//    stringstream ss;
//    ss << num;
//    string str = ss.str();
//     int flag_delete=0;
//		for(int i=0;i<plist.n;i++){
//			if(plist.question_QSList[i].question_code==str){
//				for(int j=i;j<(plist.n-1);j++)
//		          {
//			       plist.question_QSList[j]=plist.question_QSList[j+1];
//		          }
//		          flag_delete=1;
//		          break;
//			}
//	      }
//		if(flag_delete==0)
//		 {
//		   cout<<"ma cau hoi khong ton tai"<<endl;
//		   return 0;
//		 }
//		 else{
//		   plist.n--;	
//		   cout<<"xoa cau hoi thanh cong"<<endl;	
//		 }
//	ofstream myFile;
//    myFile.open(flag.c_str());
//	 for(int i=0;i<plist.n;i++)
//	 {
//		myFile<<plist.question_QSList[i].question_code<<"\n"<<plist.question_QSList[i].question_content<<"\n";
//      	myFile<<plist.question_QSList[i].question_answer_A<<endl;
//      	myFile<<plist.question_QSList[i].question_answer_B<<endl;
//      	myFile<<plist.question_QSList[i].question_answer_C<<endl;
//      	myFile<<plist.question_QSList[i].question_answer_D<<endl;
//		if(i==(plist.n-1))
//		{
//			myFile<<plist.question_QSList[i].question_correctAnswer;
//		}
//		else{
//			myFile<<plist.question_QSList[i].question_correctAnswer<<endl;
//		}
//	 }
//	 myFile.close();
// }
//}
void clear_list(QSList &plist){ 
   FILE *fp;
   fp = fopen(subjectItem().c_str(), "w"); // mo ra o che do nay thi tat ca du lieu cu bi xoa
   fclose(fp);
   cout<<"Xoa thanh cong"<<endl;
}
//void show_questionList(QSList &plist){
//	cout<<"DAIIIIIIIIIIIIIII"<<endl;
//	cout<<"fdsgfds";
//	if(load_item(plist)=="")
//	  {
//	  	cout<<"here";
//	  	cout<<"danh sach cau hoi rong\n";
//	  }
// 	else
//	 {
//	 	cout<<"here";
//    	cout<<"so cau hoi: "<<plist.n<<endl;
//	    cout<<"Danh sach cau hoi: "<<endl;
//		for(int i=0;i<plist.n;i++)
//		{
//	            cout<<"Ma cau hoi : "<<plist.question_QSList[i].question_code<<endl;
//	            cout<<"Cau hoi: "<<plist.question_QSList[i].question_content<<endl;
//	            cout<<"A."<<plist.question_QSList[i].question_answer_A<<endl;
//	            cout<<"B."<<plist.question_QSList[i].question_answer_B<<endl;
//	            cout<<"C."<<plist.question_QSList[i].question_answer_C<<endl;
//	            cout<<"D."<<plist.question_QSList[i].question_answer_D<<endl;
//	            cout<<"Dap an: "<<plist.question_QSList[i].question_correctAnswer<<endl<<endl;
//		    
//		}  
//   }
//}

bool add_QSList(QSList &pQSList, Question qst)
{       
 if(pQSList.n==MAX)
  {
  	return false;
  }
	else
	{
		pQSList.n=pQSList.n+1;
		char tmp[3];
		pQSList.question_QSList[pQSList.n-1].question_code=itoa(pQSList.n, tmp,10);
		pQSList.question_QSList[pQSList.n-1].question_content=qst.question_content;
		pQSList.question_QSList[pQSList.n-1].question_answer_A=qst.question_answer_A;
		pQSList.question_QSList[pQSList.n-1].question_answer_B=qst.question_answer_B;
		pQSList.question_QSList[pQSList.n-1].question_answer_C=qst.question_answer_C;
		pQSList.question_QSList[pQSList.n-1].question_answer_D=qst.question_answer_D;
		pQSList.question_QSList[pQSList.n-1].question_correctAnswer=qst.question_correctAnswer;
		return true;
	}
        
}

void writeQsFile(QSList &pQSList, string idSj)
{     
     ofstream myFile;
     string fileName=idSj+extensionFile;
     myFile.open(fileName,ios::out); 
     for(int i=0;i<pQSList.n;i++)
      {
     	myFile<<pQSList.question_QSList[i].question_code<<"\n"<<pQSList.question_QSList[i].question_content<<"\n";
      	myFile<<pQSList.question_QSList[i].question_answer_A<<endl;
      	myFile<<pQSList.question_QSList[i].question_answer_B<<endl;
      	myFile<<pQSList.question_QSList[i].question_answer_C<<endl;
      	myFile<<pQSList.question_QSList[i].question_answer_D<<endl;
      	if(i==pQSList.n-1)
		{
			myFile<<pQSList.question_QSList[i].question_correctAnswer;
		}
		else{
			myFile<<pQSList.question_QSList[i].question_correctAnswer<<endl;
		}
	 }
	myFile.close();
}

Question * loadExam(QSList &pQSList, int numOfQues) //ham lay cau hoi thi, tra ve mot mang cau hoi thi,
{  
  Question *arrQS=new Question[numOfQues];
  int array[pQSList.n]; // mang chua plist.n phan tu
  for(int i = 0; i<pQSList.n; i++){  // khoi tao gia tri mang tam (0->plist.n)
     array[i] = i;
    }
  srand((int)time(0));// ham nay de moi lan random la khac nhau
  ShuffleArray(array,pQSList.n); //tron mang chi so cau hoi
  int j;
  for(int i=0;i<numOfQues;i++)  // phan hien cau hoi và nhap cau tra loi, chay tu 0 toi du so cau hoi thi roi ngung
   {
   	j=array[i];
   	arrQS[i].question_code=pQSList.question_QSList[j].question_code;
   	arrQS[i].question_content=pQSList.question_QSList[j].question_content;
   	arrQS[i].question_answer_A=pQSList.question_QSList[j].question_answer_A;
   	arrQS[i].question_answer_B=pQSList.question_QSList[j].question_answer_B;
   	arrQS[i].question_answer_C=pQSList.question_QSList[j].question_answer_C;
   	arrQS[i].question_answer_D=pQSList.question_QSList[j].question_answer_D;
   	arrQS[i].question_correctAnswer=pQSList.question_QSList[j].question_correctAnswer;
   }
  return arrQS;  
}

void Swap(int* number_1, int* number_2)
{
	int temp = *number_1;
	*number_1 = *number_2;
	*number_2 = temp;
}

void ShuffleArray(int* arr, int n)
{
	srand(time(NULL));
	int minPosition;
	int maxPosition = n - 1;
	int swapPosition;
	int i = 0;
	while (i < n - 1)
	{
		minPosition = i + 1;
		swapPosition = rand() % (maxPosition - minPosition + 1) + minPosition;
		Swap(&arr[i], &arr[swapPosition]);
		i++;
	}
}

void editQuestion(QSList &list, int index, string content, string ansA, string ansB, string ansC, string ansD, char result)
{
	list.question_QSList[index].question_content=content;
	list.question_QSList[index].question_answer_A=ansA;
	list.question_QSList[index].question_answer_B=ansB;
	list.question_QSList[index].question_answer_C=ansC;
	list.question_QSList[index].question_answer_D=ansD;
	list.question_QSList[index].question_correctAnswer=result;
}


