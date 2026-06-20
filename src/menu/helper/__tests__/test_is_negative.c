#include <assert.h>
#include "../../../utils/utils.h"
#include "../helper.h"

void test_is_negative(void) {
  text_white("[ Testing is_negative Function ]", 10);
  add_new_line(1);

  assert(is_negative("-1111") == 1);
  text_green("is_negative -> should return true for -1111", 10);
  add_new_line(1);

  assert(is_negative("-1111.1") == 0);
  text_green("is_negative -> should return false for -1111.1", 10);
  add_new_line(1);

  assert(is_negative("1111") == 0);
  text_green("is_negative -> should return false for 1111", 10);
  add_new_line(1);

  assert(is_negative("1111.1") == 0);
  text_green("is_negative -> should return false for 1111.1", 10);
}
