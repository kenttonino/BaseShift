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
    // Remove the first character.
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
