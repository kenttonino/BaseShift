#include <stdio.h>
#include <stdlib.h>
#include "../helper/helper.h"
#include "../../utils/utils.h"

void _display_oct_bin(char *bin, int negative) {
  char neg_bin[1000] = "-";
  strcat(neg_bin, bin);

  printf(
      "%-16s[%s %sBinary%s %s]%s : %s%s%s",
      BLUE,
      RESET,
      GREEN,
      RESET,
      BLUE,
      RESET,
      YELLOW,
      negative == 1 ? neg_bin : bin,
      RESET
  );
}

void to_oct_bin(char* oct_input) {
  if (is_positive(oct_input)) {
    char* oct = malloc(sizeof(char) * 1000);
    strcpy(oct, oct_input);
    printf("oct: %s", oct);
    add_new_line(1);

    _display_oct_bin("1010011", 0);

    free(oct);
    return;
  }
}
