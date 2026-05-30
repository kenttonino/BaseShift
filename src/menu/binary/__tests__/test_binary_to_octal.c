#include <assert.h>
#include "../../../utils/utils.h"
#include "../binary_to_octal.c"

void test_binary_to_octal(void) {
  text_white("[ Testing binary_to_octal Functions ]", 10);
  add_new_line(1);

  char binary_group[4] = "1";
  assert(strcmp(zero_adder(binary_group), "001") == 0);
  text_green("zero_adder -> should return 001 for 1 value", 10);
}
