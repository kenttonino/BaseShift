#include "../../utils/utils.h"
#include "helper/helper.h"
#include "binary_reverse_string.c"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compute the decimal value without dot.
int get_decimal(char *binary_input) {
  char *reversed_binary_input = binary_reverse_string(binary_input);
  int reversed_binary_length = strlen(reversed_binary_input);
  int decimal = 0;

  for (int i = 0; i < reversed_binary_length; i++) {
    // Use the ASCII equivalent.
    // 0 -> 48
    // 1 -> 49
    int current_binary_int = reversed_binary_input[i] - '0';
    decimal = decimal + (current_binary_int * pow(2, i));
  }

  return decimal;
}

// Compute the decimal value with dot.
double get_decimal_with_dot(char *binary_input) {
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
  binary_after_dot[counter_after_dot] = '\0';

  // Compute the values before dot.
  char *reversed_binary_input = binary_reverse_string(binary_before_dot);
  int reversed_binary_length = strlen(reversed_binary_input);
  double decimal = 0;

  for (int i = 0; i < reversed_binary_length; i++) {
    int current_binary_int = reversed_binary_input[i] - '0';
    decimal = decimal + (current_binary_int * pow(2, i));
  }

  // Compute the values after dot.
  for (int i = 0; i < (int) strlen(binary_after_dot); i++) {
    // This converts a character representing a digit into the actual integer
    // value.
    int current_binary_int = binary_after_dot[i] - '0';
    decimal += current_binary_int * pow(2, -(i + 1));
  }

  free(binary_before_dot);
  free(binary_after_dot);
  return decimal;
}

// Output the binary to decimal result.
void display_decimal(char *decimal, int negative) {
  char neg_decimal[1000] = "-";
  strcat(neg_decimal, decimal);

  printf(
      "%-16s[%s %sDecimal%s %s]%s : %s%s%s",
      BLUE,
      RESET,
      GREEN,
      RESET,
      BLUE,
      RESET,
      YELLOW,
      negative == 1 ? neg_decimal : decimal,
      RESET
  );
}

void binary_to_decimal(char *binary_input) {
  // E.g. 1000 = 8
  if (is_positive_binary(binary_input)) {
    char *binary = malloc(sizeof(char) * 1000);
    strcpy(binary, binary_input);

    int decimal = get_decimal(binary);
    char decimal_string[1000];
    sprintf(decimal_string, "%d", decimal);
    display_decimal(decimal_string, 0);

    free(binary);
    return;
  }

  // E.g. -1000 = -8
  if (is_negative_binary(binary_input)) {
    char *binary = malloc(sizeof(char) * 1000);
    strcpy(binary, binary_input);

    char *positive_binary = malloc(sizeof(char) * 1000);
    memmove(positive_binary, binary + 1, strlen(binary));

    int decimal = get_decimal(positive_binary);
    char decimal_string[1000];
    sprintf(decimal_string, "%d", decimal);
    display_decimal(decimal_string, 1);

    free(binary);
    free(positive_binary);
    return;
  }

  // E.g. 1000.1 = 8.500
  if (is_positive_binary_with_dot(binary_input)) {
    char *binary = malloc(sizeof(char) * 1000);
    strcpy(binary, binary_input);

    double decimal = get_decimal_with_dot(binary);
    char decimal_string[1000];
    sprintf(decimal_string, "%.3f", decimal);
    display_decimal(decimal_string, 0);

    free(binary);
    return;
  }

  // E.g. -1000.1 = -8.500
  if (is_negative_binary_with_dot(binary_input)) {
    char *binary = malloc(sizeof(char) * 1000);
    strcpy(binary, binary_input);

    char *positive_binary = malloc(sizeof(char) * 1000);
    memmove(positive_binary, binary + 1, strlen(binary));

    double decimal = get_decimal_with_dot(positive_binary);
    char decimal_string[1000];
    sprintf(decimal_string, "%.3f", decimal);
    display_decimal(decimal_string, 1);

    free(binary);
    free(positive_binary);
    return;
  }

}
