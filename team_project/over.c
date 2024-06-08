#include "head.h"
#define x 25
void gameover(void) {
    gotoxy(x, 7);
    printf("  ____                         ___                 \n");
    gotoxy(x, 8);
    printf(" / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __ \n");
    gotoxy(x, 9);
    printf("| |  _ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__|\n");
    gotoxy(x, 10);
    printf("| |_| | (_| | | | | | |  __/ | |_| |\\ V /  __/ |   \n");
    gotoxy(x, 11);
    printf(" \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|   \n");
    gotoxy(x, 12);
    printf("                                                  \n");
}