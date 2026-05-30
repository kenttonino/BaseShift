#include <assert.h>
#include "../../../utils/utils.h"
#include "../binary_to_octal.c"

void test_binary_to_octal(void) {
  text_white("[ Testing binary_to_octal Functions ]", 10);
  add_new_line(1);

  char binary_group[4];
  memmove(binary_group, "1", sizeof(char) * 2);
  assert(strcmp(zero_adder(binary_group), "001") == 0);
  text_green("zero_adder -> should return 001 for 1 value", 10);
  add_new_line(1);
  memset(binary_group, 0, sizeof(char) * 4);
  memmove(binary_group, "01", sizeof(char) * 2);
  assert(strcmp(zero_adder(binary_group), "001") == 0);
  text_green("zero_adder -> should return 001 for 01 value", 10);
  add_new_line(1);
  memset(binary_group, 0, sizeof(char) * 4);
  memmove(binary_group, "001", sizeof(char) * 3);
  assert(strcmp(zero_adder("001"), "001") == 0);
  text_green("zero_adder -> should return 001 for 001", 10);
  memset(binary_group, 0, sizeof(char) * 4);
  add_new_line(1);

  assert(strcmp(octal_mapper("000"), "0") == 0);
  text_green("octal_mapper -> should return 0 for 000 value", 10);
  add_new_line(1);
  assert(strcmp(octal_mapper("001"), "1") == 0);
  text_green("octal_mapper -> should return 1 for 001 value", 10);
  add_new_line(1);
  assert(strcmp(octal_mapper("010"), "2") == 0);
  text_green("octal_mapper -> should return 2 for 010 value", 10);
  add_new_line(1);
  assert(strcmp(octal_mapper("011"), "3") == 0);
  text_green("octal_mapper -> should return 3 for 011 value", 10);
  add_new_line(1);
  assert(strcmp(octal_mapper("100"), "4") == 0);
  text_green("octal_mapper -> should return 4 for 100 value", 10);
  add_new_line(1);
  assert(strcmp(octal_mapper("101"), "5") == 0);
  text_green("octal_mapper -> should return 5 for 101 value", 10);
  add_new_line(1);
  assert(strcmp(octal_mapper("110"), "6") == 0);
  text_green("octal_mapper -> should return 6 for 110 value", 10);
  add_new_line(1);
  assert(strcmp(octal_mapper("111"), "7") == 0);
  text_green("octal_mapper -> should return 7 for 111 value", 10);
}
