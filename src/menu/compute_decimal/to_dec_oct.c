#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../utils/utils.h"
#include "../helper/helper.h"

char* _get_dec_oct(char* dec_input) {
  char* end_ptr;
  int int_dec_input = strtol(dec_input, &end_ptr, 10);

  static char oct_digits[1000];
  memset(oct_digits, 0, sizeof(char) * 1000);
  int dividend = int_dec_input;

  for (;;) {
    if (dividend != 0) {
      int reminder = dividend % 8;
      char char_reminder[1000];
      sprintf(char_reminder, "%d", reminder);
      strcat(oct_digits, char_reminder);
      dividend = dividend / 8;
      continue;
    }

    break;
  }

  return reverse_string(oct_digits);
}

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

void to_dec_oct(char* dec_input) {
  if (is_positive(dec_input)) {
    char* dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);

    char* oct = _get_dec_oct(dec);
    _display_dec_oct(oct, 0);

    free(dec);
    return;
  }
}
