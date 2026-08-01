#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../utils/utils.h"
#include "../helper/helper.h"
#include "./to_utils.h"

char * _dec_hex_mapper(char* dec) {
  if (strcmp(dec, "10") == 0) return "A";
  if (strcmp(dec, "11") == 0) return "B";
  if (strcmp(dec, "12") == 0) return "C";
  if (strcmp(dec, "13") == 0) return "D";
  if (strcmp(dec, "14") == 0) return "E";
  if (strcmp(dec, "15") == 0) return "F";
  return dec;
}

char* _get_dec_hex(char* dec) {
  char* dec_int_end_ptr;
  int int_dec = strtol(dec, &dec_int_end_ptr, 10);

  static char hex[1000];
  memset(hex, 0, sizeof(char) * 1000);
  int dividend = int_dec;
  for (;;) {
    if (dividend != 0) {
      int rem = dividend % 16;
      char char_rem[1000];
      sprintf(char_rem, "%d", rem);
      strcat(hex, _dec_hex_mapper(char_rem));
      dividend = dividend / 16;
      continue;
    }

    break;
  }

  return reverse_string(hex);
}

// Limit the result to 8 fractional digits.
char* _get_dec_hex_radixp(char* dec_radixp) {
  _dec_radixp_adder(dec_radixp);

  static char hex[9];
  memset(hex, 0, sizeof(char) * 9);
  double double_dec_radixp = atof(dec_radixp);
  double dividend = double_dec_radixp;
  for (int i = 0; i < 8; i++) {
    double quotient = dividend * 16;
    int int_quotient = (int) quotient;
    char char_quotient[1000];
    sprintf(char_quotient, "%d", int_quotient);
    char* hex_mapped = _dec_hex_mapper(char_quotient);
    strcat(hex, hex_mapped);

    if (int_quotient < 0) {
      dividend = quotient;
    } else {
      dividend = quotient - int_quotient;
    }
  }

  return hex;
}

void _display_dec_hex(char *hex, int negative) {
  char neg_hex[1000] = "-";
  strcat(neg_hex, hex);

  printf(
      "%-16s[%s %sHexadecimal%s %s]%s : %s%s%s",
      BLUE,
      RESET,
      GREEN,
      RESET,
      BLUE,
      RESET,
      YELLOW,
      negative == 1 ? neg_hex : hex,
      RESET
  );
}

void to_dec_hex(char* dec_input) {
  if (strlen(dec_input) == 1 && strcmp(dec_input, "-") == 0) {
    _display_dec_hex("0", 0);
    return;
  }

  if (strlen(dec_input) == 1 && strcmp(dec_input, "0") == 0) {
    _display_dec_hex("0", 0);
    return;
  }

  if (is_positive(dec_input)) {
    char* dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);

    char* hex = _get_dec_hex(dec);
    _display_dec_hex(hex, 0);

    free(dec);
    return;
  }

  if (is_positive_radixp(dec_input)) {
    char* dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);
    GenericInput generic_input = _get_dec_generic_input(dec);

    char* before_radixp = malloc(sizeof(char) * 1000);
    char* after_radixp = malloc(sizeof(char) * 1000);
    strcpy(before_radixp, generic_input.before_radixp);
    strcpy(after_radixp, generic_input.after_radixp);

    char* hex = malloc(sizeof(char) * 1000);
    strcpy(hex, _get_dec_hex(before_radixp));
    strcat(hex, ".");
    strcat(hex, _get_dec_hex_radixp(after_radixp));
    _display_dec_hex(hex, 0);

    free(dec);
    free(before_radixp);
    free(after_radixp);
    free(hex);
    return;
  }

  if (is_negative(dec_input)) {
    char* dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);
    char* positive_dec = malloc(sizeof(char) * 1000);
    memcpy(positive_dec, dec + 1, strlen(dec));

    char* hex = _get_dec_hex(positive_dec);
    _display_dec_hex(hex, 1);

    free(dec);
    free(positive_dec);
    return;
  }

  if (is_negative_radixp(dec_input)) {
    char* dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);
    char* positive_dec = malloc(sizeof(char) * 1000);
    memcpy(positive_dec, dec + 1, strlen(dec));
    GenericInput generic_input = _get_dec_generic_input(positive_dec);

    char* before_radixp = malloc(sizeof(char) * 1000);
    char* after_radixp = malloc(sizeof(char) * 1000);
    strcpy(before_radixp, generic_input.before_radixp);
    strcpy(after_radixp, generic_input.after_radixp);

    char* hex = malloc(sizeof(char) * 1000);
    strcpy(hex, _get_dec_hex(before_radixp));
    strcat(hex, ".");
    strcat(hex, _get_dec_hex_radixp(after_radixp));
    _display_dec_hex(hex, 1);

    free(dec);
    free(positive_dec);
    free(before_radixp);
    free(after_radixp);
    free(hex);
    return;
  }
}
