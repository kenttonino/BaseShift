#include "../../utils/utils.h"
#include <stdio.h>
#include <stdlib.h>

int main_option(void) {
  int option;
  char *garbage_buffer = malloc(100);

  printf("%-16sChoose an option:%s ", GREY, RESET);
  scanf("%d", &option);
  fgets(garbage_buffer, 100, stdin);

  return option;
}
