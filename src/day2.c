#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FALSE 0;
#define TRUE 1;

void day2() {
  FILE* fptr = fopen("inputs/day2.txt", "r");
  char line[100] = {0};
  size_t len = 0;
  long result1 = 0;
  long result2 = 0;

  while (fgets(line, 100, fptr) != NULL) {

    char* strPtr = line;
    short ok = 2;
    short greater = 3; //Default to determine greater or not on the line
    long lastVal = 0;

    while (*strPtr) {
      if (isdigit(*strPtr)) {
        long val = strtol(strPtr, &strPtr, 10);
        if (lastVal == 0) {
          lastVal = val;
          continue;
        }

        if (val > lastVal && (greater == 1 || greater == 3)) {
          greater = 1;
          if (val - lastVal > 3) {
            ok--;
          }

        } else if (val < lastVal && (greater == 0 || greater == 3)) {
          greater = 0;
          if (lastVal - val > 3) {
            ok--;
          }

        } else {
          ok--;
        }
        if (ok == 0) break;
        lastVal = val;
      } else {
        strPtr++;
      }
    }

    if (ok == 2)
      result1++;
    if (ok >= 1)
      result2++;
  }

  printf("first star : %ld\n", result1);
  printf("second star : %ld\n", result2);
}