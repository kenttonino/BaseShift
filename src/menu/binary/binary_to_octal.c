#include "helper/helper.h"
#include "../../utils/utils.h"
#include <string.h>
#include <stdio.h>

char *get_octal(char *binary_input) {
  printf("%s", binary_input);
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
    char *octal_arrays = get_octal(binary_input);
    display_octal(octal_arrays, 1);
    return;
  }

  // e.g. 1000.1111 = 10.74
  if (is_positive_binary_with_dot(binary_input)) {
    printf("Hello");
    add_new_line(2);
    return;
  }
}
