#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "./helper/helper.h"
#include "../../utils/utils.h"
#include "./binary_types.h"

char* _oct_zero_adder(char *binary) {
  int binary_len = strlen(binary);
  int binary_rem = binary_len % 3;

  if (binary_rem == 1) {
    char binary_buffer[1000];
    memset(binary_buffer, 0, sizeof(char) * 1000);
    memmove(binary_buffer + 2, binary, strlen(binary) + 2);
    binary_buffer[0] = '0';
    binary_buffer[1] = '0';
    strcpy(binary, binary_buffer);
    return binary;
  }

  if (binary_rem == 2) {
    char binary_buffer[1000];
    memset(binary_buffer, 0, sizeof(char) * 1000);
    memmove(binary_buffer + 1, binary, strlen(binary) + 1);
    binary_buffer[0] = '0';
    strcpy(binary, binary_buffer);
    return binary;
  }

  return binary;
}

char *_oct_zero_adder_with_dot(char *binary) {
  int binary_len = strlen(binary);
  int binary_rem = binary_len % 3;

  if (binary_rem == 1) {
    char binary_buffer[1000];
    memset(binary_buffer, 0, sizeof(char) * 1000);
    memmove(binary_buffer + 2, binary, strlen(binary) + 2);
    strcpy(binary_buffer, binary);
    strcat(binary_buffer, "00");
    strcpy(binary, binary_buffer);
    return binary;
  }

  if (binary_rem == 2) {
    char binary_buffer[1000];
    memset(binary_buffer, 0, sizeof(char) * 1000);
    memmove(binary_buffer + 1, binary, strlen(binary) + 1);
    strcpy(binary_buffer, binary);
    strcat(binary_buffer, "0");
    strcpy(binary, binary_buffer);
    return binary;
  }

  return binary;
}


SanitizedBinary _get_oct_sanitized_binary(char *binary_input) {
  // Store the binary in new variable.
  static char binary_buffer[1000];
  memset(binary_buffer, 0, sizeof(char) * 1000);
  memmove(binary_buffer, binary_input, strlen(binary_input));

  // Separate the binary values before and after dot.
  static char binary_before_dot[1000];
  static char binary_after_dot[1000];
  memset(binary_before_dot, 0, sizeof(char) * 1000);
  memset(binary_after_dot, 0, sizeof(char) * 1000);

  int is_after_dot = 0;
  int counter_before_dot = 0;
  int counter_after_dot = 0;
  for (int i = 0; binary_input[i] != '\0'; i++) {
    if (binary_input[i] == '.') {
      is_after_dot = 1;
      continue;
    }

    if (is_after_dot) {
      binary_after_dot[counter_after_dot++] = binary_input[i];
      continue;
    } else {
      binary_before_dot[counter_before_dot++] = binary_input[i];
    }
  }

  // Reset to the null terminator to stop reading this variables.
  binary_before_dot[counter_before_dot] = '\0';
  binary_after_dot[counter_after_dot] = '\0';

  SanitizedBinary sanitized_binary;
  sanitized_binary.before_dot = _oct_zero_adder(binary_before_dot);
  sanitized_binary.after_dot = _oct_zero_adder_with_dot(binary_after_dot);

  return sanitized_binary;
}

char *_octal_mapper(char *binary_group) {
  if (strcmp(binary_group, "001") == 0) return "1";
  if (strcmp(binary_group, "010") == 0) return "2";
  if (strcmp(binary_group, "011") == 0) return "3";
  if (strcmp(binary_group, "100") == 0) return "4";
  if (strcmp(binary_group, "101") == 0) return "5";
  if (strcmp(binary_group, "110") == 0) return "6";
  if (strcmp(binary_group, "111") == 0) return "7";
  return "0";
}

char *_get_octal(char *binary_input) {
  char *binary = _oct_zero_adder(binary_input);

  char binary_group[4] = "";
  static char current_binary[1];
  static char octal[1000];
  memset(current_binary, 0, sizeof(char));
  memset(octal, 0, sizeof(char) * 1000);

  for (size_t i = 0; i <= strlen(binary); i++) {
    *current_binary = binary[i];

    if (strlen(binary_group) < 3) {
      strcat(binary_group, current_binary);
      memset(current_binary, 0, sizeof(char));
      continue;
    } else {
      // Push the octal value of first 3 binary digits.
      strcat(octal, _octal_mapper(binary_group));

      // Reset binary group and assign value for index 0;
      memset(binary_group, 0, sizeof(char) *3);
      strcat(binary_group, current_binary);

      // Reset the current_binary for next iteration.
      memset(current_binary, 0, sizeof(char));
    }
  }

  return octal;
}


void _display_oct(char *octal, int negative) {
  char neg_octal[1000] = "-";
  strcat(neg_octal, octal);

  printf(
      "%-16s[%s %sOctal%s %s]%s : %s%s%s",
      BLUE,
      RESET,
      GREEN,
      RESET,
      BLUE,
      RESET,
      YELLOW,
      negative == 1 ? neg_octal : octal,
      RESET
  );
}

void to_octal(char *binary_input) {
  // e.g. 1000 = 10
  if (is_positive_binary(binary_input)) {
    char *binary = malloc(sizeof(char) * 1000);
    strcpy(binary, binary_input);

    char *p_octal = _get_octal(binary);
    _display_oct(p_octal, 0);

    free(binary);
    return;
  }

  // e.g. -1000 = -10
  if (is_negative_binary(binary_input)) {
    char *binary = malloc(sizeof(char) * 1000);
    strcpy(binary, binary_input);

    char *positive_binary = malloc(sizeof(char) * 1000);
    memmove(positive_binary, binary + 1, strlen(binary));

    char *p_octal = _get_octal(positive_binary);
    _display_oct(p_octal, 1);

    free(binary);
    free(positive_binary);
    return;
  }

  // e.g. 1000.1000 = 10.4
  if (is_positive_binary_with_dot(binary_input)) {
    char *binary = malloc(sizeof(char) * 1000);
    strcpy(binary, binary_input);
    SanitizedBinary sanitized_binary = _get_oct_sanitized_binary(binary);

    char *binary_before_dot = malloc(sizeof(char) * 1000);
    char *binary_after_dot = malloc(sizeof(char) * 1000);
    strcpy(binary_before_dot, sanitized_binary.before_dot);
    strcpy(binary_after_dot, sanitized_binary.after_dot);

    char *octal = malloc(sizeof(char) * 1000);
    strcpy(octal, _get_octal(binary_before_dot));
    strcat(octal, ".");
    strcat(octal, _get_octal(binary_after_dot));
    _display_oct(octal, 0);

    free(binary);
    free(octal);
    free(binary_before_dot);
    free(binary_after_dot);
    return;
  }

  // e.g. -1000.1000 = -10.4
  if (is_negative_binary_with_dot(binary_input)) {
    char *binary = malloc(sizeof(char) * 1000);
    strcpy(binary, binary_input);

    char *positive_binary = malloc(sizeof(char) * 1000);
    memmove(positive_binary, binary + 1, strlen(binary));
    SanitizedBinary sanitized_binary = _get_oct_sanitized_binary(positive_binary);

    char *binary_before_dot = malloc(sizeof(char) * 1000);
    char *binary_after_dot = malloc(sizeof(char) * 1000);
    strcpy(binary_before_dot, sanitized_binary.before_dot);
    strcpy(binary_after_dot, sanitized_binary.after_dot);

    char *octal = malloc(sizeof(char) * 1000);
    strcpy(octal, _get_octal(binary_before_dot));
    strcat(octal, ".");
    strcat(octal, _get_octal(binary_after_dot));
    _display_oct(octal, 1);

    free(binary);
    free(positive_binary);
    free(octal);
    free(binary_before_dot);
    free(binary_after_dot);
    return;
  }
}
