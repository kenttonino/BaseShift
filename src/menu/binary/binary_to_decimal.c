#include "../../utils/utils.h"
#include "binary_reverse_string.c"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// If the binary input does not include a dot (.) or negative (-).
int is_positive(char* binary_input) {
  if (strrchr(binary_input, '-') == NULL && strrchr(binary_input, '.') == NULL) {
    return 1;
  } else {
    return 0;
  }
}

// If the binary input does have a dot without negative sign.
int is_positive_dot(char* binary_input) {
  if (strrchr(binary_input, '-') == NULL && strrchr(binary_input, '.') != NULL) {
    return 1;
  } else {
    return 0;
  }
}

// If the binary input does include negative without dot.
int is_negative(char* binary_input) {
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


// Compute the decimal value before without dot.
double get_decimal(char* binary_input) {
 char *reversed_binary_input = binary_reverse_string(binary_input);
 int reversed_binary_length = strlen(reversed_binary_input);
 double decimal = 0;

 for (int i = 0; i < reversed_binary_length; i++) {
   char current_binary_char = reversed_binary_input[i];
   int current_binary_int = atoi(&current_binary_char);
   decimal = decimal + (current_binary_int * pow(2, i));
 }

 return decimal;
}

// Compute the decimal value with dot.
double get_decimal_with_dot(char* binary_input) {
  // Separate the binary values before and after dot.
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

  // Reset to the null terminator to stop reading this variables.
  binary_before_dot[counter_before_dot] = '\0';
  binary_after_dot[counter_after_dot]   = '\0';

  // Compute the values before dot.
  char *reversed_binary_input = binary_reverse_string(binary_before_dot);
  int reversed_binary_length = strlen(reversed_binary_input);
  double decimal = 0;
  for (int i = 0; i < reversed_binary_length; i++) {
    char current_binary_char = reversed_binary_input[i];
    int current_binary_int = atoi(&current_binary_char);
    int exponent = current_binary_int * pow(2, i);
    decimal = decimal + (current_binary_int * pow(2, i));
  }

  // Compute the values after dot.
  int before_dot_exponent = -1;
  for (int i = 0; i < strlen(binary_after_dot); i++) {
    // This converts a character representing a digit into the actual integer value.
    int current_binary_int = binary_after_dot[i] - '0';
    decimal += current_binary_int * pow(2, -(i + 1));
  }

  free(binary_before_dot);
  free(binary_after_dot);
  return decimal;
}

// Output the binary to decimal result.
void display_decimal(double decimal, int negative) {
  printf(
    "%-16s[%s %sDecimal%s %s]%s : %s%f%s",
    BLUE,
    RESET,
    GREEN,
    RESET,
    BLUE,
    RESET,
    YELLOW,
    negative == 1 ? -decimal : decimal,
    RESET
 );
}

void binary_to_decimal(char *binary_input) {
  // E.g. 0001 value.
  if (is_positive(binary_input)) {
    double decimal = get_decimal(binary_input);
    display_decimal(decimal, 0);
    return;
  }

  // E.g. -0001 value.
  if (is_negative(binary_input)) {
    // Remove the - character.
    memmove(binary_input, binary_input+1, strlen(binary_input));
    double decimal = get_decimal(binary_input);
    display_decimal(decimal, 1);
    return;
  }

  // E.g. -0001.1 value.
  if (is_negative_with_dot(binary_input)) {
    // Remove the - character.
    memmove(binary_input, binary_input+1, strlen(binary_input));
    double decimal = get_decimal_with_dot(binary_input);
    display_decimal(decimal, 1);
    return;
  }

  // E.g. 1111.1 values.
  if (is_positive_dot(binary_input)) {
    // Separate the binary values before and after dot.
    double decimal = get_decimal_with_dot(binary_input);
    display_decimal(decimal, 0);
    return;
  }
}
