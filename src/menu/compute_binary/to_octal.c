#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../helper/helper.h"
#include "../../utils/utils.h"
#include "./types.h"

char* _oct_zero_adder(char *bin_input) {
  int bin_len = strlen(bin_input);
  int bin_rem = bin_len % 3;

  if (bin_rem == 1) {
    char bin_buffer[1000];
    memset(bin_buffer, 0, sizeof(char) * 1000);
    memmove(bin_buffer + 2, bin_input, strlen(bin_input) + 2);
    bin_buffer[0] = '0';
    bin_buffer[1] = '0';
    strcpy(bin_input, bin_buffer);
    return bin_input;
  }

  if (bin_rem == 2) {
    char bin_buffer[1000];
    memset(bin_buffer, 0, sizeof(char) * 1000);
    memmove(bin_buffer + 1, bin_input, strlen(bin_input) + 1);
    bin_buffer[0] = '0';
    strcpy(bin_input, bin_buffer);
    return bin_input;
  }

  return bin_input;
}

char *_oct_zero_adder_with_dot(char *bin_input) {
  int bin_len = strlen(bin_input);
  int bin_rem = bin_len % 3;

  if (bin_rem == 1) {
    char bin_buffer[1000];
    memset(bin_buffer, 0, sizeof(char) * 1000);
    memmove(bin_buffer + 2, bin_input, strlen(bin_input) + 2);
    strcpy(bin_buffer, bin_input);
    strcat(bin_buffer, "00");
    strcpy(bin_input, bin_buffer);
    return bin_input;
  }

  if (bin_rem == 2) {
    char bin_buffer[1000];
    memset(bin_buffer, 0, sizeof(char) * 1000);
    memmove(bin_buffer + 1, bin_input, strlen(bin_input) + 1);
    strcpy(bin_buffer, bin_input);
    strcat(bin_buffer, "0");
    strcpy(bin_input, bin_buffer);
    return bin_input;
  }

  return bin_input;
}


DottedBinary _get_oct_dotted_bin(char *bin_input) {
  // Store the bin in new variable.
  static char bin_buffer[1000];
  memset(bin_buffer, 0, sizeof(char) * 1000);
  memmove(bin_buffer, bin_input, strlen(bin_input));

  // Separate the bin values before and after dot.
  static char bin_before_dot[1000];
  static char bin_after_dot[1000];
  memset(bin_before_dot, 0, sizeof(char) * 1000);
  memset(bin_after_dot, 0, sizeof(char) * 1000);

  int is_after_dot = 0;
  int counter_before_dot = 0;
  int counter_after_dot = 0;
  for (int i = 0; bin_input[i] != '\0'; i++) {
    if (bin_input[i] == '.') {
      is_after_dot = 1;
      continue;
    }

    if (is_after_dot) {
      bin_after_dot[counter_after_dot++] = bin_input[i];
      continue;
    } else {
      bin_before_dot[counter_before_dot++] = bin_input[i];
    }
  }

  // Reset to the null terminator to stop reading this variables.
  bin_before_dot[counter_before_dot] = '\0';
  bin_after_dot[counter_after_dot] = '\0';

  DottedBinary dotted_bin;
  dotted_bin.before_dot = _oct_zero_adder(bin_before_dot);
  dotted_bin.after_dot = _oct_zero_adder_with_dot(bin_after_dot);

  return dotted_bin;
}

char *_oct_mapper(char *bin_group) {
  if (strcmp(bin_group, "001") == 0) return "1";
  if (strcmp(bin_group, "010") == 0) return "2";
  if (strcmp(bin_group, "011") == 0) return "3";
  if (strcmp(bin_group, "100") == 0) return "4";
  if (strcmp(bin_group, "101") == 0) return "5";
  if (strcmp(bin_group, "110") == 0) return "6";
  if (strcmp(bin_group, "111") == 0) return "7";
  return "0";
}

char *_get_oct(char *bin_input) {
  char *bin = _oct_zero_adder(bin_input);

  char bin_group[4] = "";
  static char current_bin[1];
  static char oct[1000];
  memset(current_bin, 0, sizeof(char));
  memset(oct, 0, sizeof(char) * 1000);

  for (size_t i = 0; i <= strlen(bin); i++) {
    *current_bin = bin[i];

    if (strlen(bin_group) < 3) {
      strcat(bin_group, current_bin);
      memset(current_bin, 0, sizeof(char));
      continue;
    } else {
      // Push the oct value of first 3 bin digits.
      strcat(oct, _oct_mapper(bin_group));

      // Reset bin group and assign value for index 0;
      memset(bin_group, 0, sizeof(char) *3);
      strcat(bin_group, current_bin);

      // Reset the current_bin for next iteration.
      memset(current_bin, 0, sizeof(char));
    }
  }

  return oct;
}


void _display_oct(char *oct, int negative) {
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

void to_octal(char *bin_input) {
  // e.g. 1000 = 10
  if (is_positive(bin_input)) {
    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, bin_input);

    char *p_oct = _get_oct(bin);
    _display_oct(p_oct, 0);

    free(bin);
    return;
  }

  // e.g. -1000 = -10
  if (is_negative(bin_input)) {
    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, bin_input);

    char *positive_bin = malloc(sizeof(char) * 1000);
    memmove(positive_bin, bin + 1, strlen(bin));

    char *p_oct = _get_oct(positive_bin);
    _display_oct(p_oct, 1);

    free(bin);
    free(positive_bin);
    return;
  }

  // e.g. 1000.1000 = 10.4
  if (is_positive_with_dot(bin_input)) {
    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, bin_input);
    DottedBinary dotted_bin = _get_oct_dotted_bin(bin);

    char *bin_before_dot = malloc(sizeof(char) * 1000);
    char *bin_after_dot = malloc(sizeof(char) * 1000);
    strcpy(bin_before_dot, dotted_bin.before_dot);
    strcpy(bin_after_dot, dotted_bin.after_dot);

    char *oct = malloc(sizeof(char) * 1000);
    strcpy(oct, _get_oct(bin_before_dot));
    strcat(oct, ".");
    strcat(oct, _get_oct(bin_after_dot));
    _display_oct(oct, 0);

    free(bin);
    free(oct);
    free(bin_before_dot);
    free(bin_after_dot);
    return;
  }

  // e.g. -1000.1000 = -10.4
  if (is_negative_with_dot(bin_input)) {
    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, bin_input);

    char *positive_bin = malloc(sizeof(char) * 1000);
    memmove(positive_bin, bin + 1, strlen(bin));
    DottedBinary dotted_bin = _get_oct_dotted_bin(positive_bin);

    char *bin_before_dot = malloc(sizeof(char) * 1000);
    char *bin_after_dot = malloc(sizeof(char) * 1000);
    strcpy(bin_before_dot, dotted_bin.before_dot);
    strcpy(bin_after_dot, dotted_bin.after_dot);

    char *oct = malloc(sizeof(char) * 1000);
    strcpy(oct, _get_oct(bin_before_dot));
    strcat(oct, ".");
    strcat(oct, _get_oct(bin_after_dot));
    _display_oct(oct, 1);

    free(bin);
    free(positive_bin);
    free(oct);
    free(bin_before_dot);
    free(bin_after_dot);
    return;
  }
}
