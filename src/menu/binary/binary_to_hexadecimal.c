#include <stdio.h>
#include <string.h>
#include "../../utils/utils.h"
#include "helper/helper.h"

char *_hex_zero_adder(char* binary_input) {
  int binary_len = strlen(binary_input);
  int binary_rem = binary_len % 4;

  if (binary_rem == 1) {
    char binary_buffer[1000];
    memset(binary_buffer, 0, sizeof(char) * 1000);
    memmove(binary_buffer + 3, binary_input, strlen(binary_input) + 3);
    binary_buffer[0] = '0';
    binary_buffer[1] = '0';
    binary_buffer[2] = '0';
    strcpy(binary_input, binary_buffer);
    return binary_input;
  }

  if (binary_rem == 2) {
    char binary_buffer[1000];
    memset(binary_buffer, 0, sizeof(char) * 1000);
    memmove(binary_buffer + 2, binary_input, strlen(binary_input) + 2);
    binary_buffer[0] = '0';
    binary_buffer[1] = '0';
    strcpy(binary_input, binary_buffer);
    return binary_input;
  }

  if (binary_rem == 3) {
    char binary_buffer[1000];
    memset(binary_buffer, 0, sizeof(char) * 1000);
    memmove(binary_buffer + 1, binary_input, strlen(binary_input) + 1);
    binary_buffer[0] = '0';
    strcpy(binary_input, binary_buffer);
    return binary_input;
  }

  return binary_input;
}

char *_get_hexadecimal(char *binary_input) {
  char *binary = _hex_zero_adder(binary_input);
  printf("binary: %s", binary);
  add_new_line(1);
  return "8";
}

void _display_hexadecimal(char *decimal, int negative) {
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
  // e.g. 1000 = 8
  if (is_positive_binary(binary_input)) {
    char *binary = malloc(sizeof(char) * 1000);
    strcpy(binary, binary_input);

    char *p_octal = _get_hexadecimal(binary);
    _display_hexadecimal(p_octal, 0);

    free(binary);
    return;
  }
}
