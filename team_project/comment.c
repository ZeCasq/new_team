#include "head.h"
int flag_time100;

void comment_p(int a)
{
	if (a == 3) {

		gotoxy(0, 10);
		printf("그냥 굴러다니는 돌멩이었다.");
	}
	else if (a == 4) {

		gotoxy(0, 10);
		printf("횃불을 획득하였다.\n시야 추가");
	}
	else if (a == 5) {

		gotoxy(0, 10);
		printf("환각 작용을 일으키는 \n독초를 건드렸다.\n방향키 전환");
	}
	else if (a == 6) {

		gotoxy(0, 10);
		printf("바깥으로부터 산소가 \n출입하는 공간을 발견했다... \n시간 추가");
	}
	else if (a == 7) {

		gotoxy(0, 10);
		printf("동물의 사체를 발견했다… \n부패가 진행중이다… \n산소농도가 급격히 감소하고 있다… \n서둘러야겠다…\n시간 감소");
	}
	else if (a == 8) {

		gotoxy(0, 10);
		printf("횃불이 꺼졌다.\n시야 감소");
	}
	else if (a == 9) {

		gotoxy(0, 10);
		printf("벽을 잘못 건드린 것 같다...\n(텔포)");
	}
	else if (a == 10) {

		gotoxy(0, 10);
		printf("이전에 왔던 탐험가가 흘리고 간\n폭탄이다. 운이 좋았다.\n폭탄 + 1");
	}
	co = 1;
}

void comment(int a) {
	flag_time100 = time(0);
	comment_p(a);
}