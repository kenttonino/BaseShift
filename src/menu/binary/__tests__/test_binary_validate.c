#include "../../../utils/utils.h"
#include "../binary_validate.c"
#include <assert.h>

void test_binary_validate(void) {
  text_white("[ Testing binary_validate Functions ]", 10);
  add_new_line(1);

  assert(binary_validate("0001") == 1);
  text_green("binary_validate -> should accept binary values", 10);
  add_new_line(1);
  assert(binary_validate("-0001") == 1);
  text_green("binary_validate -> should accept negative binary values", 10);
  add_new_line(1);
  assert(binary_validate("0001.0001") == 1);
  text_green("binary_validate -> should accept binary values with binary dot", 10);
  add_new_line(1);
  assert(binary_validate("-0001.0001") == 1);
  text_green("binary_validate -> should accept negative binary values with binary dot", 10);
}
