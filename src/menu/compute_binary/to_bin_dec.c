#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../utils/utils.h"
#include "../helper/helper.h"

int _get_bin_dec(char *bin_input) {
  char *reversed_bin_input = reverse_string(bin_input);
  int reversed_bin_length = strlen(reversed_bin_input);
  int dec = 0;

  for (int i = 0; i < reversed_bin_length; i++) {
    // Use the ASCII equivalent.
    // 0 -> 48
    // 1 -> 49
    int current_bin_int = reversed_bin_input[i] - '0';
    dec = dec + (current_bin_int * pow(2, i));
  }

  return dec;
}

double _get_bin_dec_with_dot(char *bin_input) {
  char *bin_before_dot = malloc(strlen(bin_input) + 1);
  char *bin_after_dot = malloc(strlen(bin_input) + 1);
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

  bin_before_dot[counter_before_dot] = '\0';
  bin_after_dot[counter_after_dot] = '\0';

  char *reversed_bin_input = reverse_string(bin_before_dot);
  int reversed_bin_length = strlen(reversed_bin_input);
  double dec = 0;

  for (int i = 0; i < reversed_bin_length; i++) {
    int current_bin_int = reversed_bin_input[i] - '0';
    dec = dec + (current_bin_int * pow(2, i));
  }

  for (int i = 0; i < (int) strlen(bin_after_dot); i++) {
    // Use the ASCII equivalent.
    // 0 -> 48
    // 1 -> 49
    int current_bin_int = bin_after_dot[i] - '0';
    dec += current_bin_int * pow(2, -(i + 1));
  }

  free(bin_before_dot);
  free(bin_after_dot);
  return dec;
}

void _display_bin_dec(char *dec, int negative) {
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

void to_bin_dec(char *bin_input) {
  // E.g. 1000 = 8
  if (is_positive(bin_input)) {
    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, bin_input);

    int dec = _get_bin_dec(bin);
    char dec_string[1000];
    sprintf(dec_string, "%d", dec);
    _display_bin_dec(dec_string, 0);

    free(bin);
    return;
  }

  // E.g. -1000 = -8
  if (is_negative(bin_input)) {
    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, bin_input);

    char *positive_bin = malloc(sizeof(char) * 1000);
    memmove(positive_bin, bin + 1, strlen(bin));

    int dec = _get_bin_dec(positive_bin);
    char dec_string[1000];
    sprintf(dec_string, "%d", dec);
    _display_bin_dec(dec_string, 1);

    free(bin);
    free(positive_bin);
    return;
  }

  // E.g. 1000.1 = 8.500
  if (is_positive_with_dot(bin_input)) {
    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, bin_input);

    double dec = _get_bin_dec_with_dot(bin);
    char dec_string[1000];
    sprintf(dec_string, "%.2f", dec);
    _display_bin_dec(dec_string, 0);

    free(bin);
    return;
  }

  // E.g. -1000.1 = -8.500
  if (is_negative_with_dot(bin_input)) {
    char *bin = malloc(sizeof(char) * 1000);
    strcpy(bin, bin_input);

    char *positive_bin = malloc(sizeof(char) * 1000);
    memmove(positive_bin, bin + 1, strlen(bin));

    double dec = _get_bin_dec_with_dot(positive_bin);
    char dec_string[1000];
    sprintf(dec_string, "%.2f", dec);
    _display_bin_dec(dec_string, 1);

    free(bin);
    free(positive_bin);
    return;
  }
}
