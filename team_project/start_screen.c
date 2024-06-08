#include "head.h"
#define x 30

//시작화면 
void mainPtr(void) {
	system("mode con: cols=106 lines=30");
	system("title 보물찾기 - 메인");
    gotoxy(x, 5);
    printf("   ___           _ _             \n");
    gotoxy(x, 6);
    printf("  |_ _|_ __   __| (_) __ _ _ __   __ _ \n");
    gotoxy(x, 7);
    printf("   | || '_ \\ / _` | |/ _` | '_ \\ / _` |\n");
    gotoxy(x, 8);
    printf("   | || | | | (_| | | (_| | | | | (_| |\n");
    gotoxy(x, 9);
    printf("  |___|_| |_|\\__,_|_|\\__,_|_| |_|\\__,_|\n");
    gotoxy(x, 10);
    printf(" _   __ _____  _   _  _   __ _   _  _   __\n");
    gotoxy(x, 11);
    printf("| | / /|  _  || \\ | || | / /| | | || | / /\n");
    gotoxy(x, 12);
    printf("| |/ / | | | ||  \\| || |/ / | | | || |/ / \n");
    gotoxy(x, 13);
    printf("|    \\ | | | || . ` ||    \\ | | | ||    \\ \n");
    gotoxy(x, 14);
    printf("| |\\  \\\\ \\_/ /| |\\  || |\\  \\| |_| || |\\  \\\n");
    gotoxy(x, 15);
    printf("\\_| \\_/ \\___/ \\_| \\_/\\_| \\_/ \\___/ \\_| \\_/\n");
    printf("                                          \n");
    printf("                                          \n");
    SetColor(11);
    gotoxy(20, 20); printf("새로  하기");
    SetColor(15);
	gotoxy(47, 20); printf("이어  하기");
	gotoxy(75, 20); printf("게임  종료");
	return;
}