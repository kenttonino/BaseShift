#include "../../../utils/utils.h"
#include "./test_map_hex_bin.c"
#include "./test_validate_digit.c"
#include "./tests_mapper.c"
#include "./test_reverse_string.c"

int main(void) {
  clear_terminal();
  add_new_line(2);

  test_map_hex_bin();
  add_new_line(2);
  test_validate_digit();
  add_new_line(2);
  test_mapper();
  add_new_line(2);
  test_reverse_string();
  add_new_line(3);

  return 0;
}
