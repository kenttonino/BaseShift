#include <assert.h>
#include "../../../utils/utils.h"
#include "../to_utils.h"

void test_to_utils(void) {
  text_white("[ Testing to_dec_utils Functions ]", 10);
  add_new_line(1);

  char dot_adder_input[5];
  memmove(dot_adder_input, "123", sizeof(char) * 4);
  assert(strcmp(_dec_dot_adder(dot_adder_input), "0.123") == 0);
  text_green("_dec_dot_adder -> should return 0.123 for 123 inputs", 10);
  add_new_line(1);

  char dotted_decimal_input[8];
  memmove(dotted_decimal_input, "123.123", sizeof(char) * 8);
  DottedDecimal dotted_dec = _get_dec_dotted(dotted_decimal_input);
  assert(strcmp(dotted_dec.before_dot, "123") == 0);
  text_green("_get_dec_dotted -> should return 123 before_dot for 123.123 inputs", 10);
  add_new_line(1);
  assert(strcmp(dotted_dec.after_dot, "123") == 0);
  text_green("_get_dec_dotted -> should return 123 after_dot for 123.123 inputs", 10);
}
