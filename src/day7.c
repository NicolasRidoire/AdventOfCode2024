#include <stdio.h>
#include <math.h>

#define LINE_COUNT 850
#define MAX_NUM 15

unsigned long long find_solution(int* numList, int obj, int index, unsigned long long result, int maxLength) {
    if (index >= maxLength - 1) {
        return 0;
    }

    if (index == 0)
        result += numList[index++];

    unsigned long long solution = 0;
    solution += find_solution(numList, obj, index + 1, result + numList[index], maxLength);
    solution += find_solution(numList, obj, index + 1, result * numList[index], maxLength);
    return solution;
}

void day7() {
    FILE* fptr;
    fopen_s(&fptr, "inputs/day7.txt", "r");
    unsigned long long int result1 = 0;
    int result2 = 0;
    char line[50];

    while (fgets(line, 50, fptr) != NULL) {
        unsigned long long int obj = 0;
        char* lptr = line;
        sscanf(lptr, "%ld:", &obj);

        while (lptr[0] != ':') 
            lptr++;
        lptr += 2;

        int numList[MAX_NUM] = {0};
        int length = 0;
        for (; sscanf(lptr, "%d ", &numList[length]) == 1; length++) {
            while (lptr[0] != ' ')
                lptr++;
            lptr++;
        }

        // for (int j = 0; j < pow(2, length); j++) {
        //     unsigned long long int tempRes = 0;
        //     for (int i = 0; numList[i] != 0; i++) {
        //         int bit = (j & (1 << i)) >> i;
        //         if (bit ^ 1)
        //             tempRes += numList[i];
        //         else
        //             tempRes *= numList[i];
        //     }
        //     if (tempRes == obj) {
        //         result1 += obj;
        //         break;
        //     }
        // }
        unsigned long long tempRes = 0;
        if ((tempRes = find_solution(numList, obj, 0, 0, length)) > 0)
            result1 += tempRes;
    }

    printf("first star : %llu\n", result1);
    printf("second star : %d\n", result2);
}