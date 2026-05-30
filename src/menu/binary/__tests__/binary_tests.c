#include "./test_binary_helper.c"
#include "./test_binary_validate.c"
#include "./test_binary_to_decimal.c"
#include "./test_binary_to_octal.c"

int main(void) {
  clear_terminal();
  add_new_line(2);

  test_binary_helper();
  add_new_line(2);

  test_binary_to_decimal();
  add_new_line(2);

  test_binary_to_octal();
  add_new_line(2);

  test_binary_validate();
  add_new_line(3);

  return 0;
}
