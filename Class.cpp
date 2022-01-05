#include"Class.h"
#include <iostream>
#include <fstream>
using namespace std;


void addClass(CLASSLIST &dsl,string a,string b){ //ham them mot lop
	CLASS* p=new CLASS;
	p->classID=a;
	p->className=b;
	dsl.ds[dsl.sl]=p;
	dsl.sl++;
}

void showClass(CLASSLIST dsl) //ham test show lop ra
{
		for (int i = 0; i < dsl.sl; i++)
		{
				cout << dsl.ds[i]->classID<<" ";
				cout << dsl.ds[i]->className<<endl;
		}
}


void writeClassList(CLASSLIST dsl){ //ham ghi lop xuong file
	ofstream f("ClassList.txt",ios::out);
	for (int i = 0; i < dsl.sl; i++)
	{
		f << dsl.ds[i]->classID;
		f << endl;
		if(i==dsl.sl-1){
			f << dsl.ds[i]->className;
		}
		else f << dsl.ds[i]->className<<endl;
		writeFileStudentsOfClass(dsl.ds[i]->classID, dsl.ds[i]->studentList);
	}
	f.close();
}

void deleteClassList(CLASSLIST &dsl){   // ham giai phong lop
//	delete dsl.ds;
	for(int i=0;i<dsl.sl;i++)
	 {
	 	delete dsl.ds[i];
	 	dsl.sl=0;
	 }
}

bool loadClassList(CLASSLIST &dsl) //ham doc file len mang
{
	
	deleteClassList(dsl);
	ifstream f("ClassList.txt", ios::in);
//	fileIn.open(fileName, ios_base::in);
	if(f.fail())	return false;
	while (!f.eof())
	{
		dsl.ds[dsl.sl] = new CLASS; 
		getline(f, dsl.ds[dsl.sl]->classID);
		cout<<"ID lop: "<<dsl.ds[dsl.sl]->classID<<endl;
		getline(f, dsl.ds[dsl.sl]->className);
		
		readStudentList(dsl.ds[dsl.sl]->classID,dsl.ds[dsl.sl]->studentList);
		dsl.sl++;
	}
	f.close();
	return true;
}

void classList::freeClassList()
{
	for(int i=0; i<sl; i++)
	{
		ds[i]->studentList.freeStudentList();
		free(ds[i]);
	}
	free(ds);
}

bool checkEditableQues(CLASSLIST list,string idSubj, string idQues)
{
	for(int i=0; i<list.sl; i++)
	{
		int numStudent=list.ds[i]->studentList.getLength();
		StudentNode *pStudent=list.ds[i]->studentList.pHead;
		for(int j=0; j<numStudent; j++)
		{
			ScoreNode *pScore=pStudent->data.scoreList.pHead;
			

			while(pScore!=NULL)
			{
				int numQues=pScore->exam.length;
				for(int k=0; k<numQues; k++)
				{
					if(pScore->data.idSubject==idSubj && pScore->exam.idQuesArray[k]==idQues)	return false;
				}
				pScore=pScore->pNext;
			}
			pStudent=pStudent->pNext;
		}
	}
	return true;
}
