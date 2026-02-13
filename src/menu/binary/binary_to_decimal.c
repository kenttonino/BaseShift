#include "../../utils/utils.h"
#include "binary_reverse_string.c"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// If the binary input does not include a dot (.) or negative (-).
int is_normal(char* binary_input) {
  if (strrchr(binary_input, '-') == NULL && strrchr(binary_input, '.') == NULL) {
    return 1;
  } else {
    return 0;
  }
}

// If the binary input does include negative without dot.
int is_negative_only(char* binary_input) {
  if (strrchr(binary_input, '-') != NULL && strrchr(binary_input, '.') == NULL) {
    return 1;
  } else {
    return 0;
  }
}

// If the binary input does include a negative and dot.
int is_negative_with_dot(char* binary_input) {
  if (strrchr(binary_input, '-') != NULL && strrchr(binary_input, '.') != NULL) {
    return 1;
  } else {
    return 0;
  }
}

void binary_to_decimal(char *binary_input) {
  // E.g. 0001 value.
  if (is_normal(binary_input)) {
    // Handle the summation of the binary values.
    char *reversed_binary_input = binary_reverse_string(binary_input);
    int reversed_binary_length = strlen(reversed_binary_input);
    int decimal = 0;
    for (int i = 0; i < reversed_binary_length; i++) {
      char current_binary_char = reversed_binary_input[i];
      int current_binary_int = atoi(&current_binary_char);
      int exponent = current_binary_int * pow(2, i);
      decimal = decimal + (current_binary_int * pow(2, i));
    }

    printf(
        "%-16s[%s %sDecimal%s %s]%s : %s%d%s",
        BLUE,
        RESET,
        GREEN,
        RESET,
        BLUE,
        RESET,
        YELLOW,
        decimal,
        RESET
    );

    return;
  }

  // E.g. -0001 value.
  if (is_negative_only(binary_input)) {
    // Remove the - character.
    memmove(binary_input, binary_input+1, strlen(binary_input));

    // Handle the summation of the binary values.
    char *reversed_binary_input = binary_reverse_string(binary_input);
    int reversed_binary_length = strlen(reversed_binary_input);
    int decimal = 0;
    for (int i = 0; i < reversed_binary_length; i++) {
      char current_binary_char = reversed_binary_input[i];
      int current_binary_int = atoi(&current_binary_char);
      int exponent = current_binary_int * pow(2, i);
      decimal = decimal + (current_binary_int * pow(2, i));
    }

    printf(
        "%-16s[%s %sDecimal%s %s]%s : %s%d%s",
        BLUE,
        RESET,
        GREEN,
        RESET,
        BLUE,
        RESET,
        YELLOW,
        -decimal,
        RESET
    );

    return;
  }

  // E.g. -0001.1 value.
  if (is_negative_with_dot(binary_input)) {
    // Remove the - character.
    memmove(binary_input, binary_input+1, strlen(binary_input));

    // Separate the binary values before dot.
    char *binary_before_dot = malloc(strlen(binary_input) + 1);
    char *binary_after_dot = malloc(strlen(binary_input) + 1);
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

    // Separate the binary values after dot.

    printf("binary_before_dot: %s", binary_before_dot);
    add_new_line(1);
    printf("binary_after_dot: %s", binary_after_dot);
    free(binary_before_dot);
    free(binary_after_dot);
    return;
  }

  printf(
      "%-16s[%s %sDecimal%s %s]%s : %s%d%s",
      BLUE,
      RESET,
      GREEN,
      RESET,
      BLUE,
      RESET,
      YELLOW,
      0,
      RESET
  );
}
