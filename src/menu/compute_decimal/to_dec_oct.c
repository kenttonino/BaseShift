#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../../utils/utils.h"
#include "./to_utils.h"
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

// We will limit only the dot values to 8 octal bits.
char* _get_dec_oct_with_dot(char *dec_dot_input) {
  // Mutate the dec_dot_input parameter with prepended 0. on it.
  _dec_dot_adder(dec_dot_input);

  static char after_dot_oct[9];
  memset(after_dot_oct, 0, sizeof(char) * 9);
  double float_dec = atof(dec_dot_input);
  double dividend = float_dec;
  for (int i = 0; i < 8; i++) {
    double quotient = dividend * 8;
    int int_quotient = (int) quotient;
    char char_quotient[1000];
    sprintf(char_quotient, "%d", int_quotient);
    strcat(after_dot_oct, char_quotient);

    if (int_quotient < 0) {
      dividend = quotient;
    } else {
      dividend = quotient - int_quotient;
    }
  }

  // Remind CPU that static char ends.
  after_dot_oct[strlen(after_dot_oct)] = '\0';

  return after_dot_oct;
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

  if (is_positive_with_dot(dec_input)) {
    char* dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);
    DottedDecimal dotted_dec = _get_dec_dotted(dec_input);

    char *dec_before_dot = malloc(sizeof(char) * 1000);
    char *dec_after_dot = malloc(sizeof(char) * 1000);
    strcpy(dec_before_dot, dotted_dec.before_dot);
    strcpy(dec_after_dot, dotted_dec.after_dot);

    char *oct = malloc(sizeof(char) * 1000);
    strcpy(oct, _get_dec_oct(dec_before_dot));
    strcat(oct, ".");
    strcat(oct, _get_dec_oct_with_dot(dec_after_dot));
    _display_dec_oct(oct, 0);

    free(dec);
    free(dec_before_dot);
    free(dec_after_dot);
    free(oct);
    return;
  }

  if (is_negative(dec_input)) {
    char* dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);

    char* positive_dec = malloc(sizeof(char) * 1000);
    memmove(positive_dec, dec_input + 1, strlen(dec_input));

    char* oct = _get_dec_oct(positive_dec);
    _display_dec_oct(oct, 1);

    free(dec);
    free(positive_dec);
    return;
  }
}
