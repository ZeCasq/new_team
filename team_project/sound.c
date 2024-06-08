#include "head.h"

void bs(void) {
	mciSendString(TEXT("open \"button_s.mp3\" type mpegvideo alias mp3_2"), NULL, 0, NULL);
	mciSendString(TEXT("play mp3_2"), NULL, 0, NULL);
	Sleep(300);
	mciSendString(TEXT("close mp3_2"), NULL, 0, NULL);
}


void cl(void) {
	mciSendString(TEXT("open \"click_s.mp3\" type mpegvideo alias mp3_3"), NULL, 0, NULL);
	mciSendString(TEXT("play mp3_3"), NULL, 0, NULL);
	Sleep(300);
	mciSendString(TEXT("close mp3_3"), NULL, 0, NULL);
}

void ov(void) {
	mciSendString(TEXT("open \"gameover.mp3\" type mpegvideo alias mp3_4"), NULL, 0, NULL);
	mciSendString(TEXT("play mp3_4"), NULL, 0, NULL);
}

void tp(void) {
	mciSendString(TEXT("open \"warp.mp3\" type mpegvideo alias mp3_5"), NULL, 0, NULL);
	mciSendString(TEXT("play mp3_5"), NULL, 0, NULL);
}
void fl(void) {
	a = time(0);
	mciSendString(TEXT("open \"flag_s.mp3\" type mpegvideo alias mp3_6"), NULL, 0, NULL);
	mciSendString(TEXT("play mp3_6"), NULL, 0, NULL);
}
void clea(void) {
	mciSendString(TEXT("open \"clear_s.m4a\" type mpegvideo alias mp3_7"), NULL, 0, NULL);
	mciSendString(TEXT("play mp3_7"), NULL, 0, NULL);
}