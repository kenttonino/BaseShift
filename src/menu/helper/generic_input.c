#include <string.h>

typedef struct {
  char* before_radixp;
  char* after_radixp;
} GenericInput;

char* radixp_adder(char* after_radixp) {
  char buffer[1000];
  memset(buffer, 0, sizeof(char) * 1000);
  memmove(buffer + 2, buffer, strlen(after_radixp) + 2);
  buffer[0] = '0';
  buffer[1] = '.';
  strcat(buffer, after_radixp);
  strcpy(after_radixp, buffer);
  return after_radixp;
}

GenericInput get_generic_input(char* input) {
  static char buffer[1000];
  memset(buffer, 0, sizeof(char) * 1000);
  memmove(buffer, input, strlen(input));

  static char before_radixp[1000];
  static char after_radixp[1000];
  memset(before_radixp, 0, sizeof(char) * 1000);
  memset(after_radixp, 0, sizeof(char) * 1000);

  int is_after_radixp = 0;
  int counter_before_radixp = 0;
  int counter_after_radixp = 0;
  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] == '.') {
      is_after_radixp = 1;
      continue;
    }

    if (is_after_radixp) {
      after_radixp[counter_after_radixp++] = input[i];
      continue;
    } else {
      before_radixp[counter_before_radixp++] = input[i];
    }
  }

  before_radixp[counter_before_radixp] = '\0';
  after_radixp[counter_after_radixp] = '\0';

  GenericInput generic_input;
  generic_input.before_radixp = before_radixp;
  generic_input.after_radixp = after_radixp;

  return generic_input;
}
