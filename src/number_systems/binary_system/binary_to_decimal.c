#include "../../displays/ansi_color.h"
#include "reverse_string.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

void binary_to_decimal(char *binary_input) {
  char *reversed_binary_input = reverse_string(binary_input);
  int reversed_binary_length = strlen(reversed_binary_input);
  int decimal = 0;

  for (int i = 0; i < reversed_binary_length; i++) {
    char current_binary_char = reversed_binary_input[i];
    int current_binary_int = atoi(&current_binary_char);
    int exponent = current_binary_int * pow(2, i);
    decimal = decimal + (current_binary_int * pow(2, i));
  }

  printf("%-16s[%s %sDecimal%s %s]%s : %s%d%s", BLUE, RESET, GREEN, RESET, BLUE,
         RESET, YELLOW, decimal, RESET);
}
