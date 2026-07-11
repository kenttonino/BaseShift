#include "../../../utils/utils.h"
#include "./test_to_dec_bin.c"
#include "./test_to_dec_oct.c"

int main(void) {
  clear_terminal();
  add_new_line(2);

  test_to_dec_bin();
  add_new_line(3);

  test_to_dec_oct();
  add_new_line(3);

  return 0;
}
