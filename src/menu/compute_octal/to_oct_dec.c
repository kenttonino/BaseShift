#include "../helper/helper.h"
#include "../../utils/utils.h"

void _display_oct_dec(char *dec, int negative) {
  char neg_dec[1000] = "-";
  strcat(neg_dec, dec);

  printf(
      "%-16s[%s %sDeciaml%s %s]%s : %s%s%s",
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

void to_oct_dec(char* oct_input) {
  if (is_positive(oct_input)) {
    char* oct = malloc(sizeof(char) * 1000);
    strcpy(oct, oct_input);
    printf("%s", oct);
    add_new_line(1);

    _display_oct_dec("83", 0);

    free(oct);
    return;
  }
}
