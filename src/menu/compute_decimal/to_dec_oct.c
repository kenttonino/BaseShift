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

char* _get_dec_oct_dot(char* dec_input) {
  char* end_ptr;
  double double_dec_input = strtod(dec_input, &end_ptr);
  int dec_powered = double_dec_input * pow(8, 8);

  char char_dec_powered[1000];
  sprintf(char_dec_powered, "%d", dec_powered);

  static char oct_digits[1000];
  memset(oct_digits, 0, sizeof(char) * 1000);
  int dividend = dec_powered;

  for (;;) {
    if (dividend != 0) {
      printf("dividend: %d", dividend % 8);
      add_new_line(1);
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

  if (is_positive_with_dot(dec_input)) {
    char* dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);
    DottedDecimal dotted_dec = _get_dec_dotted(dec_input);

    char *dec_before_dot = malloc(sizeof(char) * 1000);
    char *dec_after_dot = malloc(sizeof(char) * 1000);
    strcpy(dec_before_dot, dotted_dec.before_dot);
    strcpy(dec_after_dot, dotted_dec.after_dot);
    add_new_line(1);

    char *oct = malloc(sizeof(char) * 1000);
    strcpy(oct, _get_dec_oct(dec_before_dot));
    strcat(oct, ".");
    strcat(oct, _get_dec_oct_dot(dec_after_dot));
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
