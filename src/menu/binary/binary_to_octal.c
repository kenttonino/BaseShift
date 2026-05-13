#include <stdio.h>
#include "helper/helper.h"
#include <string.h>
#include <stdlib.h>

void octal_zero_adder(int num_zeroes, int binary_length, char *binary_input, char *new_binary_input) {
  for (int i = 0; i < 3; i++) {
    if (i < 2) {
      new_binary_input[i] = '0';
    } else {
      for (int j = 0; j < binary_length; j++) {
        new_binary_input[i + j] = (char) binary_input[j];
      }
    }
  }
}

char *octal_value_mapper(int octal) {
  switch (octal) {
  case 000:
    return "0";
  case 001:
    return "1";
  case 010:
    return "2";
  case 011:
    return "3";
  case 100:
    return "4";
  case 101:
    return "5";
  case 110:
    return "6";
  case 111:
    return "7";
  default:
    return "0";
  }
}

void binary_to_octal(char *binary_input) {
  // e.g. 1000 = 10
  if (is_positive_binary(binary_input)) {
    int binary_length = strlen(binary_input);
    int octal_reminder = binary_length % 3;

    if (octal_reminder == 1) {
      // Prepend the 2 zeroes in binary_input.
      int zeroes_to_add = 2;
      char *new_binary_input = malloc(sizeof(char) * (binary_length  + zeroes_to_add));
      octal_zero_adder(zeroes_to_add, binary_length, binary_input, new_binary_input);

      // e.g. "001"
      char *octal_group = malloc(sizeof(char) * 3);
      // e.g. ["001", "000"]
      char *octal_arrays = malloc(1000);

      char *octal = octal_value_mapper(atoi("111"));
      printf("%s", octal);
    }

    return;
  }
}
