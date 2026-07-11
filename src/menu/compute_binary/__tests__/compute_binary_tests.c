#include "./test_to_bin_dec.c"
#include "./test_to_bin_hex.c"
#include "./test_to_bin_oct.c"

int main(void) {
  clear_terminal();
  add_new_line(2);

  test_to_bin_dec();
  add_new_line(2);

  test_to_bin_oct();
  add_new_line(2);

  test_to_bin_hex();
  add_new_line(2);

  return 0;
}
