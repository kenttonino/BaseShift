#include <assert.h>
#include "../../../utils/utils.h"
#include "../helper.h"

void test_map_hex_bin(void) {
  text_white("[ Testing map_hex_bin Function ] ", 10);
  add_new_line(1);

  char hex[2];
  memmove(hex, "0", sizeof(char) * 2);
  assert(strcmp(map_hex_bin(hex), "0000") == 0);
  text_green("map_hex_bin -> should return 0000 binary digits for 0 hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "1", sizeof(char) * 2);
  assert(strcmp(map_hex_bin(hex), "0001") == 0);
  text_green("map_hex_bin -> should return 0001 binary digits for 1 hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "2", sizeof(char) * 2);
  assert(strcmp(map_hex_bin(hex), "0010") == 0);
  text_green("map_hex_bin -> should return 0010 binary digits for 2 hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "3", sizeof(char) * 2);
  assert(strcmp(map_hex_bin(hex), "0011") == 0);
  text_green("map_hex_bin -> should return 0011 binary digits for 3 hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "4", sizeof(char) * 2);
  assert(strcmp(map_hex_bin(hex), "0100") == 0);
  text_green("map_hex_bin -> should return 0100 binary digits for 4 hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "5", sizeof(char) * 2);
  assert(strcmp(map_hex_bin(hex), "0101") == 0);
  text_green("map_hex_bin -> should return 0101 binary digits for 5 hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "6", sizeof(char) * 2);
  assert(strcmp(map_hex_bin(hex), "0110") == 0);
  text_green("map_hex_bin -> should return 0110 binary digits for 6 hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "7", sizeof(char) * 2);
  assert(strcmp(map_hex_bin(hex), "0111") == 0);
  text_green("map_hex_bin -> should return 0111 binary digits for 7 hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "8", sizeof(char) * 2);
  assert(strcmp(map_hex_bin(hex), "1000") == 0);
  text_green("map_hex_bin -> should return 1000 binary digits for 8 hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "9", sizeof(char) * 2);
  assert(strcmp(map_hex_bin(hex), "1001") == 0);
  text_green("map_hex_bin -> should return 1001 binary digits for 9 hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "a", sizeof(char) * 2);
  assert(strcmp(map_hex_bin(hex), "1010") == 0);
  text_green("map_hex_bin -> should return 1010 binary digits for a hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "A", sizeof(char) * 2);
  assert(strcmp(map_hex_bin(hex), "1010") == 0);
  text_green("map_hex_bin -> should return 1010 binary digits for A hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "b", sizeof(char) * 2);
  assert(strcmp(map_hex_bin(hex), "1011") == 0);
  text_green("map_hex_bin -> should return 1011 binary digits for b hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "B", sizeof(char) * 2);
  assert(strcmp(map_hex_bin(hex), "1011") == 0);
  text_green("map_hex_bin -> should return 1011 binary digits for B hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "c", sizeof(char) * 2);
  assert(strcmp(map_hex_bin(hex), "1100") == 0);
  text_green("map_hex_bin -> should return 1100 binary digits for c hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "C", sizeof(char) * 2);
  assert(strcmp(map_hex_bin(hex), "1100") == 0);
  text_green("map_hex_bin -> should return 1100 binary digits for C hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "d", sizeof(char) * 2);
  assert(strcmp(map_hex_bin(hex), "1101") == 0);
  text_green("map_hex_bin -> should return 1101 binary digits for d hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "D", sizeof(char) * 2);
  assert(strcmp(map_hex_bin(hex), "1101") == 0);
  text_green("map_hex_bin -> should return 1101 binary digits for D hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "e", sizeof(char) * 2);
  assert(strcmp(map_hex_bin(hex), "1110") == 0);
  text_green("map_hex_bin -> should return 1110 binary digits for e hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "E", sizeof(char) * 2);
  assert(strcmp(map_hex_bin(hex), "1110") == 0);
  text_green("map_hex_bin -> should return 1110 binary digits for E hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "f", sizeof(char) * 2);
  assert(strcmp(map_hex_bin(hex), "1111") == 0);
  text_green("map_hex_bin -> should return 1110 binary digits for f hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "F", sizeof(char) * 2);
  assert(strcmp(map_hex_bin(hex), "1111") == 0);
  text_green("map_hex_bin -> should return 1110 binary digits for F hex", 10);
  memset(hex, 0, sizeof(char) * 2);
}
