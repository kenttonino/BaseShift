#include "../helper/helper.h"
#include "../../utils/utils.h"
#include "./utils.h"

// Add zero to make it divisible by 4.
// Used the binaries mapped from octal values.
void _get_oct_hex_zero_adder(char* oct_bin) {
  int oct_bin_len = strlen(oct_bin);
  int oct_bin_mod = oct_bin_len % 4;
  static char temp_oct_bin[1000];
  memset(temp_oct_bin, 0, sizeof(char) * 1000);

  if (oct_bin_mod == 1) {
    temp_oct_bin[0] = '0';
    temp_oct_bin[1] = '0';
    temp_oct_bin[2] = '0';
    strcat(temp_oct_bin, oct_bin);
    strcpy(oct_bin, temp_oct_bin);
    return;
  }

  if (oct_bin_mod == 2) {
    temp_oct_bin[0] = '0';
    temp_oct_bin[1] = '0';
    strcat(temp_oct_bin, oct_bin);
    strcpy(oct_bin, temp_oct_bin);
    return;
  }

  if (oct_bin_mod == 3) {
    temp_oct_bin[0] = '0';
    strcat(temp_oct_bin, oct_bin);
    strcpy(oct_bin, temp_oct_bin);
    return;
  }

  return;
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
  // _get_oct_hex_zero_adder(oct_bin);
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
  if (is_positive(oct_input)) {
    char* oct = malloc(sizeof(char) * 1000);
    strcpy(oct, oct_input);

    char* hex = _get_oct_hex(oct);
    _display_oct_hex(hex, 0);

    free(oct);
    return;
  }
}
