#include <string.h>
#include <stdio.h>
#include "../helper/helper.h"
#include "../../utils/utils.h"

void _display_hex_bin(char *bin, int negative) {
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

void to_hex_bin(char* hex_input) {
  ZeroPrefix zero_prefix = is_zero_only(hex_input);
  if (zero_prefix.zero_only == 1) {
    _display_hex_bin("0", 0);
    return;
  }

  _display_hex_bin("TODO", 0);
  return;
}
