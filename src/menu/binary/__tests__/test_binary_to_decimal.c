#include <assert.h>
#include "../to_decimal.c"
#include "../../../utils/utils.h"

void test_binary_to_decimal(void) {
  text_white("[ Testing binary_to_decimal Functions ]", 10);
  add_new_line(1);

  assert(_get_decimal("1111") == 15);
  text_green("get_decimal -> should return 15 for 1111", 10);
  add_new_line(1);

  assert(_get_decimal_with_dot("1111.1") == 15.5);
  text_green("get_decimal_with_dot -> should return 15.5 for 1111.1", 10);
}
