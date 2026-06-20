#include <assert.h>
#include "../../../utils/utils.h"
#include "../helper.h"

void test_is_positive(void) {
  assert(is_positive("1111") == 1);
  text_green("is_positive -> should return true for 1111", 10);
  add_new_line(1);

  assert(is_positive("1111.1") == 0);
  text_green("is_positive -> should return false for 1111.1", 10);
  add_new_line(1);

  assert(is_positive("-1111") == 0);
  text_green("is_positive -> should return false for -1111", 10);
  add_new_line(1);

  assert(is_positive("-1111.1") == 0);
  text_green("is_positive -> should return false for -1111.1", 10);
}
