#include "../../../utils/utils.h"
#include "./test_to_binary.c"

int main(void) {
  clear_terminal();
  add_new_line(2);

  test_to_binary();
  add_new_line(3);

  return 0;
}
