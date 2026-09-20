#include "../helper/helper.h"
#include "../../utils/utils.h"
#include "./utils.h"

// Add zero to make it divisible by 4.
// Used the binaries mapped from octal values.
char* _get_oct_hex_zero_adder(char* oct_bin) {
  int oct_bin_len = strlen(oct_bin);
  int oct_bin_mod = oct_bin_len % 4;

  if (oct_bin_mod == 1) {
    char temp_oct_bin[1000];
    memset(temp_oct_bin, 0, sizeof(char) * 1000);
    temp_oct_bin[0] = '0';
    temp_oct_bin[1] = '0';
    temp_oct_bin[2] = '0';
    strcat(temp_oct_bin, oct_bin);
    strcpy(oct_bin, temp_oct_bin);
    return oct_bin;
  }

  if (oct_bin_mod == 2) {
    char temp_oct_bin[1000];
    memset(temp_oct_bin, 0, sizeof(char) * 1000);
    temp_oct_bin[0] = '0';
    temp_oct_bin[1] = '0';
    strcat(temp_oct_bin, oct_bin);
    strcpy(oct_bin, temp_oct_bin);
    return oct_bin;
  }

  if (oct_bin_mod == 3) {
    char temp_oct_bin[1000];
    memset(temp_oct_bin, 0, sizeof(char) * 1000);
    temp_oct_bin[0] = '0';
    strcat(temp_oct_bin, oct_bin);
    strcpy(oct_bin, temp_oct_bin);
    return oct_bin;
  }

  return oct_bin;
}

char* _get_oct_hex(char* oct) {
  int oct_len = strlen(oct);
  static char oct_bin[1000];
  static char current_oct[2];
  memset(oct_bin, 0, sizeof(char) * 1000);
  memset(current_oct, 0, sizeof(char) * 2);
  for (int i = 0; i < oct_len; i++) {
    current_oct[0] = oct[i];
    char* bin = get_oct_bin_3d_mapper(current_oct);
    strcat(oct_bin, bin);
  }

  // Mutate the oct_bin to make it divisible by 4.
  _get_oct_hex_zero_adder(oct_bin);

  // TODO: Handle the convertion of binaries to hex.
  int counter = 0;
  for (int i = 0; i < strlen(oct_bin); i++) {}
  printf("oct_bin: %s", oct_bin);
  add_new_line(1);

  return "53";
}

void _display_oct_hex(char *hex, int negative) {
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

void to_oct_hex(char* oct_input) {
  ZeroPrefix zero_prefix = is_zero_only(oct_input);
  if (zero_prefix.zero_only == 1) {
    _display_oct_hex("0", 0);
    return;
  }

  if (is_positive(oct_input)) {
    char* oct = malloc(sizeof(char) * 1000);
    strcpy(oct, oct_input);

    char* hex = _get_oct_hex(oct);
    _display_oct_hex(hex, 0);

    free(oct);
    return;
  }
}
