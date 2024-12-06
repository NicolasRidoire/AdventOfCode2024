#include <stdio.h>

#define BOARD_SIZE 16900
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

struct Position {
    int x;
    int y;
};

int getIndex(struct Position pos) {
    return pos.y * 130 + pos.x;
}

struct Position move(struct Position pos, int direction) {
    switch (direction) {
        case UP:
            pos.y--;
            break;
        case RIGHT:
            pos.x++;
            break;
        case DOWN:
            pos.y++;
            break;
        case LEFT:
            pos.x--;
            break;
    }
    return pos;
}

int simulation(struct Position guardPos, char* board, int guardDirection, int* visitedTiles) {
    int i = 0;
    while (guardPos.y >= 0 && guardPos.y < 130 && guardPos.x >= 0 && guardPos.x < 130) {
        visitedTiles[getIndex(guardPos)] = guardDirection;
        struct Position nextPos = move(guardPos, guardDirection);
        while (board[getIndex(nextPos)] == '#') {
            guardDirection = ++guardDirection % 4;
            if (visitedTiles[getIndex(guardPos)] == guardDirection || i > BOARD_SIZE * 2) 
                return 1;
            nextPos = move(guardPos, guardDirection);
        }
        guardPos = nextPos;
        i++;
    }
    return 0;
}

void day6() {
    FILE* fptr;
    fopen_s(&fptr, "inputs/day6.txt", "r");
    int result1 = 0;
    int result2 = 0;
    char board[BOARD_SIZE];

    char line[130];
    for (int i = 0; fgets(line, 133, fptr) != NULL; i += 130) {
        memcpy(&board[i], line, 130);
    }

    fclose(fptr);

    struct Position guardPos = {0, 0};
    int guardDirestion = UP;
    for (int i = 0; board[i] != '^'; i++) {
        guardPos.y = i / 130;
        guardPos.x = i % 130 + 1;
    }

    int visitedTiles[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++)
        visitedTiles[i] = 5;
    simulation(guardPos, board, guardDirestion, visitedTiles);
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (visitedTiles[i] < 5) {
            result1++;

            if (i == getIndex(guardPos)) continue;
            char modifiedBoard[BOARD_SIZE];
            memcpy(modifiedBoard, board, BOARD_SIZE);
            modifiedBoard[i] = '#';
            int visitedTiles2[BOARD_SIZE];
            for (int i = 0; i < BOARD_SIZE; i++)
                visitedTiles2[i] = 5;
            result2 += simulation(guardPos, modifiedBoard, guardDirestion, visitedTiles2);
        }
    }

    // for (int i = 0; i < BOARD_SIZE; i++) {
    //     board[i] = '#';
    //     struct Position obstacle;
    //     obstacle.y = i / 130;
    //     obstacle.x = i % 130;
    //     result2 += simulation(guardPos, board, guardDirestion, visitedTiles, obstacle);
    // }


    printf("first star : %d\n", result1);
    printf("second star : %d\n", result2);
}