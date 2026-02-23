#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Использование: %s д1 м1 г1\n", argv[0]);
    printf("Пример: %s 1 1 2020\n", argv[0]);
    return 1;
  }
  
  int d1 = atoi(argv[1]);
  int m1 = atoi(argv[2]);
  int y1 = atoi(argv[3]);

  printf("Исходные данные:\n");
  printf("Дата: %02d.%02d.%04d\n", d1, m1, y1);
  printf("(отсчет с 1 января 1970 года)\n\n");
}