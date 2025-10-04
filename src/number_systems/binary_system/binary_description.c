#include "../../displays/ansi_color.h"
#include "../../displays/custom_print.h"
#include "../../displays/escape_sequence.h"

void binary_description(void) {
  printf("%-15s--------------------------------------------------------%s",
         BLUE, RESET);
  add_new_line(2);
  text_green("Binary to Other System", 32);
  add_new_line(2);
  printf("%-15s--------------------------------------------------------%s",
         BLUE, RESET);
}
