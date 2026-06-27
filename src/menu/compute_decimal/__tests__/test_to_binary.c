#include <assert.h>
#include "../../../utils/utils.h"
#include "../to_binary.c"

void test_to_binary(void) {
  text_white("[ Testing to_binary Functions ]", 10);
  add_new_line(1);

  char dec_input[5];
  memmove(dec_input, "1000", sizeof(char) * 5);
  assert(strcmp(_get_bin(dec_input), "1111101000") == 0);
  text_green("_get_bin -> should return 1111101000 binary digits for 1000 decimal digits", 10);
}
