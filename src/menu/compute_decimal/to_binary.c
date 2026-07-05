#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../helper/helper.h"
#include "../../utils/utils.h"
#include "./types.h"

char* _get_bin(char *dec_input) {
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

char* _get_bin_with_dot(char *dec_input) {
  char dec_buffer[1000];
  memset(dec_buffer, 0, sizeof(char) * 1000);
  memmove(dec_buffer + 2, dec_buffer, strlen(dec_input) + 2);
  dec_buffer[0] = '0';
  dec_buffer[1] = '.';
  strcat(dec_buffer, dec_input);
  strcpy(dec_input, dec_buffer);
  return dec_input;
}

DottedDecimal _get_sanitized_dotted_dec(char* dec_input) {
  // Store the decimal input in new variable.
  static char dec_buffer[1000];
  memset(dec_buffer, 0, sizeof(char) * 1000);
  memmove(dec_buffer, dec_input, strlen(dec_input));

  // Sanitized the decimal values before and after dot.
  static char dec_before_dot[1000];
  static char dec_after_dot[1000];
  memset(dec_before_dot, 0, sizeof(char) * 1000);
  memset(dec_after_dot, 0, sizeof(char) * 1000);

  int is_after_dot = 0;
  int counter_before_dot = 0;
  int counter_after_dot = 0;
  for (int i = 0; dec_input[i] != '\0'; i++) {
    if (dec_input[i] == '.') {
      is_after_dot = 1;
      continue;
    }

    if (is_after_dot) {
      dec_after_dot[counter_after_dot++] = dec_input[i];
      continue;
    } else {
      dec_before_dot[counter_before_dot++] = dec_input[i];
    }
  }

  // Reset to the null terminator to stop reading this variables.
  dec_before_dot[counter_before_dot] = '\0';
  dec_after_dot[counter_after_dot] = '\0';

  DottedDecimal sanitized_dec;
  sanitized_dec.before_dot = dec_before_dot;
  sanitized_dec.after_dot = dec_after_dot;

  return sanitized_dec;
}

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
    DottedDecimal dotted_dec = _get_sanitized_dotted_dec(dec);

    char *dec_before_dot = malloc(sizeof(char) * 1000);
    char *dec_after_dot = malloc(sizeof(char) * 1000);
    strcpy(dec_before_dot, dotted_dec.before_dot);
    strcpy(dec_after_dot, dotted_dec.after_dot);

    printf("before_dot: %s", dec_before_dot);
    add_new_line(1);
    printf("after_dot: %s", _get_bin_with_dot(dec_after_dot));
    add_new_line(1);

    _display_bin("1111011.00011001", 0);
    free(dec);
    free(dec_before_dot);
    free(dec_after_dot);
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
