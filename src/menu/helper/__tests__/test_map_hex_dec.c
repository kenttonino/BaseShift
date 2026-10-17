#include <assert.h>
#include "../../../utils/utils.h"
#include "../helper.h"

void test_map_hex_dec(void) {
  text_white("[ Testing map_hex_dec Function ] ", 10);
  add_new_line(1);

  char hex[2];
  memmove(hex, "0", sizeof(char) * 2);
  assert(map_hex_dec(hex) == 0);
  text_green("map_hex_dec -> should return 0 decimal digit for 0 hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "1", sizeof(char) * 2);
  assert(map_hex_dec(hex) == 1);
  text_green("map_hex_dec -> should return 1 decimal digit for 1 hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "2", sizeof(char) * 2);
  assert(map_hex_dec(hex) == 2);
  text_green("map_hex_dec -> should return 2 decimal digit for 2 hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "3", sizeof(char) * 2);
  assert(map_hex_dec(hex) == 3);
  text_green("map_hex_dec -> should return 3 decimal digits for 3 hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "4", sizeof(char) * 2);
  assert(map_hex_dec(hex) == 4);
  text_green("map_hex_dec -> should return 4 decimal digits for 4 hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "5", sizeof(char) * 2);
  assert(map_hex_dec(hex) == 5);
  text_green("map_hex_dec -> should return 5 decimal digits for 5 hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "6", sizeof(char) * 2);
  assert(map_hex_dec(hex) == 6);
  text_green("map_hex_dec -> should return 6 decimal digits for 6 hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "7", sizeof(char) * 2);
  assert(map_hex_dec(hex) == 7);
  text_green("map_hex_dec -> should return 7 decimal digits for 7 hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "8", sizeof(char) * 2);
  assert(map_hex_dec(hex) == 8);
  text_green("map_hex_dec -> should return 8 decimal digits for 8 hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "9", sizeof(char) * 2);
  assert(map_hex_dec(hex) == 9);
  text_green("map_hex_dec -> should return 9 decimal digits for 9 hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "a", sizeof(char) * 2);
  assert(map_hex_dec(hex) == 10);
  text_green("map_hex_dec -> should return 10 decimal digits for a hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "A", sizeof(char) * 2);
  assert(map_hex_dec(hex) == 10);
  text_green("map_hex_dec -> should return 10 decimal digits for A hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "b", sizeof(char) * 2);
  assert(map_hex_dec(hex) == 11);
  text_green("map_hex_dec -> should return 11 decimal digits for b hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "B", sizeof(char) * 2);
  assert(map_hex_dec(hex) == 11);
  text_green("map_hex_dec -> should return 11 decimal digits for B hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "c", sizeof(char) * 2);
  assert(map_hex_dec(hex) == 12);
  text_green("map_hex_dec -> should return 12 decimal digits for c hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "C", sizeof(char) * 2);
  assert(map_hex_dec(hex) == 12);
  text_green("map_hex_dec -> should return 12 decimal digits for C hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "d", sizeof(char) * 2);
  assert(map_hex_dec(hex) == 13);
  text_green("map_hex_dec -> should return 13 decimal digits for d hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "D", sizeof(char) * 2);
  assert(map_hex_dec(hex) == 13);
  text_green("map_hex_dec -> should return 13 decimal digits for D hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "e", sizeof(char) * 2);
  assert(map_hex_dec(hex) == 14);
  text_green("map_hex_dec -> should return 14 decimal digits for e hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "E", sizeof(char) * 2);
  assert(map_hex_dec(hex) == 14);
  text_green("map_hex_dec -> should return 14 decimal digits for E hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "f", sizeof(char) * 2);
  assert(map_hex_dec(hex) == 15);
  text_green("map_hex_dec -> should return 15 decimal digits for f hex", 10);
  memset(hex, 0, sizeof(char) * 2);
  add_new_line(1);

  memmove(hex, "F", sizeof(char) * 2);
  assert(map_hex_dec(hex) == 15);
  text_green("map_hex_dec -> should return 15 decimal digits for F hex", 10);
  memset(hex, 0, sizeof(char) * 2);
}
