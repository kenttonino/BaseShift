#include <math.h>
#include "../helper/helper.h"
#include "../../utils/utils.h"


char* _get_oct_dec(char* oct) {
  int oct_len = strlen(oct);
  int exponent = oct_len - 1;
  int dec = 0;
  for (int i = 0; i < oct_len; i++) {
    dec = dec + ((oct[i] - '0') * pow(8, exponent));
    exponent = exponent - 1;
  }

  static char sdec[1000];
  memset(sdec, 0, sizeof(char) * 1000);
  sprintf(sdec, "%d", dec);
  return sdec;
}

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

    char* dec = _get_oct_dec(oct);
    _display_oct_dec(dec, 0);

    free(oct);
    return;
  }

  if (is_negative(oct_input)) {
    char* oct = malloc(sizeof(char) * 1000);
    strcpy(oct, oct_input);

    char* positive_oct = malloc(sizeof(char) * 1000);
    memmove(positive_oct, oct + 1, strlen(oct));

    char* dec = _get_oct_dec(positive_oct);
    _display_oct_dec(dec, 1);

    free(oct);
    free(positive_oct);
    return;
  }
}
