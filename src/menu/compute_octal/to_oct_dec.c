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

char* _get_oct_dec_radixp(char* oct_radixp) {
  int oct_radixp_len = strlen(oct_radixp);
  int exponent = -1;
  double dec_radixp = 0;
  for (int i = 0; i < oct_radixp_len; i++) {
    dec_radixp = dec_radixp + ((oct_radixp[i] - '0') * pow(8, exponent));
    exponent = exponent - 1;
  }

  static char sdec_radixp[1000];
  memset(sdec_radixp, 0, sizeof(char) * 1000);
  sprintf(sdec_radixp, "%f", dec_radixp);
  memmove(sdec_radixp, sdec_radixp + 2, strlen(sdec_radixp));

  return sdec_radixp;
}

void _display_oct_dec(char *dec, int negative) {
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

void to_oct_dec(char* oct_input) {
  if (is_positive(oct_input)) {
    char* oct = malloc(sizeof(char) * 1000);
    strcpy(oct, oct_input);

    char* dec = _get_oct_dec(oct);
    _display_oct_dec(dec, 0);

    free(oct);
    return;
  }

  if (is_positive_radixp(oct_input)) {
    char* oct = malloc(sizeof(char) * 1000);
    strcpy(oct, oct_input);
    GenericInput generic_input = get_generic_input(oct);

    char* before_radixp = malloc(sizeof(char) * 1000);
    char* after_radixp = malloc(sizeof(char) * 1000);
    strcpy(before_radixp, generic_input.before_radixp);
    strcpy(after_radixp, generic_input.after_radixp);

    char* dec = malloc(sizeof(char) * 1000);
    strcpy(dec, _get_oct_dec(before_radixp));
    strcat(dec, ".");
    strcat(dec, _get_oct_dec_radixp(after_radixp));
    _display_oct_dec(dec, 0);

    free(oct);
    free(before_radixp);
    free(after_radixp);
    free(dec);
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

  if (is_negative_radixp(oct_input)) {
    char* oct = malloc(sizeof(char) * 1000);
    strcpy(oct, oct_input);

    char* positive_oct = malloc(sizeof(char) * 1000);
    memmove(positive_oct, oct + 1, strlen(oct));
    GenericInput generic_input = get_generic_input(positive_oct);

    char* before_radixp = malloc(sizeof(char) * 1000);
    char* after_radixp = malloc(sizeof(char) * 1000);
    strcpy(before_radixp, generic_input.before_radixp);
    strcpy(after_radixp, generic_input.after_radixp);

    char* dec = malloc(sizeof(char) * 1000);
    strcpy(dec, _get_oct_dec(before_radixp));
    strcat(dec, ".");
    strcat(dec, _get_oct_dec_radixp(after_radixp));
    _display_oct_dec(dec, 1);

    free(oct);
    free(positive_oct);
    free(before_radixp);
    free(after_radixp);
    free(dec);
    return;
  }
}
