#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../utils/utils.h"
#include "./to_utils.h"
#include "../helper/helper.h"

char* _get_dec_oct(char* dec) {
  char* end_ptr;
  int int_dec = strtol(dec, &end_ptr, 10);

  static char oct[1000];
  memset(oct, 0, sizeof(char) * 1000);
  int dividend = int_dec;

  for (;;) {
    if (dividend != 0) {
      int reminder = dividend % 8;
      char char_reminder[1000];
      sprintf(char_reminder, "%d", reminder);
      strcat(oct, char_reminder);
      dividend = dividend / 8;
      continue;
    }

    break;
  }

  return reverse_string(oct);
}

// We will limit only the after radix point digits to 8 octal bits.
char* _get_dec_oct_radixp(char *dec_radixp) {
  _dec_radixp_adder(dec_radixp);

  static char oct[9];
  memset(oct, 0, sizeof(char) * 9);
  double double_dec = atof(dec_radixp);
  double dividend = double_dec;
  for (int i = 0; i < 8; i++) {
    double quotient = dividend * 8;
    int int_quotient = (int) quotient;
    char char_quotient[1000];
    sprintf(char_quotient, "%d", int_quotient);
    strcat(oct, char_quotient);

    if (int_quotient < 0) {
      dividend = quotient;
    } else {
      dividend = quotient - int_quotient;
    }
  }

  oct[strlen(oct)] = '\0';

  return oct;
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
  if (strlen(dec_input) == 1 && strcmp(dec_input, "-") == 0) {
    _display_dec_oct("0", 0);
    return;
  }

  if (strlen(dec_input) == 1 && strcmp(dec_input, "0") == 0) {
    _display_dec_oct("0", 0);
    return;
  }

  if (is_positive(dec_input)) {
    char* dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);

    char* oct = _get_dec_oct(dec);
    _display_dec_oct(oct, 0);

    free(dec);
    return;
  }

  if (is_positive_radixp(dec_input)) {
    char* dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);
    GenericInput generic_input = _get_dec_generic_input(dec);

    char *dec_before_radixp = malloc(sizeof(char) * 1000);
    char *dec_after_radixp = malloc(sizeof(char) * 1000);
    strcpy(dec_before_radixp, generic_input.before_radixp);
    strcpy(dec_after_radixp, generic_input.after_radixp);

    char *oct = malloc(sizeof(char) * 1000);
    strcpy(oct, _get_dec_oct(dec_before_radixp));
    strcat(oct, ".");
    strcat(oct, _get_dec_oct_radixp(dec_after_radixp));
    _display_dec_oct(oct, 0);

    free(dec);
    free(dec_before_radixp);
    free(dec_after_radixp);
    free(oct);
    return;
  }

  if (is_negative(dec_input)) {
    char* dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);

    char* positive_dec = malloc(sizeof(char) * 1000);
    memmove(positive_dec, dec + 1, strlen(dec));

    char* oct = _get_dec_oct(positive_dec);
    _display_dec_oct(oct, 1);

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

    char *oct = malloc(sizeof(char) * 1000);
    strcpy(oct, _get_dec_oct(dec_before_radixp));
    strcat(oct, ".");
    strcat(oct, _get_dec_oct_radixp(dec_after_radixp));
    _display_dec_oct(oct, 1);

    free(dec);
    free(positive_dec);
    free(dec_before_radixp);
    free(dec_after_radixp);
    free(oct);
    return;
  }
}
