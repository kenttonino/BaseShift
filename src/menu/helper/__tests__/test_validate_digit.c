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

  assert(is_negative_radixp("-1111.1") == 1);
  text_green("is_negative_radixp -> should return true for -1111.1", 10);
  add_new_line(1);
  assert(is_negative_radixp("-1111") == 0);
  text_green("is_negative_radixp -> should return false for -1111", 10);
  add_new_line(1);
  assert(is_negative_radixp("1111") == 0);
  text_green("is_negative_radixp -> should return false for 1111", 10);
  add_new_line(1);
  assert(is_negative_radixp("1111.1") == 0);
  text_green("is_negative_radixp -> should return false for 1111.1", 10);
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

  assert(is_positive_radixp("1111.1") == 1);
  text_green("is_positive_radixp -> should return true for 1111.1", 10);
  add_new_line(1);
  assert(is_positive_radixp("1111") == 0);
  text_green("is_positive_radixp -> should return false for 1111", 10);
  add_new_line(1);
  assert(is_positive_radixp("-1111") == 0);
  text_green("is_positive_radixp -> should return false for -1111", 10);
  add_new_line(1);
  assert(is_positive_radixp("-1111.1") == 0);
  text_green("is_positive_radixp -> should return false for -1111.1", 10);
  add_new_line(1);

  char bin[5];
  memmove(bin, "0000", sizeof(char) * 5);
  ZeroPrefix zero_prefix = is_zero_only(bin);
  assert(zero_prefix.zero_only == 1);
  text_green("is_zero_only -> should return 1 zero_only if all value is zero", 10);
  add_new_line(1);
  assert(zero_prefix.num_zero_prefix == 4);
  text_green("iz_zero_only -> should return 4 num_zero_prefix based on the input", 10);
  memset(bin, 0, sizeof(char) * 5);
}
