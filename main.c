#include <stdio.h>

#include "src/day1.c"
#include "src/day2.c"
#include "src/day3.c"

void selectDay(int);

int main() {
  int day = 3;
  selectDay(day);
  return 0;
}

void selectDay(int day) {
  switch (day) {
    case 1:
      day1();
      break;
    case 2:
      day2();
      break;
    case 3:
      day3();
      break;
  }
}