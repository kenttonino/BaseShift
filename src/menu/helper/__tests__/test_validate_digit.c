#include <assert.h>
#include "../../../utils/utils.h"
#include "../helper.h"

void test_validate_digit(void) {
  text_white("[ Testing validate_digit Functions ]", 10);
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
  add_new_line(1);

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
  text_green("is_negative_with_dot -> should return false for 1111.1", 10);
  add_new_line(1);

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
  add_new_line(1);

  assert(is_positive_with_dot("1111.1") == 1);
  text_green("is_positive_with_dot -> should return true for 1111.1", 10);
  add_new_line(1);
  assert(is_positive_with_dot("1111") == 0);
  text_green("is_positive_with_dot -> should return false for 1111", 10);
  add_new_line(1);
  assert(is_positive_with_dot("-1111") == 0);
  text_green("is_positive_with_dot -> should return false for -1111", 10);
  add_new_line(1);
  assert(is_positive_with_dot("-1111.1") == 0);
  text_green("is_positive_with_dot -> should return false for -1111.1", 10);
}
