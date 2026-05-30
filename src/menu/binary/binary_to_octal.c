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

char *get_octal(char *binary_input) {
  char *p_new_binary = zero_adder(binary_input);

  printf("%s", p_new_binary);

  return "10";
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
    display_octal(p_octal, 1);
    return;
  }

  // e.g. 1000.1111 = 10.74
  if (is_positive_binary_with_dot(binary_input)) {
    printf("Hello");
    add_new_line(2);
    return;
  }
}
