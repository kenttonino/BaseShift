#include <math.h>
#include <string.h>
#include <stdio.h>
#include "../helper/helper.h"
#include "../../utils/utils.h"

char* _get_hex_to_dec(char* hex) {
  int hex_len = strlen(hex);
  int exponent = hex_len - 1;

  int dec = 0;
  static char current_hex[2];
  memset(current_hex, 0, sizeof(char) * 2);
  for (int i = 0; i < hex_len; i++) {
    current_hex[0] = hex[i];
    int hex_digit = map_hex_dec(current_hex);
    dec = dec + (hex_digit * pow(16, exponent));
    exponent = exponent - 1;
    memset(current_hex, 0, sizeof(char) * 2);
  }


  static char dec_string[1000];
  memset(dec_string, 0, sizeof(char) * 1000);
  sprintf(dec_string, "%d", dec);

  return dec_string;
}

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

    char* dec = _get_hex_to_dec(hex);
    _display_hex_dec(dec, 0);

    free(hex);
    return;
  }

  _display_hex_dec("TODO", 0);
  return;
}
