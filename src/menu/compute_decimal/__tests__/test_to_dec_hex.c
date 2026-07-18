#include <assert.h>
#include "../../../utils/utils.h"
#include "../to_dec_hex.c"

void test_to_dec_hex(void) {
  text_white("[ Testing to_dec_hex Functions ]", 10);
  add_new_line(1);

  char rem[3];
  memmove(rem, "1", 2);
  assert(strcmp(_dec_hex_mapper(rem), "1") == 0);
  text_green("_dec_hex_mapper -> should return 1 hexadecimal digit for 1 decimal reminder", 10);
  add_new_line(1);

  memset(rem, 0, sizeof(char) * 3);
  memmove(rem, "2", 2);
  assert(strcmp(_dec_hex_mapper(rem), "2") == 0);
  text_green("_dec_hex_mapper -> should return 2 hexadecimal digit for 2 decimal reminder", 10);
  add_new_line(1);

  memset(rem, 0, sizeof(char) * 3);
  memmove(rem, "3", 2);
  assert(strcmp(_dec_hex_mapper(rem), "3") == 0);
  text_green("_dec_hex_mapper -> should return 3 hexadecimal digit for 3 decimal reminder", 10);
  memset(rem, 0, sizeof(char) * 3);
  add_new_line(1);

  memset(rem, 0, sizeof(char) * 3);
  memmove(rem, "4", 2);
  assert(strcmp(_dec_hex_mapper(rem), "4") == 0);
  text_green("_dec_hex_mapper -> should return 4 hexadecimal digit for 4 decimal reminder", 10);
  memset(rem, 0, sizeof(char) * 3);
  add_new_line(1);

  memset(rem, 0, sizeof(char) * 3);
  memmove(rem, "5", 2);
  assert(strcmp(_dec_hex_mapper(rem), "5") == 0);
  text_green("_dec_hex_mapper -> should return 5 hexadecimal digit for 5 decimal reminder", 10);
  memset(rem, 0, sizeof(char) * 3);
  add_new_line(1);

  memset(rem, 0, sizeof(char) * 3);
  memmove(rem, "6", 2);
  assert(strcmp(_dec_hex_mapper(rem), "6") == 0);
  text_green("_dec_hex_mapper -> should return 6 hexadecimal digit for 6 decimal reminder", 10);
  memset(rem, 0, sizeof(char) * 3);
  add_new_line(1);

  memset(rem, 0, sizeof(char) * 3);
  memmove(rem, "7", 2);
  assert(strcmp(_dec_hex_mapper(rem), "7") == 0);
  text_green("_dec_hex_mapper -> should return 7 hexadecimal digit for 7 decimal reminder", 10);
  memset(rem, 0, sizeof(char) * 3);
  add_new_line(1);

  memset(rem, 0, sizeof(char) * 3);
  memmove(rem, "8", 2);
  assert(strcmp(_dec_hex_mapper(rem), "8") == 0);
  text_green("_dec_hex_mapper -> should return 8 hexadecimal digit for 8 decimal reminder", 10);
  memset(rem, 0, sizeof(char) * 3);
  add_new_line(1);

  memset(rem, 0, sizeof(char) * 3);
  memmove(rem, "9", 2);
  assert(strcmp(_dec_hex_mapper(rem), "9") == 0);
  text_green("_dec_hex_mapper -> should return 9 hexadecimal digit for 9 decimal reminder", 10);
  memset(rem, 0, sizeof(char) * 3);
  add_new_line(1);

  memset(rem, 0, sizeof(char) * 3);
  memmove(rem, "10", 3);
  assert(strcmp(_dec_hex_mapper(rem), "A") == 0);
  text_green("_dec_hex_mapper -> should return A hexadecimal digit for 10 decimal reminder", 10);
  memset(rem, 0, sizeof(char) * 3);
  add_new_line(1);

  memset(rem, 0, sizeof(char) * 3);
  memmove(rem, "11", 3);
  assert(strcmp(_dec_hex_mapper(rem), "B") == 0);
  text_green("_dec_hex_mapper -> should return B hexadecimal digit for 11 decimal reminder", 10);
  memset(rem, 0, sizeof(char) * 3);
  add_new_line(1);

  memset(rem, 0, sizeof(char) * 3);
  memmove(rem, "12", 3);
  assert(strcmp(_dec_hex_mapper(rem), "C") == 0);
  text_green("_dec_hex_mapper -> should return C hexadecimal digit for 12 decimal reminder", 10);
  memset(rem, 0, sizeof(char) * 3);
  add_new_line(1);

  memset(rem, 0, sizeof(char) * 3);
  memmove(rem, "13", 3);
  assert(strcmp(_dec_hex_mapper(rem), "D") == 0);
  text_green("_dec_hex_mapper -> should return D hexadecimal digit for 13 decimal reminder", 10);
  memset(rem, 0, sizeof(char) * 3);
  add_new_line(1);

  memset(rem, 0, sizeof(char) * 3);
  memmove(rem, "14", 3);
  assert(strcmp(_dec_hex_mapper(rem), "E") == 0);
  text_green("_dec_hex_mapper -> should return E hexadecimal digit for 14 decimal reminder", 10);
  memset(rem, 0, sizeof(char) * 3);
  add_new_line(1);

  memset(rem, 0, sizeof(char) * 3);
  memmove(rem, "15", 3);
  assert(strcmp(_dec_hex_mapper(rem), "F") == 0);
  text_green("_dec_hex_mapper -> should return F hexadecimal digit for 15 decimal reminder", 10);
  memset(rem, 0, sizeof(char) * 3);
}
