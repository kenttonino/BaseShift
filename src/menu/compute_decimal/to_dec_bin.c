#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../helper/helper.h"
#include "../../utils/utils.h"
#include "./to_utils.h"

char* _get_dec_bin(char *dec_input) {
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

// We will limit only the binary dot values to 8 fractional bits.
char* _get_dec_bin_with_dot(char *dec_dot_input) {
  // Mutate the dec_dot_input parameter with prepended 0. on it.
  _dec_dot_adder(dec_dot_input);

  static char bin[9];
  memset(bin, 0, sizeof(char) * 9);
  double float_dec = atof(dec_dot_input);

  for (int i = 0; i < 8; i++) {
    double product = float_dec * 2;

    if (product < 1) {
      bin[i] = '0';
      float_dec = product;
      continue;
    } else {
      bin[i] = '1';
      float_dec = product - 1;
      continue;
    }
  }

  // Remind CPU that static char ends.
  bin[strlen(bin)] = '\0';

  return bin;
}

void _display_dec_bin(char *bin, int negative) {
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

void to_dec_bin(char *dec_input) {
  // e.g. 123 = 1111011
  if (is_positive(dec_input)) {
    char *dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);

    char *bin_digits = _get_dec_bin(dec);
    _display_dec_bin(bin_digits, 0);

    free(dec);
    return;
  }

  // e.g. 123.1 = 1111011.00011001
  if (is_positive_with_dot(dec_input)) {
    char *dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);
    DottedDecimal dotted_dec = _get_dec_dotted(dec);

    char *dec_before_dot = malloc(sizeof(char) * 1000);
    char *dec_after_dot = malloc(sizeof(char) * 1000);
    strcpy(dec_before_dot, dotted_dec.before_dot);
    strcpy(dec_after_dot, dotted_dec.after_dot);

    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, _get_dec_bin(dec_before_dot));
    strcat(bin, ".");
    strcat(bin, _get_dec_bin_with_dot(dec_after_dot));

    _display_dec_bin(bin, 0);
    free(dec);
    free(dec_before_dot);
    free(dec_after_dot);
    free(bin);
    return;
  }

  // e.g. -123 = -1111011
  if (is_negative(dec_input)) {
    char* dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);

    char* positive_dec = malloc(sizeof(char) * 1000);
    memmove(positive_dec, dec + 1, strlen(dec));

    char* bin_digits = _get_dec_bin(positive_dec);
    _display_dec_bin(bin_digits, 1);

    free(dec);
    free(positive_dec);
    return;
  }

  // e.g. -123.1 = -1111011.00011001
  if (is_negative_with_dot(dec_input)) {
    char* dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);

    char* positive_dec = malloc(sizeof(char) * 1000);
    memmove(positive_dec, dec + 1, strlen(dec));
    DottedDecimal dotted_dec = _get_dec_dotted(positive_dec);

    char *dec_before_dot = malloc(sizeof(char) * 1000);
    char *dec_after_dot = malloc(sizeof(char) * 1000);
    strcpy(dec_before_dot, dotted_dec.before_dot);
    strcpy(dec_after_dot, dotted_dec.after_dot);

    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, _get_dec_bin(dec_before_dot));
    strcat(bin, ".");
    strcat(bin, _get_dec_bin_with_dot(dec_after_dot));
    _display_dec_bin(bin, 1);

    free(dec);
    free(positive_dec);
    free(dec_before_dot);
    free(dec_after_dot);
    free(bin);
    return;
  }
}
