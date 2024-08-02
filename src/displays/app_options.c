#include "ansi_color.h"
#include "escape_sequence.h"
#include <stdlib.h>

char *option(int num) {
  char *formatted_option = malloc(sizeof(char) * 50);

  // Write the formatted output in formatted_option variable.
  sprintf(formatted_option, "%-16s[%s %s%d%s %s]%s", BLUE, RESET, GREEN, num,
          RESET, BLUE, RESET);

  return formatted_option;
}

void app_options(void) {
  printf("%s Convert Binary", option(1));
  add_new_line();
  printf("%s Convert Decimal", option(2));
  add_new_line();
  printf("%s Convert Octal", option(3));
  add_new_line();
  printf("%s Convert Hexadecimal", option(4));
  add_new_line();
  printf("%s Exit", option(5));
  add_new_line();
}
