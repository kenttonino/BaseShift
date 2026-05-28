#include "helper/helper.h"
#include "../../utils/utils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void octal_zero_adder(char *binary_input, char *new_binary_input) {
  int binary_len = strlen(binary_input);
  int rem_binary_len = binary_len % 3;

  // If we don't need to add zeroes.
  if (rem_binary_len == 0) {
    for (int j = 0; j < binary_len; j++) {
      new_binary_input[j] = (char) binary_input[j];
    }
    return;
  }

  // If we need to add two zeroes.
  if (rem_binary_len == 1) {
    // Add the zeroes first.
    for (int i = 0; i < 2; i++) {
      new_binary_input[i] = '0';
    };
    // Add the binary input next.
    for (int j = 0; j < binary_len; j++) {
      new_binary_input[j+2] = (char) binary_input[j];
    }
    return;
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

char *get_octal(char *binary_input) {
  // Prepend the 2 zeroes in binary_input.
  char *new_binary_input = malloc(sizeof(char) * 1000);
  octal_zero_adder(binary_input, new_binary_input);

  // Process an array of octal values.
  int new_binary_input_len = strlen(new_binary_input);
  // e.g. "001"
  char *binary_group = malloc(sizeof(char) * 3);
  // e.g. ["001", "000"]
  static char octal_arrays[1000];

  for (int i = 0; i <= new_binary_input_len; i++) {
    int binary_group_len = strlen(binary_group);

    if (binary_group_len == 0) {
      binary_group[0] = new_binary_input[i];
      continue;
    }

    if (binary_group_len == 1) {
      binary_group[1] = new_binary_input[i];
      continue;
    }

    if (binary_group_len == 2) {
      binary_group[2] = new_binary_input[i];
      continue;
    }

    if (binary_group_len == 3) {
      // Get the octal value equivalent.
      char *octal_value = octal_value_mapper(atoi(binary_group));

      // Insert the new value in the octal arrays.
      int octal_arrays_len = strlen(octal_arrays);
      octal_arrays[octal_arrays_len] = *octal_value;

      // Reset the binary group.
      // Assign an index 0 value.
      memset(binary_group, 0, sizeof(char) * 3);
      binary_group[0] = new_binary_input[i];
    }
  }

  free(new_binary_input);
  free(binary_group);
  return octal_arrays;
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
    char *octal_arrays = get_octal(binary_input);
    display_octal(atoi(octal_arrays), 0);
    return;
  }

  // e.g. 1000.1111 = 10.74
  if (is_positive_binary_with_dot(binary_input)) {
    printf("Hello");
    add_new_line(2);
    return;
  }
}
