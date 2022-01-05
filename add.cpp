bool add_QSList(QSList &pQSList, Question qst)
{     
      
      if(pQSList.n==MAX)
       {
       	 return false;
	   }
	  int last_code;
      if(pQSList.n==0){
      	last_code==0;
	  }else
	     {
	     	stringstream str2num(pQSList.question_QSList[pQSList.n-1].question_code);  // chuyen chi so cua cau hoi cuoi cung ve int
            str2num>>last_code; //chuyen chi so cuoi vao day
		 }
	  last_code=last_code+1;
      stringstream ss;
      ss<<last_code;
        pQList.n=pQSList+1;
//      cin.ignore(); xem thu bo ham nay ra co bi mat ki tu k 
        pQSList.question_QSList[pQList.n-1].question_code=ss.str(); 
	    getline(cin,pQSList.question_QSList[pQList.n-1].question_content);
	    getline(cin,pQSList.question_QSList[pQList.n-1].question_answer_A);
        getline(cin,pQSList.question_QSList[pQList.n-1].question_answer_B);
        getline(cin,pQSList.question_QSList[pQList.n-1].question_answer_C);
        getline(cin,pQSList.question_QSList[pQList.n-1].question_answer_D);
        getline(cin,pQSList.question_QSList[pQList.n-1].question_correctAnswer);		
     }
  return true;
}

