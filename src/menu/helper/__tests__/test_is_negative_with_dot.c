#include <assert.h>
#include "../../../utils/utils.h"
#include "../helper.h"

void test_is_negative_with_dot(void) {
  assert(is_negative_with_dot("-1111.1") == 1);
  text_green("is_negative_with_dot -> should return true for -1111.1", 10);
  add_new_line(1);

  assert(is_negative_with_dot("-1111") == 0);
  text_green("is_negative_with_dot -> should return false for -1111", 10);
  add_new_line(1);

  assert(is_negative_with_dot("1111") == 0);
  text_green("is_negative_with_dot -> should return false for 1111", 10);
  add_new_line(1);

  assert(is_negative_with_dot("1111.1") == 0);
  text_green("is_negrative_with_dot -> should return false for 1111.1", 10);
}
