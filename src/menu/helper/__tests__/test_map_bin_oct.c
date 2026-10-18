#include <assert.h>
#include "../../../utils/utils.h"
#include "../helper.h"

void test_map_bin_oct(void) {
  text_white("[ Testing map_bin_oct Function ] ", 10);
  add_new_line(1);

  char bin[4];
  memmove(bin, "000", sizeof(char) * 4);
  assert(strcmp(map_bin_oct(bin), "0") == 0);
  text_green("map_bin_oct -> should return 0 octal for 000 binary", 10);
  memset(bin, 0, sizeof(char) * 4);
  add_new_line(1);
  memmove(bin, "001", sizeof(char) * 4);
  assert(strcmp(map_bin_oct(bin), "1") == 0);
  text_green("map_bin_oct -> should return 1 octal for 001 binary", 10);
  memset(bin, 0, sizeof(char) * 4);
  add_new_line(1);
  memmove(bin, "010", sizeof(char) * 4);
  assert(strcmp(map_bin_oct(bin), "2") == 0);
  text_green("map_bin_oct -> should return 2 octal for 010 binary", 10);
  memset(bin, 0, sizeof(char) * 4);
  add_new_line(1);
  memmove(bin, "011", sizeof(char) * 4);
  assert(strcmp(map_bin_oct(bin), "3") == 0);
  text_green("map_bin_oct -> should return 3 octal for 011 binary", 10);
  memset(bin, 0, sizeof(char) * 4);
  add_new_line(1);
  memmove(bin, "100", sizeof(char) * 4);
  assert(strcmp(map_bin_oct(bin), "4") == 0);
  text_green("map_bin_oct -> should return 4 octal for 100 binary", 10);
  memset(bin, 0, sizeof(char) * 4);
  add_new_line(1);
  memmove(bin, "101", sizeof(char) * 4);
  assert(strcmp(map_bin_oct(bin), "5") == 0);
  text_green("map_bin_oct -> should return 5 octal for 101 binary", 10);
  memset(bin, 0, sizeof(char) * 4);
  add_new_line(1);
  memmove(bin, "110", sizeof(char) * 4);
  assert(strcmp(map_bin_oct(bin), "6") == 0);
  text_green("map_bin_oct -> should return 6 octal for 110 binary", 10);
  memset(bin, 0, sizeof(char) * 4);
  add_new_line(1);
  memmove(bin, "111", sizeof(char) * 4);
  assert(strcmp(map_bin_oct(bin), "7") == 0);
  text_green("map_bin_oct -> should return 7 octal for 111 binary", 10);
  memset(bin, 0, sizeof(char) * 4);
}
