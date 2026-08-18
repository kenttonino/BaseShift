#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../helper/helper.h"
#include "../../utils/utils.h"

char* _oct_bin_mapper(char* oct_digit) {
  if (strcmp(oct_digit, "1") == 0) return "001";
  if (strcmp(oct_digit, "2") == 0) return "010";
  if (strcmp(oct_digit, "3") == 0) return "011";
  if (strcmp(oct_digit, "4") == 0) return "100";
  if (strcmp(oct_digit, "5") == 0) return "101";
  if (strcmp(oct_digit, "6") == 0) return "110";
  if (strcmp(oct_digit, "7") == 0) return "111";
  return "000";
}

char* _get_oct_bin(char* oct) {
  static char bin[1000];
  memset(bin, 0, sizeof(char) * 1000);
  int oct_len = strlen(oct);
  static char current_oct[2];
  memset(current_oct, 0, sizeof(char) * 2);

  for (int i = 0; i < oct_len; i++) {
    current_oct[0] = oct[i];
    current_oct[1] = '\0';
    char* current_bin = _oct_bin_mapper(current_oct);
    strcat(bin, current_bin);
  }

  return bin;
}

void _display_oct_bin(char *bin, int negative) {
  char neg_bin[1000] = "-";
  strcat(neg_bin, bin);

  printf(
      "%-16s[%s %sBinary%s %s]%s : %s%s%s",
      BLUE,
      RESET,
      GREEN,
      RESET,
      BLUE,
      RESET,
      YELLOW,
      negative == 1 ? neg_bin : bin,
      RESET
  );
}

void to_oct_bin(char* oct_input) {
  if (strlen(oct_input) == 1 && strcmp(oct_input, "0") == 0) {
    _display_oct_bin("0", 0);
    return;
  }

  if (strlen(oct_input) == 1 && strcmp(oct_input, "-") == 0) {
    _display_oct_bin("0", 0);
    return;
  }

  if (is_positive(oct_input)) {
    char* oct = malloc(sizeof(char) * 1000);
    strcpy(oct, oct_input);

    char* bin = _get_oct_bin(oct);

    _display_oct_bin(bin, 0);

    free(oct);
    return;
  }

  if (is_negative(oct_input)) {
    char* oct = malloc(sizeof(char) * 1000);
    strcpy(oct, oct_input);

    char* positive_oct = malloc(sizeof(char) * 1000);
    memmove(positive_oct, oct + 1, strlen(oct));

    char* bin = _get_oct_bin(positive_oct);
    _display_oct_bin(bin, 1);

    free(oct);
    free(positive_oct);
    return;
  }
}
