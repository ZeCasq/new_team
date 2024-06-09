#include "head.h"

void con_txt(void);

void game(void); //게임 전반적인 구성
int main_menu();
int menu(void);
void init();


int first = 0; //게임 실행후 플레이가 최초인지 아닌지 구분
int X, Y;
int Life, sec, clear, eyesight;
int regame = 0;


extern int** map, flag_time, flag_time2, flag_time3, flag_time100;
struct condition playeR = { 0,0,0 };
int main(void) {

	setlocale(LC_CTYPE, ""); // 유니코드 출력 설정
	while (1)
	{
		if (regame == 1) {
			//lev = 1; 이코드있으면 재시작시 쉬움난이도 부터 시작
			game();
		}
		else if (clear == 1 && lev < 3)		//이지,노멀 클리어시 다음 레벨로 진행
		{
			lev++;
			game();
		}
		else
		{
			int POS = main_menu();
			delay;
			if (first == 0) {
				story();

				gotoxy(73, 25); printf("넘어가려면 enter 누르시오        ");
				while (!GetAsyncKeyState(VK_RETURN));
				cl();
				cls;
				Sleep(300);
				con_txt();
				gotoxy(73, 25); printf("넘어가려면 enter 누르시오        ");
				while (!GetAsyncKeyState(VK_RETURN));
				cl();

				cls;
				Sleep(300);
				first = 1;
			}


			//게임 부분

			switch (POS) {
				//게임 시작 파트
			case 0:
				level();
				game();
				break;
			case 1:
				//이어하기
				break;
			case 2:
				printf("아무키나 누르시오..");
				pause;
				exit(0);
				break;
			}
		}
	}

	return 0;
}

//메인 메뉴 호출
int main_menu(void) {
	//int lives = 3; //목숨, 전역으로 뺀다.


	//시작 화면 파트
	int p = 0;
	CursorView(0);    //커서의 깜빡임을 숨겨준다.
	system("COLOR 0F");    //화면 배경을 검정, 글씨 색깔을 하얀색으로 설정해 준다.	 
	mainPtr();

	while (1) {
		title1();

		if (GetAsyncKeyState(VK_LEFT)) {
			bs();
			if (p == 0) p = 1;
			else p -= 1;
		}
		else if (GetAsyncKeyState(VK_RIGHT)) {
			bs();
			if (p == 1) p = 0;
			else p += 1;
		}
		else if (GetAsyncKeyState(VK_RETURN)) {
			cl();
			break;
		}
		switch (p) {
		case 0:
			SetColor(11);
			gotoxy(30, 20); printf("시작  하기");
			SetColor(15);
			gotoxy(62, 20); printf("게임  종료");
			break;
		case 1:
			gotoxy(30, 20); printf("시작  하기");
			SetColor(11);
			gotoxy(62, 20); printf("게임  종료");
			SetColor(15);
			break;
	

		default: break;
		}
		delay;
	}
	cls;
	return p;
}
//기본적인 움직임 구현 툴
void game(void) {
	co = 0;;
	int anti = 0;
	int cou = 0;
	int coun = 0;
	int count = 0;
	//initFlag();//난이도에 따라 깃발 초기화가 다르면 좋을듯
	init();
	time_t b = 0;
	mciSendString(TEXT("open \"maze.mp3\" type mpegvideo alias mp3_1"), NULL, 0, NULL);
	mciSendString(TEXT("play mp3_1"), NULL, 0, NULL);
	int ch;
	Start_time = time(0); //게임 시작 시간 설정
	GamePlay();
	makeFlag();//난이도에 따라 깃발 배치갯수가 다르면 좋을듯
	gotoxy(0, 0);
	printf("level: %d", lev);
	while (1) {
		if (co == 1) {
			if (time(0) - flag_time100 < 5) {
				comment_p(com);


			}
			else {
				flag_time100 = 0;
				cls;
				co = 0;
			}

		}
		if (time(0) - a > 1) {
			mciSendString(TEXT("close mp3_6"), NULL, 0, NULL);
		}
		if (time(0) - b > 150) {
			mciSendString(TEXT("close mp3_1"), NULL, 0, NULL);
			mciSendString(TEXT("open \"maze.mp3\" type mpegvideo alias mp3_1"), NULL, 0, NULL);
			mciSendString(TEXT("play mp3_1"), NULL, 0, NULL);
			b = time(0);
		}
		if (time(0) - flag_time < playeR.sight_p) {
			if (count == 0) {
				cls;
				gotoxy(0, 0);
				printf("level: %d", lev);
				eyesight += 2;
			}
			count = 2;
			gotoxy(2, 23);
			printf("시야 버프: %3d", playeR.sight_p - time(0) + flag_time);
		}
		else if (count == 2) {
			cls;
			gotoxy(0, 0);
			printf("level: %d", lev);
			flag_time = 0;
			eyesight -= 2;
			playeR.sight_p = 0;
			count = 0;
		}
		if (time(0) - flag_time2 < playeR.sight_m) {
			if (coun == 0) {
				cls;
				gotoxy(0, 0);
				printf("level: %d", lev);
				eyesight -= 3;
			}			coun = 2;
			gotoxy(2, 22);
			printf("시야 너프: %3d", playeR.sight_m - time(0) + flag_time2);
		}
		else if (coun == 2) {
			cls;
			gotoxy(0, 0);
			printf("level: %d", lev);
			flag_time2 = 0;
			eyesight += 3;
			playeR.sight_m = 0;
			coun = 0;
		}
		if (time(0) - flag_time3 < playeR.mushroom) {
			if (cou == 0) {
				anti = 1;
			}
			cou = 2;
			gotoxy(2, 21);
			printf("환각 버섯: %3d", playeR.mushroom - time(0) + flag_time3);
		}
		else if (cou == 2) {
			cls;
			gotoxy(0, 0);
			printf("level: %d", lev);
			flag_time3 = 0;
			anti = 0;
			playeR.mushroom = 0;
			cou = 0;
		}


		//esc 눌러서 일시정지
		if (GetAsyncKeyState(VK_ESCAPE)) {
			Stop_time = time(0); // 멈춘 시간 저장
			while (1) {
				int m_c = menu();
				if (m_c == 0) {
					break;
				}
				else if (m_c == 1) {
					regame = 1;
					return;
				}
				else if (m_c == 2) {
					continue;
				}
				else if (m_c == 3) {
					return;
				}
			}
			cls;
			Start_time += (time(0) - Stop_time); //멈춘 시간은 제한시간에서 제외
			pause_item(&playeR.sight_p);
			pause_item(&playeR.sight_m);
		}
		if (!anti) {
			if (GetAsyncKeyState(VK_LEFT) & 0x0001) { //왼쪽
				if (lev == 1)
					Past_path(map, X, Y);
				judgeMove(X - 1, Y);
			}
			if (GetAsyncKeyState(VK_RIGHT) & 0x0001) { //오른쪽
				if (lev == 1)
					Past_path(map, X, Y);
				judgeMove(X + 1, Y);

			}
			if (GetAsyncKeyState(VK_UP) & 0x0001) { //위
				if (lev == 1)
					Past_path(map, X, Y);
				judgeMove(X, Y - 1);
			}
			if (GetAsyncKeyState(VK_DOWN) & 0x0001) { //아래
				if (lev == 1)
					Past_path(map, X, Y);
				judgeMove(X, Y + 1);
			}
		}
		else {
			if (GetAsyncKeyState(VK_RIGHT) & 0x0001) { //왼쪽
				if (lev == 1)
					Past_path(map, X, Y);
				judgeMove(X - 1, Y);
			}
			if (GetAsyncKeyState(VK_LEFT) & 0x0001) { //오른쪽
				if (lev == 1)
					Past_path(map, X, Y);
				judgeMove(X + 1, Y);

			}
			if (GetAsyncKeyState(VK_DOWN) & 0x0001) { //위
				if (lev == 1)
					Past_path(map, X, Y);
				judgeMove(X, Y - 1);
			}
			if (GetAsyncKeyState(VK_UP) & 0x0001) { //아래
				if (lev == 1)
					Past_path(map, X, Y);
				judgeMove(X, Y + 1);
			}
		}
		if (GetAsyncKeyState(0x20) & 0x0001)		//폭탄 까기
		{
			if (bomb_num > 0) {
				bomb_num -= 1;
				bomb();
			}
		}
		if (GetAsyncKeyState(0x21) & 0x0001)
		{
			map[Y - 1][X] = 2;
		}
		if (GetAsyncKeyState(0x22) & 0x0001)
		{
			X = Y = 1;
		}
		if (GetAsyncKeyState(0x63) & 0x0001)
		{
			map[Y - 1][X] = 3;
		}
		if (GetAsyncKeyState(0x64) & 0x0001)
		{
			map[Y - 1][X] = 4;
		}
		if (GetAsyncKeyState(0x65) & 0x0001)
		{
			map[Y - 1][X] = 5;
		}
		if (GetAsyncKeyState(0x66) & 0x0001)
		{
			map[Y - 1][X] = 6;
		}
		if (GetAsyncKeyState(0x67) & 0x0001)
		{
			map[Y - 1][X] = 7;
		}
		if (GetAsyncKeyState(0x68) & 0x0001)
		{
			map[Y - 1][X] = 8;
		}
		if (GetAsyncKeyState(0x69) & 0x0001)
		{
			map[Y - 1][X] = 9;
		}
		if (GetAsyncKeyState(0x62) & 0x0001)
		{
			map[Y - 1][X] = 10;
		}


		if (clear)
		{
			if (lev < 3) {
				cls;
				clea();
				claer();
				delay;
				gotoxy(73, 25); printf("다음 레벨로 넘어가려면 enter..");

				if (kbhit())
					while (!GetAsyncKeyState(VK_RETURN)) {//게임 완전 클리어
					}
				mciSendString(TEXT("close mp3_7"), NULL, 0, NULL);
				cls;
			}
			else {
				cls;
				clea();
				claer();
				delay;
				gotoxy(65, 25); printf("메인 메뉴로 가려면 enter 누르세요..");
				if (kbhit())
					while (!GetAsyncKeyState(VK_RETURN)) {//게임 완전 클리어
					}
				gotoxy(65, 25); printf("               로딩중...               ");
				Sleep(3000);
				mciSendString(TEXT("close mp3_7"), NULL, 0, NULL);
				
			}
			return;
		}
		else {
			printMap();
			gotoxy(2, 26);
			printf("X: %d Y: %d", X, Y);
			gotoxy(2, 24);
			printf("폭탄 수: %d  ", bomb_num);
			//게임 시간 표현
			gotoxy(2, 25);

			printf("time : %d           ", full_time - ((time(0) - Start_time)));
			if (full_time - (time(0) - Start_time) <= 0) {
				cls;
				GameOver();
				break;
			}
			//system("cls");
		}
	}
}


//일시정지 함수
int menu(void) {
	cls;

	gotoxy(20, 10); printf("재개");
	gotoxy(20, 12); printf("처음부터 다시 시작");
	gotoxy(20, 14); printf("게임 설명");
	gotoxy(20, 16); printf("메인 메뉴");
	int pos = 0;
	while (1) {
		if (GetAsyncKeyState(VK_UP)) {
			bs();
			if (pos == 0) pos = 3;
			else pos -= 1;
		}
		else if (GetAsyncKeyState(VK_DOWN)) {
			bs();
			if (pos == 3) pos = 0;
			else pos += 1;
		}
		else if (GetAsyncKeyState(VK_RETURN)) {				//엔터를 눌렀을 때
			cl();
			break;
		}
		switch (pos) {
		case 0:

			SetColor(11);
			gotoxy(20, 10); printf("재개");
			SetColor(15);
			gotoxy(20, 12); printf("처음부터 다시 시작");
			gotoxy(20, 14); printf("게임 설명");
			gotoxy(20, 16); printf("메인 메뉴");

			break;
		case 1:

			gotoxy(20, 10); printf("재개");
			SetColor(11);
			gotoxy(20, 12); printf("처음부터 다시 시작");
			SetColor(15);
			gotoxy(20, 14); printf("게임 설명");
			gotoxy(20, 16); printf("메인 메뉴");
			break;
		case 2:

			gotoxy(20, 10); printf("재개");
			gotoxy(20, 12); printf("처음부터 다시 시작");
			SetColor(11);
			gotoxy(20, 14); printf("게임 설명");
			SetColor(15);
			gotoxy(20, 16); printf("메인 메뉴");
			break;
		case 3:

			gotoxy(20, 10); printf("재개");
			gotoxy(20, 12); printf("처음부터 다시 시작");
			gotoxy(20, 14); printf("게임 설명");
			SetColor(11);
			gotoxy(20, 16); printf("메인 메뉴");
			SetColor(15);
			break;
		default: break;
		}

	}

	switch (pos) {
	case 0:
		break;
		return 0;
	case 1:
		mciSendString(TEXT("close mp3_1"), NULL, 0, NULL);
		cls;
		playeR.mushroom = 0;
		playeR.sight_m = 0;
		playeR.sight_p = 0;
		//game();
		return 1;
		break;
	case 2:		//게임 설명
		cls;
		con_txt();
		gotoxy(47, 25);
		printf("<<<1 / 2>>>");
		int k = 0;
		while (1) {
			if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(VK_LEFT)) {
				if (k == 0) {
					cls;
					explain();
					gotoxy(47, 25);
					printf("<<<2 / 2>>>");
					k = 1;
					Sleep(300);
					continue;
				}
				if (k == 1) {
					cls;
					con_txt();
					gotoxy(47, 25);
					printf("<<<1 / 2>>>");
					k = 0;
					Sleep(300);
				}
			}
			if (GetAsyncKeyState(VK_RETURN))
				break;
		}
		delay;
		return 2;
		break;
	case 3:										//메인 메뉴로 돌아가기
		mciSendString(TEXT("close mp3_1"), NULL, 0, NULL);
		cls;
		return 3;
	default: break;
	}
}



//조작키 설명
void con_txt(void) {
	gotoxy(20, 10); printf("\u2190         left");
	gotoxy(20, 12); printf("\u2192         right");
	gotoxy(20, 14); printf("\u2191	       up");
	gotoxy(20, 16); printf("\u2193	       down");
	gotoxy(20, 18); printf("space      bomb");
	gotoxy(20, 20); printf("esc	       pause");
	gotoxy(73, 25); printf("다시 돌아가려면 enter 누르세요..");

}




void init() {			//lev별로 다른 초기화ㄱㄴ, initFlag()에서도 레벨별로 다른 초기화 ㄱㄴ하게 하자
	initFlag();
	regame = 0;

	if (lev == 1)
	{
		bomb_num = 3;
		sec = 300;
		clear = 0;
		eyesight = 7;
		X = Y = 48;
	}
	else if (lev == 2)
	{
		bomb_num = 3;
		sec = 300;
		clear = 0;
		eyesight = 5;
		X = Y = 98;
	}
	else if (lev == 3)
	{
		bomb_num = 5;
		sec = 300;
		clear = 0;
		eyesight = 5;
		X = Y = 148;
	}

	return;
}