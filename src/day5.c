#include <float.h>
#include <stdio.h>

struct rule {
    int first;
    int second;
};

int linearSearch(int* arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            return -1;
        } else if (arr[i] == key) {
            return i;
        }
    }
}

int getMedianValue(int* arr, int n) {
    int i = 0;
    for (; i < n && arr[i] != 0; i++)
        ;

    return (i / 2) + 1;
        
}

void day5() {
    FILE* fptr;
    fopen_s(&fptr, "inputs/day5.txt", "r");
    struct rule rules[1200] = {0};
    char line[80] = {0};
    int result1 = 0;
    int result2 = 0;

    for (int i = 0; fscanf(fptr, "%d|%d", &rules[i].first, &rules[i].second) == 2; i++) 
        ;

    fseek(fptr, -2, SEEK_CUR);
    int currentLine = 0;
    while (fgets(line, 80, fptr) != NULL) {
        currentLine++;
        int number = 0;
        int numList[40] = {0};
        char* lptr = line;
        for (int i = 0; sscanf(lptr, "%d", &number) == 1; i++) {
            numList[i] = number;
            lptr += 3;
        }

        int doomed = 0;
        int n = sizeof(numList) / sizeof(numList[0]);
        for (int i = 0; i < 1200; i++) {
            if (rules[i].first == 0) {
                break;
            }
            int firstIndex = linearSearch(numList, n, rules[i].first);
            int secondIndex = linearSearch(numList, n, rules[i].second);
            if ((firstIndex != -1 && secondIndex != -1) && firstIndex > secondIndex) {
                int temp = numList[firstIndex];
                numList[firstIndex] = numList[secondIndex];
                numList[secondIndex] = numList[temp];
                doomed = 1;
                break;
            }
        }

        if (doomed == 0) {
            result1 += numList[getMedianValue(numList, n)];
        } else {
            result2 += numList[getMedianValue(numList, n)];
        }

        for (int j = 0; j < 40; j++) {
            numList[j] = 0;
        }
    } 
    fclose(fptr);

    printf("first star : %d\n", result1);
    printf("second star : %d", result2);
}
