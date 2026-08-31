#include "../helper/helper.h"
#include "../../utils/utils.h"

char* _oct_bin_converter(char* oct) {
  if (strcmp(oct, "1") == 0) return "001";
  if (strcmp(oct, "2") == 0) return "010";
  if (strcmp(oct, "3") == 0) return "011";
  if (strcmp(oct, "4") == 0) return "100";
  if (strcmp(oct, "5") == 0) return "101";
  if (strcmp(oct, "6") == 0) return "110";
  if (strcmp(oct, "7") == 0) return "111";
  return "000";
}

char* _get_oct_hex(char* oct) {
  int oct_len = strlen(oct);
  static char oct_bin[1000];
  static char current_oct[2];
  memset(oct_bin, 0, sizeof(char) * 1000);
  memset(current_oct, 0, sizeof(char) * 2);
  for (int i = 0; i < oct_len; i++) {
    current_oct[0] = oct[i];
    char* bin = _oct_bin_converter(current_oct);
    strcat(oct_bin, bin);
  }

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
