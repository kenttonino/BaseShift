#include "./test_to_decimal.c"
#include "./test_to_octal.c"
#include "./test_to_hexadecimal.c"

int main(void) {
  clear_terminal();
  add_new_line(2);

  test_to_decimal();
  add_new_line(2);

  test_to_octal();
  add_new_line(2);

  test_to_hexadecimal();
  add_new_line(2);

  return 0;
}
