//bool timeout()
//{
//	if (testTime == 0) return true;
//	else return false;
//}
//void* countTime(void* unused)
//{
//	gotoxy(22, 6);
//	int mm;
//	int ss;
//	for (int i = thoigianKT; i >= 0; i--)
//	{
//		mm=(i - (i % 60)) / 60;
//		ss=i % 60
////		gotoxy(33, 6);
////		cout << "                                              ";
////		gotoxy(20, 6);
////		cout << "Thoi gian: " << (i - (i % 60)) / 60 << ':' << i % 60;
//		char buff[3];
//		outtextxy(1050, 30, itoa(mm, buff, 10));
//		outtextxy(1060, 30, itoa(ss, buff, 10));
//		if (timeout()) pthread_exit(NULL);
//		Sleep(999);
//	}
////	gotoxy(40, 6);
////	cout << "HET GIO!!! nhan phim bat ky...";
//	testTime = 0;
//	pthread_exit(NULL);
//	return NULL;
//
//}
//int thiTracNghiem()
//{
//	int thoigianKT=0;
//	cout << "Nhap thoi gian kiem tra (phut) : ";
//	thoigianKT = getNumber(69, 22);
//	if (thoigianKT == 0) thoigianKT = 5;
//	if (thoigianKT < 0) return -1;
//	thoigianKT = thoigianKT * 60;
//	
//	pthread_t thread;
//	pthread_create(&thread, NULL, &tinhGio, NULL);
//}
