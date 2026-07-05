#include <assert.h>
#include "../../../utils/utils.h"
#include "../to_binary.c"

void test_to_binary(void) {
  text_white("[ Testing to_binary Functions ]", 10);
  add_new_line(1);

  char dec_input[5];
  memmove(dec_input, "123", sizeof(char) * 4);
  assert(strcmp(_get_bin(dec_input), "1111011") == 0);
  text_green("_get_bin -> should return 1111011 binary digits for 123 decimal digits", 10);
  add_new_line(1);

  char dec_dot_input[5];
  memmove(dec_dot_input, "123", sizeof(char) * 4);
  assert(strcmp(_get_bin_with_dot(dec_dot_input), "00011111") == 0);
  text_green("_get_bin_with_dot -> should return 00011111 binary digits for 123 decimal dots digits", 10);
  add_new_line(1);

  char dotted_decimal_input[8];
  memmove(dotted_decimal_input, "123.123", sizeof(char) * 8);
  DottedDecimal dotted_decimal = _get_sanitized_dotted_dec(dotted_decimal_input);
  assert(strcmp(dotted_decimal.before_dot, "123") == 0);
  text_green("_get_sanitized_dotted_dec -> should return 123 decimal digits for before_dot 123.123 decimal digits", 10);
  add_new_line(1);
  assert(strcmp(dotted_decimal.after_dot, "123") == 0);
  text_green("_get_sanitized_dotted_dec -> should return 123 decimal digits for after_dot 123.123 decimal digits.", 10);
}
