#include <stdio.h>
#include "../../utils/utils.h"
#include "helper/helper.h"

// Output the binary to decimal result.
void display_hexadecimal(char *decimal, int negative) {
  char neg_decimal[1000] = "-";
  strcat(neg_decimal, decimal);

  printf(
      "%-16s[%s %sHexadecimal%s %s]%s : %s%s%s",
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

void binary_to_hexadecimal(char *binary_input) {
  if (is_positive_binary(binary_input)) {
    printf("binary_input: %s", binary_input);
    add_new_line(1);
    display_hexadecimal("8", 0);
    return;
  }
}
