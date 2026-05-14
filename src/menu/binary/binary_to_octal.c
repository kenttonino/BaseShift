#include "helper/helper.h"
#include "../../utils/utils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

void display_octal(double octal, int negative) {
  printf(
      "%-16s[%s %sOctal%s %s]%s : %s%f%s",
      BLUE,
      RESET,
      GREEN,
      RESET,
      BLUE,
      RESET,
      YELLOW,
      negative == 1 ? -octal : octal,
      RESET
  );
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

      // Process an array of octal values.
      int new_binary_input_length = strlen(new_binary_input);
      // e.g. "001"
      char *binary_group = malloc(sizeof(char) * 3);
      // e.g. ["001", "000"]
      char *octal_arrays = malloc(1000);

      for (int i = 0; i <= new_binary_input_length; i++) {
        int binary_group_length = strlen(binary_group);

        if (binary_group_length == 0) {
          binary_group[0] = new_binary_input[i];
          continue;
        }

        if (binary_group_length == 1) {
          binary_group[1] = new_binary_input[i];
          continue;
        }

        if (binary_group_length == 2) {
          binary_group[2] = new_binary_input[i];
          continue;
        }

        if (binary_group_length == 3) {
          char *octal_value = octal_value_mapper(atoi(binary_group));
          char octal_arrays_len = strlen(octal_arrays);

          octal_arrays[octal_arrays_len] = (char) *octal_value;
          binary_group = malloc(1000);
          binary_group[0] = new_binary_input[i];
        }
      }

      display_octal(atoi(octal_arrays), 0);
    }

    return;
  }
}
