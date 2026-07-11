#include <assert.h>
#include "../../../utils/utils.h"
#include "../to_dec_bin.c"

void test_to_dec_bin(void) {
  text_white("[ Testing to_dec_bin Functions ]", 10);
  add_new_line(1);

  char dot_adder_input[5];
  memmove(dot_adder_input, "123", sizeof(char) * 4);
  assert(strcmp(_dec_bin_dot_adder(dot_adder_input), "0.123") == 0);
  text_green("_dec_bin_dot_adder -> should return 0.123 for 123 inputs", 10);
  add_new_line(1);

  char dec_input[5];
  memmove(dec_input, "123", sizeof(char) * 4);
  assert(strcmp(_get_bin(dec_input), "1111011") == 0);
  text_green("_get_bin -> should return 1111011 for 123 inputs", 10);
  add_new_line(1);

  char dec_dot_input[5];
  memmove(dec_dot_input, "123", sizeof(char) * 4);
  assert(strcmp(_get_bin_with_dot(dec_dot_input), "00011111") == 0);
  text_green("_get_bin_with_dot -> should return 00011111 for 123 inputs", 10);
  add_new_line(1);

  char dotted_decimal_input[8];
  memmove(dotted_decimal_input, "123.123", sizeof(char) * 8);
  DottedDecimal dotted_decimal = _get_sanitized_dotted_dec(dotted_decimal_input);
  assert(strcmp(dotted_decimal.before_dot, "123") == 0);
  text_green("_get_sanitized_dotted_dec -> should return 123 before_dot for 123.123 inputs", 10);
  add_new_line(1);
  assert(strcmp(dotted_decimal.after_dot, "123") == 0);
  text_green("_get_sanitized_dotted_dec -> should return 123 after_dot for 123.123 inputs", 10);
}
