#include <stdio.h>
#include <string.h>
#include "../../utils/utils.h"
#include "./types.h"
#include "../helper/helper.h"

char *_hex_zero_adder(char* bin_input) {
  int bin_len = strlen(bin_input);
  int bin_rem = bin_len % 4;

  if (bin_rem == 1) {
    char bin_buffer[1000];
    memset(bin_buffer, 0, sizeof(char) * 1000);
    memmove(bin_buffer + 3, bin_input, strlen(bin_input) + 3);
    bin_buffer[0] = '0';
    bin_buffer[1] = '0';
    bin_buffer[2] = '0';
    strcpy(bin_input, bin_buffer);
    return bin_input;
  }

  if (bin_rem == 2) {
    char bin_buffer[1000];
    memset(bin_buffer, 0, sizeof(char) * 1000);
    memmove(bin_buffer + 2, bin_input, strlen(bin_input) + 2);
    bin_buffer[0] = '0';
    bin_buffer[1] = '0';
    strcpy(bin_input, bin_buffer);
    return bin_input;
  }

  if (bin_rem == 3) {
    char bin_buffer[1000];
    memset(bin_buffer, 0, sizeof(char) * 1000);
    memmove(bin_buffer + 1, bin_input, strlen(bin_input) + 1);
    bin_buffer[0] = '0';
    strcpy(bin_input, bin_buffer);
    return bin_input;
  }

  return bin_input;
}

char *_hex_zero_adder_with_dot(char *bin_input) {
  int bin_len = strlen(bin_input);
  int bin_rem = bin_len % 4;

  if (bin_rem == 1) {
    char bin_buffer[1000];
    memset(bin_buffer, 0, sizeof(char) * 1000);
    memmove(bin_buffer + 3, bin_input, strlen(bin_input) + 3);
    strcpy(bin_buffer, bin_input);
    strcat(bin_buffer, "000");
    strcpy(bin_input, bin_buffer);
    return bin_input;
  }

  if (bin_rem == 2) {
    char bin_buffer[1000];
    memset(bin_buffer, 0, sizeof(char) * 1000);
    memmove(bin_buffer + 2, bin_input, strlen(bin_input) + 2);
    strcpy(bin_buffer, bin_input);
    strcat(bin_buffer, "00");
    strcpy(bin_input, bin_buffer);
    return bin_input;
  }

  if (bin_rem == 3) {
    char bin_buffer[1000];
    memset(bin_buffer, 0, sizeof(char) * 1000);
    memmove(bin_buffer + 1, bin_input, strlen(bin_input) + 1);
    strcpy(bin_buffer, bin_input);
    strcat(bin_buffer, "0");
    strcpy(bin_input, bin_buffer);
    return bin_input;
  }

  return bin_input;
}

char *_hex_mapper(char *bin_group) {
  if (strcmp(bin_group, "0000") == 0) return "0";
  if (strcmp(bin_group, "0001") == 0) return "1";
  if (strcmp(bin_group, "0010") == 0) return "2";
  if (strcmp(bin_group, "0011") == 0) return "3";
  if (strcmp(bin_group, "0100") == 0) return "4";
  if (strcmp(bin_group, "0101") == 0) return "5";
  if (strcmp(bin_group, "0110") == 0) return "6";
  if (strcmp(bin_group, "0111") == 0) return "7";
  if (strcmp(bin_group, "1000") == 0) return "8";
  if (strcmp(bin_group, "1001") == 0) return "9";
  if (strcmp(bin_group, "1010") == 0) return "A";
  if (strcmp(bin_group, "1011") == 0) return "B";
  if (strcmp(bin_group, "1100") == 0) return "C";
  if (strcmp(bin_group, "1101") == 0) return "D";
  if (strcmp(bin_group, "1110") == 0) return "E";
  if (strcmp(bin_group, "1111") == 0) return "F";
  return "0";
}

SanitizedBinary _get_hex_sanitized_bin(char *bin_input) {
  // Store the binary in new variable.
  static char bin_buffer[1000];
  memset(bin_buffer, 0, sizeof(char) * 1000);
  memmove(bin_buffer, bin_input, strlen(bin_input));

  // Separate the binary values before and after dot.
  static char bin_before_dot[1000];
  static char bin_after_dot[1000];
  memset(bin_before_dot, 0, sizeof(char) * 1000);
  memset(bin_after_dot, 0, sizeof(char) * 1000);

  int is_after_dot = 0;
  int counter_before_dot = 0;
  int counter_after_dot = 0;
  for (int i = 0; bin_input[i] != '\0'; i++) {
    if (bin_input[i] == '.') {
      is_after_dot = 1;
      continue;
    }

    if (is_after_dot) {
      bin_after_dot[counter_after_dot++] = bin_input[i];
      continue;
    } else {
      bin_before_dot[counter_before_dot++] = bin_input[i];
    }
  }

  // Reset to the null terminator to stop reading this variables.
  bin_before_dot[counter_before_dot] = '\0';
  bin_after_dot[counter_after_dot] = '\0';

  SanitizedBinary sanitized_binary;
  sanitized_binary.before_dot = _hex_zero_adder(bin_before_dot);
  sanitized_binary.after_dot = _hex_zero_adder_with_dot(bin_after_dot);

  return sanitized_binary;
}

char *_get_hex(char *bin_input) {
  char *bin = _hex_zero_adder(bin_input);

  char bin_group[5] = "";
  static char current_bin[1];
  static char hex[1000];
  memset(current_bin, 0, sizeof(char));
  memset(hex, 0, sizeof(char) * 1000);

  for (size_t i = 0; i <= strlen(bin); i++) {
    *current_bin = bin[i];

    if (strlen(bin_group) < 4) {
      strcat(bin_group, current_bin);
      memset(current_bin, 0, sizeof(char));
      continue;
    } else {
      strcat(hex, _hex_mapper(bin_group));

      memset(bin_group, 0, sizeof(char) * 5);
      strcat(bin_group, current_bin);
      memset(current_bin, 0, sizeof(char));
    }
  }

  return hex;
}

void _display_hex(char *hex, int negative) {
  char neg_hex[1000] = "-";
  strcat(neg_hex, hex);

  printf(
      "%-16s[%s %sHexadecimal%s %s]%s : %s%s%s",
      BLUE,
      RESET,
      GREEN,
      RESET,
      BLUE,
      RESET,
      YELLOW,
      negative == 1 ? neg_hex : hex,
      RESET
  );
}

void to_hexadecimal(char *bin_input) {
  // e.g. 1000 = 8
  if (is_positive(bin_input)) {
    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, bin_input);

    char *hex = _get_hex(bin);
    _display_hex(hex, 0);

    free(bin);
    return;
  }

  // e.g. 1000.1 = 8.8
  if (is_positive_with_dot(bin_input)) {
    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, bin_input);
    SanitizedBinary sanitized_binary = _get_hex_sanitized_bin(bin);

    char *bin_before_dot = malloc(sizeof(char) * 1000);
    char *bin_after_dot = malloc(sizeof(char) * 1000);
    strcpy(bin_before_dot, sanitized_binary.before_dot);
    strcpy(bin_after_dot, sanitized_binary.after_dot);

    char *hex = malloc(sizeof(char) * 1000);
    strcpy(hex, _get_hex(bin_before_dot));
    strcat(hex, ".");
    strcat(hex, _get_hex(bin_after_dot));
    _display_hex(hex, 0);

    free(bin);
    free(bin_before_dot);
    free(bin_after_dot);
    free(hex);
    return;
  }

  // e.g. -1000 = -8
  if (is_negative(bin_input)) {
    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, bin_input);

    char *positive_bin = malloc(sizeof(char) * 1000);
    memmove(positive_bin, bin + 1, strlen(bin));

    char *hex = _get_hex(positive_bin);
    _display_hex(hex, 1);

    free(bin);
    free(positive_bin);
    return;
  }

  // e.g. -1000.1 = -8.8
  if (is_negative_with_dot(bin_input)) {
    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, bin_input);
    char *positive_bin = malloc(sizeof(char) * 1000);
    memmove(positive_bin, bin + 1, strlen(bin));
    SanitizedBinary sanitized_binary = _get_hex_sanitized_bin(positive_bin);

    char *bin_before_dot = malloc(sizeof(char) * 1000);
    char *bin_after_dot = malloc(sizeof(char) * 1000);
    strcpy(bin_before_dot, sanitized_binary.before_dot);
    strcpy(bin_after_dot, sanitized_binary.after_dot);

    char *hex = malloc(sizeof(char) * 1000);
    strcpy(hex, _get_hex(bin_before_dot));
    strcat(hex, ".");
    strcat(hex, _get_hex(bin_after_dot));
    _display_hex(hex, 1);

    free(bin);
    free(positive_bin);
    free(bin_before_dot);
    free(bin_after_dot);
    free(hex);
    return;
  }
}
