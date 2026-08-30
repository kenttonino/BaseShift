#include "../helper/helper.h"
#include "../../utils/utils.h"

char* _get_oct_hex(char* oct) {
  printf("oct: %s", oct);
  add_new_line(1);
  return "53";
};

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

    char* hex = _get_oct_hex(hex);
    _display_oct_hex(hex, 0);

    free(oct);
    return;
  }
}
