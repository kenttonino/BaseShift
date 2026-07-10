#include "./test_to_bin_dec.c"
#include "./test_to_octal.c"
#include "./test_to_hexadecimal.c"

int main(void) {
  clear_terminal();
  add_new_line(2);

  test_to_bin_dec();
  add_new_line(2);

  test_to_octal();
  add_new_line(2);

  test_to_hexadecimal();
  add_new_line(2);

  return 0;
}
