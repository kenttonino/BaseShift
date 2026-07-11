#include <assert.h>
#include "../../../utils/utils.h"
#include "../to_bin_hex.c"

void test_to_bin_hex(void) {
  text_white("[ Testing to_bin_hex Functions]", 10);
  add_new_line(1);

  char bin_input[5];
  memmove(bin_input, "1", sizeof(char) * 2);
  assert(strcmp(_bin_hex_zero_adder(bin_input), "0001") == 0);
  text_green("_bin_hex_zero_adder -> should return 0001 for 1 digit", 10);
  add_new_line(1);
  memset(bin_input, 0, sizeof(char) * 5);
  memmove(bin_input, "01", sizeof(char) * 3);
  assert(strcmp(_bin_hex_zero_adder(bin_input), "0001") == 0);
  text_green("_bin_hex_zero_adder -> should return 0001 for 01 digits", 10);
  add_new_line(1);
  memset(bin_input, 0, sizeof(char) * 5);
  memmove(bin_input, "001", sizeof(char) * 4);
  assert(strcmp(_bin_hex_zero_adder(bin_input), "0001") == 0);
  text_green("_bin_hex_zero_adder -> should return 0001 for 001 digits", 10);
  add_new_line(1);
  memset(bin_input, 0, sizeof(char) * 5);
  memmove(bin_input, "0001", sizeof(char) * 5);
  assert(strcmp(_bin_hex_zero_adder(bin_input), "0001") == 0);
  text_green("_bin_hex_zero_adder -> should return 0001 for 0001 digits", 10);
  add_new_line(1);

  memset(bin_input, 0, sizeof(char) * 5);
  memmove(bin_input, "1", sizeof(char) * 2);
  assert(strcmp(_bin_hex_zero_adder_with_dot(bin_input), "1000") == 0);
  text_green("_bin_hex_zero_adder_with_dot -> should return 1000 for 1 digit", 10);
  add_new_line(1);
  memset(bin_input, 0, sizeof(char) * 5);
  memmove(bin_input, "10", sizeof(char) * 3);
  assert(strcmp(_bin_hex_zero_adder_with_dot(bin_input), "1000") == 0);
  text_green("_bin_hex_zero_adder_with_dot -> should return 1000 for 10 digits", 10);
  add_new_line(1);
  memset(bin_input, 0, sizeof(char) * 5);
  memmove(bin_input, "100", sizeof(char) * 4);
  assert(strcmp(_bin_hex_zero_adder_with_dot(bin_input), "1000") == 0);
  text_green("_bin_hex_zero_adder_with_dot -> should return 1000 for 100 digits", 10);
  add_new_line(1);
  memset(bin_input, 0, sizeof(char) * 5);
  memmove(bin_input, "1000", sizeof(char) * 5);
  assert(strcmp(_bin_hex_zero_adder_with_dot(bin_input), "1000") == 0);
  text_green("_bin_hex_zero_adder_with_dot -> should return 1000 for 1000 digits", 10);
}
