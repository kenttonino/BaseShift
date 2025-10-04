#include "ansi_color.h"
#include "utils.h"
#include <stdlib.h>

char *format_option(int num) {
  char *formatted_option = malloc(sizeof(char) * 50);

  // Write the formatted output in formatted_option variable.
  sprintf(formatted_option, "%-16s[%s %s%d%s %s]%s", BLUE, RESET, GREEN, num,
          RESET, BLUE, RESET);

  return formatted_option;
}

void app_options(void) {
  printf("%s Convert Binary", format_option(1));
  add_new_line(1);
  printf("%s Convert Decimal", format_option(2));
  add_new_line(1);
  printf("%s Convert Octal", format_option(3));
  add_new_line(1);
  printf("%s Convert Hexadecimal", format_option(4));
  add_new_line(1);
  printf("%s Exit", format_option(5));
  add_new_line(1);
}
