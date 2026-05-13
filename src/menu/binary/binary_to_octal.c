#include <stdio.h>
#include "helper/helper.h"
#include <string.h>
#include <stdlib.h>

void zero_adder(int num_zeroes, int binary_length, char *binary_input, char *new_binary_input) {
  for (int i = 0; i < 3; i++) {
    if (i < 2) {
      new_binary_input[i] = '0';
    } else {
      for (int j = 0; j < binary_length; j++) {
        new_binary_input[i + j] = (char)binary_input[j];
      }
    }
  }
}

void binary_to_octal(char *binary_input) {
  // e.g. 1000 = 10
  if (is_positive_binary(binary_input)) {
    int binary_length = strlen(binary_input);
    int octal_reminder = binary_length % 3;

    if (octal_reminder == 1) {
      int zeroes_to_add = 2;
      char *new_binary_input = malloc(sizeof(char) * (binary_length  + zeroes_to_add));
      zero_adder(zeroes_to_add, binary_length, binary_input, new_binary_input);
      printf("%s", new_binary_input);
    }

    return;
  }
}
