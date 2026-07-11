#include <assert.h>
#include "../to_bin_dec.c"
#include "../../../utils/utils.h"

void test_to_bin_dec(void) {
  text_white("[ Testing to_bin_dec Functions ]", 10);
  add_new_line(1);

  assert(_get_bin_dec("1111") == 15);
  text_green("_get_bin_dec -> should return 15 for 1111 digits", 10);
  add_new_line(1);

  assert(_get_bin_dec_with_dot("1111.1") == 15.5);
  text_green("_get_bin_dec_with_dot -> should return 15.5 for 1111.1 digits", 10);
}
