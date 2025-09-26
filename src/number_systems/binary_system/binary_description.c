#include "../../displays/ansi_color.h"
#include "../../displays/escape_sequence.h"

void binary_description(void) {
  printf("%-15s--------------------------------------------------------%s",
         BLUE, RESET);
  add_new_line(1);
  printf("%-32sBinary to Other System%s", GREEN, RESET);
  add_new_line(1);
  printf("%-15s--------------------------------------------------------%s",
         BLUE, RESET);
}
