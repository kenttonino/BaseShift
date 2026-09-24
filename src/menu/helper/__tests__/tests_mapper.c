#include <assert.h>
#include "../../../utils/utils.h"
#include "../helper.h"

void test_mapper(void) {
  text_white("[ Testing mapper Functions ] ", 10);
  add_new_line(1);

  char bin[5];
  memmove(bin, "0000", sizeof(char) * 5);
  assert(strcmp(get_bin_hex_mapper(bin), "0") == 0);
  text_green("get_bin_hex_mapper -> should return 0 hex for 0000 binary", 10);
  memset(bin, 0, sizeof(char) * 5);
  add_new_line(1);

  memmove(bin, "0001", sizeof(char) * 5);
  assert(strcmp(get_bin_hex_mapper(bin), "1") == 0);
  text_green("get_bin_hex_mapper -> should return 1 hex for 0001 binary", 10);
  memset(bin, 0, sizeof(char) * 5);
  add_new_line(1);

  memmove(bin, "0010", sizeof(char) * 5);
  assert(strcmp(get_bin_hex_mapper(bin), "2") == 0);
  text_green("get_bin_hex_mapper -> should return 2 hex for 0010 binary", 10);
  memset(bin, 0, sizeof(char) * 5);
  add_new_line(1);

  memmove(bin, "0011", sizeof(char) * 5);
  assert(strcmp(get_bin_hex_mapper(bin), "3") == 0);
  text_green("get_bin_hex_mapper -> should return 3 hex for 0011 binary", 10);
  memset(bin, 0, sizeof(char) * 5);
  add_new_line(1);

  memmove(bin, "0100", sizeof(char) * 5);
  assert(strcmp(get_bin_hex_mapper(bin), "4") == 0);
  text_green("get_bin_hex_mapper -> should return 4 hex for 0100 binary", 10);
  memset(bin, 0, sizeof(char) * 5);
  add_new_line(1);

  memmove(bin, "0101", sizeof(char) * 5);
  assert(strcmp(get_bin_hex_mapper(bin), "5") == 0);
  text_green("get_bin_hex_mapper -> should return 5 hex for 0101 binary", 10);
  memset(bin, 0, sizeof(char) * 5);
  add_new_line(1);

  memmove(bin, "0110", sizeof(char) * 5);
  assert(strcmp(get_bin_hex_mapper(bin), "6") == 0);
  text_green("get_bin_hex_mapper -> should return 6 hex for 0110 binary", 10);
  memset(bin, 0, sizeof(char) * 5);
  add_new_line(1);

  memmove(bin, "0111", sizeof(char) * 5);
  assert(strcmp(get_bin_hex_mapper(bin), "7") == 0);
  text_green("get_bin_hex_mapper -> should return 7 hex for 0111 binary", 10);
  memset(bin, 0, sizeof(char) * 5);
  add_new_line(1);

  memmove(bin, "1000", sizeof(char) * 5);
  assert(strcmp(get_bin_hex_mapper(bin), "8") == 0);
  text_green("get_bin_hex_mapper -> should return 8 hex for 1000 binary", 10);
  memset(bin, 0, sizeof(char) * 5);
  add_new_line(1);

  memmove(bin, "1001", sizeof(char) * 5);
  assert(strcmp(get_bin_hex_mapper(bin), "9") == 0);
  text_green("get_bin_hex_mapper -> should return 9 hex for 1001 binary", 10);
  memset(bin, 0, sizeof(char) * 5);
  add_new_line(1);

  memmove(bin, "1010", sizeof(char) * 5);
  assert(strcmp(get_bin_hex_mapper(bin), "A") == 0);
  text_green("get_bin_hex_mapper -> should return A hex for 1010 binary", 10);
  memset(bin, 0, sizeof(char) * 5);
  add_new_line(1);

  memmove(bin, "1011", sizeof(char) * 5);
  assert(strcmp(get_bin_hex_mapper(bin), "B") == 0);
  text_green("get_bin_hex_mapper -> should return B hex for 1011 binary", 10);
  memset(bin, 0, sizeof(char) * 5);
  add_new_line(1);

  memmove(bin, "1100", sizeof(char) * 5);
  assert(strcmp(get_bin_hex_mapper(bin), "C") == 0);
  text_green("get_bin_hex_mapper -> should return C hex for 1100 binary", 10);
  memset(bin, 0, sizeof(char) * 5);
  add_new_line(1);

  memmove(bin, "1101", sizeof(char) * 5);
  assert(strcmp(get_bin_hex_mapper(bin), "D") == 0);
  text_green("get_bin_hex_mapper -> should return D hex for 1101 binary", 10);
  memset(bin, 0, sizeof(char) * 5);
  add_new_line(1);

  memmove(bin, "1110", sizeof(char) * 5);
  assert(strcmp(get_bin_hex_mapper(bin), "E") == 0);
  text_green("get_bin_hex_mapper -> should return E hex for 1110 binary", 10);
  memset(bin, 0, sizeof(char) * 5);
  add_new_line(1);

  memmove(bin, "1111", sizeof(char) * 5);
  assert(strcmp(get_bin_hex_mapper(bin), "F") == 0);
  text_green("get_bin_hex_mapper -> should return F hex for 1111 binary", 10);
  memset(bin, 0, sizeof(char) * 5);
}
