#include <stdio.h>
#include "../helper/helper.h"
#include "../../utils/utils.h"

void _display_bin(char *bin, int negative) {
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

void to_binary(char *dec_input) {
  if (is_positive(dec_input)) {
    printf("dec_input: %s", dec_input);
    add_new_line(1);
    _display_bin("1111101000", 0);
    return;
  }
}
