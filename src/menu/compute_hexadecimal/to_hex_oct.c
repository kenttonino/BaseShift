#include <string.h>
#include <stdio.h>
#include "../helper/helper.h"
#include "../../utils/utils.h"

// Map the hex character to equivalent 4 digits binary.
void _stage_one(char* hex, char* hex_bin, char* current_hex) {
  int hex_len = strlen(hex);
  for (int i = 0; i < hex_len; i++) {
    current_hex[0] = hex[i];
    char* current_hex_bin = map_hex_bin(current_hex);
    if (strlen(hex_bin) == 0) {
      strcpy(hex_bin, current_hex_bin);
    } else {
      strcat(hex_bin, current_hex_bin);
    }

    memset(current_hex, 0, sizeof(char) * 2);
  }
}

void _stage_two(char* hex_bin, char* oct_bin) {
  int hex_bin_len = strlen(hex_bin);
  int hex_bin_reminder = hex_bin_len % 3;
  memset(oct_bin, 0, sizeof(char) * 1000);
  if (hex_bin_reminder == 1) {
    oct_bin[0] = '0';
    oct_bin[1] = '0';
    strcat(oct_bin, hex_bin);
  }
  if (hex_bin_reminder == 2) {
    oct_bin[0] = '0';
    strcat(oct_bin, hex_bin);
  }
  if (hex_bin_reminder == 0) {
    strcpy(oct_bin, hex_bin);
  }
}

void _stage_three(char* oct, char* oct_group, char* oct_bin) {
  int oct_bin_len = strlen(oct_bin);
  int counter = 0;
  for (int i = 0; i <= oct_bin_len; i++) {
    if (counter == 3) {
      char* current_oct = map_bin_oct(oct_group);
      if (strlen(oct) == 0) {
        strcpy(oct, current_oct);
      } else {
        strcat(oct, current_oct);
      }

      memset(oct_group, 0, sizeof(char) * 4);
      oct_group[0] = oct_bin[i];
      counter = 1;
    } else {
      oct_group[counter] = oct_bin[i];
      counter = counter + 1;
    }
  }
}

char* _get_hex_to_oct(char* hex) {
  static char hex_bin[1000];
  static char current_hex[2];
  memset(hex_bin, 0, sizeof(char) * 1000);
  memset(hex_bin, 0, sizeof(char) * 1000);
  _stage_one(hex, hex_bin, current_hex);

  static char oct_bin[1000];
  memset(oct_bin, 0, sizeof(char) * 1000);
  _stage_two(hex_bin, oct_bin);

  static char oct[1000];
  static char oct_group[4];
  memset(oct, 0, sizeof(char) * 1000);
  memset(oct_group, 0, sizeof(char) * 4);
  _stage_three(oct, oct_group, oct_bin);

  // Stage 4 = If index zero of octal is zero character, remove it.
  if (oct[0] == '0') {
    memmove(oct, oct + 1, strlen(oct));
  }


  return oct;
}

void _display_hex_oct(char *oct, int negative) {
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

void to_hex_oct(char* hex_input) {
  ZeroPrefix zero_prefix = is_zero_only(hex_input);
  if (zero_prefix.zero_only == 1) {
    _display_hex_oct("0", 0);
    return;
  }

  if (is_positive(hex_input)) {
    char* hex = malloc(sizeof(char) * 1000);
    strcpy(hex, hex_input);

    char* oct = _get_hex_to_oct(hex);
    _display_hex_oct(oct, 0);

    free(hex);
    return;
  }

  if (is_negative(hex_input)) {
    char* hex = malloc(sizeof(char) * 1000);
    strcpy(hex, hex_input);
    char* positive_hex = malloc(sizeof(char) * 1000);
    memmove(positive_hex, hex + 1, strlen(hex));

    char* oct = _get_hex_to_oct(positive_hex);
    _display_hex_oct(oct, 1);

    free(hex);
    free(positive_hex);
    return;
  }

  _display_hex_oct("TODO", 0);
  return;
}
