#include <assert.h>
#include "../../../utils/utils.h"
#include "../../helper/helper.h"

void test_to_utils(void) {
  text_white("[ Testing to_dec_utils Functions ]", 10);
  add_new_line(1);

  char radixp_adder_input[5];
  memmove(radixp_adder_input, "123", sizeof(char) * 4);
  assert(strcmp(radixp_adder(radixp_adder_input), "0.123") == 0);
  text_green("radixp_adder -> should return 0.123 for 123 inputs", 10);
  add_new_line(1);

  char radixp_dec_input[8];
  memmove(radixp_dec_input, "123.123", sizeof(char) * 8);
  GenericInput generic_input = get_generic_input(radixp_dec_input);
  assert(strcmp(generic_input.before_radixp, "123") == 0);
  text_green("get_generic_input -> should return 123 before_dot for 123.123 inputs", 10);
  add_new_line(1);
  assert(strcmp(generic_input.after_radixp, "123") == 0);
  text_green("get_generic_input -> should return 123 after_dot for 123.123 inputs", 10);
}
