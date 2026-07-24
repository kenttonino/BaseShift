#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../utils/utils.h"
#include "../helper/helper.h"

char * _dec_hex_mapper(char* dec) {
  if (strcmp(dec, "10") == 0) return "A";
  if (strcmp(dec, "11") == 0) return "B";
  if (strcmp(dec, "12") == 0) return "C";
  if (strcmp(dec, "13") == 0) return "D";
  if (strcmp(dec, "14") == 0) return "E";
  if (strcmp(dec, "15") == 0) return "F";
  return dec;
}

char* _get_dec_hex(char* dec) {
  char* dec_int_end_ptr;
  int int_dec = strtol(dec, &dec_int_end_ptr, 10);

  static char hex[1000];
  memset(hex, 0, sizeof(char) * 1000);
  int dividend = int_dec;
  for (;;) {
    if (dividend != 0) {
      int rem = dividend % 16;
      char char_rem[1000];
      sprintf(char_rem, "%d", rem);
      strcat(hex, _dec_hex_mapper(char_rem));
      dividend = dividend / 16;
      continue;
    }

    break;
  }

  return reverse_string(hex);
}

void _display_dec_hex(char *hex, int negative) {
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

void to_dec_hex(char* dec_input) {
  if (is_positive(dec_input)) {
    char* dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);

    char* hex = _get_dec_hex(dec);
    _display_dec_hex(hex, 0);

    free(dec);
    return;
  }

  if (is_positive_with_dot(dec_input)) {
    char* dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);

    printf("dec: %s", dec);
    add_new_line(1);
    _display_dec_hex("7B.1999999A", 0);

    free(dec);
    return;
  }

  if (is_negative(dec_input)) {
    char* dec = malloc(sizeof(char) * 1000);
    strcpy(dec, dec_input);

    char* positive_dec = malloc(sizeof(char) * 1000);
    memcpy(positive_dec, dec_input + 1, strlen(dec_input));

    char* hex = _get_dec_hex(positive_dec);
    _display_dec_hex(hex, 1);

    free(dec);
    free(positive_dec);
    return;
  }
}
