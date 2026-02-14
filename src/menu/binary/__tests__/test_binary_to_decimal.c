#include "../../../utils/utils.h"
#include "../binary_to_decimal.c"
#include <assert.h>

void test_binary_to_decimal(void) {
  text_white("[ Testing binary_to_decimal Functions ]", 10);
  add_new_line(1);

  // 1111 values.
  assert(is_positive("1111") == 1);
  text_green("is_positive -> should accept positive binary without dot", 10);
  add_new_line(1);
  assert(is_positive("1111.1") == 0);
  text_green("is_positive -> should not accept positive binary with dot", 10);
  add_new_line(1);
  assert(is_positive("-1111") == 0);
  text_green("is_positive -> should not accept negative binary without dot", 10);
  add_new_line(1);
  assert(is_positive("-1111.1") == 0);
  text_green("is_positive -> should not accept negative binary with dot", 10);
  add_new_line(1);

  // 1111.1 values.
  assert(is_positive_with_dot("1111.1") == 1);
  text_green("is_positive_with_dot -> should accept positive binary with dot", 10);
  add_new_line(1);
  assert(is_positive_with_dot("1111") == 0);
  text_green("is_positive_with_dot -> should not accept positive binary without dot", 10);
  add_new_line(1);
  assert(is_positive_with_dot("-1111") == 0);
  text_green("is_positive_with_dot -> should not accept negative binary without dot", 10);
  add_new_line(1);
  assert(is_positive_with_dot("-1111.1") == 0);
  text_green("is_positive_with_dot -> should not accept negative binary with dot", 10);
  add_new_line(1);

  // -1111 values.
  assert(is_negative("-1111") == 1);
  text_green("is_negative -> should accept negative binary without dot.", 10);
  add_new_line(1);
  assert(is_negative("-1111.1") == 0);
  text_green("is_negative -> should not accept negative binary with dot.", 10);
  add_new_line(1);
  assert(is_negative("1111") == 0);
  text_green("is_negative -> should not accept positive binary without dot.", 10);
  add_new_line(1);
  assert(is_negative("1111.1") == 0);
  text_green("is_negative -> should not accept positive binary with dot.", 10);
  add_new_line(1);

  // -1111.1 values.
  assert(is_negative_with_dot("-1111.1") == 1);
  text_green("is_negative_with_dot -> should accept negative binary with dot", 10);
  add_new_line(1);
  assert(is_negative_with_dot("-1111") == 0);
  text_green("is_negative_with_dot -> should not accept negative binary without dot", 10);
  add_new_line(1);
  assert(is_negative_with_dot("1111") == 0);
  text_green("is_negative_with_dot -> should not accept positive binary with dot", 10);
  add_new_line(1);
  assert(is_negative_with_dot("1111.1") == 0);
  text_green("is_negative_with_dot -> should not accept positive binary without dot", 10);
}
