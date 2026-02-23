#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int daysInMonth(int month, int year) {
    int days[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 
                  31, 31, 30, 31, 30, 31};
    return days[month - 1];
}


int main(int argc, char *argv[]) {
  if (argc != 7) {
      printf("Использование: %s д1 м1 г1 д2 м2 г2\n", argv[0]);
      printf("Пример: %s 1 1 2020 1 1 2021\n", argv[0]);
      return 1;
  }
  
  int d1 = atoi(argv[1]);
  int m1 = atoi(argv[2]);
  int y1 = atoi(argv[3]);
  int d2 = atoi(argv[4]);
  int m2 = atoi(argv[5]);
  int y2 = atoi(argv[6]);

  printf("Исходные данные:\n");
  printf("Первая дата: %02d.%02d.%04d\n", d1, m1, y1);
  printf("Вторая дата: %02d.%02d.%04d\n", d2, m2, y2);
  printf("(отсчет с 1 января 1970 года)\n\n");
}