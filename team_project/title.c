#include "head.h"
#define x 30

void title1(void) {
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
}

void blank(void) {
    for (int i = 5; i <= 15; i++) {
        gotoxy(x, i);
        printf("                                              ");
    }
}

void claer(void) {
    gotoxy(x, 7);
    printf(" _____  _      _____   ___  ______ \n");
    gotoxy(x, 8);
    printf("/  __ \\| |    |  ___| / _ \\ | ___ \\\n");
    gotoxy(x, 9);
    printf("| /  \\/| |    | |__  / /_\\ \\| |_/ /\n");
    gotoxy(x, 10);
    printf("| |    | |    |  __| |  _  ||    / \n");
    gotoxy(x, 11);
    printf("| \\__/\\| |____| |___ | | | || |\\ \\ \n");
    gotoxy(x, 12);
    printf(" \\____/\\_____/\\____/ \\_| |_/\\_| \\_\\\n");
    gotoxy(x, 13);
    printf("                                   \n");

    return 0;
}

