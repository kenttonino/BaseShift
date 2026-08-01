#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../helper/helper.h"
#include "../../utils/utils.h"

char* _bin_oct_zero_adder(char *bin_input) {
  int bin_len = strlen(bin_input);
  int bin_rem = bin_len % 3;

  if (bin_rem == 1) {
    char bin_buffer[1000];
    memset(bin_buffer, 0, sizeof(char) * 1000);
    memmove(bin_buffer + 2, bin_input, strlen(bin_input) + 2);
    bin_buffer[0] = '0';
    bin_buffer[1] = '0';
    strcpy(bin_input, bin_buffer);
    return bin_input;
  }

  if (bin_rem == 2) {
    char bin_buffer[1000];
    memset(bin_buffer, 0, sizeof(char) * 1000);
    memmove(bin_buffer + 1, bin_input, strlen(bin_input) + 1);
    bin_buffer[0] = '0';
    strcpy(bin_input, bin_buffer);
    return bin_input;
  }

  return bin_input;
}

char *_bin_oct_zero_adder_radixp(char *bin_input) {
  int bin_len = strlen(bin_input);
  int bin_rem = bin_len % 3;

  if (bin_rem == 1) {
    char bin_buffer[1000];
    memset(bin_buffer, 0, sizeof(char) * 1000);
    memmove(bin_buffer + 2, bin_input, strlen(bin_input) + 2);
    strcpy(bin_buffer, bin_input);
    strcat(bin_buffer, "00");
    strcpy(bin_input, bin_buffer);
    return bin_input;
  }

  if (bin_rem == 2) {
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


GenericInput _get_bin_oct_generic_input(char *bin) {
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
  generic_input.before_radixp = _bin_oct_zero_adder(bin_before_radixp);
  generic_input.after_radixp = _bin_oct_zero_adder_radixp(bin_after_radixp);

  return generic_input;
}

char *_bin_oct_mapper(char *bin_group) {
  if (strcmp(bin_group, "001") == 0) return "1";
  if (strcmp(bin_group, "010") == 0) return "2";
  if (strcmp(bin_group, "011") == 0) return "3";
  if (strcmp(bin_group, "100") == 0) return "4";
  if (strcmp(bin_group, "101") == 0) return "5";
  if (strcmp(bin_group, "110") == 0) return "6";
  if (strcmp(bin_group, "111") == 0) return "7";
  return "0";
}

char *_get_bin_oct(char *bin_input) {
  char *bin = _bin_oct_zero_adder(bin_input);

  char bin_group[4] = "";
  static char current_bin[1];
  static char oct[1000];
  memset(current_bin, 0, sizeof(char));
  memset(oct, 0, sizeof(char) * 1000);

  for (size_t i = 0; i <= strlen(bin); i++) {
    *current_bin = bin[i];

    if (strlen(bin_group) < 3) {
      strcat(bin_group, current_bin);
      memset(current_bin, 0, sizeof(char));
      continue;
    } else {
      // Push the oct value of first 3 bin digits.
      strcat(oct, _bin_oct_mapper(bin_group));

      // Reset bin group and assign value for index 0;
      memset(bin_group, 0, sizeof(char) *3);
      strcat(bin_group, current_bin);

      // Reset the current_bin for next iteration.
      memset(current_bin, 0, sizeof(char));
    }
  }

  return oct;
}


void _display_bin_oct(char *oct, int negative) {
  char neg_oct[1000] = "-";
  strcat(neg_oct, oct);

  printf(
      "%-16s[%s %sOctal%s %s]%s : %s%s%s",
      BLUE,
      RESET,
      GREEN,
      RESET,
      BLUE,
      RESET,
      YELLOW,
      negative == 1 ? neg_oct : oct,
      RESET
  );
}

void to_bin_oct(char *bin_input) {
  if (strlen(bin_input) == 1 && strcmp(bin_input, "-")) {
    _display_bin_oct("0", 0);
    return;
  }

  if (is_positive(bin_input)) {
    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, bin_input);

    char *p_oct = _get_bin_oct(bin);
    _display_bin_oct(p_oct, 0);

    free(bin);
    return;
  }

  if (is_negative(bin_input)) {
    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, bin_input);

    char *positive_bin = malloc(sizeof(char) * 1000);
    memmove(positive_bin, bin + 1, strlen(bin));

    char *p_oct = _get_bin_oct(positive_bin);
    _display_bin_oct(p_oct, 1);

    free(bin);
    free(positive_bin);
    return;
  }

  if (is_positive_radixp(bin_input)) {
    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, bin_input);
    GenericInput generic_input = _get_bin_oct_generic_input(bin);

    char *bin_before_radixp = malloc(sizeof(char) * 1000);
    char *bin_after_radixp = malloc(sizeof(char) * 1000);
    strcpy(bin_before_radixp, generic_input.before_radixp);
    strcpy(bin_after_radixp, generic_input.after_radixp);

    char *oct = malloc(sizeof(char) * 1000);
    strcpy(oct, _get_bin_oct(bin_before_radixp));
    strcat(oct, ".");
    strcat(oct, _get_bin_oct(bin_after_radixp));
    _display_bin_oct(oct, 0);

    free(bin);
    free(oct);
    free(bin_before_radixp);
    free(bin_after_radixp);
    return;
  }

  if (is_negative_radixp(bin_input)) {
    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, bin_input);

    char *positive_bin = malloc(sizeof(char) * 1000);
    memmove(positive_bin, bin + 1, strlen(bin));
    GenericInput generic_input = _get_bin_oct_generic_input(positive_bin);

    char *bin_before_radixp = malloc(sizeof(char) * 1000);
    char *bin_after_radixp = malloc(sizeof(char) * 1000);
    strcpy(bin_before_radixp, generic_input.before_radixp);
    strcpy(bin_after_radixp, generic_input.after_radixp);

    char *oct = malloc(sizeof(char) * 1000);
    strcpy(oct, _get_bin_oct(bin_before_radixp));
    strcat(oct, ".");
    strcat(oct, _get_bin_oct(bin_after_radixp));
    _display_bin_oct(oct, 1);

    free(bin);
    free(positive_bin);
    free(oct);
    free(bin_before_radixp);
    free(bin_after_radixp);
    return;
  }
}
