#include "../../utils/utils.h"
#include <stdio.h>

void get_binary_input(char *binary_input) {
  printf("%-16s[%s %sBinary%s %s]%s : ", BLUE, RESET, GREY, RESET, BLUE, RESET);
  scanf("%s", binary_input);
}
