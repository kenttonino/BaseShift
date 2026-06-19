#include <assert.h>
#include "../../../utils/utils.h"
#include "../binary_to_hexadecimal.c"

void test_binary_to_hexadecimal(void) {
  text_white("[ Testing binary_to_hexadecimal Functionss]", 10);
  add_new_line(1);

  char binary_input[5];
  memmove(binary_input, "1", 2);
  assert(strcmp(_hex_zero_adder(binary_input), "0001") == 0);
  text_green("_hex_zero_adder -> should return 0001 for 1 value", 10);
  add_new_line(1);
  memset(binary_input, 0, sizeof(char) * 5);
  memmove(binary_input, "01", 3);
  assert(strcmp(_hex_zero_adder(binary_input), "0001") == 0);
  text_green("_hex_zero_adder -> should return 0001 for 01 value", 10);
  add_new_line(1);
  memset(binary_input, 0, sizeof(char) * 5);
  memmove(binary_input, "001", 4);
  assert(strcmp(_hex_zero_adder(binary_input), "0001") == 0);
  text_green("_hex_zero_adder -> should return 0001 for 001 value", 10);
  add_new_line(1);
  memset(binary_input, 0, sizeof(char) * 5);
  memmove(binary_input, "0001", sizeof(char) * 5);
  assert(strcmp(_hex_zero_adder(binary_input), "0001") == 0);
  text_green("_hex_zero_adder -> should return 0001 for 0001 value", 10);
}
