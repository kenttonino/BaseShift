#include "../displays/custom_print.h"
#include "ansi_color.h"
#include "escape_sequence.h"

void app_description(void) {
  printf("%-15s--------------------------------------------------------%s",
         BLUE, RESET);
  add_new_line(2);
  text_green("BaseShift", 38);
  add_new_line(2);
  text_white("A CLI tool thhat converts a number system to another.", 17);
  add_new_line(2);
  printf("%-15s--------------------------------------------------------%s",
         BLUE, RESET);
}
