#include "../../../utils/utils.h"
#include "../binary_to_decimal.c"
#include <assert.h>

void test_binary_to_decimal(void) {
  text_white("[ Testing binary_to_decimal Functions ]", 10);
  add_new_line(1);

  // The is_normal function only accepts 1111 values.
  assert(is_normal("1111") == 1);
  text_green("is_normal -> should accept normal binary values", 10);
  add_new_line(1);
  assert(is_normal("1111.1") == 0);
  text_green("is_normal -> should not accept binary values with dot", 10);
  add_new_line(1);
  assert(is_normal("-1111") == 0);
  text_green("is_normal -> should not accept negative binary values", 10);
  add_new_line(1);
  assert(is_normal("-1111.1") == 0);
  text_green("is_normal -> should not accept negative binary values with dot", 10);
  add_new_line(1);

  // THe is_negative_only function only accepts -1111 values.
  assert(is_negative_only("-1111") == 1);
  text_green("is_negative_only -> should accept negative binary values without dot.", 10);
  add_new_line(1);
  assert(is_negative_only("-1111.1") == 0);
  text_green("is_negative_only -> should not accept negative binary values with dot.", 10);
  add_new_line(1);
  assert(is_negative_only("1111") == 0);
  text_green("is_negative_only -> should not accept non-negative binary values.", 10);
  add_new_line(1);
  assert(is_negative_only("1111.1") == 0);
  text_green("is_negative_only -> should not accept binary values with dot.", 10);
}
