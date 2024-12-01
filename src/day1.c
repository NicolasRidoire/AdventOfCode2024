#include <stdio.h>

int min(int* list);
int count(int* list, int number);

void day1() {
  int list1[1000] = {0};
  int list2[1000] = {0};
  int copy1[1000] = {0};
  int copy2[1000] = {0};
  int n1 = 0, n2 = 0, i = 0, result1 = 0, result2 = 0;

  FILE* fptr = fopen("inputs/day1.txt", "r");
  while(fscanf(fptr, "%d %d", &n1, &n2) == 2) {
    list1[i] = n1;
    list2[i] = n2;
    i++;
  }
  fclose(fptr);

  for (int i = 0; i < 1000; i++) {
    copy1[i] = list1[i]; 
    copy2[i] = list2[i]; 
  }

  for (int i = 0; i < 1000; i++) {
    int minList1 = min(list1);
    int minList2 = min(list2);
    if (minList1 > minList2)
      result1 += minList1 - minList2;
    else
      result1 += minList2 - minList1;

    result2 += copy1[i] * count(copy2, copy1[i]);
  }

  printf("first star : %d\n", result1);
  printf("second star : %d\n", result2);
}

int min(int* list) {
  int currentMin = 9999999;
  int minIndex = 0;
  for (int i = 0; i < 1000; i++) {
    if (list[i] == 0) continue;
    if (list[i] < currentMin) {
      currentMin = list[i];
      minIndex = i;
    }
  }
  list[minIndex] = 0;
  printf("%d\n", currentMin);
  return currentMin;
}

int count(int* list, int number) {
  int total = 0;
  for (int i = 0; i < 1000; i++) {
    if (list[i] == number)
      total++;
  }
  return total;
}