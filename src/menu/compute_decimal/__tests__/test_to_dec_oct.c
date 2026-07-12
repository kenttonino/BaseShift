#include <assert.h>
#include <string.h>
#include "../../../utils/utils.h"
#include "../to_dec_oct.c"

void test_to_dec_oct(void) {
  text_white("[ Testing to_dec_oct Functions ]", 10);
  add_new_line(1);

  char dec_input[5];
  memmove(dec_input, "123", sizeof(char) * 4);
  assert(strcmp(_get_dec_oct(dec_input), "173") == 0);
  text_green("_get_dec_oct -> should return 173 for 123 inputs", 10);
  add_new_line(1);

  char dec_dot_input[2];
  memmove(dec_dot_input, "1", sizeof(char) * 2);
  assert(strcmp(_get_dec_oct_with_dot(dec_dot_input), "06314631") == 0);
  text_green("_get_dec_oct_with_dot -> should return 06314631 for 1 dec dot input", 10);
}
