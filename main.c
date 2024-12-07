#include "src/day1.c"
#include "src/day2.c"
#include "src/day3.c"
#include "src/day4.c"
#include "src/day5.c"
#include "src/day6.c"
#include "src/day7.c"

void selectDay(int);

int main() {
    int day = 7;
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
    case 4:
        day4();
        break;
    case 5:
        day5();
        break;
    case 6:
        day6();
        break;
    case 7:
        day7();
        break;
    }
}
