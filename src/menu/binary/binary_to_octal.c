#include "helper/helper.h"
#include "../../utils/utils.h"
#include <string.h>
#include <stdio.h>


char* zero_adder(char *binary) {
  int binary_len = strlen(binary);
  int binary_rem = binary_len % 3;

  if (binary_rem == 1) {
    char binary_buffer[1000];
    memmove(binary_buffer + 2, binary, strlen(binary) + 2);
    binary_buffer[0] = '0';
    binary_buffer[1] = '0';
    strcpy(binary, binary_buffer);
    return binary;
  }

  if (binary_rem == 2) {
    char binary_buffer[1000];
    memmove(binary_buffer + 1, binary, strlen(binary) + 1);
    binary_buffer[0] = '0';
    strcpy(binary, binary_buffer);
    return binary;
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
  char *binary = zero_adder(binary_input);
  static char binary_buffer[1000];
  memset(binary_buffer, 0, sizeof(char) * 1000);
  memmove(binary_buffer, binary, strlen(binary));

  char binary_group[4] = "";
  static char current_binary[1];
  static char octal[1000];
  memset(octal, 0, sizeof(char) * 1000);

  for (size_t i = 0; i <= strlen(binary_buffer); i++) {
    *current_binary = binary_buffer[i];

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

  // e.g. -1000 = -10
  if (is_negative_binary(binary_input)) {
    char *positive_binary = malloc(sizeof(char) * 1000);
    memmove(positive_binary, binary_input + 1, strlen(binary_input));

    char *p_octal = get_octal(positive_binary);
    display_octal(p_octal, 1);

    free(positive_binary);
    return;
  }

  // e.g. 1000.1111 = 10.74
  if (is_positive_binary_with_dot(binary_input)) {
    printf("Hello");
    add_new_line(2);
    return;
  }
}
