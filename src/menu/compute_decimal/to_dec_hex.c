#include "../../utils/utils.h"
#include "../helper/helper.h"

char* _get_dec_hex(char* dec) {
  printf("%s", dec);
  add_new_line(1);

  return "7B";
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
}
