#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../helper/helper.h"
#include "../../utils/utils.h"
#include "./utils.h"

char* _get_oct_bin(char* oct) {
  static char bin[1000];
  memset(bin, 0, sizeof(char) * 1000);
  int oct_len = strlen(oct);
  static char current_oct[2];
  memset(current_oct, 0, sizeof(char) * 2);

  for (int i = 0; i < oct_len; i++) {
    current_oct[0] = oct[i];
    current_oct[1] = '\0';
    char* current_bin = get_oct_bin_mapper(current_oct);
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

  if (is_positive_radixp(oct_input))  {
    char* oct = malloc(sizeof(char) * 1000);
    strcpy(oct, oct_input);
    GenericInput generic_input = get_generic_input(oct);

    char* before_radixp = malloc(sizeof(char) * 1000);
    char* after_radixp = malloc(sizeof(char) * 1000);
    strcpy(before_radixp, generic_input.before_radixp);
    strcpy(after_radixp, generic_input.after_radixp);

    char* bin = malloc(sizeof(char) * 1000);
    strcpy(bin, _get_oct_bin(before_radixp));
    strcat(bin, ".");
    strcat(bin, _get_oct_bin(after_radixp));
    _display_oct_bin(bin, 0);

    free(oct);
    free(before_radixp);
    free(after_radixp);
    free(bin);
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

  if (is_negative_radixp(oct_input)) {
    char* oct = malloc(sizeof(char) * 1000);
    strcpy(oct, oct_input);

    char* positive_oct = malloc(sizeof(char) * 1000);
    memmove(positive_oct, oct + 1, strlen(oct));
    GenericInput generic_input = get_generic_input(positive_oct);

    char* before_radixp = malloc(sizeof(char) * 1000);
    char* after_radixp = malloc(sizeof(char) * 1000);
    strcpy(before_radixp, generic_input.before_radixp);
    strcpy(after_radixp, generic_input.after_radixp);

    char* bin = malloc(sizeof(char) * 1000);
    strcpy(bin, _get_oct_bin(before_radixp));
    strcat(bin, ".");
    strcat(bin, _get_oct_bin(after_radixp));
    _display_oct_bin(bin, 1);

    free(oct);
    free(positive_oct);
    free(before_radixp);
    free(after_radixp);
    free(bin);
    return;
  }
}
