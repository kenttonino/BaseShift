#include <assert.h>
#include "../../../utils/utils.h"
#include "../binary_to_octal.c"

void test_binary_to_octal(void) {
  text_white("[ Testing binary_to_decimal Functions ]", 10);
  add_new_line(1);

  assert(strcmp(zero_adder("1"), "001") == 0);
  text_green("zero_adder -> should return 001 for 1 input", 10);
  add_new_line(1);
  assert(strcmp(zero_adder("01"), "001") == 0);
  text_green("zero_adder -> should return 001 for 01 input", 10);
  add_new_line(1);
  assert(strcmp(zero_adder("001"), "001") == 0);
  text_green("zero_adder -> should return 001 for 001 input", 10);
}
