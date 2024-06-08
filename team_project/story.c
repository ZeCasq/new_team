#include "head.h"

void story(void)
{

    // 문자열 배열 초기화
    char* string[] = {
        "유적탐험가로 살아온 지 20년차...",
        "지금까지 탐험한 모든 유적지에서의 단서가 지금 단 한 곳을 가리키고 있다...",
        "다시 그곳을 가게 되었다...",
        "처음 그곳을 갈땐 유적에 대한 부족한 지식과 미약한 준비물로 인하여...",
        "나에게 유적 탐험이 결코 만만치가 않음을 깨닫게 해줬던...",
        "이제 만반의 준비를 하고 다시 그곳에 발을 들이기로 하였다..."
    };

    int stop = 0;  // 종료 플래그
    gotoxy(73, 25);
    printf("스킵하려면 s를 누르시오.");
    gotoxy(0, 0);
    // 각 문자열의 문자를 하나씩 출력
    for (int i = 0; i < 6 && !stop; i++) {
        for (int j = 0; string[i][j] != '\0' && !stop; j++) {
            printf("%c", string[i][j]);
            Sleep(70);  // 70밀리초 대기
            

            // 키보드 입력 체크
            if (_kbhit()) {
                char ch = _getch();  // 입력된 키를 읽음
                
                if (ch == 's') {
                    cl();
                    stop = 1;  // 종료 플래그 설정
                    
                }
            }
            
        }
        printf("\n");
    }
    cls;
    for (int i = 0; i < 6; i++) {
        printf("%s\n", string[i]);
    }

    gotoxy(73, 25); printf("넘어가려면 enter 누르시오        ");
    while (!GetAsyncKeyState(VK_RETURN));
    cl();
    
    delay;
    cls;
    
    Sleep(300);
    
    explain();
    return 0;
}

void explain(void) {
    
    printf("===========================================================\n");
    printf("게임 설명:\n");
    printf("미로로 이루어진 유적지를 탈출하시오\n");
    printf("산소 부족으로 인한 시간제한이 존재하니 시간 안에 탈출하세요.\n");
    printf("\n");
    printf("===========================================================\n");
    printf("아이템 및 함정 설명: \n\n");
    SetColor(14);
    printf("시간 증가 \n");
    SetColor(14);
    printf("다이너마이트 : n*n의 블럭 사라짐 \n");// 범위 수정해주세요
    SetColor(14);
    printf("횃불 : 시야 증가 \n\n");

    SetColor(12);
    printf("시간 감소 \n");
    SetColor(12);
    printf("횃불 화력 약화 \n");
    SetColor(12);
    printf("블랙 아웃 : (n초 동안 시야가 사라짐) \n"); //몇 초인지 수정해 주세요
    SetColor(12);
    printf("구덩이 : 다른 공간으로 텔레포트 됩니다. \n");
    SetColor(12);
    printf("환각효과 : 방향키 변환\n");
    printf("===========================================================\n");
    SetColor(15);
    gotoxy(73, 25); printf("다시 돌아가려면 enter 누르세요..");
}