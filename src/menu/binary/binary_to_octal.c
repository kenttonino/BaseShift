#include "helper/helper.h"
#include "../../utils/utils.h"
#include <string.h>
#include <stdio.h>

char* zero_adder(char *binary) {
  int binary_len = strlen(binary);
  int binary_rem = binary_len % 3;
  static char binary_prepend_one_zero[1000] = "0";
  static char binary_prepend_two_zero[1000] = "00";

  if (binary_rem == 1) {
    strcat(binary_prepend_two_zero, binary);
    return binary_prepend_two_zero;
  }

  if (binary_rem == 2) {
    strcat(binary_prepend_one_zero, binary);
    return binary_prepend_one_zero;
  }

  return binary;
}

char *octal_mapper(char *binary_group) {
  if (strcmp(binary_group, "001") == 0) return "1";
  if (strcmp(binary_group, "010") == 0) return "2";
  if (strcmp(binary_group, "011") == 0) return "3";
  if (strcmp(binary_group, "100") == 0) return "4";
  if (strcmp(binary_group, "101") == 0) return "5";
  if (strcmp(binary_group, "110") == 0) return "6";
  if (strcmp(binary_group, "111") == 0) return "7";
  return "0";
}

char *get_octal(char *binary_input) {
  char *p_new_binary = zero_adder(binary_input);
  static char new_binary[1000];
  strcat(new_binary, p_new_binary);

  char binary_group[3] = "";
  static char current_binary[1];
  static char octal[1000] = "";

  for (size_t i = 0; i <= strlen(new_binary); i++) {
    *current_binary = new_binary[i];

    if (strlen(binary_group) < 3) {
      strcat(binary_group, current_binary);
      memset(current_binary, 0, sizeof(char));
      continue;
    } else {
      // Push the octal value of first 3 binary digits.
      strcat(octal, octal_mapper(binary_group));

      // Reset binary group and assign value for index 0;
      memset(binary_group, 0, sizeof(char) *3);
      strcat(binary_group, current_binary);

      // Reset the current_binary for next iteration.
      memset(current_binary, 0, sizeof(char));
    }
  }

  return octal;
}

void display_octal(char *octal, int negative) {
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

void binary_to_octal(char *binary_input) {
  // e.g. 1000 = 10
  if (is_positive_binary(binary_input)) {
    char *p_octal = get_octal(binary_input);
    display_octal(p_octal, 0);
    return;
  }

  // e.g. 1000.1111 = 10.74
  if (is_positive_binary_with_dot(binary_input)) {
    printf("Hello");
    add_new_line(2);
    return;
  }
}
