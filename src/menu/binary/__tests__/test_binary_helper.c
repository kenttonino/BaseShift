#include "../../../utils/utils.h"
#include "../binary_helper.c"
#include <assert.h>

void test_binary_helper(void) {
  text_white("[ Testing binary_helper Functions ]", 10);
  add_new_line(1);

  // 1111 values.
  assert(is_positive_binary("1111") == 1);
  text_green("is_positive_binary -> should accept positive binary without dot",
             10);
  add_new_line(1);
  assert(is_positive_binary("1111.1") == 0);
  text_green("is_positive_binary -> should not accept positive binary with dot",
             10);
  add_new_line(1);
  assert(is_positive_binary("-1111") == 0);
  text_green(
      "is_positive_binary -> should not accept negative binary without dot",
      10);
  add_new_line(1);
  assert(is_positive_binary("-1111.1") == 0);
  text_green("is_positive_binary -> should not accept negative binary with dot",
             10);
  add_new_line(1);

  // 1111.1 values.
  assert(is_positive_binary_with_dot("1111.1") == 1);
  text_green(
      "is_positive_binary_with_dot -> should accept positive binary with dot",
      10);
  add_new_line(1);
  assert(is_positive_binary_with_dot("1111") == 0);
  text_green("is_positive_binary_with_dot -> should not accept positive binary "
             "without dot",
             10);
  add_new_line(1);
  assert(is_positive_binary_with_dot("-1111") == 0);
  text_green("is_positive_binary_with_dot -> should not accept negative binary "
             "without dot",
             10);
  add_new_line(1);
  assert(is_positive_binary_with_dot("-1111.1") == 0);
  text_green("is_positive_binary_with_dot -> should not accept negative binary "
             "with dot",
             10);
  add_new_line(1);

  // -1111 values.
  assert(is_negative_binary("-1111") == 1);
  text_green("is_negative_binary -> should accept negative binary without dot.",
             10);
  add_new_line(1);
  assert(is_negative_binary("-1111.1") == 0);
  text_green(
      "is_negative_binary -> should not accept negative binary with dot.", 10);
  add_new_line(1);
  assert(is_negative_binary("1111") == 0);
  text_green(
      "is_negative_binary -> should not accept positive binary without dot.",
      10);
  add_new_line(1);
  assert(is_negative_binary("1111.1") == 0);
  text_green(
      "is_negative_binary -> should not accept positive binary with dot.", 10);
  add_new_line(1);

  // -1111.1 values.
  assert(is_negative_binary_with_dot("-1111.1") == 1);
  text_green(
      "is_negative_binary_with_dot -> should accept negative binary with dot",
      10);
  add_new_line(1);
  assert(is_negative_binary_with_dot("-1111") == 0);
  text_green("is_negative_binary_with_dot -> should not accept negative binary "
             "without dot",
             10);
  add_new_line(1);
  assert(is_negative_binary_with_dot("1111") == 0);
  text_green("is_negative_binary_with_dot -> should not accept positive binary "
             "with dot",
             10);
  add_new_line(1);
  assert(is_negative_binary_with_dot("1111.1") == 0);
  text_green("is_negative_binary_with_dot -> should not accept positive binary "
             "without dot",
             10);
}
