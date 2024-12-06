#include <stdio.h>

int getNumber(char* ptr, int* nb) {
  char number[3] = {0};
  int res = 0;
  while (*ptr >= '0' && *ptr <= '9') {
    if (*nb > 3) {
      *nb = 0;
      return -1;
    }
    number[*nb] = *ptr;
    (*nb)++;
    ptr++;
  }
  res = atoi(number);
  return res;
}

void day3() {
  FILE* fptr = fopen("inputs/day3.txt", "r");
  char line[10000] = {0};
  int result = 0; 
  char* reg = "mul(1,2)";
  char* regDo = "do()";
  char* regDont = "don't()";
  int enable = 1;
  int i = 0;

  while (fgets(line, 10000, fptr) != NULL) {
    char* ptr = line;
    int firstNumber = 0;
    int secondNumber = 0;

    while (*ptr) {
      if (*ptr == regDo[i]) {
        if (regDo[i] == ')') {
          i = -1;
          enable = 1;
        }
        i++;
      }
      else if (*ptr == regDont[i]) {
        if (regDont[i] == ')') {
          i = -1;
          enable = 0;
        }
        i++;
      }
      else if (enable == 1 && (*ptr == reg[i] || (*ptr >= '0' && *ptr <= '9'))) {
        if (reg[i] == '1') {
          int nb = 0;
          firstNumber = getNumber(ptr, &nb);
          ptr += nb - 1;
          if (firstNumber == -1) {
            i = 0; continue;
          }
        }
        else if (reg[i] == '2') {
          int nb = 0;
          secondNumber = getNumber(ptr, &nb);
          ptr += nb - 1;
          if (secondNumber == -1) {
            i = 0; continue;
          }
        }
        if (reg[i] == ')') {
          i = 0;
          result += firstNumber * secondNumber;
          continue;
        }
        i++;
      } else {
        i = 0;
      }
      ptr++;
    }
  }

  printf("second star : %d\n", result);
}