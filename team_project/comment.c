#include "head.h"
int flag_time100;

void comment_p(int a)
{
	if (a == 3) {

		gotoxy(0, 10);
		printf("�׳� �����ٴϴ� �����̾���.");
	}
	else if (a == 4) {

		gotoxy(0, 10);
		printf("ȶ���� ȹ���Ͽ���.\n�þ� �߰�");
	}
	else if (a == 5) {

		gotoxy(0, 10);
		printf("ȯ�� �ۿ��� ����Ű�� \n���ʸ� �ǵ�ȴ�.\n����Ű ��ȯ");
	}
	else if (a == 6) {

		gotoxy(0, 10);
		printf("�ٱ����κ��� ��Ұ� \n�����ϴ� ������ �߰��ߴ�... \n�ð� �߰�");
	}
	else if (a == 7) {

		gotoxy(0, 10);
		printf("������ ��ü�� �߰��ߴ١� \n���а� �������̴١� \n��ҳ󵵰� �ް��� �����ϰ� �ִ١� \n���ѷ��߰ڴ١�\n�ð� ����");
	}
	else if (a == 8) {

		gotoxy(0, 10);
		printf("ȶ���� ������.\n�þ� ����");
	}
	else if (a == 9) {

		gotoxy(0, 10);
		printf("���� �߸� �ǵ帰 �� ����...\n(����)");
	}
	else if (a == 10) {

		gotoxy(0, 10);
		printf("������ �Դ� Ž�谡�� �긮�� ��\n��ź�̴�. ���� ���Ҵ�.\n��ź + 1");
	}
	co = 1;
}

void comment(int a) {
	flag_time100 = time(0);
	comment_p(a);
}