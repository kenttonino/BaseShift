#include <stdio.h>
#include <string.h>
#include "../../utils/utils.h"
#include "../helper/helper.h"

char *_bin_hex_zero_adder(char* bin_input) {
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

char *_bin_hex_zero_adder_radixp(char *bin_input) {
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

char *_bin_hex_mapper(char *bin_group) {
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

GenericInput _get_bin_hex_generic_input(char *bin) {
  static char bin_buffer[1000];
  memset(bin_buffer, 0, sizeof(char) * 1000);
  memmove(bin_buffer, bin, strlen(bin));

  static char bin_before_radixp[1000];
  static char bin_after_radixp[1000];
  memset(bin_before_radixp, 0, sizeof(char) * 1000);
  memset(bin_after_radixp, 0, sizeof(char) * 1000);

  int is_after_radixp = 0;
  int counter_before_radixp = 0;
  int counter_after_radixp = 0;
  for (int i = 0; bin[i] != '\0'; i++) {
    if (bin[i] == '.') {
      is_after_radixp = 1;
      continue;
    }

    if (is_after_radixp) {
      bin_after_radixp[counter_after_radixp++] = bin[i];
      continue;
    } else {
      bin_before_radixp[counter_before_radixp++] = bin[i];
    }
  }

  bin_before_radixp[counter_before_radixp] = '\0';
  bin_after_radixp[counter_after_radixp] = '\0';

  GenericInput generic_input;
  generic_input.before_radixp = _bin_hex_zero_adder(bin_before_radixp);
  generic_input.after_radixp = _bin_hex_zero_adder_radixp(bin_after_radixp);

  return generic_input;
}

char *_get_bin_hex(char *bin_input) {
  char *bin = _bin_hex_zero_adder(bin_input);

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
      strcat(hex, _bin_hex_mapper(bin_group));

      memset(bin_group, 0, sizeof(char) * 5);
      strcat(bin_group, current_bin);
      memset(current_bin, 0, sizeof(char));
    }
  }

  return hex;
}

void _display_bin_hex(char *hex, int negative) {
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

void to_bin_hex(char *bin_input) {
  // e.g. 1000 = 8
  if (is_positive(bin_input)) {
    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, bin_input);

    char *hex = _get_bin_hex(bin);
    _display_bin_hex(hex, 0);

    free(bin);
    return;
  }

  if (is_positive_radixp(bin_input)) {
    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, bin_input);
    GenericInput generic_input = _get_bin_hex_generic_input(bin);

    char *bin_before_radixp = malloc(sizeof(char) * 1000);
    char *bin_after_radixp = malloc(sizeof(char) * 1000);
    strcpy(bin_before_radixp, generic_input.before_radixp);
    strcpy(bin_after_radixp, generic_input.after_radixp);

    char *hex = malloc(sizeof(char) * 1000);
    strcpy(hex, _get_bin_hex(bin_before_radixp));
    strcat(hex, ".");
    strcat(hex, _get_bin_hex(bin_after_radixp));
    _display_bin_hex(hex, 0);

    free(bin);
    free(bin_before_radixp);
    free(bin_after_radixp);
    free(hex);
    return;
  }

  if (is_negative(bin_input)) {
    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, bin_input);

    char *positive_bin = malloc(sizeof(char) * 1000);
    memmove(positive_bin, bin + 1, strlen(bin));

    char *hex = _get_bin_hex(positive_bin);
    _display_bin_hex(hex, 1);

    free(bin);
    free(positive_bin);
    return;
  }

  if (is_negative_radixp(bin_input)) {
    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, bin_input);

    char *positive_bin = malloc(sizeof(char) * 1000);
    memmove(positive_bin, bin + 1, strlen(bin));
    GenericInput generic_input = _get_bin_hex_generic_input(positive_bin);

    char *bin_before_radixp = malloc(sizeof(char) * 1000);
    char *bin_after_radixp = malloc(sizeof(char) * 1000);
    strcpy(bin_before_radixp, generic_input.before_radixp);
    strcpy(bin_after_radixp, generic_input.after_radixp);

    char *hex = malloc(sizeof(char) * 1000);
    strcpy(hex, _get_bin_hex(bin_before_radixp));
    strcat(hex, ".");
    strcat(hex, _get_bin_hex(bin_after_radixp));
    _display_bin_hex(hex, 1);

    free(bin);
    free(positive_bin);
    free(bin_before_radixp);
    free(bin_after_radixp);
    free(hex);
    return;
  }
}
