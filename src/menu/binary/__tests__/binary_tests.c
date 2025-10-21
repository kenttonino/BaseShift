#include "./tests_binary_validate.c"

int main(void) {
  clear_terminal();
  add_new_line(2);

  // Tests functions;
  tests_binary_validate();

  add_new_line(2);
  return 0;
}
