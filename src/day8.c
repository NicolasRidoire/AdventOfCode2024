#include <stdio.h>
#include <string.h>

#define SIZE 50
#define BOARD_SIZE2 2500

typedef struct {
    int index;
    char type;
} Antenna;

void day8() {
    FILE* fptr;
    fopen_s(&fptr, "inputs/day8.txt", "r");
    int result1 = 0;
    int result2 = 0;
    char board[BOARD_SIZE2];
    char resBoard[BOARD_SIZE2] = {'.'};
    char line[SIZE];
    Antenna antenna[BOARD_SIZE2] = {0, '.'};

    for (int i = 0; fgets(line, 52, fptr) != NULL; i += 50) {
        memcpy(&board[i], line, 50);
    }

    int j = 0;
    for (int i = 0; i < BOARD_SIZE2; i++) {
        if (board[i] != '.') {
            antenna[j].type = board[i];
            antenna[j].index = i;
            j++;
        }
    }

    for (int i = 0; antenna[i].type != '\000'; i++) {

    }

    printf("first star : %d\n", result1);
    printf("second star : %d\n", result2);
}