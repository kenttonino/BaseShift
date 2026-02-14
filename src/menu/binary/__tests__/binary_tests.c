#include "./test_binary_validate.c"
#include "./test_binary_to_decimal.c"

int main(void) {
  clear_terminal();
  add_new_line(2);

  // Tests functions;
  test_binary_to_decimal();
  add_new_line(2);
  test_binary_validate();

  add_new_line(2);
  return 0;
}
