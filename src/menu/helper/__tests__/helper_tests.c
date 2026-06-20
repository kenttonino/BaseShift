#include "../../../utils/utils.h"
#include "./test_is_positive.c"
#include "./test_is_positive_with_dot.c"
#include "./test_is_negative.c"
#include "./test_is_negative_with_dot.c"

int main(void) {
  clear_terminal();
  add_new_line(2);

  test_is_positive();
  add_new_line(2);
  test_is_positive_with_dot();
  add_new_line(2);
  test_is_negative();
  add_new_line(2);
  test_is_negative_with_dot();

  add_new_line(2);
  return 0;
}
