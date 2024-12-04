#include <stdio.h>
#include <string.h>

// #define UL 0
// #define U 1
// #define UR 2
// #define L 3
// #define R 4
// #define DL 5
// #define D 6
// #define DR 7

void UL(int* i, int* j) {
    (*i)--;
    (*j)--;
}
void U(int* i, int* j) {
    (*i)--;
}
void UR(int* i, int* j) {
    (*i)--;
    (*j)++;
}
void L(int* i, int* j) {
    (*j)--;
}
void R(int* i, int* j) {
    (*j)++;
}
void DL(int* i, int* j) {
    (*i)++;
    (*j)--;
}
void D(int* i, int* j) {
    (*i)++;
}
void DR(int* i, int* j) {
    (*i)++;
    (*j)++;
}

void day4() {
    FILE* fptr;
    int result1 = 0;
    int result2 = 0;
    fopen_s(&fptr, "inputs/day4.txt", "r");
    char* reg = "XMAS";
    char* reg2 = "MAS";
    char input[140 * 142] = {0};
    char line[142] = {0};
    void (*dir[8])(int*, int*) = {&UL, &U, &UR, &L, &R, &DL, &D, &DR};

    int i = 0;
    while(fgets(line, 143, fptr) != NULL) {
        memcpy(&input[i*140], line, sizeof(line));
        i++;
    }
    fclose(fptr);

    for (int i = 0; i < 140; i++)
    {
        int i2 = i;
        for (int j = 0; j < 140; j++)
        {
            int j2 = j;
            if (input[i2 * 140 + j2] == reg[0])
            {
                for (int l = 0; l < 8; l++)
                {
                    for (int m = 1; m < 4; m++)
                    {
                        dir[l](&i2, &j2);
                        if (i2 >= 0 && i2 <= 140 && j2 >= 0 && j2 <= 140)
                        {
                            if (input[i2 * 140 + j2] == reg[m])
                            {
                                if (reg[m] == 'S')
                                {
                                    result1++;
                                    i2 = i;
                                    j2 = j;
                                    break;
                                }
                            }
                            else
                            {
                                i2 = i;
                                j2 = j;
                                break;
                            }
                        }
                        else
                        {
                            i2 = i;
                            j2 = j;
                            break;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 140; i++)
    {
        int i2 = i;
        for (int j = 0; j < 140; j++)
        {
            int j2 = j;
            i2 = i;
            j2 = j;
            if (input[i2 * 140 + j2] == reg2[1])
            {
                int ok = 0;
                dir[0](&i2, &j2);
                if (i2 >= 0 && i2 <= 140 && j2 >= 0 && j2 <= 140)
                {
                    if (input[i2 * 140 + j2] == reg2[0])
                    {
                        i2 = i;
                        j2 = j;
                        dir[7](&i2, &j2);
                        if (i2 >= 0 && i2 <= 140 && j2 >= 0 && j2 <= 140)
                        {
                            if (input[i2 * 140 + j2] == reg2[2])
                            {
                                ok++;
                            }
                        }
                    }
                    else if (input[i2 * 140 + j2] == reg2[2])
                    {
                        i2 = i;
                        j2 = j;
                        dir[7](&i2, &j2);
                        if (i2 >= 0 && i2 <= 140 && j2 >= 0 && j2 <= 140)
                        {
                            if (input[i2 * 140 + j2] == reg2[0])
                            {
                                ok++;
                            }
                        }
                    }
                }
                i2 = i;
                j2 = j;
                dir[2](&i2, &j2);
                if (i2 >= 0 && i2 <= 140 && j2 >= 0 && j2 <= 140)
                {
                    if (input[i2 * 140 + j2] == reg2[0])
                    {
                        i2 = i;
                        j2 = j;
                        dir[5](&i2, &j2);
                        if (i2 >= 0 && i2 <= 140 && j2 >= 0 && j2 <= 140)
                        {
                            if (input[i2 * 140 + j2] == reg2[2])
                            {
                                ok++;
                            }
                        }
                    }
                    else if (input[i2 * 140 + j2] == reg2[2])
                    {
                        i2 = i;
                        j2 = j;
                        dir[5](&i2, &j2);
                        if (i2 >= 0 && i2 <= 140 && j2 >= 0 && j2 <= 140)
                        {
                            if (input[i2 * 140 + j2] == reg2[0])
                            {
                                ok++;
                            }
                        }
                    }
                }
                if (ok == 2)
                {
                    result2++;
                }
            }
        }
    }

    printf("first star : %d\n", result1);
    printf("second star : %d\n", result2);
}
