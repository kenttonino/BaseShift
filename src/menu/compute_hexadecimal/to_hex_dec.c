#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../helper/helper.h"
#include "../../utils/utils.h"

char* _get_hex_to_dec(char* hex) {
  int hex_len = strlen(hex);
  int exponent = hex_len - 1;

  int dec = 0;
  static char current_hex[2];
  memset(current_hex, 0, sizeof(char) * 2);
  for (int i = 0; i < hex_len; i++) {
    current_hex[0] = hex[i];
    int hex_digit = map_hex_dec(current_hex);
    dec = dec + (hex_digit * pow(16, exponent));
    exponent = exponent - 1;
    memset(current_hex, 0, sizeof(char) * 2);
  }


  static char dec_string[1000];
  memset(dec_string, 0, sizeof(char) * 1000);
  sprintf(dec_string, "%d", dec);

  return dec_string;
}

char* _get_hex_to_dec_radixp(char* hex) {
  int hex_len = strlen(hex);
  int exponent = -1;

  double dec = 0;
  static char current_hex[2];
  memset(current_hex, 0, sizeof(char) * 2);
  for (int i = 0; i < hex_len; i++) {
    current_hex[0] = hex[i];
    int hex_digit = map_hex_dec(current_hex);
    dec = dec + (hex_digit * pow(16, exponent));
    exponent = exponent - 1;
    memset(current_hex, 0, sizeof(char) * 2);
  }

  static char dec_string[1000];
  memset(dec_string, 0, sizeof(char) * 1000);
  sprintf(dec_string, "%f", dec);

  return dec_string;
}

char* _get_hex_to_dec_sum(char* dec_before_radixp, char* dec_after_radixp) {
  int int_dec = atoi(dec_before_radixp);
  double double_dec = atof(dec_after_radixp);
  double total = int_dec + double_dec;

  static char dec_sum[1000];
  memset(dec_sum, 0, sizeof(char) * 1000);
  sprintf(dec_sum, "%f", total);
  return dec_sum;
}

void _display_hex_dec(char *dec, int negative) {
  char neg_dec[1000] = "-";
  strcat(neg_dec, dec);

  printf(
      "%-16s[%s %sDecimal%s %s]%s : %s%s%s",
      BLUE,
      RESET,
      GREEN,
      RESET,
      BLUE,
      RESET,
      YELLOW,
      negative == 1 ? neg_dec : dec,
      RESET
  );
}

void to_hex_dec(char* hex_input) {
  ZeroPrefix zero_prefix = is_zero_only(hex_input);
  if (zero_prefix.zero_only == 1) {
    _display_hex_dec("0", 0);
    return;
  }

  if (is_positive(hex_input)) {
    char* hex = malloc(sizeof(char) * 1000);
    strcpy(hex, hex_input);

    char* dec = _get_hex_to_dec(hex);
    _display_hex_dec(dec, 0);

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

    char* dec_before_radixp = _get_hex_to_dec(before_radixp);
    char* dec_after_radixp = _get_hex_to_dec_radixp(after_radixp);
    char* dec_sum = _get_hex_to_dec_sum(dec_before_radixp, dec_after_radixp);
    _display_hex_dec(dec_sum, 0);

    free(hex);
    free(before_radixp);
    free(after_radixp);
    return;
  }

  if (is_negative(hex_input)) {
    char* hex = malloc(sizeof(char) * 1000);
    strcpy(hex, hex_input);
    char* positive_hex = malloc(sizeof(char) * 1000);
    memmove(positive_hex, hex + 1, strlen(hex));

    char* dec = _get_hex_to_dec(positive_hex);
    _display_hex_dec(dec, 1);

    free(hex);
    free(positive_hex);
    return;
  }

  if (is_negative_radixp(hex_input)) {
    char* hex = malloc(sizeof(char) * 1000);
    strcpy(hex, hex_input);
    char* positive_hex = malloc(sizeof(char) * 1000);
    memmove(positive_hex, hex + 1, strlen(hex));
    GenericInput generic_input = get_generic_input(positive_hex);

    char* before_radixp = malloc(sizeof(char) * 1000);
    char* after_radixp = malloc(sizeof(char) * 1000);
    strcpy(before_radixp, generic_input.before_radixp);
    strcpy(after_radixp, generic_input.after_radixp);

    char* dec_before_radixp = _get_hex_to_dec(before_radixp);
    char* dec_after_radixp = _get_hex_to_dec_radixp(after_radixp);
    char* dec_sum = _get_hex_to_dec_sum(dec_before_radixp, dec_after_radixp);
    _display_hex_dec(dec_sum, 1);

    free(hex);
    free(positive_hex);
    free(before_radixp);
    free(after_radixp);
    return;
  }
}
