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

int daysSince1970(int day, int month, int year) {
    int total = 0;

    if (year < 1970 || month < 1 || month > 12 || 
        day < 1 || day > daysInMonth(month, year)) {
        return -1;
    }

    for (int y = 1970; y < year; y++) {
        total += isLeapYear(y) ? 366 : 365;
    }

    for (int m = 1; m < month; m++) {
        total += daysInMonth(m, year);
    }

    total += day - 1;

    return total;
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

  int days1 = daysSince1970(d1, m1, y1);
  int days2 = daysSince1970(d2, m2, y2);

  printf("Результаты:\n");
  printf("Дней с 01.01.1970 до %02d.%02d.%04d: %d\n", d1, m1, y1, days1);
  printf("Дней с 01.01.1970 до %02d.%02d.%04d: %d\n", d2, m2, y2, days2);
  printf("Дней между датами: %d\n", abs(days2 - days1));

  return 0;
}