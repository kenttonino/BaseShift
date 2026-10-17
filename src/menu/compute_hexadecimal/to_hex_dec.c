#include <string.h>
#include <stdio.h>
#include "../helper/helper.h"
#include "../../utils/utils.h"

void _display_hex_dec(char *dec, int negative) {
  char neg_dec[1000] = "-";
  strcat(neg_dec, dec);

  printf(
      "%-16s[%s %sDecimal%s %s]%s : %s%s%s",
      BLUE,
      RESET,
      GREEN,
      RESET,
      BLUE,
      RESET,
      YELLOW,
      negative == 1 ? neg_dec : dec,
      RESET
  );
}

void to_hex_dec(char* hex_input) {
  ZeroPrefix zero_prefix = is_zero_only(hex_input);
  if (zero_prefix.zero_only == 1) {
    _display_hex_dec("0", 0);
    return;
  }

  if (is_positive(hex_input)) {
    char* hex = malloc(sizeof(char) * 1000);
    strcpy(hex, hex_input);

    printf("hex: %s", hex);
    add_new_line(1);
    _display_hex_dec("291", 0);

    free(hex);
    return;
  }

  _display_hex_dec("TODO", 0);
  return;
}
