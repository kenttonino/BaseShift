#include <stdio.h>
#include <string.h>
#include "../../utils/utils.h"
#include "../helper/helper.h"

void _display_dec_oct(char *oct, int negative) {
  char neg_oct[1000] = "-";
  strcat(neg_oct, oct);

  printf(
      "%-16s[%s %sOctal%s %s]%s : %s%s%s",
      BLUE,
      RESET,
      GREEN,
      RESET,
      BLUE,
      RESET,
      YELLOW,
      negative == 1 ? neg_oct : oct,
      RESET
  );
}

void to_decimal_octal(char* dec_input) {
  if (is_positive(dec_input)) {
    printf("dec_input: %s", dec_input);
    add_new_line(1);
    _display_dec_oct("123", 0);
    return;
  }
}
