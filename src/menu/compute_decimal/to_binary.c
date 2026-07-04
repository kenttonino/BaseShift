#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../helper/helper.h"
#include "../../utils/utils.h"

char *_get_bin(char *dec_input) {
  char *end_ptr;
  int int_dec = strtol(dec_input, &end_ptr, 10);

  static char bin_digits[1000];
  int current_dividend = int_dec;
  memset(bin_digits, 0, sizeof(char) * 1000);
  for (;;) {
    if (current_dividend != 0) {
      int current_rem = current_dividend % 2;
      char bin_digit[1000];
      sprintf(bin_digit, "%d", current_rem);

      if (strcmp(bin_digit, "0") == 0 || strcmp(bin_digit, "1") == 0) {
        strcat(bin_digits, bin_digit);
        current_dividend = current_dividend / 2;
        continue;
      }
    }

    break;
  }

  return reverse_string(bin_digits);
}


//char *_get_bin_with_dot(char *dec_input) {
//    return "0.0001100110011001101";
//}

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
  // e.g. 123 = 1111011
  if (is_positive(dec_input)) {
    char *dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);

    char *bin_digits = _get_bin(dec);
    _display_bin(bin_digits, 0);

    free(dec);
    return;
  }

  // e.g. 123.1 = 1111011.00011001
  if (is_positive_with_dot(dec_input)) {
    char *dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);

    _display_bin("1111011.00011001", 0);
    free(dec);
    return;
  }

  // e.g. -123 = -1111011
  if (is_negative(dec_input)) {
    char *dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);

    char *positive_dec = malloc(sizeof(char) * 1000);
    memmove(positive_dec, dec + 1, strlen(dec));

    char *bin_digits = _get_bin(positive_dec);
    _display_bin(bin_digits, 1);

    free(dec);
    free(positive_dec);
    return;
  }
}
