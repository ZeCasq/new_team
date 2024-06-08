#include "map.h"
#include "head.h"

//char* pMap[2] = {"  ", "■"};
int** map, mapSize, ** backupMap;
int lv = 1, timer = 0;

void SetMap();
int** RollingArray(int MapArr[RMS][RMS], int num, int block);

void GamePlay(void) {
    SetMap();
}

void SetMap(void) {
    mapSize = lv * 100;
    map = (int**)malloc(sizeof(int*) * mapSize);
    for (int i = 0; i < mapSize; i++)
        map[i] = (int*)malloc(sizeof(int) * mapSize);

    for (int i = 0; i < mapSize; i++)
        for (int j = 0; j < mapSize; j++)
            map[i][j] = SPACE;

    timer = lv * 120;

    int num = mapSize / RMS;

    srand((unsigned)time(NULL)); // 랜덤 시드 초기화

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            int** arr = RollingArray(RandomMap[rand() % 2], rand() % 3, ((i == 0 && j == 0) || (i == num - 1 && j == num - 1)) ? 0 : (rand() % 5));
            for (int AH = RMS * i, height = 0; height < RMS; height++, AH++) {
                for (int AW = RMS * j, width = 0; width < RMS; width++, AW++) {
                    map[AH][AW] = arr[height][width];
                }
            }
            for (int k = 0; k < RMS; k++) {
                free(arr[k]);
            }
            free(arr);
        }
    }

    for (int i = 0; i < mapSize; i++) {
        map[i][0] = WALL;
        map[0][i] = WALL;
        map[i][mapSize - 1] = WALL;
        map[mapSize - 1][i] = WALL;
    }
}

int** RollingArray(int MapArr[RMS][RMS], int num, int block) {
    int** arr = (int**)malloc(sizeof(int*) * RMS);
    for (int i = 0; i < RMS; i++) {
        arr[i] = (int*)malloc(sizeof(int) * RMS);
    }

    for (int i = 0; i < RMS; i++) {
        for (int j = 0; j < RMS; j++) {
            arr[i][j] = MapArr[i][j];
        }
    }

    for (int n = 0; n < num; n++) {
        int tempArr[RMS][RMS];
        for (int i = 0; i < RMS; i++) {
            for (int j = 0; j < RMS; j++) {
                tempArr[j][RMS - 1 - i] = arr[i][j];
            }
        }
        for (int i = 0; i < RMS; i++) {
            for (int j = 0; j < RMS; j++) {
                arr[i][j] = tempArr[i][j];
            }
        }
    }

    bool check[8] = { 0 };
    for (int i = 0; i < block; i++) {
        int random = rand() % 8;
        while (check[random]) {
            random = rand() % 8;
        }

        check[random] = true;
        switch (random) {
        case 0:
            arr[1][0] = WALL;
            break;
        case 1:
            arr[0][1] = WALL;
            break;
        case 2:
            arr[0][RMS - 2] = WALL;
            break;
        case 3:
            arr[1][RMS - 1] = WALL;
            break;
        case 4:
            arr[RMS - 2][0] = WALL;
            break;
        case 5:
            arr[RMS - 1][1] = WALL;
            break;
        case 6:
            arr[RMS - 2][RMS - 1] = WALL;
            break;
        case 7:
            arr[RMS - 1][RMS - 2] = WALL;
            break;
        }
    }

    return arr;
}
