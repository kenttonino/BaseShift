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

char *hexadecimal_mapper(char *binary_group) {
  if (strcmp(binary_group, "0000") == 0) return "0";
  if (strcmp(binary_group, "0001") == 0) return "1";
  if (strcmp(binary_group, "0010") == 0) return "2";
  if (strcmp(binary_group, "0011") == 0) return "3";
  if (strcmp(binary_group, "0100") == 0) return "4";
  if (strcmp(binary_group, "0101") == 0) return "5";
  if (strcmp(binary_group, "0110") == 0) return "6";
  if (strcmp(binary_group, "0111") == 0) return "7";
  if (strcmp(binary_group, "1000") == 0) return "8";
  if (strcmp(binary_group, "1001") == 0) return "9";
  if (strcmp(binary_group, "1010") == 0) return "A";
  if (strcmp(binary_group, "1011") == 0) return "B";
  if (strcmp(binary_group, "1100") == 0) return "C";
  if (strcmp(binary_group, "1101") == 0) return "D";
  if (strcmp(binary_group, "1110") == 0) return "E";
  if (strcmp(binary_group, "1111") == 0) return "F";
  return "0";
}

char *_get_hexadecimal(char *binary_input) {
  char *binary = _hex_zero_adder(binary_input);

  char binary_group[5] = "";
  static char current_binary[1];
  static char hexadecimal[1000];
  memset(current_binary, 0, sizeof(char));
  memset(hexadecimal, 0, sizeof(char) * 1000);

  for (size_t i = 0; i <= strlen(binary); i++) {
    *current_binary = binary[i];

    if (strlen(binary_group) < 4) {
      strcat(binary_group, current_binary);
      memset(current_binary, 0, sizeof(char));
      continue;
    } else {
      strcat(hexadecimal, hexadecimal_mapper(binary_group));

      memset(binary_group, 0, sizeof(char) * 5);
      strcat(binary_group, current_binary);
      memset(current_binary, 0, sizeof(char));
    }
  }

  return hexadecimal;
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

    char *hexadecimal = _get_hexadecimal(binary);
    _display_hexadecimal(hexadecimal, 0);

    free(binary);
    return;
  }

  // e.g. -1000 = -8
  if (is_negative_binary(binary_input)) {
    char *binary = malloc(sizeof(char) * 1000);
    strcpy(binary, binary_input);

    char *positive_binary = malloc(sizeof(char) * 1000);
    memmove(positive_binary, binary + 1, strlen(binary));

    char *hexadecimal = _get_hexadecimal(positive_binary);
    _display_hexadecimal(hexadecimal, 1);

    free(binary);
    free(positive_binary);
    return;
  }
}
