#pragma once
#include <stdio.h>
#include <windows.h>
#include <stralign.h>
#include <stdlib.h>
#include <time.h>
#include <mmsystem.h>
#include <malloc.h>
#include <locale.h>
#include<stdbool.h>
#pragma comment(lib, "winmm.lib")

#define START 3
#define FINISH 4
#define PLAYER 20
#define PAST_PATH 30
#define WALL 1
#define SPACE 0
#define RMS 25
#define pause system("pause > nul") //프로그램 종료후 뜨는 문구 제거
#define cls system("cls") //화면 초기화 함수 
#define delay Sleep(500) //지연
#define full_time 300 //게임 제한 시간

void claer(void);
void SetColor(int color); // 색 설정
void CursorView(char show); //커서 존재 유무 조정
void gotoxy(int x, int y);  // 커서 위치 이동
void mainPtr(void); //시작창
void level(void); //단계 창
void GameOver(void); // 게임 오버 창
void GamePlay(void);
int initFlag();
int makeFlag();
void judgeMove(int x, int y);
void printMap();
void pause_item(time_t* );
void itemtime(time_t* );
void explain(void);
void Past_path(int** n, int X, int Y);
void bs(void);
void bss(void);
void cl(void);
void ov(void);
void tp(void);
void fl(void);
void comment(int a);
void clea(void);
//void displayMazeWithLimitedView();


typedef struct Flag {		//깃발마다 멤버의 값을 음,양으로 줘서 계산하자 ex) life = 0, sec = -10 인경우 시간10초 감소 깃발~
	int life;
	int sec;
	int clear;		//0 == 클리어깃발x, 1 == 클리어깃발o
	int eyeSight;
}Flag;

struct condition {
	time_t sight_p;
	time_t sight_m;
	time_t mushroom;
};


/*
typedef struct Player {
	int x;
	int y;
	int life;
	int sec;
	int eyeSight;
	//int clear;
}Player;
*/

//시간 제약 부분 변수
time_t Start_time; //게임 시작 시간
time_t Stop_time; //일시정지 시간

int lev;				//1 == 쉬움, 2 ==... 3==...
int bomb_num;
time_t a;
int flag_time100;
int co;
int com;