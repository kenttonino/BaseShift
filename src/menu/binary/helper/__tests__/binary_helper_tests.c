#include "../../../../utils/utils.h"
#include "test_is_positive_binary.c"
#include "test_is_positive_binary_with_dot.c"
#include "test_is_negative_binary.c"

int main(void) {
  clear_terminal();
  add_new_line(2);

  test_is_positive_binary();
  add_new_line(2);
  test_is_positive_binary_with_dot();
  add_new_line(2);
  test_is_negative_binary();

  add_new_line(2);
  return 0;
}
