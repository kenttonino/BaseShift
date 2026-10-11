#include <assert.h>
#include <string.h>
#include "../../../utils/utils.h"
#include "../helper.h"

void test_reverse_string() {
  text_white("[ Testing reverse_string Functions ] ", 10);
  add_new_line(1);

  char bin[5];
  memmove(bin, "1234", sizeof(char) * 5);
  assert(strcmp(reverse_string(bin), "4321") == 0);
  text_green("reverse_string -> should return 4321 for 1234 input", 10);
  memset(bin, 0, sizeof(char) * 5);
}
