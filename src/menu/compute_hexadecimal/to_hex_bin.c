#include <string.h>
#include <stdio.h>
#include "../helper/helper.h"
#include "../../utils/utils.h"

char* _get_hex_to_bin(char* hex) {
  int hex_len = strlen(hex);
  static char bin[1000];
  static char current_hex[2];
  memset(bin, 0, sizeof(char) * 1000);
  memset(current_hex, 0, sizeof(char) * 2);
  for (int i = 0; i < hex_len; i++) {
    current_hex[0] = hex[i];
    char* current_bin = map_hex_bin(current_hex);
    if (strlen(bin) == 0) {
      strcpy(bin, current_bin);
    } else {
      strcat(bin, current_bin);
    }

    memset(current_hex, 0, sizeof(char) * 2);
  }


  return bin;
}

void _display_hex_bin(char *bin, int negative) {
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

void to_hex_bin(char* hex_input) {
  ZeroPrefix zero_prefix = is_zero_only(hex_input);
  if (zero_prefix.zero_only == 1) {
    _display_hex_bin("0", 0);
    return;
  }

  if (is_positive(hex_input)) {
    char* hex = malloc(sizeof(char) * 1000);
    strcpy(hex, hex_input);

    char* bin = _get_hex_to_bin(hex);
    _display_hex_bin(bin, 0);

    free(hex);
    return;
  }

  if (is_positive_radixp(hex_input)) {
    char* hex = malloc(sizeof(char) * 1000);
    strcpy(hex, hex_input);
    GenericInput generic_input = get_generic_input(hex);

    char* before_radixp = malloc(sizeof(char) * 1000);
    char* after_radixp = malloc(sizeof(char) * 1000);
    strcpy(before_radixp, generic_input.before_radixp);
    strcpy(after_radixp, generic_input.after_radixp);

    char* bin = malloc(sizeof(char) * 1000);
    strcpy(bin, _get_hex_to_bin(before_radixp));
    strcat(bin, ".");
    strcat(bin, _get_hex_to_bin(after_radixp));
    _display_hex_bin(bin, 0);

    free(hex);
    free(before_radixp);
    free(after_radixp);
    free(bin);
    return;
  }

  if (is_negative(hex_input)) {
    char* hex = malloc(sizeof(char) * 1000);
    strcpy(hex, hex_input);
    char* positive_hex = malloc(sizeof(char) * 1000);
    memmove(positive_hex, hex + 1, strlen(hex));

    char* bin = _get_hex_to_bin(positive_hex);
    _display_hex_bin(bin, 1);

    free(hex);
    free(positive_hex);
    return;
  }
}
