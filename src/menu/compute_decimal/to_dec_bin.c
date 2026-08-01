#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../helper/helper.h"
#include "../../utils/utils.h"
#include "./to_utils.h"

char* _get_dec_bin(char *dec) {
  char *end_ptr;
  int int_dec = strtol(dec, &end_ptr, 10);

  static char bin[1000];
  int current_dividend = int_dec;
  memset(bin, 0, sizeof(char) * 1000);
  for (;;) {
    if (current_dividend != 0) {
      int current_rem = current_dividend % 2;
      char char_current_rem[1000];
      sprintf(char_current_rem, "%d", current_rem);

      if (strcmp(char_current_rem, "0") == 0 || strcmp(char_current_rem, "1") == 0) {
        strcat(bin, char_current_rem);
        current_dividend = current_dividend / 2;
        continue;
      }
    }

    break;
  }

  return reverse_string(bin);
}

// We will limit only the binary dot values to 8 fractional bits.
char* _get_dec_bin_radixp(char *dec_radixp) {
  _dec_radixp_adder(dec_radixp);

  static char bin[9];
  memset(bin, 0, sizeof(char) * 9);
  double double_dec = atof(dec_radixp);

  for (int i = 0; i < 8; i++) {
    double product = double_dec * 2;

    if (product < 1) {
      bin[i] = '0';
      double_dec = product;
      continue;
    } else {
      bin[i] = '1';
      double_dec = product - 1;
      continue;
    }
  }

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
  if (strlen(dec_input) == 1 && strcmp(dec_input, "-") == 0) {
    _display_dec_bin("0", 0);
    return;
  }

  if (strlen(dec_input) == 1 && strcmp(dec_input, "0") == 0) {
    _display_dec_bin("0", 0);
    return;
  }

  if (is_positive(dec_input)) {
    char *dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);

    char *bin = _get_dec_bin(dec);
    _display_dec_bin(bin, 0);

    free(dec);
    return;
  }

  if (is_positive_radixp(dec_input)) {
    char *dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);
    GenericInput generic_input = _get_dec_generic_input(dec);

    char *dec_before_radixp = malloc(sizeof(char) * 1000);
    char *dec_after_radixp = malloc(sizeof(char) * 1000);
    strcpy(dec_before_radixp, generic_input.before_radixp);
    strcpy(dec_after_radixp, generic_input.after_radixp);

    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, _get_dec_bin(dec_before_radixp));
    strcat(bin, ".");
    strcat(bin, _get_dec_bin_radixp(dec_after_radixp));

    _display_dec_bin(bin, 0);
    free(dec);
    free(dec_before_radixp);
    free(dec_after_radixp);
    free(bin);
    return;
  }

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

  if (is_negative_radixp(dec_input)) {
    char* dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);

    char* positive_dec = malloc(sizeof(char) * 1000);
    memmove(positive_dec, dec + 1, strlen(dec));
    GenericInput generic_input = _get_dec_generic_input(positive_dec);

    char *dec_before_radixp = malloc(sizeof(char) * 1000);
    char *dec_after_radixp = malloc(sizeof(char) * 1000);
    strcpy(dec_before_radixp, generic_input.before_radixp);
    strcpy(dec_after_radixp, generic_input.after_radixp);

    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, _get_dec_bin(dec_before_radixp));
    strcat(bin, ".");
    strcat(bin, _get_dec_bin_radixp(dec_after_radixp));
    _display_dec_bin(bin, 1);

    free(dec);
    free(positive_dec);
    free(dec_before_radixp);
    free(dec_after_radixp);
    free(bin);
    return;
  }
}
