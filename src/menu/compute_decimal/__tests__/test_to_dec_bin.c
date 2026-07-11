#include <assert.h>
#include "../../../utils/utils.h"
#include "../to_dec_bin.c"

void test_to_dec_bin(void) {
  text_white("[ Testing to_dec_bin Functions ]", 10);
  add_new_line(1);

  char dec_input[5];
  memmove(dec_input, "123", sizeof(char) * 4);
  assert(strcmp(_get_dec_bin(dec_input), "1111011") == 0);
  text_green("_get_dec_bin -> should return 1111011 for 123 inputs", 10);
  add_new_line(1);

  char dec_dot_input[5];
  memmove(dec_dot_input, "123", sizeof(char) * 4);
  assert(strcmp(_get_dec_bin_with_dot(dec_dot_input), "00011111") == 0);
  text_green("_get_dec_bin_with_dot -> should return 00011111 for 123 inputs", 10);
}
