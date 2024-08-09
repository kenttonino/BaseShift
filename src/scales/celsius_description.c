#include "../displays/ansi_color.h"
#include "../displays/escape_sequence.h"
#include <stdio.h>

void celsius_description(void) {
  printf("%-15s--------------------------------------------------------%s",
         BLUE, RESET);
  add_new_line();
  add_new_line();
  printf("%-25sConvert Celsius (°C) to Other Scale%s", GREEN, RESET);
  add_new_line();
  add_new_line();
  printf("%-15s--------------------------------------------------------%s",
         BLUE, RESET);
}
