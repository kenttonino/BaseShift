#include <assert.h>
#include "../../../../utils/utils.h"
#include "../is_negative_binary.c"

void test_is_negative_binary(void) {
  assert(is_negative_binary("-1111") == 1);
  text_green("is_negative_binary -> should return true for -1111", 10);
  add_new_line(1);

  assert(is_negative_binary("-1111.1") == 0);
  text_green("is_negative_binary -> should return false for -1111.1", 10);
  add_new_line(1);

  assert(is_negative_binary("1111") == 0);
  text_green("is_negative_binary -> should return false for 1111", 10);
  add_new_line(1);

  assert(is_negative_binary("1111.1") == 0);
  text_green("is_negative_binary -> should return false for 1111.1", 10);
}
