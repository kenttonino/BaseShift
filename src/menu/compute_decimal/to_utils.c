#include <string.h>
#include "../helper/helper.h"

char *_dec_radixp_adder(char* dec_after_radixp) {
  char dec_buffer[1000];
  memset(dec_buffer, 0, sizeof(char) * 1000);
  memmove(dec_buffer + 2, dec_buffer, strlen(dec_after_radixp) + 2);
  dec_buffer[0] = '0';
  dec_buffer[1] = '.';
  strcat(dec_buffer, dec_after_radixp);
  strcpy(dec_after_radixp, dec_buffer);
  return dec_after_radixp;
}

GenericInput _get_dec_generic_input(char* dec) {
  static char dec_buffer[1000];
  memset(dec_buffer, 0, sizeof(char) * 1000);
  memmove(dec_buffer, dec, strlen(dec));

  static char dec_before_radixp[1000];
  static char dec_after_radixp[1000];
  memset(dec_before_radixp, 0, sizeof(char) * 1000);
  memset(dec_after_radixp, 0, sizeof(char) * 1000);

  int is_after_radixp = 0;
  int counter_before_radixp = 0;
  int counter_after_radixp = 0;
  for (int i = 0; dec[i] != '\0'; i++) {
    if (dec[i] == '.') {
      is_after_radixp = 1;
      continue;
    }

    if (is_after_radixp) {
      dec_after_radixp[counter_after_radixp++] = dec[i];
      continue;
    } else {
      dec_before_radixp[counter_before_radixp++] = dec[i];
    }
  }

  dec_before_radixp[counter_before_radixp] = '\0';
  dec_after_radixp[counter_after_radixp] = '\0';

  GenericInput generic_input;
  generic_input.before_radixp = dec_before_radixp;
  generic_input.after_radixp = dec_after_radixp;

  return generic_input;
}
