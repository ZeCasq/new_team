#include "head.h"
#define Bomb_Range 4				// 폭탄 범위(플레이어 기준으로 좌우상하 +-)

extern int X, Y, mapSize;
extern int** map;
extern int Life, sec, clear, eyesight;
extern struct condition playeR;

void teleport(int y, int x);
void bomb();
int judgeFlag(void);
void print_telpo(int** p, int** p2, int, int, int, int);
int flag_time = 0 ;
int flag_time2 = 0;
int flag_time3 = 0;

Flag Flages[9];


int initFlag() {				// 2는 탈출깃발, 3: life +1, 4: life -1, 5: sec + 10, 6: sec -10, 7: eyeSight +1, 8: eyeSight -1; 
	Flages[2].life = 0;
	Flages[2].sec = 0;
	Flages[2].clear = 1;
	Flages[2].eyeSight = 0;

	Flages[3].life = 1;
	Flages[3].sec = 0;
	Flages[3].clear = 0;
	Flages[3].eyeSight = 0;

	Flages[4].life = -1;
	Flages[4].sec = 0;
	Flages[4].clear = 0;
	Flages[4].eyeSight = 0;

	Flages[5].life = 0;
	Flages[5].sec = 10;
	Flages[5].clear = 0;
	Flages[5].eyeSight = 0;

	Flages[6].life = 0;
	Flages[6].sec = -10;
	Flages[6].clear = 0;
	Flages[6].eyeSight = 0;

	Flages[7].life = 0;
	Flages[7].sec = 0;
	Flages[7].clear = 0;
	Flages[7].eyeSight = 1;

	Flages[8].life = 0;
	Flages[8].sec = 0;
	Flages[8].clear = 0;
	Flages[8].eyeSight = -1;
}

int makeFlag()
{
	int x, y;

	//각각의 for문은 다른 정수값을 배치, 즉 다른 효과의 깃발 배치한다. (0은 길,1은 벽, 2는 탈출깃발, 3부터 효과 깃발 차례대로..

	while (1)									//2번깃발(탈출) 배치
	{
		x = rand() % (mapSize - 1) + 1;				//애초에 x,y값을 벽포함 안되게 설정해도ㄱㅊ
		y = rand() % (mapSize - 1) + 1;
		if (map[x][y] == SPACE)				//탈출 깃발 배치 조건은 좀더 있어도 괜찮을듯 ex) 맵의 중앙에서 50x50안에는 없어야 한다 등~~
		{
			//map[x][y]에 깃발 배치
			map[x][y] = 2;
			break;
		}
		else
		{
			continue;
		}
	}

	//for (int i = 0; i < 5; i++)				//3번깃발 배치
	//{

	//	while (1)
	//	{
	//		x = rand() % (mapSize - 1) + 1;
	//		y = rand() % (mapSize - 1) + 1;
	//		if (map[x][y] == SPACE)
	//		{
	//			//map[x][y]에 깃발 배치
	//			map[x][y] = 3;
	//			break;
	//		}
	//		else
	//		{
	//			continue;
	//		}
	//	}
	//}

	//for (int i = 0; i < 5; i++)				//4번깃발 배치
	//{
	//	while (1)
	//	{
	//		x = rand() % (mapSize - 1) + 1;
	//		y = rand() % (mapSize - 1) + 1;
	//		if (map[x][y] == SPACE)
	//		{
	//			//map[x][y]에 깃발 배치
	//			map[x][y] = 4;
	//			break;
	//		}
	//		else
	//		{
	//			continue;
	//		}
	//	}
	//}

	for (int i = 0; i < 5; i++)				//5번깃발 배치
	{

		while (1)
		{
			x = rand() % (mapSize - 1) + 1;
			y = rand() % (mapSize - 1) + 1;
			if (map[x][y] == SPACE)
			{
				//map[x][y]에 깃발 배치
				map[x][y] = 5;
				break;
			}
			else
			{
				continue;
			}
		}
	}

	for (int i = 0; i < 5; i++)				//6번깃발 배치
	{

		while (1)
		{
			x = rand() % (mapSize - 1) + 1;
			y = rand() % (mapSize - 1) + 1;
			if (map[x][y] == SPACE)
			{
				//map[x][y]에 깃발 배치
				map[x][y] = 6;
				break;
			}
			else
			{
				continue;
			}
		}
	}

	for (int i = 0; i < 5; i++)				//7번깃발 배치
	{

		while (1)
		{
			x = rand() % (mapSize - 1) + 1;
			y = rand() % (mapSize - 1) + 1;
			if (map[x][y] == SPACE)
			{
				//map[x][y]에 깃발 배치
				map[x][y] = 7;
				break;
			}
			else
			{
				continue;
			}
		}
	}

	for (int i = 0; i < 5; i++)				//8번깃발 배치
	{

		while (1)
		{
			x = rand() % (mapSize - 1) + 1;
			y = rand() % (mapSize - 1) + 1;
			if (map[x][y] == SPACE)
			{
				//map[x][y]에 깃발 배치
				map[x][y] = 8;
				break;
			}
			else
			{
				continue;
			}
		}
	}

	for (int i = 0; i < 5; i++)				//9번깃발 배치(telpo)
	{
		

		while (1)
		{
			x = rand() % (mapSize - 1) + 1;
			y = rand() % (mapSize - 1) + 1;
			if (map[x][y] == SPACE)
			{
				//map[x][y]에 깃발 배치
				map[x][y] = 9;
				break;
			}
			else
			{
				continue;
			}
		}
	}

	for (int i = 0; i < 5; i++)				//10번깃발 배치(bomb)
	{

		while (1)
		{
			x = rand() % (mapSize - 1) + 1;
			y = rand() % (mapSize - 1) + 1;
			if (map[x][y] == SPACE)
			{
				//map[x][y]에 깃발 배치
				map[x][y] = 10;
				break;
			}
			else
			{
				continue;
			}
		}
	}

}


int judgeFlag()
{
	int flag_time100 = 0;
	int x, y;
	int temp = map[Y][X];
	gotoxy(50, 10);
	//	깃발은 2~10번까지밖에없다. 이조건은 이 함수에서 판단하자.
	if (temp == SPACE)
	{
		return 0;
	}
	else if (temp == PAST_PATH) {
		return 0;
	}
	else
	{
		fl();
		if (temp == 2)
		{
			mciSendString(TEXT("close mp3_1"), NULL, 0, NULL);
			Start_time = time(0);
			clear += Flages[temp].clear;
			map[Y][X] = SPACE;

			cls;
			if (lev < 3) {
				cls;
				clea();
				claer();
				gotoxy(73, 25); printf("다음 레벨로 넘어가려면 enter..");
				
				if(kbhit())
				while (!GetAsyncKeyState(VK_RETURN)) {//게임 완전 클리어
				}
				mciSendString(TEXT("close mp3_7"), NULL, 0, NULL);
				lev += 1;
				cls;
				game();
			}
			else { 
				clea();
				claer();
				delay;
				gotoxy(65, 25); printf("메인 메뉴로 가려면 enter 누르세요..");
				if (kbhit())
				while (!GetAsyncKeyState(VK_RETURN)) {//게임 완전 클리어
				}
				mciSendString(TEXT("close mp3_7"), NULL, 0, NULL);
				Sleep(3000);
				main();
				return 1;
			}
		}
		else if (temp == 3)				//꽝
		{
			com = temp;
			comment(com);
			map[Y][X] = SPACE;
		}
		else if (temp == 4)				//시야버프
		{
			com = temp;
			comment(com);
			itemtime(&playeR.sight_p);
			if (flag_time == 0) {
				flag_time = time(0);
			}
			map[Y][X] = SPACE;
		}
		else if (temp == 5)				//방향키 변환
		{
			com = temp;
			comment(com);
			itemtime(&playeR.mushroom);
			if (flag_time3 == 0) {
				flag_time3 = time(0);
			}
			map[Y][X] = SPACE;
		}
		else if (temp == 6)				//시간 증가
		{
			com = temp;
			comment(com);
			Start_time += 30;
			map[Y][X] = SPACE;
		}
		else if (temp == 7)				//시간 감소
		{
			 com = temp;
			comment(com);
			Start_time -= 30;
			map[Y][X] = SPACE;
		}
		else if (temp == 8)				//시야너프
		{
			com = temp;
			comment(com);
			itemtime(&playeR.sight_m);
			if (flag_time2 == 0) {
				flag_time2 = time(0);
			}
			map[Y][X] = SPACE;
		}
		else if (temp == 9)						//텔포
		{
			com = temp;
			comment(com);
			tp();
			map[Y][X] = SPACE;
			while (1)
			{
				x = rand() % (mapSize - 1) + 1;
				y = rand() % (mapSize - 1) + 1;
				if (map[y][x] == SPACE)
				{
					teleport(y, x);
					mciSendString(TEXT("close mp3_5"), NULL, 0, NULL);
					return 0;
				}
				else
				{
					continue;
				}
			}
			
			return 0;
		}
		else if (temp == 10)				//bomb
		{
			com = temp;
			comment(com);
			bomb_num += 1;
			map[Y][X] = SPACE;
		}
		
	}
	//Flag[index].~~처럼 값 활용~
}

void bomb()
{
	int temp_x, temp_y;
	if (X - Bomb_Range < 1)
	{
		temp_x = 1;
	}
	else if (X + Bomb_Range >= (mapSize - 1))
	{
		temp_x = (mapSize - 1) - (2 * Bomb_Range + 1);
	}
	else
	{
		temp_x = X - Bomb_Range;
	}
	if (Y - Bomb_Range < 1)
	{
		temp_y = 1;
	}
	else if (Y + Bomb_Range >= (mapSize - 1))
	{
		temp_y = (mapSize - 1) - (2 * Bomb_Range + 1);
	}
	else
	{
		temp_y = Y - Bomb_Range;
	}


	int x, y, t_x, t_y;

	if (X - Bomb_Range < 1)
	{
		t_x = 53 - 2 * (eyesight - 1 - Bomb_Range);
	}
	else if (X + Bomb_Range >= (mapSize - 1))
	{
		t_x = 53 + 2 * (eyesight - 1 - Bomb_Range);
	}
	else if (X < eyesight)
	{
		t_x = 53 - 2 * (eyesight - X);
	}
	else if (X > (mapSize - 1) - eyesight)
	{
		t_x = 53 + 2 * (eyesight - (mapSize - 1 - X));
	}
	else
	{
		t_x = 53;
	}

	if (Y - Bomb_Range < 1)
	{
		t_y = 15 - eyesight + 1 + Bomb_Range;
	}
	else if (Y + Bomb_Range >= (mapSize - 1))
	{
		t_y = 15 + eyesight - 1 - Bomb_Range;
	}
	else if(Y < eyesight)
	{
		t_y = 15 - (eyesight - Y);
	}
	else if (Y > (mapSize - 1) - eyesight)
	{
		t_y = 15 +  (eyesight - (mapSize - 1 - Y));

	}
	else
	{
		t_y = 15;
	}

	for (int i = 0; i <= Bomb_Range; i++)
	{
		printMap();
		y = t_y - i;
		for (int j = 0; j < 2 * i + 1; j++)
		{
			x = t_x - i * 2;
			for (int k = 0; k < 2 * i + 1; k++)
			{
				gotoxy(x, y);
				if (j == 0 || k == 0 || j == (2 * i) || k == (2 * i))
				{
					if (map[temp_y + Bomb_Range - i + j][temp_x + Bomb_Range - i + k] == WALL)
						map[temp_y + Bomb_Range - i + j][temp_x + Bomb_Range - i + k] = SPACE;
					printf("■");
				}
				x += 2;
			}
			y++;
		}

		Sleep(300);
	}

	return 0;
}

void teleport(int y, int x)
{
	

	int** p = (int**)malloc(sizeof(int*) * (eyesight * 2 + 1));
	int** p2 = (int**)malloc(sizeof(int*) * (eyesight * 2 + 1));
	int past_x, past_y;
	int past_X, past_Y;
	
	int temp_x, temp_y;
	if (X - eyesight < 0)
	{
		temp_x = 0;
	}
	else if (X + eyesight >= mapSize)
	{
		temp_x = mapSize - (2 * eyesight + 1);
	}
	else
	{
		temp_x = X - eyesight;
	}
	if (Y - eyesight < 0)
	{
		temp_y = 0;
	}
	else if (Y + eyesight >= mapSize)
	{
		temp_y = mapSize - (2 * eyesight + 1);
	}
	else
	{
		temp_y = Y - eyesight;
	}
	past_x = temp_x;
	past_y = temp_y;

	past_X = X;
	past_Y = Y;

	for (int i = 0; i < eyesight * 2 + 1; i++)
	{
		p[i] = (int*)malloc(sizeof(int) * (eyesight * 2 + 1));
		p2[i] = (int*)malloc(sizeof(int) * (eyesight * 2 + 1));
		for (int j = 0; j < eyesight * 2 + 1; j++)
		{
			p[i][j] = map[temp_y + i][temp_x + j];
		}
	}

	X = x;
	Y = y;

	if (X - eyesight < 0)
	{
		temp_x = 0;
	}
	else if (X + eyesight >= mapSize)
	{
		temp_x = mapSize - (2 * eyesight + 1);
	}
	else
	{
		temp_x = X - eyesight;
	}
	if (Y - eyesight < 0)
	{
		temp_y = 0;
	}
	else if (Y + eyesight >= mapSize)
	{
		temp_y = mapSize - (2 * eyesight + 1);
	}
	else
	{
		temp_y = Y - eyesight;
	}

	for (int i = 0; i < eyesight * 2 + 1; i++)
	{
		for (int j = 0; j < eyesight * 2 + 1; j++)
		{
			p2[i][j] = map[temp_y + i][temp_x + j];
		}
	}
	print_telpo(p, p2, past_x, past_y, past_X, past_Y);
	return;
}

void print_telpo(int** p, int** p2, int past_x, int past_y, int past_X, int past_Y)
{
	
	int temp_x, temp_y;
	if (X - eyesight < 0)
	{
		temp_x = 0;
	}
	else if (X + eyesight >= mapSize)
	{
		temp_x = mapSize - (2 * eyesight + 1);
	}
	else
	{
		temp_x = X - eyesight;
	}
	if (Y - eyesight < 0)
	{
		temp_y = 0;
	}
	else if (Y + eyesight >= mapSize)
	{
		temp_y = mapSize - (2 * eyesight + 1);
	}
	else
	{
		temp_y = Y - eyesight;
	}


	for (int i = 0; i < eyesight * 2 + 1; i++)
	{
		int x = 53 - eyesight * 2;
		int y = 15 - eyesight;
		for (int j = 0; j < eyesight * 2 + 1; j++)
		{
			gotoxy(x, y);
			for (int k = 0; k < eyesight * 2 + 1; k++)
			{
				if (k < i)
				{
					//p2출력
					if (temp_y + j == Y && temp_x + k == X)
					{
						printf("◇");
					}
					else
					{
						if (p2[j][k] == WALL)
							printf("■");
						else if (p2[j][k] == SPACE)
							printf("  ");
						else if (p2[j][k] == PAST_PATH)
							printf("⊙");
						else
							printf("□");
					}
					
				}
				else if (k > i)
				{
					//p출력
					if (past_y + j == past_Y && past_x + k == past_X)
					{
						printf("◇");
					}
					else
					{
						if (p[j][k] == WALL)
							printf("■");
						else if (p[j][k] == SPACE)
							printf("  ");
						else if (p[j][k] == PAST_PATH)
							printf("⊙");
						else
							printf("□");
					}
				}
				else
				{
					//벽만 출력!
					printf("■");
				}
			}
			y++;
		}
		Sleep(100);
	}

	return;
}

void judgeMove(int x, int y)
{
	int result;
	if (x >= 0 && x < mapSize && y >= 0 && y < mapSize)
	{
		
		if (map[y][x] != WALL)
		{
			
			X = x;
			Y = y;
		}
		if (judgeFlag())
		{
			//클리어 깃발 획득
		}
	}

	return;
}
/*멘트 구문
flag_time100 = time(0);
cls;
while(time(0) - flag_time100 < 5){
gotoxy(2,10);
printf("멘트");
}
cls;
*/